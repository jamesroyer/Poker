#pragma once

namespace Poker
{

using IGame;
using Player;

/*
 * Notes:
 * - Derived classes will use Dependency Injection to build up a specific
 *   type of game (e.g. five card draw).
 * - Derived classes could be designed to change the game type after each
 *   hand (dealer's choice).
 */
class IGameEngine
{
public:
	// Allow the type of game to be changed after each hand (dealer's choice).
	// Choice of game types may be limited by number of players.
	// If the game type is determined on construction, this method is not
	// needed.
	virtual void SetGameType(IGame* game) = 0;

	// FSM methods ...
	virtual void Enter() = 0;
	virtual void StartNewRound() = 0;
	virtual void CollectAnte() = 0;
	virtual void CollectBlinds() = 0;
	virtual void Deal() = 0;
	virtual void Bet() = 0;
	virtual void ReplaceCards() = 0;
	virtual void Showdown() = 0;
	virtual void Payout() = 0;

	// Player methods ...
	virtual Player& FindStartingPlayer() = 0;
};

} // namespace Poker
