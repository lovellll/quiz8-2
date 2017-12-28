#pragma once
#include <array>
#include "Card.h"


class Deck
{
private:
	std::array<Card, 52> m_deck;
	int m_cardIndex;

public:
	Deck():m_cardIndex(0)
	{
		// We could initialize each card individually, but that would be a pain.  Let's use a loop.
		int card = 0;
		for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
			for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
			{
				m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
				++card;
			}
	}

	void printDeck();

private:
	 
	static int getRandomNumber(int min, int max)
	{
		// Generate a random number between min and max (inclusive)
		// Assumes srand() has already been called
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																					 // evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static void swapCard(Card &a, Card &b)
	{
		Card temp = a;
		a = b;
		b = temp;
	}

public:

	void shuffleDeck();

	const Card& dealCard();

};