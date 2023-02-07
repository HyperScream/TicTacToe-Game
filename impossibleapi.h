#pragma once
#include "extrafun.h"
#include "display.h"

#pragma once
#include <random>
#include "display.h"
#include "extrafun.h"
#include <chrono>
#include <thread>

using namespace std;

void impossibleApi()
{

	string callDisplayValue{ "---------" };
	callDisplay(callDisplayValue);
	while (true)
	{
		callDisplayValue = playerInput(callDisplayValue);
		string replaceCharVal;
		string checkIfChange;
		string checkIfChange2;
		string checkIfChange3;

		while (true)
		{

			checkIfChange2 = openingMove(callDisplayValue);
			if (checkIfChange2 != callDisplayValue)
			{
				callDisplayValue = checkIfChange2;
				callDisplay(callDisplayValue);
				break;
			}
			else
			{

			}
			checkIfChange3 = diagonalBlock(callDisplayValue);
			if (checkIfChange3 != callDisplayValue)
			{
				callDisplayValue = checkIfChange3;
				callDisplay(callDisplayValue);
				break;
			}
			checkIfChange = winPotent(callDisplayValue);
			if (checkIfChange != callDisplayValue)
			{
				callDisplayValue = checkIfChange;
				callDisplay(callDisplayValue);
				break;
			}
			else
			{

			}
			random_device rd;
			int getRandomNumber = rd() % 9;

			if (getRandomNumber >= callDisplayValue.length())
			{
				continue;
			}
			else
			{
				char replaceCharVal = callDisplayValue.at(getRandomNumber);

				if (replaceCharVal != 'x' && replaceCharVal != 'o')
				{
					callDisplayValue.replace(getRandomNumber, 1, "x");
					callDisplay(callDisplayValue);
					break;
				}
				else
				{
					string z{ callDisplayValue };
					string winBool2;

					winBool2 = checkWin(z);
					if (winBool2 == "playerWin")
					{
						cout << "The player has won the game!" << endl;
						std::this_thread::sleep_for(chrono::milliseconds(5000));
						exit(2);
					}
					else if (winBool2 == "playerLose")
					{
						cout << "The player has lost the game!" << endl;
						std::this_thread::sleep_for(chrono::milliseconds(5000));
						exit(2);
					}
					else if (winBool2 == "neither")
					{
						std::this_thread::sleep_for(chrono::milliseconds(10));
					}
					else if (winBool2 == "draw")
					{
						cout << "Draw!" << endl;
						std::this_thread::sleep_for(chrono::milliseconds(5000));
						exit(2);
					}
					else
					{
						cout << "Exception Handled: Invalid winCondition" << endl;
					}
				}
			}

		}

		string x{ callDisplayValue };
		string winBool;

		winBool = checkWin(x);
		if (winBool == "playerWin")
		{
			cout << "The player has won the game!" << endl;
			std::this_thread::sleep_for(chrono::milliseconds(10000));
			break;
		}
		else if (winBool == "playerLose")
		{
			cout << "The player has lost the game!" << endl;
			std::this_thread::sleep_for(chrono::milliseconds(5000));
			break;
		}
		else if (winBool == "neither")
		{
			std::this_thread::sleep_for(chrono::milliseconds(50));
		}
		else
		{
			cout << "Exception Handled: Invalid winCondition" << endl;
		}

	}
}