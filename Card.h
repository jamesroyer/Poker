#pragma once

namespace Poker
{

/*
 * Notes:
 * - Cards need to be sortable to be able to put them into a std::set.
 * - Card could simply be a number between 1-52 rather than suit/number.
 * - Helper functions can be used to convert to different formats/styles.
 * - I don't think this should be an interface class/struct.
 */
struct Card
{
	enum class Suit { heart, club, diamond, spade };

	Suit suit;
	int number;	// 1 (A), 2-10, 11 (J), 12 (Q), 13 (K)

	Card(Suit suit, int number);
	Card(Card const& other);
	Card& operator=(Card const& other);
	Card(Card&& other);
	Card& operator=(Card&& other);

	operator int() const;

	bool operator<(Card const& other) const;
};

} // namespace Poker
