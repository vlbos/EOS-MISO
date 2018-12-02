#include "miso.hpp"

/**
 * Set Contract Owner
 * @desc Updates the current contract owner configuration
 * @param delegate <eosio::name> New contract owner 
 * @author Mitch Pierias <https://github.com/MitchPierias>
 * @public
 */
void miso::setowner(const name delegate) {
	// Authenticate
	require_auth(_self);
	require_auth(configs.get().application);
	// Update configuration
	configs.set(Config{ delegate }, delegate);
}

/**
 * Purchase Shares
 * @desc Purchases shares for account at the current market price
 * @param account <eosio::name> Purchaser account
 * @param amount <eosio::asset> Shares to purchase
 * @param paid <eosio::asset> EOS amount paid
 * @author Mitch Pierias <https://github.com/MitchPierias>
 * @public
 */
void miso::purchase(const account_name account, const asset amount, const asset paid) {

}

/**
 * Witness Task
 * @desc Allows a shareholder to witness the completion of a task
 * @param account <eosio::name> Witness account
 * @param task_id <uint64_t> Task identifier
 * @author Mitch Pierias <https://github.com/MitchPierias>
 * @public
 */
void miso::witness(const account_name account, const uint64_t task_id) {

}

/**
 * Payment Received
 * @desc Called be eosio.token when asset transfer occured
 * @param transfer <eosio::currency::transfer> Transfer details
 * @param caller <eosio::account_name> Caller account
 * @author Mitch Pierias <https://github.com/MitchPierias>
 * @private
 */
void miso::received_payment(const currency::transfer &transfer, const account_name caller) {
	// Validate arguments
	eosio_assert(caller == N(eosio.token), "Only eosio.token may call this action");
	eosio_assert(transfer.quantity.is_valid(), "Invalid quantity");
	// Ignore invalid transfers
	if (transfer.from == _self || transfer.to != _self || transfer.from == N(eosio.ram)) return;
	
	print("Received payment ", transfer.quantity, " from ", transfer.from);
}

extern "C" void apply(uint64_t receiver, uint64_t code, uint64_t action) {

	auto self = receiver;

	if (code == self || code == N(eosio.token)) {

		if (action == N(transfer)) {
			eosio_assert(code == N(eosio.token), "EOS required for transfer");
		}

		TYPE thiscontract(self);

		switch (action) {
			EOSIO_API(TYPE, MEMBERS)
		}

		// Prevent contract destructor from executing `eosio_exit(0);`
	}
}