#include "BlackjackProb.h"
using namespace std;

/*
To-do list:
3. probabilities. ungh

4. split starting cards into two hands if they are the same.

5. possibly simple graphics?

*/



void WelcomeText();

void deck(int deckArray[312], string cardArray[312], int cardNumber, int valueArray[312], int suitArray[312]);

void turnOperation(string cardArray[312], int cardNumber, string playerHand[13], string dealerHand[13], int& nextCard, int valueArray[312],
	 int suitArray[312], int& totalPlayerValue, int& totalDealerValue);

void probabilities(int valueArray[312], int suitArray[312], string playerHand[13], string dealerHand[13], int& nextCard, 
	 int& totalPlayerValue, int& totalDealerValue);

int main() {

	int playerChoice = 1;
	int deckArray[312];
	string cardArray[312];
	int valueArray[312];
	int suitArray[312];
	char continueGame = 'Q';
	int cardNumber = 0;
	string playerHand[13];  //Cannot exceed 13 or that would be an impossible hand size (1+1+1+1+1+1+2+2+2+2+2+2+3 = 21)
	string dealerHand[13];
	int nextCard = 0;
	char reshuffle = 'N';
	int totalPlayerValue = 0;
	int totalDealerValue = 0;


	WelcomeText();
	
	cin >> continueGame;

	deck(deckArray, cardArray, cardNumber, valueArray, suitArray);			// Shuffling the deck
	
	while (continueGame == 'S' || continueGame == 's') {

		

		turnOperation(cardArray, cardNumber, playerHand, dealerHand, nextCard, valueArray, suitArray, totalPlayerValue, totalDealerValue); // Playing the game

		cout << "Would you like to play again? Press S to replay or Q to leave." << endl;

		cin >> continueGame;

		if (continueGame == 'S' || continueGame == 's') {

			cout << "Resuming program. Would you like the deck to be reshuffled? Answer Y or N." << endl;

			// Emptying hands

			for (int i = 0; i < 13; i++) {

				playerHand[i].clear(); // clear each string
				dealerHand[i].clear();

			}



			cin >> reshuffle;			// Asking if the player wants the deck to be reshuffled

			if (reshuffle == 'Y' || reshuffle == 'y') {

				cout << "The deck will be reshuffled." << endl;
				cout << endl;

				deck(deckArray, cardArray, cardNumber, valueArray, suitArray); 
				nextCard = 0;

			} else {
			
				system("cls");

				cout << "The deck will not be reshuffled." << endl;
				cout << endl;

				system("pause");
			}

			continue;

		}
		else if (continueGame == 'Q' || continueGame == 'q') {

			cout << "Ending program" << endl;

			break;

		}
		else {

			system("cls");
			cout << "Neither S or Q was selected. Choose one." << endl;

			cin >> continueGame;

			continue;

		}

		

	}




	return 0;
}