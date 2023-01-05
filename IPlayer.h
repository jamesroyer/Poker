#pragma once

#include "Hand.h"

namespace Poker
{

/*
 * The player interface needs to:
 * - Allow the game engine to prompt players to take actions
 *   (ante, add blinds, check, bet, raise, or fold).
 * - Allow other players to know stats about them
 *   (chip count, position, face up cards, etc.) Maybe use pub/sub.
 * - Allow different types of players (real or AI).
 * - Players need to exist independently of the hands they play.
 * - Player needs to be able to retrieve current limits (ante, min bet,
 *   max bet, etc.)
 *
 * Player will need to be given:
 * - Game engine
 *   - Needed to query stats about hands, players, pot.
 * - Poker clock
 *   - Needed to query min/max bet, ante.
 *
 * NOTES:
 * - Players make decisions based on a variety of information.
 * - Pub/Sub would allow AI players to track information and alter their
 *   difficulty levels.
 */
class IPlayer
{
public:
	enum class Action { ante, blind, check, bet, raise, fold };
	enum class Button { none, dealer, smallblind, bigblind };

	// Assign hand to player. Hand receives dealt cards.
	virtual void SetHand(Hand const& hand) = 0;

	// Provide another player with a list of face up cards.
	// Not ideal to have each player querying all other players.
	virtual Hand GetVisibleHand() const = 0;

	// Buttons: dealer (D), small blind (SB), or big blind (BB)
	virtual void SetButton(Button button) = 0;

	// Allow another player/game engine to query button.
	virtual Button GetButton() const = 0;

	// Player has won the pot or side-pot.
	virtual void AwardChips(unsigned int amount) = 0;

	// Provide another player/game engine with chip count.
	virtual unsigned int GetChipCount() const = 0;

	// When a player "goes all in" after chips have been collected from all
	// remaining players equal to that amount, any additional raises are
	// added to a side pot. If the all-in player has the best hand, they
	// win the main pot and any side-pots they are entitled to.
	virtual void SetMaxPot(size_t potOffset) = 0;

	// Game engine prods player to take action.
	virtual void PerformAction(Action action) = 0;
};

} // namespace Poker
