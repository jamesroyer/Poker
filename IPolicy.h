#pragma once

namespace Poker
{

/*
 * A policy is applied to the current game/round/hand. A policy is returned
 * from the poker clock and is valid until the current round is complete.
 *
 * The ante and blind amounts are determined at the start of the hand and
 * probably don't need to be stored, but it would be useful to retain for
 * logging purposes or to reference during the round.
 *
 * The limits are used differently in each type of game and need to be
 * remembered during the multiple rounds of betting.
 */
class IPolicy
{
public:
	virtual int GetMaxRaises() const = 0;
	virtual int GetMinBet() const = 0;
	virtual int GetMaxBet() const = 0;
	// ...
};

class PolicyUnlimited : public IPolicy
{
public:
	int GetMaxRaises() const override { return 0; }
	int GetMinBet() const override { return 0; }
	int GetMaxBet() const override { return 0; }
	// ...
};

} // namespace Poker
