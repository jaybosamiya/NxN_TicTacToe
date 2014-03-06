#include <iostream>
#include <string>

const int DEPTH_OF_LOOK_AHEAD = 7;
const int N = 4;

#include "game.cpp"
#include "alphabeta.cpp"

using namespace std;

void header() {
	cout << N << "x" << N << " Tic Tac Toe\n";
	cout << "---------------\n\n";
}

char menu() {
	char c;
	cout << "Options:\n";
	cout << "\tPlay vs [C]omputer\n";
	cout << "\tPlay vs [H]uman\n";
	cout << "\t[A]bout\n";
	cout << "\t[E]xit\n";
	do {
		cout << "Enter choice: ";
		cin >> c;
	} while ( c != 'C' && c != 'H' && c != 'A' && c != 'E' );
	return c;
}

void clearscreen() { // TODO: Rewrite to make it portable
	system("cls");
}

void pausescreen() { // TODO: Rewrite to make it portable
	system("pause>nul");
}

void playComputer();
void playHuman();

void about() {
	header();
	cout << "Plays a 4x4 version of the very popular game Tic Tac Toe.\n";
	cout << "Has advanced AI in order to make it a challenge to beat the computer.\n";
	cout << "Can YOU beat it?\n\n";
	cout << "\tCopyright 2014 Jay Hitesh Bosamiya, Palash Agrawal\n";
	cout << "\t\tAll Rights Reserved\n";

}

int main() {
	clearscreen();
	header();
	char choice = menu();
	clearscreen();
	switch(choice) {
		case 'C':
			playComputer();
			break;
		case 'H':
			playHuman();
			break;
		case 'A':
			about();
			break;
		case 'E':
			header();
			cout << "Bye Bye!\n";
	}
	pausescreen();
}

Board board;

void displayBoard() {
	clearscreen();
	header();
	cout << board.toString() << endl;
}

void displayResult(){
	int x = 0, o = 0;
	for ( int i = 0 ; i < N ; i++ ) {
		x = max(x,board.countRow(i,board.X));
		x = max(x,board.countColumn(i,board.X));
		o = max(o,board.countRow(i,board.O));
		o = max(o,board.countColumn(i,board.O));
	}
	x = max(x,board.countDiag1(board.X));
	x = max(x,board.countDiag2(board.X));
	o = max(o,board.countDiag1(board.O));
	o = max(o,board.countDiag2(board.O));
	if ( x == N ) {
		cout<<"\tPlayer 1 played better... X has won!!!\n";
	} else if ( o == N ) {
		cout<<"\tPlayer 2 played better... O has won!!!\n";
	} else {
		cout<<"\tBoth players are evenly matched... Its a draw!!!\n";
	}
}

void humanTurn() {
	int r, c;
	Move move;
	do {
		bool isMoveInRange;
		do {
			cout << "Enter location to play: ";
			cin >> r >> c;
			isMoveInRange = move.set(r,c);
		} while ( !isMoveInRange );
	} while ( !board.isLegal(move) );
	board = board.doMove(move);
}

void computerTurn() {
	Move move;
	alpha_beta(DEPTH_OF_LOOK_AHEAD,MAX,board,-INF,INF,move);
	board = board.doMove(move);
}

void playComputer() {
	displayBoard();
	char c;
	bool flag;
	do {
		cout << "Do you want to start? [Y/N] ";
		cin >> c;
	} while ( c != 'Y' && c != 'N' );
	if ( c == 'Y' ) {
		flag = true;
		MAX = false; MIN = true;
	} else {
		flag = false;
		MAX = true; MIN = false;
	}
	while ( !board.isGameOver() && !board.isDrawn() ) {
		displayBoard();
		if ( flag ) humanTurn();
		else computerTurn();
		flag = !flag;
	}
	displayBoard();
	displayResult();
}

void playHuman() {
	while ( !board.isGameOver() && !board.isDrawn() ) {
		displayBoard();
		humanTurn();
	}
	displayBoard();
	displayResult();
}
