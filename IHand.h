#pragma once

#include "Card.h"

#include <set>

namespace Poker
{

/*
 * Each poker game starts with players choosing to join the game (i.e. receive
 * a hand). Cards are dealt into the hand which can be folded (deleted) before
 * the end of the game (round?)
 *
 * Assumptions:
 * - Cards can be dealt face down and not visible to other players (hole cards).
 * - Cards can be dealt face up and visible to all players.
 *   - Face up cards can belong just to the player (i.e. seven stud) or
 *     shared with other players (community cards).
 * - Community cards don't have to be exclusively owned by one Hand.
 * - Only hole cards can be removed and replaced by new cards (i.e. five card
 *   draw).
 */
class IHand
{
public:
	// Add face-down cards into hand.
	virtual void AddHoleCard(Card card) = 0;

	// These cards are visible to all players and go by different names like:
	// door card, fourth street, river.
	// For simplicity, Hold'Em community cards are added to each players hand.
	virtual void AddCommunity(Card card) = 0;

	// Some games (i.e. five card draw) allow face-down cards to be swapped out.
	virtual void RemoveCards(std::set<Card> const& cards) = 0;

	// Only player can view hole cards.
	virtual std::set<Card> GetHoleCards() const = 0;

	// All players can view these cards.
	// Access to hand is done via IPlayer to control access.
	virtual std::set<Card> GetVisibleCards() const = 0;

	// Only player / game engine needs access to all cards to determine best
	// hand.
	virtual std::set<Card> GetAllCards() const = 0;
};

} // namespace Poker
