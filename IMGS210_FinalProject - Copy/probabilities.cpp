#include "BlackjackProb.h"
using namespace std;

void probabilities(int valueArray[312], int suitArray[312], string playerHand[13], string dealerHand[13], int& nextCard, 
	 int& totalPlayerValue, int& totalDealerValue) {

	/*
	Choices for inputs.

	1. chance of getting a specific card value given the amount of cards already drawn
		"given there are X amount of cards of Y value and there are Z amount of cards left in the deck, "

	2. chance of getting a specific card and suit given the amount of cards already drawn
		"given there are X amount of cards of Y value and K suit and there are Z amount of cards left in the deck, "

	3. chance of player win in the current game compared to a dealer score of 17
		"

	4. chance of dealer win in the current game


	5. chance of dealer drawing over 21

	6. Player blackjack in the next card


	*/

	int input = 1;

	cout << "What would you like to know? Enter a number." << endl;
	cin >> input;


	if (input == 6) {

		cout << "Calculating the chance of the player getting a blackjack in the next card pull." << endl;

		int neededValue = 21 - totalPlayerValue;
		int valueFound = 0;


		for (int i = nextCard; i <= 311; i++) {

			if (valueArray[i] == neededValue) {

				valueFound++;

			}
		}

		cout << "Out of " << 312 - nextCard << " cards, there are " << valueFound << " cards that meet the requirements." << endl;
		cout << "The chance of pulling the card is " << (valueFound / 312) * 100 << "%." << endl;

	}


}