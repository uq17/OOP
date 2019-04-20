/* Name: (Umar Qureshi)
Date: (10/9/17)
Section: (0002)
Assignment: (Assignment4)
Due Date: (10/20/17)
About this project: (This project implements the topics of selection statements, repitition,
					 functions, and random number generation to create a game that allows 
					 the user to simulate the Monty Hall game show. The user can choose
					 which option in the menu he/she desires, play the game to win or lose,
					 and then see or reset their statistics.
Assumptions: (assume integer is entered for door choices and menu entrys)

All work below was performed by (Umar Qureshi) */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void printDoors();
int doornumber();
void stats(int w, int l);


int main()
{
	int entry;								// user main menu choice
	int choice;								// first user door choice
	int winvalue;
	int losevalue;							// door that is opened for user
	int choice2;							// remaining door option after one door has been opened
	int choice3;							// other remaining door option after one door has been opened
	int wins = 0;
	int losses = 0;	
	int i = 0;								// number of games played
	

	srand((unsigned int)time(0));

	cout << "Welcome to the Monty Hall Let's Make a Deal Simulator!\n";

	do																		// menu will print each time unless user chooses quit
	{
			cout << "\nChoose one of the following: \n";
			cout << "1 Play Game\n";
			cout << "2 View Stats\n";
			cout << "3 Reset Stats\n";
			cout << "4 Quit\n> ";
			cin >> entry;


			while (entry < 1 || entry > 4)									// ensures that the menu entry is valid
			{
				cout << "Invalid option, please retry > ";
				cin >> entry;
			}
										                                    

			if (entry == 1)													
			{
				winvalue = doornumber();								    // assigns random number (1-3) as the CAR
				i++;														// increases number of games played

				cout << "Pick a Door, 1, 2, or 3!\n\n";
				printDoors();
				cout << "\nChoice > ";
				cin >> choice;

				while (choice < 1 || choice > 3)							// ensures that door choice is valid
				{
					cout << "Invalid option, please retry > ";
					cin >> choice;
				}

				do															// ensures that the losing door (1-3) is not the same
				{															// as the choice or the winvalue.
					losevalue = doornumber();

				} while (losevalue == choice || losevalue == winvalue);

				cout << "You chose door #" << choice << "!\n";
				cout << "I'll now open a door for you randomly that you didn't choose!\n";
				cout << "Opening door #" << losevalue << " and it's a GOAT!\n";

				do																			// ensures that the remaining door option 
				{																			// is not the same as the losevalue, 
					choice2 = doornumber();													// randomizes the two remaining door choices

				} while (choice2 == losevalue);

				do																			//ensures that the other remaining door option
				{																			// is not the same as losevalue or choice2.
					choice3 = doornumber();

				} while (choice3 == losevalue || choice3 == choice2);


				cout << "Now, I'll be a kind host and give you the chance to switch your door!\n";
				cout << "Would you like door #" << choice2 << " or #" << choice3 << "? > ";
				cin >> choice;

				while (choice < 1 || choice > 3)									// ensures that second door choice is valid
				{
					cout << "Invalid option, please retry > ";
					cin >> choice;
				}

				cout << "Opening door #" << choice << ".....\n";

				
				if (choice == winvalue)												 // if choice is the same as winvalue, hooray
				{
					cout << "it's a BRAND NEW CAR!!!! YOU WIN!!!!\n\n";
					wins++;
				}

				if (choice != winvalue)												 // if not, boohoo
				{
					cout << "baaaaaaaaaaaaa.... it's a GOAT!!!! You LOSE!\n\n";
					losses++;
				}
																							 
			}																	

			if (entry == 2) 
			{	
				if (i + wins + losses == 0)											//if no games have been played
					cout << "No Stats to Display, 0 games played.\n\n";
				else
				{
					cout << "Results after " << i << " games:\n";               
					stats(wins, losses);											// call function to determine win/loss stats
				}
			}

			if (entry == 3)
			{	
				i = 0, wins = 0, losses = 0;						// resets statistics to 0
				cout << "... Statistics Reset!\n\n";
			}

			if (entry == 4)
				cout << "Goodbye!\n";				

		
	} while (entry == 1 || entry == 2 || entry == 3);



	return 0;
}


void printDoors()
{
	cout << "---------    ---------    ---------- \n";
	cout << "|       |    |  ____ |    |  _____ | \n";
	cout << "|   |   |    |     | |    |      | | \n";
	cout << "|   |   |    |  ___| |    |   ___| | \n";
	cout << "|   |   |    | |     |    |      | | \n";
	cout << "|   |   |    | |____ |    |  ____| | \n";
	cout << "---------    ---------    ---------- \n";

	return;
}


int doornumber()
{
	int r;
	r = rand() % 3 + 1;
	
	return r;
}

void stats(int w, int l)
{
	cout << "Wins: " << w << "         Losses: " << l << endl;
	
	cout << fixed << showpoint << setprecision(1);

	cout << "Win %: " << (w * 1.0 / (w + l)) * 100 << "              Loss %: " << (l * 1.0 / (w + l)) * 100 << endl << endl;
}

