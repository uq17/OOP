/* Name: (Umar Qureshi)
Date: (10/26/17)
Section: (0002)
Assignment: (Assignment5)
Due Date: (11/7/17)
About this project: (This project allows for a better understanding of arrays and how they function within
					 a program by allowing the user to print, fillwith random values, insert a value into, 
					 delete a value in, reverse the contents of, and return the maximum odd value of an 
					 array. Most of these array functions were completed using for loops which allowed 
					 for each index of the array to be manipulated one at a time.)
Assumptions: (Assume the FillArray option is selected first by the user to populate the array with data 
			  before any other options are selected, that the min and max values are valid, and that 
			  there is at least one off value in the array if MaxOdd is selected.)

All work below was performed by (Umar Qureshi) */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void menu();
void PrintArray(const int arr[], const int size);
void FillArray(int arr[], const int size, int min, int max);
void Delete(int arr[], const int size, int index);
void Reverse(int arr[], const int size);
int MaxOdd(const int arr[], const int size);
void Insert(int arr[], const int size, int value, int index);

int main()
{
	const int SIZE = 15;
	char entry;

	srand(time(0));
	
	int arr[SIZE];									 // Declare your array of size SIZE

	menu();											 // Loop that presents user with menu options and calls appropriate Array functions
	do
	{
		cout << "\nEnter your menu selection: ";
		cin >> entry;

		if (entry == 'P')										// prints array
		{
			PrintArray(arr, SIZE);
		}

		if (entry == 'F')										// fills array with random #'s btw. min and max
		{
			int min;
			int max;
			cout << "What is the minimum random value? ";
			cin >> min;
			cout << "What is the maximum random value? ";
			cin >> max;		

			FillArray(arr, SIZE, min, max);
			PrintArray(arr, SIZE);
		}

		if (entry == 'I')										// inserts value at index, leaves off last value
		{
			int value;
			int index;
			cout << "Enter value to insert: ";
			cin >> value;
			cout << "Enter index at which to insert: ";
			cin >> index;
			Insert(arr, SIZE, value, index);
			PrintArray(arr, SIZE);

		}

		if (entry == 'D')										// deletes value at index
		{
			int index;
			cout << "Enter index of item to delete: ";
			cin >> index; 

			Delete(arr, SIZE, index);
			PrintArray(arr, SIZE);

		}

		if (entry == 'R')										// reverses contents of array
		{
			Reverse(arr, SIZE);
			PrintArray(arr, SIZE);
		}

		if (entry == 'X')										// returns max odd value of array
		{
			cout << "The maximum odd value is " << MaxOdd(arr, SIZE) << endl;
		}

		if (entry == 'M')										// prints menu again
		{
			cout << endl;
			menu();
			continue;
		}
		if (entry == 'Q')										// prints array and quits
			PrintArray(arr, SIZE);

	} while (entry == 'P' || entry == 'F' || entry == 'I' || entry == 'D' || entry == 'R' || entry == 'X' || entry == 'M');

	return 0;
}


void menu()
{
	cout << "	** Given features **\n";
	cout << "P       Print the array contents\n\n";
	cout << "	** Function Tests **\n";
	cout << "F       Fill the array with random values\n";
	cout << "I       Insert\n";
	cout << "D       Delete\n";
	cout << "R       Reverse\n";
	cout << "X       Max Odd Value\n\n";
	cout << "M       Print this menu\n";
	cout << "Q       Quit this program\n";
}


void FillArray(int arr[], const int size, int min, int max)
{
	
	for (int i = 0; i < size; i++)
			arr[i] =  min + rand() % ((max+1)-min);						// ensures that the random values filled can include the min and max
}

void Delete(int arr[], const int size, int index)
{
	for (int i = index; i < size; i++)
		arr[i] = arr[i + 1];											// shifts every value after the index back 1 position

	arr[size - 1] = 0;													// makes last index position 0
}

void Reverse(int arr[], const int size)
{
	
	for (int i = 0; i < (size/2); i++)									// stops loop halfway to ensure values aren't switched back
	{
		int temp;
		temp = arr[i];													// switches the position of the value across from index in array
		arr[i] = arr[(size-1)- i];
		arr[(size-1) - i] = temp;
	}
}

int MaxOdd(const int arr[], const int size)
{
	int maxodd = 0;
	for (int i = 0; i < size; i++)										// tests whether current i value is odd and larger than the last
	{
		if (arr[i] >= maxodd && (arr[i] % 2) != 0)
			maxodd = arr[i];
		else
			continue;
	}
	return maxodd;
}

void Insert(int arr[], const int size, int value, int index)
{
	for (int i = 1; i < size - index; i++)								// pushes the values after the index forward
	{																	// one position, cutting off the last value
		arr[size - i] = arr[(size - 1) - i];
	}
	arr[index] = value;													// inserts user value at index
}

//PrintArray Function
//This function prints the contents of any interger array of any size seperated by commas
void PrintArray(const int arr[], const int size)
{
	cout << "\nThe array:\n { ";
	for (int i = 0; i < size - 1; i++)	// for loop, prints each item (not last due to comma handling)
		cout << arr[i] << ", ";

	cout << arr[size - 1] << " }\n";	// prints last item , sans comma
}
