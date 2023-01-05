#pragma once

namespace Poker
{

using IPlayer;

/*
 * Interface to a new game/round.
 *
 * Notes:
 * - When a new round starts, need to retrieve data from the poker clock
 *   and store it until the round ends.
 * - Game type determines the maximum number of players based on the maximum
 *   number of cards that could be dealt during a round.
 * - Limit games need to prevent additional raises once limit is reached.
 * - An FSM is one way to implement a generic game engine. All states need
 *   to be implemented but may just advance the FSM state.
 */
class IGame
{
public:
	// Different games use more/less cards with limits player count.
	virtual int GetMaxPlayers() const = 0;

	// Return max raise limit for current betting round.
	// Return zero for no limit.
	virtual int GetMaxRaise() const = 0;

	// Return max bet limit for current betting round.
	// Return zero for no limit.
	virtual int GetMaxBet() const = 0;

	// Deal count determines betting rounds.
	virtual int GetDealCount() const = 0;

	// Players are added to a game up to the max limit.
	// Maybe players should be assigned to seats rather than to the end of
	// the list.
	virtual void AddPlayer(IPlayer& player) = 0;

	// May want to allow players to leave a game between rounds.
	virtual void RemovePlayer(IPlayer& player) = 0;

	// FSM methods...
	virtual void CollectOpeningAmount() = 0;
	virtual void Deal() = 0;
	virtual IPlayer& GetStartingPlayer() = 0;

	// Return true to move to next player.
	// Return false when betting round is complete.
	virtual bool PerformBetting() = 0;

	// Pot methods ...
	virtual void RakeChips() = 0;
	virtual void AddSidePot() = 0;
};

} // namespace Poker
