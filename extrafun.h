#pragma once
#include <cstdlib>
#include <thread>
#include <chrono>
#include <string>

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
				std::this_thread::sleep_for(std::chrono::seconds(1));
				exit(2);
			}

			if (userPlayInput > 8 || userPlayInput < 0)
			{
				cout << "Sorry, thats not a valid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else if (!cin)
			{
				cout << "Sorry, thats not a valid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
		}

	}
	return checkCurrentString;
}

string winPotent(string anotherBoardDataType) {
	string saveBoard = anotherBoardDataType;
	string board = anotherBoardDataType;
	char bot = 'x';
	char player = 'o';
	int win_positions[8][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6} };

	for (int i = 0; i < 8; i++) {
		int a = win_positions[i][0];
		int b = win_positions[i][1];
		int c = win_positions[i][2];
		if (board[a] == bot && board[b] == bot && board[c] == '-') {
			board[c] = bot;
			return board;
		}
		if (board[a] == bot && board[c] == bot && board[b] == '-') {
			board[b] = bot;
			return board;
		}
		if (board[b] == bot && board[c] == bot && board[a] == '-') {
			board[a] = bot;
			return board;
		}
	}

	for (int i = 0; i < 8; i++) {
		int a = win_positions[i][0];
		int b = win_positions[i][1];
		int c = win_positions[i][2];
		if (board[a] == player && board[b] == player && board[c] == '-') {
			board[c] = bot;
			return board;
		}
		if (board[a] == player && board[c] == player && board[b] == '-') {
			board[b] = bot;
			return board;
		}
		if (board[b] == player && board[c] == player && board[a] == '-') {
			board[a] = bot;
			return board;
		}
	}

	if (saveBoard == board) {
		return saveBoard;
	}
	else {
		return board;
	}
}

string openingMove(string newBoardPos)
{
	string oldBoardPos;
	oldBoardPos = newBoardPos;


	char player = 'o';
	char bot = 'x';

	if (newBoardPos == "o--------" || newBoardPos == "--o------" || newBoardPos == "------o--" || newBoardPos == "--------o")
	{
		newBoardPos[4] = bot;
	}
	else if (newBoardPos == "----o----")
	{
		newBoardPos[8] = bot;
	}
	else if (newBoardPos == "-o-------")
	{
		newBoardPos[0] = bot;
	}
	else if (newBoardPos == "-------o-")
	{
		newBoardPos[8] = bot;
	}
	else if (newBoardPos == "-----o---")
	{
		newBoardPos[2] = bot;
	}
	else if (newBoardPos == "---o-----")
	{
		newBoardPos[6] = bot;
	}
	else if (newBoardPos[1] == player && newBoardPos[6] == player || newBoardPos[8] == player && newBoardPos[0] == bot)
	{
		if (newBoardPos[4] = '-')
		{
			newBoardPos[4] = bot;
		}
	}
	else if (newBoardPos[3] == player && newBoardPos[8] == player || newBoardPos[2] == player && newBoardPos[6] == bot)
	{
		if (newBoardPos[4] = '-')
		{
			newBoardPos[4] = bot;
		}
	}
	else if (newBoardPos[7] == player && newBoardPos[0] == player || newBoardPos[2] == player && newBoardPos[8] == bot)
	{
		if (newBoardPos[4] = '-')
		{
			newBoardPos[4] = bot;
		}
	}
	else if (newBoardPos[5] == player && newBoardPos[0] == player || newBoardPos[6] == player && newBoardPos[2] == bot)
	{
		if (newBoardPos[4] = '-')
		{
			newBoardPos[4] = bot;
		}
	}
	else
	{
		return oldBoardPos;
	}
	return newBoardPos;
}

string diagonalBlock(string diagonalBoardPos)
{
	string oldBoard;
	oldBoard = diagonalBoardPos;

	char player = 'o';
	char bot = 'x';

	if (diagonalBoardPos == "o---x---o" || diagonalBoardPos == "--o-x-o--")
	{
		diagonalBoardPos[3] = bot;
	}
	else
	{
		return oldBoard;
	}
	return diagonalBoardPos;

}

