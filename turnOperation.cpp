#include "BlackjackProb.h"


using namespace std;

void turnOperation(string cardArray[312], int cardNumber, string playerHand[13], string dealerHand[13], int& nextCard, 
	 int valueArray[312], int suitArray[312], int& totalPlayerValue, int& totalDealerValue) {

	int naturalSkip = 0;
	int playerLostSkip = 0;
	int dealerLostSkip = 0;
	int playerHandStep = 1;
	int dealerHandStep = 1;
	int unchangedAce = 0;

	cout << "You have been dealt a " << cardArray[nextCard] << "." << endl;
	playerHand[playerHandStep] = cardArray[nextCard];
	totalPlayerValue = valueArray[nextCard];

	if ((valueArray[nextCard]) == 11) {		// If the card that was just added from the valueArray is 11, unchangedAce will be true. 

		unchangedAce = 1;

	}

	playerHandStep++;
	nextCard++;


	system("pause");
	cout << endl;

	cout << "The dealer has drawn a " << cardArray[nextCard] << "." << endl;
	dealerHand[dealerHandStep] = cardArray[nextCard];
	totalDealerValue = valueArray[nextCard];
	dealerHandStep++;
	nextCard++;

	system("pause");
	cout << endl;

	cout << "You have been dealt a " << cardArray[nextCard] << "." << endl;
	playerHand[playerHandStep] = cardArray[nextCard];
	totalPlayerValue = totalPlayerValue + valueArray[nextCard];

	if ((valueArray[nextCard]) == 11) {

		unchangedAce = 1;

	}

	playerHandStep++;
	nextCard++;

	system("pause");
	cout << endl;

	cout << "The dealer has drawn his next card facedown." << endl;
	dealerHand[dealerHandStep] = cardArray[nextCard];
	totalDealerValue = totalDealerValue + valueArray[nextCard];
	dealerHandStep++;
	nextCard++;

	char drawCard = 'Y';

	cout << endl;
	cout << "Your turn." << endl << "You have: " << endl;
	cout << playerHand[1] << ", " << playerHand[2] << endl;
	cout << "The total value of your cards is " << totalPlayerValue << endl;

	if (totalPlayerValue == 21) {									// Tracking natural blackjacks

		cout << "You drew a natural blackjack. ";

		system("pause");

		if (totalDealerValue == 21) {

			cout << "The dealer also drew a natural blackjack. The game is a tie." << endl;

		}
		else {

			cout << "You win!" << endl;

		}

		naturalSkip = 1;

	}


	// Start of player operations

	if (naturalSkip == 0) {

		cout << "Would you like to draw a card? Answer Y or N. Alternatively, answer P for probabilities." << endl;

		cin >> drawCard;

		while (true) {

			system("cls");

			if (drawCard == 'Y' || drawCard == 'y') {

				cout << endl;
				cout << "You have chosen to draw a card." << endl;
				cout << "You have drawn a " << cardArray[nextCard] << "." << endl;
				playerHand[playerHandStep] = cardArray[nextCard];
				totalPlayerValue = totalPlayerValue + valueArray[nextCard];
				playerHandStep++;
				nextCard++;

				if (valueArray[nextCard - 1] == 11) {

					int aceValue = 11;

					cout << "You have drawn an ace, which would make the total value of your cards " << totalPlayerValue << "." << endl;
					cout << "You can choose to make the ace count as either a 1 or an 11. Which will it be ? Answer 1 or 11." << endl;

					cin >> aceValue;

					if (aceValue == 11) {

						cout << "The ace will count as 11." << endl;
						unchangedAce = 1;

					}
					else if (aceValue == 1) {

						cout << "The ace will count as 1." << endl;
						totalPlayerValue = totalPlayerValue - 10;


					}
					else {

						cout << "Neither choice was picked. Choose 1 or 11." << endl;

						cin >> aceValue;

					}

				}

				cout << "Your total value of your cards is " << totalPlayerValue << "." << endl;


				if (totalPlayerValue > 21 && unchangedAce == 0) {								// Lose game

					cout << "You have gone over 21. You lose." << endl;
					playerLostSkip = 1;
					break;

				}
				else if (totalPlayerValue > 21 && unchangedAce == 1) {						// Would lose but can change ace back to 1

					cout << "You have gone over 21 but kept an ace's value at 11. Would you like to make it's value 1 to keep playing?" << endl << "Answer Y or N." << endl;

					char aceGame = 'Y';
					cin >> aceGame;

					if (aceGame == 'Y' || aceGame == 'y') {

						cout << "The ace will count as 1 and the game will continue." << endl;
						totalPlayerValue = totalPlayerValue - 10;

					}
					else if (aceGame == 'N' || aceGame == 'n') {

						cout << "The ace will count as an 11." << endl << "You have gone over 21. You lose." << endl;
						playerLostSkip = 1;
						break;


					}
					else {

						cout << "You did not pick Y or N. Choose one." << endl;

						cin >> aceGame;

					}


				}


			}
			else if (drawCard == 'N' || drawCard == 'n') {

				cout << "You have chosen not to draw anymore cards." << endl << "The dealer will now draw cards." << endl;
				cout << endl;
				break;

			}
			else if (drawCard == 'P' || drawCard == 'p') {	

				//probabilities(valueArray, suitArray, playerHand, dealerHand, nextCard, totalPlayerValue, totalDealerValue);


				int input = 1;

				cout << "What would you like to know? Enter a number." << endl;
				cout << "1. Who could win?" << endl;
				cout << "2. Chance to draw a specific card." << endl;
				cout << "3. Chance to draw a specific value." << endl;
				cout << "4. Chance for the dealer to draw over 21." << endl;
				cout << "5. Chance for the player to get a blackjack in the next card." << endl;
				cout << "6. Chance for the dealer to get a blackjack in the next card." << endl;

				cin >> input;
				int valueFound = 0;

				system("cls");

				if (input == 3) {

					// Look for the specified card value throughout the entire deck and increment a counter for each time it is found

					cout << "What value do you want? Enter a value 1-11." << endl;

					int cardValue = 0;
					cin >> cardValue;

					
					if  (cardValue > 0 && cardValue < 12) {

						cout << "Calculating the chance of the player getting a " << cardValue << " in the next card pull." << endl;


						for (int i = nextCard; i <= 311; i++) {

							if (valueArray[i] == cardValue) {

								valueFound++;

							}
							else if (cardValue == 1 && valueArray[i] == 11) {		//Counting aces as ones if the needed value is 1 but an 11 is found in the value array

								valueFound++;

							}

						}
					}
					else {
						cout << "Pick a different number." << endl;

						cin >> cardValue;


					}

					cout << "Out of " << 312 - nextCard << " cards, there are " << valueFound << " cards that meet the requirements." << endl;

					float percent = (float(valueFound) / (312 - nextCard) * 100);

					cout << "The chance of pulling the card is " << percent << "%." << endl;



					system("pause");

				}
				else if (input == 2) {

					// Same as above, but also looking if the card is of the correct suit.

					cout << "What value do you want? Enter a value 1-11." << endl;

					int cardValue = 0;
					int suitValueFound = 0;
					cin >> cardValue;


					if (cardValue > 0 && cardValue < 12) {

						cout << "What suit do you want? Enter a number." << endl << "Spades = 1, Clubs = 2, Hearts = 3, Diamonds = 4." << endl;
						int suitValue = 0;

						cin >> suitValue;

						if (suitValue > 0 && suitValue < 5) {

						cout << "Calculating the chance of the player getting a " << cardValue << " of";
						
						switch (suitValue) {
						case 1: cout << " Spades";
							break;
						case 2: cout << " Clubs";
							break;
						case 3: cout << " Hearts";
							break;
						case 4: cout << " Diamonds";
							break;
						}
						
							cout << " in the next card pull." << endl;


							for (int i = nextCard; i <= 311; i++) {

								if (valueArray[i] == cardValue && suitArray[i] == suitValue) {

								valueFound++;

								}
								else if (cardValue == 1 && valueArray[i] == 11 && suitArray[i] == suitValue) {		//Counting aces as ones if the needed value is 1 but an 11 is found in the value array

								valueFound++;

								}
							}
							for (int i = nextCard; i <= 311; i++) {

								if (suitArray[i] == suitValue) {

									suitValueFound++;

								}
							}
						}
						else {
							cout << "Pick a different number." << endl << "Spades = 1, Clubs = 2, Hearts = 3, Diamonds = 4." << endl;

							cin >> suitValue;
							continue;
						}
					}
					else {
						cout << "Pick a different number." << endl;

						cin >> cardValue;
						continue;

					}

					cout << "Out of " << 312 - nextCard << " cards, there are " << valueFound << " cards that meet the requirements." << endl;

					float percent = (float(valueFound) / (312 - nextCard));

					percent = percent/(float(suitValueFound) / (312 - nextCard)) * 100;

					cout << "The chance of pulling the card is " << percent << "%." << endl;



					system("pause");
				}
				else if (input == 1) {

					// Look at the next 13 cards to see if it is more likely to draw over, below, or at 21. Then do the same with the dealer.

					cout << "Observing the next 13 cards to calculate chances." << endl;

					int neededValue = 21 - totalPlayerValue;
					int exact21 = 0;
					int above21 = 0;
					int below21 = 0;
					int valueAdd = 0;

					for (int i = nextCard; i <= (nextCard+12); i++) {

						valueAdd = valueAdd + valueArray[i];

						if (valueAdd == neededValue) {

							exact21++;
							valueAdd = 0;

						}
						else if (valueAdd > neededValue && valueArray[i] == 11) {

							below21++;
							valueAdd = valueAdd - 10;

						}
						else if (valueAdd > neededValue) {

							above21++;
							valueAdd = 0;

						}
						else {

							below21++;

						}
					}
					float playerPercent = ((float(above21) / 13) * 100);
					float percentAdd = playerPercent;

					cout << "The chances of the player drawing over 21 is " << playerPercent << "%." << endl;

					float percent = ((float(exact21) / 13) * 100);
					percentAdd = percent + percentAdd;
					cout << "The chances of the player drawing exactly 21 is " << percent << "%." << endl;

					percent = ((float(below21) / 13) * 100);
					percentAdd = percent + percentAdd;
					cout << "The chances of the player drawing below 21 is " << percent << "%." << endl << "Total chance is " << percentAdd << "%." << endl << endl;
					

					neededValue = 21 - totalDealerValue;
					exact21 = 0;
					above21 = 0;
					below21 = 0;
					valueAdd = 0;

					for (int i = nextCard; i <= (nextCard + 12); i++) {

						valueAdd = valueAdd + valueArray[i];

						if (valueAdd == neededValue) {

							exact21++;
							valueAdd = 0;

						}
						else if (valueAdd > neededValue) {

							above21++;
							valueAdd = 0;

						}
						else if (valueAdd < neededValue && totalDealerValue >= 17 && totalDealerValue < 21) {

							below21++;
							valueAdd = 0;

						}
						else {

							below21++;

						}
					}
					float dealerPercent = ((float(above21) / 13) * 100);
					percentAdd = dealerPercent;

					cout << "If the player was to stop drawing cards now and the dealer starts drawing cards:" << endl;

					cout << "The chances of the dealer drawing over 21 is " << dealerPercent << "%." << endl;

					percent = ((float(exact21) / 13) * 100);
					percentAdd = percent + percentAdd;
					cout << "The chances of the dealer drawing exactly 21 is " << percent << "%." << endl;

					percent = ((float(below21) / 13) * 100);
					percentAdd = percent + percentAdd;
					cout << "The chances of the dealer drawing below 21 is " << percent << "%." << endl << "Total chance is " << percentAdd << "%." << endl << endl;

					system("pause");

					if (totalPlayerValue > totalDealerValue && playerPercent > dealerPercent) {

						cout << "The player is more likely to win." << endl;

					}
					else if (totalPlayerValue < totalDealerValue && playerPercent < dealerPercent) {

						cout << "The dealer is more likely to win." << endl;

					}
					else {

						cout << "The game cannot be determined as of now." << endl;

					}

				}
				else if (input == 4) {

					int neededValue = 21 - totalDealerValue;
					int exact21 = 0;
					int above21 = 0;
					int below21 = 0;
					int valueAdd = 0;

					for (int i = nextCard; i <= (nextCard + 12); i++) {

						valueAdd = valueAdd + valueArray[i];

						if (valueAdd == neededValue) {

							exact21++;
							valueAdd = 0;

						}
						else if (valueAdd > neededValue) {

							above21++;
							valueAdd = 0;

						}
						else if (valueAdd < neededValue && totalDealerValue >= 17 && totalDealerValue < 21) {

							below21++;
							valueAdd = 0;

						}
						else {

							below21++;

						}
					}
					float dealerPercent = ((float(above21) / 13) * 100);
					float percentAdd = dealerPercent;

					cout << "If the player was to stop drawing cards now and the dealer starts drawing cards:" << endl;

					cout << "The chances of the dealer drawing over 21 is " << dealerPercent << "%." << endl;

					system("pause");

				}
				else if (input == 5) {

					cout << "Calculating the chance of the player getting a blackjack in the next card pull." << endl;

					int neededValue = 21 - totalPlayerValue;
					int valueFound = 0;


					for (int i = nextCard; i <= 311; i++) {

						if (valueArray[i] == neededValue) {

							valueFound++;

						}
						else if (neededValue == 1 && valueArray[i] == 11) {		//Counting aces as ones if the needed value is 1 but an 11 is found in the value array

							valueFound++;

						}

					}
					cout << "Out of " << 312 - nextCard << " cards, there are " << valueFound << " cards that meet the requirements." << endl;

					float percent = (float(valueFound) / (312 - nextCard) * 100);

					cout << "The chance of pulling the card is " << percent << "%." << endl;

					if (valueFound == 0) {

						cout << "It is not possible for dealer to get a blackjack in one card pull." << endl;
					}

					system("pause");
				}
				else if (input == 6) {

					cout << "Calculating the chance of the dealer getting a blackjack in the next card pull." << endl;

					int neededValue = 21 - totalDealerValue;
					int valueFound = 0;


					for (int i = nextCard; i <= 311; i++) {

						if (valueArray[i] == neededValue) {

							valueFound++;

						}
						else if (neededValue == 1 && valueArray[i] == 11) {		//Counting aces as ones if the needed value is 1 but an 11 is found in the value array

							valueFound++;

						}

					}
					cout << "Out of " << 312 - nextCard << " cards, there are " << valueFound << " cards that meet the requirements." << endl;

					float percent = (float(valueFound) / (312 - nextCard) * 100);

					cout << "The chance of pulling the card is " << percent << "%." << endl;

					if (valueFound == 0) {

						cout << "It is not possible for dealer to get a blackjack in one card pull." << endl;
					}



					system("pause");
				}
			}

			cout << "Would you like to draw a card? Answer Y or N. Alternatively, answer P for probabilities." << endl << "The value of your cards is " << totalPlayerValue << "." << endl;

			cin >> drawCard;
		}


		if (playerLostSkip == 0) {
			// Start of dealer operations

			cout << "The dealer flips his facedown card to reveal a " << dealerHand[2] << endl;
			cout << "The total value of the dealer's cards is " << totalDealerValue << "." << endl;

			system("pause");



			if (totalDealerValue > 17) {		// If initial dealer value is equal to or more than 17, he will stay. Otherwise, it will draw until he goes over 17.

				cout << "Because this is greater than 17, the dealer will not draw any cards." << endl;

			}
			else if (totalDealerValue == 17) {

				cout << "Because this is equal to 17, the dealer will not draw any cards." << endl;

			}
			else {

				cout << "Because this is less than 17, the dealer will draw any cards until their total value is above 17." << endl;
				cout << endl;

				while (true) {

					cout << "The dealer has drawn a " << cardArray[nextCard] << "." << endl;
					dealerHand[dealerHandStep] = cardArray[nextCard];
					totalDealerValue = totalDealerValue + valueArray[nextCard];
					dealerHandStep++;
					nextCard++;


					cout << "The value of the dealer's hand is now " << totalDealerValue << "." << endl;

					system("pause");
					cout << endl;

					if (totalDealerValue < 17) {

						cout << "Because the value is less than 17, the dealer will draw another card." << endl;

					}
					else if (totalDealerValue == 17) {

						cout << "Because the value is equal to 17, the dealer will not draw anymore cards." << endl;
						break;

					}
					else if (totalDealerValue > 21) {

						cout << "Because the value is greater than 21, the dealer has lost." << endl;
						cout << "You win!" << endl;
						dealerLostSkip = 1;
						break;

					}
					else if (totalDealerValue > 17 && totalDealerValue <= 21) {

						cout << "Because the value is greater than 17, the dealer will not draw anymore cards." << endl;
						break;


					}


					cout << endl;

				}
			}

			if (dealerLostSkip == 0) {

				// Determining who wins the hand

				cout << "The value of your cards will be compared to the dealer's hand to see who wins." << endl;

				system("pause");
				system("cls");

				cout << "You have:" << endl;		// Output player hand and score

				for (int i = 0; i <= playerHandStep; i++) {

					cout << playerHand[i] << endl;

				}

				cout << "This is a total hand value of " << totalPlayerValue << "." << endl;

				system("pause");

				cout << endl;
				cout << "The dealer has:" << endl;	// Output dealer hand and score

				for (int i = 0; i <= dealerHandStep; i++) {

					cout << dealerHand[i] << endl;

				}

				cout << "This is a total hand value of " << totalDealerValue << "." << endl << endl;

				if (totalPlayerValue > totalDealerValue) {		// Output who wins

					cout << "Your " << totalPlayerValue << " beats the dealer's " << totalDealerValue << "." << endl << "You win!" << endl;

				}
				else if (totalPlayerValue < totalDealerValue) {

					cout << "The dealer's " << totalDealerValue << " beats your " << totalPlayerValue << "." << endl << "You lose." << endl;

				}
				else if (totalPlayerValue = totalDealerValue) {

					cout << "Your total hand value and the dealer's hand value are the same. It's a tie!" << endl;

				}

				cout << endl;

			}
		}
	}
}