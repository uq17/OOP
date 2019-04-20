/* Name: (Umar)
Date: (11/30/17)
Section: (0002)
Assignment: (Assignment7)
Due Date: (12/6/17)
About this project: (The project takes in data from a file and puts it into an array that can
					 be accessed and displayed through a menu. An array of structs is used
					 to store pieces of data for each team. The user may choose to display
					 the data based on different data as well as sort the data.)
Assumptions: (Assume that a file is in the correct format, that there is no trailing whitespace 
			  in the file, and that the variables are as described in the instructions.)

All work below was performed by (Umar Qureshi) */


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct teamInfo									// struct that stores each piece of data for a team
{
	char teamname[30];
	int wins;
	int losses;
	bool playoffs;
	int diff;
};
																	// functions based on user choice
void choice1(teamInfo teams[], const int size);
void choice2(teamInfo teams[], const int size, const int x_wins);
void choice3(teamInfo teams[], const int size);
void choice4(teamInfo teams[], const int size);
void choice5(teamInfo teams[], const int size);
void menu();


int main()
{
	ifstream in;													// declare a stream object to take in data from file
	char filename[30];
	int choice;
	int size;
	int x_wins;														// minimum amount of wins entered for choice 2

	do																// *loop from notes*
	{
		in.clear();	

		cout << "Please enter the name of the input file.\n";
		cout << "Filename:  ";
		cin >> filename;

		in.open(filename);
		if (!in)
			cout << "That is not a valid file.  Try again!\n";

	} while (!in);

	in >> size; 
	teamInfo * teams = new teamInfo[size];							// after reading first number from file, an array of structs is created of
																	// that size.
	for (int i = 0; i < size; i++)									// will take in each piece of the file and input it into the according array 
	{																// index and struct variable, making sure to ignore endlines and commas 
		in.ignore();												
		in.getline(teams[i].teamname, 30 , ',');
		in >> teams[i].wins;
		in.ignore();
		in >> teams[i].losses;
		in.ignore();
		in >> teams[i].playoffs;
		teams[i].diff = teams[i].wins - teams[i].losses;
	}
	
	do																			// menu loop
	{
		menu();
		cout << "Choice: ";
		cin >> choice;
		cout << endl;

		if (choice == 1)														// each user menu entry calls different functions defined at 
		{																		// bottom of program
			choice1(teams, size);
			cout << endl;
		}

		if (choice == 2)
		{
			cout << "Show teams with at least how many wins ? --> ";
			cin >> x_wins;
			choice2(teams, size, x_wins);
			cout << endl;
		}

		if (choice == 3)
		{
			choice3(teams, size);
			cout << endl << endl;
		}

		if (choice == 4)
		{
			choice4(teams, size);
			cout << endl;
		}

		if (choice == 5)
		{
			choice5(teams, size);

		}

		if (choice == 0)
		{
			cout << "Goodbye!\n";
		}

		if (choice < 0 || choice > 5)
			cout << "Invalid Choice.\n\n";

	} while (choice != 0);

	in.close();									// closes file attached to stream object
	delete [] teams;							// deallocates dynamic array of structs

	return 0;
}

void choice1(teamInfo teams[], const int size)
{
	cout << "Team W-L:\n";

	for (int i = 0; i < size; i++)							// simply displays data stored in the array of structs one index at a time
	{							
		cout << teams[i].teamname << " ";
		cout << teams[i].wins << "-";
		cout << teams[i].losses << endl;
	}
}

void choice2(teamInfo teams[], const int size, const int x_wins)
{
	for (int i = 0; i < size; i++)									// takes in min number of wins entered by user and tests whether 
	{																// team wins are greater than this and prints the teamname if true
		if (teams[i].wins >= x_wins)
			cout << teams[i].teamname << endl;
	}
}

void choice3(teamInfo teams[], const int size)
{
	int i;														// this loop is required to ensure that the first playoff team is 
	for (i = 0; i < size; i++)									// printed and nothing else, the loop is ended after the first 
	{															// playoff team is printed, for comma handling
		if (teams[i].playoffs)
		{
			cout << teams[i].teamname;
			i++;
			break;
		}
	}
	
	for (int j = i; j < size; j++)								// Because first playoff team has already been printed, commas can now
	{															// be printed before the teamname is printed to ensure the last teamname
		if (teams[j].playoffs)									// printed does not have a comma after it.
		{
			cout << ", ";
			cout << teams[j].teamname;
		}
	}

}

void choice4(teamInfo teams[], const int size)
{
	for (int i = 0; i < size; i++)								
	{
		cout << showpos;										// turns flag on to print a + before any positive value.
		cout << teams[i].teamname << " " << teams[i].diff;
	
		cout << endl;
	}
	cout << noshowpos;											// turns flag off to make sure other positive function values do not have a +
}

void choice5(teamInfo teams[], const int size)
{
	for (int x = 0; x < 2; x++)									// the two for loops below run and put the array in ascending order based on team
	{															// diff values, however, the loops ignore the second value in the array if the third
		for (int j = 0; j < size; j++)							// one is larger than it, so this third for loop ensures the system is run twice,
		{														// which allows it to be ascending order completely.
			for (int i = j; i < size; i++)						// Each time this loops is run, the largest diff value is switched with any value 
			{													// lower than it, until the largest value ends up as the last index of the array 
				if (teams[i].diff < teams[i - 1].diff)			// Because the entirety of the loop only takes the one largest value to the last
				{												// array index, it must be put inside of another for loop to ensure each next 
					teamInfo temp = teams[i];					// largest value is switched to be right before the value larger than it.
					teams[i] = teams[i - 1];
					teams[i - 1] = temp;
				}

			}
		}
	}
}

void menu()
{
	cout << "Select one of the following choices:\n";
	cout << "\t1 - View team Win/Loss records\n";
	cout << "\t2 - Show teams with at least x wins\n";
	cout << "\t3 - List teams that made the playoffs\n";
	cout << "\t4 - Print teams and their Win Loss Differentials\n";
	cout << "\t5 - Sort teams by their Win Loss Differentials\n";
	cout << "\t0 - Exit program\n";
	cout << "------------------------------------------\n";
}