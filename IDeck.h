#pragma once

#include <Card.h>

namespace Poker
{

class IDeck
{
public:
	// Allow deck of cards to be reused.
	virtual void Reset() = 0;

	// Called to randomize the cards.
	// Perhaps it isn't necessary as it could be done in ctor or Reset().
	virtual void Shuffle() = 0;

	// Return the card at the top of the deck.
	// Throw an exception if no more cards are available.
	virtual Card GetCard() = 0;
};

} // namespace Poker
