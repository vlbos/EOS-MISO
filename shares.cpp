#include "shares.hpp"

namespace miso {

	/**
	 * Set Terms
	 * @desc Updates the terms of a particular share
	 * @param share_id <uint64_t> Share unique identifier
	 * @param term_id <uint64_t> Term unique identifier
	 * @author Mitch Pierias <https://github.com/MitchPierias>
	 * @public
	 */
	void shares::terms(const uint64_t share_id, const uint64_t term_id) {
		// Authenticate
		require_auth(_self);
		require_auth(configs.get().application);
		// Update configuration
		configs.set(Config{ delegate }, delegate);
	}

	/**
	 * Lock Share
	 * @desc Locks a share from all activity
	 * @param share_id <uint64_t> Share unique identifier
	 * @author Mitch Pierias <https://github.com/MitchPierias>
	 * @public
	 */
	void shares::lock(const uint64_t share_id) {
		// Authenticate
		require_auth(_self);
		require_auth(configs.get().application);
		// Update configuration
		configs.set(Config{ delegate }, delegate);
	}
}