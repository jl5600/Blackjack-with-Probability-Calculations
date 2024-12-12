#include "BlackjackProb.h"
using namespace std;

void deck(int deckArray[312], string cardArray[312], int cardNumber, int valueArray[312], int suitArray[312]) {

	cout << "The deck is being shuffled" << endl;
	cout << "Do you want to see the cards? Answer Y or N" << endl;

	char readCards;
	int noReadOut = 1;
	cin >> readCards;		// Getting input to display cards

	if (readCards == 'Y' || readCards == 'y') {

		cout << "Showing all cards." << endl;

		noReadOut = 1;		// Will read cards

	}
	else if (readCards == 'N' || readCards == 'n') {

		cout << "Hiding cards." << endl;

		noReadOut = 0;		// Won't read cards

	}
	else {

		cout << "Neither Y or N was selected. Choose one." << endl;

		cin >> readCards;	// Makes sure only acceptable inputs are used

	}




	srand(time(0));

	for (cardNumber = 0; cardNumber <= 311; cardNumber++) {

		if (readCards == 'Y' || readCards == 'y') {

			noReadOut = 1;

		}
		else if (readCards == 'N' || readCards == 'n') {

			noReadOut = 0;

		}


		deckArray[cardNumber] = (rand() % 54);		// Divides random number by 54 to represent one card of a deck

		int suit = deckArray[cardNumber] % 4;		// Divides the random number by 4 to determine the suit of the card
		suitArray[cardNumber] = suit + 1;
		int value = deckArray[cardNumber] % 13;		// Divides the random number by 13 to determine the value of the card

		if (value >= 10) {

			int faceValue = 9;
			valueArray[cardNumber] = faceValue + 1;

		}
		else if (value == 0) {

			int faceValue = 10;
			valueArray[cardNumber] = faceValue + 1;

		}
		else {

			valueArray[cardNumber] = value + 1;

		}


		if (value == 0) {							// This section attaches strings to the suits and values associated with the card  
			cardArray[cardNumber] = "Ace of ";

		}
		else if (value == 10) {
			cardArray[cardNumber] = "Jack of ";

		}
		else if (value == 11) {
			cardArray[cardNumber] = "Queen of ";

		}
		else if (value == 12) {
			cardArray[cardNumber] = "King of ";

		}
		else {
			cardArray[cardNumber] = to_string(value + 1) + " of ";

		}

		if (suit == 0) {

			cardArray[cardNumber] = cardArray[cardNumber] + "Spades";

		}
		else if (suit == 1) {

			cardArray[cardNumber] = cardArray[cardNumber] + "Clubs";

		}
		else if (suit == 2) {

			cardArray[cardNumber] = cardArray[cardNumber] + "Hearts";

		}
		else if (suit == 3) {

			cardArray[cardNumber] = cardArray[cardNumber] + "Diamonds";

		}

		int similarityCount = 0;
		bool resetCount = true;

		for (int i = 0; i != cardNumber; i++) {					// This section compares the last drawn card with every previous card, then 
			// adds one to similarityCount for each like card. If similarityCount reaches 6,  
			if (cardArray[i] == cardArray[cardNumber]) {		// the limit of that specific card in the boot has been reached, and will decrease 
				// the cardNumber counter by one and not reset the similarityCount. This is done 
				similarityCount++;								// to get a different number in which the suit and value will be determined from.

			}

			if (similarityCount == 6) {

				cardNumber--;
				noReadOut = 0;
				resetCount = false;
				break;
			}

		}

		if (noReadOut == 1) {

			cout << "Card " << cardNumber + 1 << ": " << cardArray[cardNumber] << " Number of total appearances: " << similarityCount + 1 << endl;
			//cout << "Internal Value: " << valueArray[cardNumber] << " Internal Suit: " << suitArray[cardNumber] << endl; // Debugging line

		}

		if (resetCount = true) {

			similarityCount = 0;

		}

	}

	cout << "The deck is shuffled!" << endl;

	system("pause");
	system("CLS");
}