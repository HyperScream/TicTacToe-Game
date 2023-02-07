#include <string>
#include <iostream>
#include "randomapi.h"
#include "mediumapi.h"
#include <chrono>
#include <thread>
#include "hardapi.h"
#include "impossibleapi.h"

using namespace std;


int main()
{

	random_device rd;
	int randomTimer = rd() % 5001;

	cout << "Hello! Welcome to my TicTacToe Project! \t Current version is 2.13" << endl << endl;
	cout << endl << "Choose the difficulty you wish to play" << endl << "(1)Level 1 Ai" << endl << "(2)Level 2 Ai" << endl << "(3)Level 3 Ai" << endl << "(4)Level 4 Ai (Max)" << endl;
	string aigettr;
	while (true)
	{
		getline(cin, aigettr);

		if (aigettr == "2")
		{
			cout << "Starting game session..." << endl;
			std::this_thread::sleep_for(chrono::milliseconds(randomTimer));
			mediumApi();
			break;
		}
		else if (aigettr == "1")
		{
			cout << "Starting game session..." << endl;
			std::this_thread::sleep_for(chrono::milliseconds(randomTimer));
			randomApi();
			break;
		}
		else if (aigettr == "3")
		{
			cout << "Starting game session..." << endl;
			std::this_thread::sleep_for(chrono::milliseconds(randomTimer));
			hardApi();
			break;
		}
		else if (aigettr == "4")
		{
			cout << "Starting game session..." << endl;
			std::this_thread::sleep_for(chrono::milliseconds(randomTimer));
			impossibleApi();
			break;
		}
		else
		{
			cout << "Invalid input!" << endl;
			aigettr.clear();
		}
	}
}
