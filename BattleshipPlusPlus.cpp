// BattleshipPlusPlus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

string where = "You placed your ships at: ";
string locate = "This is the location in memory : ";
string comma = ", ";

int hits = 0;
int numberOfTurns = 0;
int isShip = 1;
int isMiss = 2;
int ocean[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void placeShips(int row, int col) 
{
    ocean[row][col] = isShip;
}

void placeShipsPrompt(ofstream& Fleet)
{
	// Ask user to enter the row and column they want the ship to be placed
	cout << "Enter the row and column of the ship you want to place numbered between 1 and 10: ";
	int row;
	int col;
	cin >> row;
	cin >> col;
    int correctedRow, correctedCol;

	// Subtract 1 from row and column so ship is placed within the bounds of the dimensions of the arrays
	correctedRow = row - 1;
	correctedCol = col - 1;
	Fleet << correctedRow << "," << correctedCol << "\n";
	placeShips(correctedRow, correctedCol);
	
	// Tell user where they placed their ships
	cout << where << row << comma << col << "\n";
	
}



void guesserShipPlacement(ifstream& Fleet)
{
	
	/*string fleetLine = "";
	Fleet >> fleetLine;
	int row;
	int col;
	while (Fleet >> row >> col)
	{
		placeShips(row, col);
	}*/
	placeShips(5, 6);
	placeShips(5, 5);
	placeShips(5, 4);
	placeShips(5, 3);
	placeShips(5, 2);
}

void displayShipPosition()
{
	const int N = 10;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << ocean[i][j] << ((i + 1) + (j + 1) % N ? " " : "\n");
		}
		cout << endl;
	}
}

int main()
{
	

	// Ask player if they would like to place (hits) or place (ships)
	cout << "Would you like to (place) or (play)?";
	string choice;
	cin >> choice;
	if (choice == "place") {
		ofstream Fleet("save.txt");
		// prompt user for 5 ships
		for (int i = 0; i < 5; i++) {
			placeShipsPrompt(Fleet);
		}
	} else if (choice == "play") {

		ifstream Fleet("save.txt");
		string fleetLine, rowString, colString;
		getline(Fleet, fleetLine);
		fleetLine.append("\n");
		cout << fleetLine;
		
		stringstream str(fleetLine, ios_base::out);
		
		while (getline(str, rowString, ','));
		cout << rowString;
		rowString.append("\0");
		/*int row = stoi(rowString);*/
		while (getline(str, colString));
		cout << colString;
		colString.append("\0");
		/*
		int col = stoi(colString);
		cout << row << " followed by " << col;*/
		/*guesserShipPlacement(Fleet);
		cout << "Where would you like to fire a torpedo? (x,y)";*/

	}

    
	
	// print out the users ships showing where they are stored in memory for verification
	displayShipPosition();

	
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
