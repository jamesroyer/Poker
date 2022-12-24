# Poker

# UML Class Diagrams

| Class         | Description                                                          |
| ------------- | -------------------------------------------------------------------- |
| IPolicy       | Data needed for each poker round (ante, min/max bet, raise limit)    |
| IPokerClock   | Abstract interface to use for testing                                |
| PokerClock    | Responsible for periodically updating policy data                    |
| Deck          | A deck of cards that can be shuffled and retrieve one card at a time |
| Card          | One of 52 unique cards in a deck assigned a suit and a number (1-13) |
| Hand          | Poker hands consist of 5 or 7 cards or 2 cards + 5 community cards   |
| Pot           | Chips are added to the pots - need to handle all-in players          |
| Decision      | Player's decision: check, call, bet, raise, fold                     |
| IGame         |                                                                      |
| Game          | Data shared with players: pot size, active hands, other player chips |
| Player        | Holds player's hand and chips. Player decision is made when betting. |
| GameEngine    | FSM driven by game type. Find next player, start bet, rake chips.    |
| IGameEngine   | Interface to be implemented by different poker games.                |
| HoldEm        | Implements IGameEngine with Texas Hold 'Em rules.                    |
| FiveCardDraw  | Implements IGameEngine with five card draw rules.                    |
| SevenCardStud | Implements IGameEngine with seven card stud rules.                   |

```mermaid
classDiagram
	class IPolicy {
		int minBet
		int maxBet
		int ante
		int smallBlind
		int bigBlind
		int raiseLimit
	}
	class IPokerClock {
		<<interface>>
		IPolicy GetCurrentPolicy()
	}
	class PokerClock {
	}
	class Deck {
		vector m_cards
		Shuffle()
		GetCard()
	}
	class Card {
		enum m_suit
		int m_number
	}
	class Hand {
		list m_cards
		AddCard()
		RemoveCard()
	}
	class Pot {
		vector chips
	}
	class IGame {
		<<interface>>
		IPolicy m_policy
		IPokerClock m_clock
		vector m_pots
		vector m_players
		vector m_hands
		int m_maxPlayers

		+SetMaxPlayers()
		+AddPlayer()
		+RemovePlayer()

		-AssignHand_(Player)
		-RevokeHand_(Player)

		-MoveDealButton_()
		-AssignBlinds_()
		-RakeChips_()
		-SetPlayersMaxPot_(Player)
	}
	class Game {
	}
	class GameEngine {
		+StartFSM()
		#StartNewRound()
		#CollectAnte()
		#CollectBlinds()
		#Deal()
		#Bet()
		#ReplaceCards()
		#Showdown()
		#Payout()
	}
	class HoldEm {
		+Deal()
		-DealHoleCards_()
		-DealFlopCards_()
		-DealTurnCard_()
		-DealRiverCard_()
	}
	class FiveCardDraw {
		+Deal()
		-DealInitialCards_()
		-DealReplacementCards_()
	}
	class SevenCardStud {
		+Deal()
		-DealInitialCards_()
		-DealFourthStreet_()
		-DealFifthStreet_()
		-DealSixthStreet_()
		-DealSeventhStreet_()
	}
	class Decision {
		<<enumeration>>
		Check
		Bet
		Raise
		Fold
	}
	class Player {
		Hand m_hand
		int m_chips
		optional m_potOffset
		+Decision Action()
		-Decision EvalulateCards_()
		-Decision EvalulatePlayers_()
	}
	Card --o Deck
	IPokerClock <|-- PokerClock
	IPolicy <|-- IPokerClock
	GameEngine <|-- HoldEm
	GameEngine <|-- FiveCardDraw
	GameEngine <|-- SevenCardStud
	GameEngine o-- IGame
	IGame o-- Deck
	IGame o-- IPokerClock
	IGame o-- IPolicy
	IGame *-- Pot
	IGame <|-- Game
	Card --o Hand
	Hand --o IGame
	Hand --o Player
	Decision -- Player
	Player --o IGame
```
