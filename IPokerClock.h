#pragma once

#include "IPolicy.h"

namespace Poker
{

/*
 * A poker clock is used to periodically increase the limits to help speed
 * a game up and eliminate players to reach the end of the game.
 *
 * There are algorithms that are used to calculate limits based on game type,
 * number of players, and desired end time. The end time is not guaranteed but
 * they work really well.
 */
class IPokerClock
{
public:
	virtual IPolicy GetCurrentPolicy() const = 0;

	virtual void Start() = 0;
	virtual void Stop() = 0;
	// ... functions needed to configure the poker clock ...
};

} // namespace Poker
