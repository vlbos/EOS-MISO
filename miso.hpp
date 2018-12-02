#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>
#include <eosiolib/print.h>
#include <eosiolib/transaction.hpp>
#include <string>

using namespace eosio;
using eosio::asset;
using std::string;

class miso : public eosio::contract {
	

	public:
		// Constructor
		explicit miso(action_name self) : contract(self), config(_self, _self) {
			config.set(Config{_self}, _self);
		}
		// @abi action
		void setowner(const name delegate);
		// @abi action
		void purchase(const account_name account, const asset amount, const asset paid);
		// @abi action
		void witness(const account_name account, const uint64_t task_id);

	private:
		// @abi table wallets i64
		struct Wallet {
			account_name	account;
			uint64_t		balance;

			auto primary_key() const {
				return account;
			};

			EOSLIB_SERIALIZE(Wallet, (account)(balance));
		};
		// @abi table tasks i64
		struct Task {
			uint64_t		id;
			string			name;
		}

		struct Config {
			account_name		owner;
		};

		typedef singleton<N(config), Config> config_table;

		config_table config;
};