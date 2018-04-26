#include <iostream>
#include <string>
using namespace std;

//using group 2's specification

//doing the user input for player 1 and player 2





int main(){
	//player 1
	char move1;
	cout << "Player 1 enter a column: ";
	cin >> move1;
	//if the move is a word or out of bounds re-enter a number
	if((move1 < 48) && (move1 > 62)){
		char move2;
		cout << "Error please re-enter a column: ";
		cin << move2;
	}

	//if the move is valid build the board

	//player 2 will go after player one plays a valid move
	char move3;
	cout << "Player 2 enter a column: ";
	cin >> move3;
	//if the move is a word or out of bounds-re-enter a number
	if((move1 < 48) && (move1 > 62)){
		char move4;
		cout << "Error please re-enter a column: ";
		cin << move4;
	}
	//if the move is valid build the board


	return 0;
}