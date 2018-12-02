#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>
#include <eosiolib/print.h>
#include <eosiolib/transaction.hpp>
#include <string>

namespace miso {

	using namespace eosio;
	using eosio::asset;
	using std::string;

	class shares : public eosio::contract {
		

		public:
			// Constructor
			explicit shares(action_name self) : contract(self), config(_self, _self) {
				config.set(Config{_self}, _self);
			}
			// @abi action
			void terms(const uint64_t share_id, const uint64_t term_id);
			// @abi action
			void lock(const uint64_t share_id);

		private:
			// @abi table shares i64
			struct Share {
				uint64_t		terms; // Share class
				uint64_t		date_issued;
				bool			locked;
			}
			// @abi table terms i64
			struct Term {
				uint64_t		id;
				string			name;
				bool			votable = true;	// Carrys a voting right
				uint8_t			preference;		// Compensation ordering
				uint8_t			dividend;		// Earnings payout percentage
				uint8_t			distribution; 	// Solvency distribution
			}

			struct Config {
				account_name		owner;
			};

			typedef singleton<N(config), Config> config_table;

			config_table config;
	};
}