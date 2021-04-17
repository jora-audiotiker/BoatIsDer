#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "ship.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Global Variable Declarations
string username;
int rndm;
int row;
char columnlet;
int col;
bool finaloption;
int tempdone;
bool tempboat;
bool tempis;
bool tempder;

int main() {
	// Initial Object Declarations
	Ship BattleShip;
	Boat BattleBoat;
	Is BattleIs;
	Der BattleDer;
	do {
		// Final option is set equivelant to 1.
		finaloption = 1;
		// Variable count is made 17, allowing user to have 17 tries to win.
		int count = 17;
		// Ghost Board Initialized -- This Will Store Board Randomizer Traits
		char board[6][6] = { { ' ', 'A', 'B', 'C', 'D', 'E'},  { '1', 'x', 'x', 'x', 'x', 'x'},
	 { '2', 'x', 'x', 'x', 'x', 'x'} , { '3', 'x', 'x', 'x', 'x', 'x'} ,
	 { '4', 'x', 'x', 'x', 'x', 'x'} , { '5', 'x', 'x', 'x', 'x', 'x'} };
		// Real Board -- This Is Displayed to User and Will Change with Decisions
		char Realboard[6][6] = { { ' ', 'A', 'B', 'C', 'D', 'E'},  { '1', 'x', 'x', 'x', 'x', 'x'},
	{ '2', 'x', 'x', 'x', 'x', 'x'} , { '3', 'x', 'x', 'x', 'x', 'x'} ,
	{ '4', 'x', 'x', 'x', 'x', 'x'} , { '5', 'x', 'x', 'x', 'x', 'x'} };

		// Board Randomizer. There are 10 possibilities for how the board layout can look, which is determined off a 1 - 10 random integer. 
		srand(time(NULL));
		rndm = (rand() % 10 + 1);

		if (rndm == 1) {
			board[1][1] = 'B';
			board[1][2] = 'O';
			board[1][3] = 'A';
			board[1][4] = 'T';
			board[3][1] = 'I';
			board[3][2] = 'S';
			board[4][3] = 'D';
			board[4][4] = 'E';
			board[4][5] = 'R';
		}
		else if (rndm == 2) {
			board[1][5] = 'B';
			board[2][5] = 'O';
			board[3][5] = 'A';
			board[4][5] = 'T';
			board[2][4] = 'I';
			board[3][4] = 'S';
			board[5][1] = 'D';
			board[5][2] = 'E';
			board[5][3] = 'R';
		}
		else if (rndm == 3) {
			board[1][4] = 'I';
			board[1][5] = 'S';
			board[2][1] = 'T';
			board[3][1] = 'A';
			board[4][1] = 'O';
			board[5][1] = 'B';
			board[5][3] = 'D';
			board[5][4] = 'E';
			board[5][5] = 'R';
		}
		else if (rndm == 4) {
			board[2][2] = 'B';
			board[2][3] = 'O';
			board[2][4] = 'A';
			board[2][5] = 'T';
			board[3][3] = 'D';
			board[3][4] = 'E';
			board[3][5] = 'R';
			board[4][4] = 'I';
			board[5][4] = 'S';
		}
		else if (rndm == 5) {
			board[1][1] = 'I';
			board[2][1] = 'S';
			board[3][1] = 'D';
			board[4][1] = 'E';
			board[5][1] = 'R';
			board[5][2] = 'B';
			board[5][3] = 'O';
			board[5][4] = 'A';
			board[5][5] = 'T';
		}
		else if (rndm == 6) {
			board[1][3] = 'B';
			board[2][3] = 'O';
			board[3][3] = 'A';
			board[4][3] = 'T';
			board[4][1] = 'I';
			board[4][2] = 'S';
			board[2][5] = 'D';
			board[3][5] = 'E';
			board[4][5] = 'R';
		}
		else if (rndm == 7) {
			board[4][1] = 'B';
			board[4][2] = 'O';
			board[4][3] = 'A';
			board[4][4] = 'T';
			board[5][1] = 'I';
			board[5][2] = 'S';
			board[5][3] = 'D';
			board[5][4] = 'E';
			board[5][5] = 'R';
		}
		else if (rndm == 8) {
			board[1][4] = 'I';
			board[2][4] = 'S';
			board[3][5] = 'D';
			board[4][5] = 'E';
			board[5][5] = 'R';
			board[4][1] = 'B';
			board[4][2] = 'O';
			board[4][3] = 'A';
			board[4][4] = 'T';
		}
		else if (rndm == 9) {
			board[1][1] = 'B';
			board[2][1] = 'O';
			board[3][1] = 'A';
			board[4][1] = 'T';
			board[2][3] = 'I';
			board[2][4] = 'S';
			board[4][2] = 'D';
			board[4][3] = 'E';
			board[4][4] = 'R';
		}
		else if (rndm == 10) {
			board[1][3] = 'D';
			board[2][3] = 'E';
			board[3][3] = 'R';
			board[2][2] = 'T';
			board[3][2] = 'A';
			board[4][2] = 'O';
			board[5][2] = 'B';
			board[3][5] = 'S';
			board[4][5] = 'I';
		}
		// Introduction to game
		cout << "Welcome to Boat Is Der! What is your username?" << endl;
		cin >> username;
		cout << endl;
		cout << "Hello " << username << endl;
		// While loop for variable count, as well as if all "boat" pieces are hit.
		do {
			// Notifies user of how many tries they have left
			cout << "You have " << count << " tries left. " << endl;
			cout << endl;

			// Print statement for Board
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
					cout << "  " << Realboard[i][j];
				cout << endl;
			}
			cout << endl;
			// Sets variable Cont equal to 0.
			bool cont = 0;
			// User is asked which row they would like to select and given console input.
			cout << "Which row would you like to select?" << endl;
			cin >> row;
			// While loop to ensure that users select a valid option for their column. Loops if they pick any option aside from chars A - E.
			while (cont != 1) {
				cout << "Which column would you like to select? (case sensitive)" << endl;
				cin >> columnlet;
				cout << endl;
				if (columnlet == 'A') {
					col = 1;
					cont = 1;
				}
				else if (columnlet == 'B') {
					col = 2;
					cont = 1;
				}
				else if (columnlet == 'C') {
					col = 3;
					cont = 1;
				}
				else if (columnlet == 'D') {
					col = 4;
					cont = 1;
				}
				else if (columnlet == 'E') {
					col = 5;
					cont = 1;
				}
				else {
					// Notifies user of an invalid entry if they don't pick letters A - E.
					cout << "Invalid Entry. Try again." << endl;
				}
			}
			// If statemets that call on respective hit method if there is a hit on board.
			if (board[row][col] == 'B') {
				cout << "Hit!" << endl;
				Realboard[row][col] = '*';
				BattleBoat.BHit();
			}
			else if (board[row][col] == 'O') {
				cout << "Hit!" << endl;
				Realboard[row][col] = '*';
				BattleBoat.OHit();
			}
			else if (board[row][col] == 'A') {
				cout << "Hit!" << endl;
				Realboard[row][col] = '*';
				BattleBoat.AHit();
			}
			else if (board[row][col] == 'T') {
				cout << "Hit!" << endl;
				Realboard[row][col] = '*';
				BattleBoat.THit();
			}
			else if (board[row][col] == 'I') {
				cout << "Hit!" << endl;
				Realboard[row][col] = '*';
				BattleIs.IHit();
			}
			else if (board[row][col] == 'S') {
				cout << "Hit!" << endl;
				Realboard[row][col] = '*';
				BattleIs.SHit();
			}
			else if (board[row][col] == 'D') {
				cout << "Hit!" << endl;
				Realboard[row][col] = '*';
				BattleDer.DHit();
			}
			else if (board[row][col] == 'E') {
				cout << "Hit!" << endl;
				Realboard[row][col] = '*';
				BattleDer.EHit();
			}
			else if (board[row][col] == 'R') {
				cout << "Hit!" << endl;
				Realboard[row][col] = '*';
				BattleDer.RHit();
			}
			else {
				cout << "Miss!" << endl;
				Realboard[row][col] = 'O';
			}
			// Count decreases by 1, meaning user has one less turn.
			count = count - 1;
			cout << endl;

			//BoatL, IsL, and DerL methods are called upon to check if all parts of a "boat" piece were hit. If so, change piece life to 0.
			BattleBoat.BoatL(BattleShip, 0);
			BattleIs.IsL(BattleShip, 0);
			BattleDer.DerL(BattleShip, 0);
			//Temporary variable used to store the boolean value of Ship's BoatLife, IsLife, and DerLife attributes. 
			tempboat = BattleShip.CheckBoat();
			tempder = BattleShip.CheckDer();
			tempis = BattleShip.CheckIs();
			//while statement, looping for while count is greater than 0, or while any "boat" piece in the game is alive.
		} while ((count > 0) && ((tempboat == true) || (tempder == true) || (tempis == true)));
		cout << endl;
		// User is notified of the end of the game. Given option to restart if they would like.
		cout << "Good Game! Would you like to play again?" << endl;
		cout << "0 - No" << endl;
		cout << "1 - Yes" << endl;
		// User inputs final option
		cin >> finaloption;
		// Code exits if user inputs 0.
	}while (finaloption != 0);
	cout << "Thank you for playing!" << endl;
	// return 0 for good practice :)
	return 0;
}
	
