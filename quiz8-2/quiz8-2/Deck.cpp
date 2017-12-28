#include "stdafx.h"
#include "Deck.h"
#include <iostream>

void Deck::printDeck()
{
	for (const auto &card : m_deck)
	{
		card.printCard();
		std::cout << ' ';
	}

	std::cout << '\n';
}

void Deck::shuffleDeck()
{
	// Step through each card in the deck
	for (int index = 0; index < 52; ++index)
	{
		// Pick a random card, any card
		int swapIndex = getRandomNumber(0, 51);
		// Swap it with the current card
		swapCard(m_deck[index], m_deck[swapIndex]);
	}
	m_cardIndex = 0;
}
const Card& Deck::dealCard()
{
	return m_deck[m_cardIndex++];
}