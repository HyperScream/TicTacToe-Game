#include <string>
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include "hardapi.h"
#include "randomapi.h"

using namespace std;


int main()
{
	system("Color 70");

	random_device rd;
	int randomTimer = rd() % 10001;

	cout << "Want to play some tic tac toe? (y/n)" << endl;
	string gettr;
	getline(cin, gettr);
	if (gettr == "n" || gettr == "N" || gettr == "no" || gettr == "No")
	{
		return 0;
	}
	
	cout << endl << "Great, would you like to play against the impossible ai, or the random ai?" << endl << "(1)Impossible AI" << endl << "(2)Random Ai" << endl;
	string aigettr;
	while (true)
	{
		getline(cin, aigettr);

		if (aigettr == "1")
		{
			cout << "Sorry, this feature hasn't been implemented yet!" << endl;
			//initialize
		}
		else if (aigettr == "2")
		{
			cout << "Starting game session..." << endl;
			Sleep(randomTimer);
			randomApi();
			break;
		}
		else
		{
			cout << "Invalid input!" << endl;
			aigettr.clear();
		}
	}



	//ask the player if they want to play tic tac toe
	//ask the player if they would like to play against the hard api or the random api
	//play the player
}