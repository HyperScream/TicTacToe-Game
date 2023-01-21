#pragma once
#include <cstdlib>
string checkWin(string checkCurrentDisplayWin)
{
	string winCondition;
	char posTL = checkCurrentDisplayWin.at(0);
	char posTM = checkCurrentDisplayWin.at(1);
	char posTR = checkCurrentDisplayWin.at(2);
	char posML = checkCurrentDisplayWin.at(3);
	char posM = checkCurrentDisplayWin.at(4);
	char posMR = checkCurrentDisplayWin.at(5);
	char posBL = checkCurrentDisplayWin.at(6);
	char posBM = checkCurrentDisplayWin.at(7);
	char posBR = checkCurrentDisplayWin.at(8);


	if (posTL == 'o' && posTM == 'o' && posTR == 'o')
	{
		winCondition = "playerWin";
	}
	else if (posML == 'o' && posM == 'o' && posMR == 'o')
	{
		winCondition = "playerWin";
	}
	else if (posBL == 'o' && posBM == 'o' && posBR == 'o')
	{
		winCondition = "playerWin";
	}
	else if (posTL == 'o' && posML == 'o' && posBL == 'o')
	{
		winCondition = "playerWin";
	}
	else if (posTM == 'o' && posM == 'o' && posBM == 'o')
	{
		winCondition = "playerWin";
	}
	else if (posTR == 'o' && posMR == 'o' && posBR == 'o')
	{
		winCondition = "playerWin";
	}
	else if (posTL == 'o' && posM == 'o' && posBR == 'o')
	{
		winCondition = "playerWin";
	}
	else if (posBL == 'o' && posM == 'o' && posTR == 'o')
	{
		winCondition = "playerWin";
	}
	else if (posTL == 'x' && posTM == 'x' && posTR == 'x')
	{
		winCondition = "playerLose";
	}
	else if (posML == 'x' && posM == 'x' && posMR == 'x')
	{
		winCondition = "playerLose";
	}
	else if (posBL == 'x' && posBM == 'x' && posBR == 'x')
	{
		winCondition = "playerLose";
	}
	else if (posTL == 'x' && posML == 'x' && posBL == 'x')
	{
		winCondition = "playerLose";
	}
	else if (posTM == 'x' && posM == 'x' && posBM == 'x')
	{
		winCondition = "playerLose";
	}
	else if (posTR == 'x' && posMR == 'x' && posBR == 'x')
	{
		winCondition = "playerLose";
	}
	else if (posTL == 'x' && posM == 'x' && posBR == 'x')
	{
		winCondition = "playerLose";
	}
	else if (posBL == 'x' && posM == 'x' && posTR == 'x')
	{
		winCondition = "playerLose";
	}
	else if (posTL != '-' && posTM != '-' && posTR != '-' && posML != '-' && posM != '-' && posMR != '-' && posBL != '-' && posBM != '-' && posBR != '-')
	{
		winCondition = "draw";
	}
	else
	{
		winCondition = "neither";
	}
	return winCondition;
}

string playerInput(string checkCurrentString)
{
	cout << endl;
	while (true)
	{
		cout << "What would you like to do?" << endl;
		cout << "(0)Place in Top Left" << endl;
		cout << "(1)Place in Top Middle" << endl;
		cout << "(2)Place in Top Right" << endl;
		cout << "(3)Place in Middle Left" << endl;
		cout << "(4)Place in Middle" << endl;
		cout << "(5)Place in Middle Right" << endl;
		cout << "(6)Place in Bottom Left" << endl;
		cout << "(7)Place in Bottom Middle" << endl;
		cout << "(8)Place in Bottom Right" << endl;
		cout << "(9)Call for a draw" << endl;

		int userPlayInput;

		while (true)
		{
			cin >> userPlayInput;

			if (userPlayInput == 9)
			{
				cout << "The player has called a draw!";
				exit( 2 );
			}

			if (userPlayInput > 8 || userPlayInput < 0)
			{
				cout << "Sorry, thats not a valid input" << endl;
			}
			else if (!cin)
			{
				cout << "Sorry, thats not a valid input" << endl;
			}
			else
			{
				break;
			}
		}
		char userPlayReplace = checkCurrentString.at(userPlayInput);

		if (userPlayReplace != 'o' && userPlayReplace != 'x')
		{
			checkCurrentString.replace(userPlayInput, 1, "o");
			break;
		}
		else
		{
			cout << "Sorry, that position seems to be unavailable!" << endl;
			//calls invalid string place
		}

	}
	return checkCurrentString;
}