#include "miso.hpp"

/**
 * Set Contract Owner
 * @desc Updates the current contract owner configuration
 * @param delegate <eosio::name> New contract owner 
 * @author Mitch Pierias <https://github.com/MitchPierias>
 * @public
 */
void setowner(const name delegate) {
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
void purchase(const account_name account, const asset amount, const asset paid) {

}

/**
 * Witness Task
 * @desc Allows a shareholder to witness the completion of a task
 * @param account <eosio::name> Witness account
 * @param task_id <uint64_t> Task identifier
 * @author Mitch Pierias <https://github.com/MitchPierias>
 * @public
 */
void witness(const account_name account, const uint64_t task_id) {

}