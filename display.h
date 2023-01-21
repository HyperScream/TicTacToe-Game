#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void callDisplay(string currentDisplay)
{
	/*ok so basically, i want my display to work as, the api returns a 9 digit value
	* where as - represents the square as empty, 1 represents the square being taken by the
	* "x" user, and 2 represents the square being taken by the "o" user
	* this might be complicated
	*/

	char top_left = currentDisplay.at(0);
	char top_middle = currentDisplay.at(1);
	char top_right = currentDisplay.at(2);
	char middle_left = currentDisplay.at(3);
	char middle = currentDisplay.at(4);
	char middle_right = currentDisplay.at(5);
	char bottom_left = currentDisplay.at(6);
	char bottom_middle = currentDisplay.at(7);
	char bottom_right = currentDisplay.at(8);

	cout << "     |     |     " << endl;
	cout << "  " << top_left << "  |  " << top_middle << "  |  " << top_right << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << middle_left << "  |  " << middle << "  |  " << middle_right << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << bottom_left << "  |  " << bottom_middle << "  |  " << bottom_right << endl;
	cout << "     |     |     " << endl;

}