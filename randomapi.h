#pragma once
#include <random>
#include "display.h"
#include "extrafun.h"
#include <synchapi.h>

using namespace std;

void randomApi()
{

	string callDisplayValue{ "---------" };
	callDisplay(callDisplayValue);
	while (true)
	{
		callDisplayValue = playerInput(callDisplayValue);
		string replaceCharVal;
		int checkCharVal;

		while (true)
		{
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
						Sleep(10000);
						exit(2);
					}
					else if (winBool2 == "playerLose")
					{
						cout << "The player has lost the game!" << endl;
						Sleep(10000);
						exit(2);
					}
					else if (winBool2 == "neither")
					{
						Sleep(10);
					}
					else if (winBool2 == "draw")
					{
						cout << "Draw!" << endl;
						Sleep(10000);
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
			Sleep(10000);
			break;
		}
		else if (winBool == "playerLose")
		{
			cout << "The player has lost the game!" << endl;
			Sleep(10000);
			break;
		}
		else if (winBool == "neither")
		{
			Sleep(50);
		}
		else
		{
			cout << "Exception Handled: Invalid winCondition" << endl;
		}

	}
}