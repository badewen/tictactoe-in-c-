#include <iostream>

class TicTacToe {
public:
	void Run() {
		while (!GameEnded)
		{	
			ChangePlayer();
			PrintBoard();
			UserInput();
			UpdateBoard();
			CheckWin();
			Winner();
			if (!GameEnded) {
				system("cls");
			}
			
		}
		std::cin.ignore(INT32_MAX, '\n');
		std::cin.get();
	}
private:
	char board[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int16_t answer = 0;
	char X_Or_Y = 'X';
	int16_t flag = 0; // 0 = X 1 = O
	const int16_t WIN = 1;
	const int16_t DRAW = 2;
	const int16_t CONTINUE = 0; // game in progress
	bool DisplayColumnOccuppiedMessage = false;
	bool GameEnded = false;
	bool DisplayInvalidMoveMessage = false;
	bool ChangeSide = true; // true so it change side
	int16_t GameState = CONTINUE;
private:
	void PrintBoard() {
		int16_t counter = 0;
		std::cout << " ";
		for (int16_t i = 1; i < sizeof(board) / sizeof(board[0]); i++) {
			std::cout << board[i];
			if (i % 3 != 0) {
				std::cout << " | ";
			}
			if (i == 3) {
				std::cout << "\tplayer " << X_Or_Y << " Turn";
			}
			if (i == 6 && DisplayColumnOccuppiedMessage == true) {
				std::cout << "\tthat column is already occupied";
			}
			if (i == 9 && DisplayInvalidMoveMessage == true) {
				std::cout << "\tinvalid move";
			}

			if (i % 3 == 0) {
				std::cout << "\n";
				if (counter < 2) {
					std::cout << "-----------" << std::endl;
					counter++;
				}
				std::cout << " ";
			}
		}
		std::cout << "\renter your move here: ";
	}
	void UserInput() {
		std::cin >> answer;
		while (std::cin.fail()) {
			std::cout << "enter number duh" << std::endl;
			std::cin.clear();				/// these two idk how it work if you do know pls open issue to explain what these two do	//  magic
			std::cin.ignore(INT32_MAX, '\n');
			std::cin >> answer;
		}
	}
	void UpdateBoard() {

		if (answer <= 0 || answer > 9) {

		}
		else {
			if (board[answer] == 'X' || board[answer] == 'O') {
				ChangeSide = false;
				DisplayColumnOccuppiedMessage = true;
				answer = 1;
			}
			else {
				DisplayColumnOccuppiedMessage = false;
				board[answer] = X_Or_Y;
				ChangeSide = true;
			}
		}
	}
	void CheckWin() {
		if (board[1] == board[2] && board[2] == board[3]) {
			GameState = WIN;
		}
		else if (board[4] == board[5] && board[5] == board[6]) {
			GameState = WIN;
		} 
		else if (board[7] == board[8] && board[8] == board[9]) {
			GameState = WIN;
		} 
		else if (board[1] == board[4] && board[4] == board[7]) {
			GameState = WIN;
		} 
		else if (board[2] == board[5] && board[5] == board[8]) {
			GameState = WIN;
		} 
		else if (board[3] == board[6] && board[6] == board[9]) {
			GameState = WIN;
		} 
		else if (board[1] == board[5] && board[5] == board[9]) {
			GameState = WIN;
		}
		else if (board[3] == board[5] && board[5] == board[7]) {
			GameState = WIN;
		}
		else if (board[1] != '1' && board[2] != '2' && board[3] != '3'
			  && board[4] != '4' && board[5] != '5' && board[6] != '6'
			  && board[7] != '7' && board[8] != '8' && board[9] != '9')
		{
			GameState = DRAW;
		}
		else {
			GameState = CONTINUE;
		}
	}
	void Winner() {
		if (GameState == DRAW) {
			system("cls");
			PrintBoard();
			std::cout << '\n';
			std::cout << "this game is a draw" << std::endl;
			GameEnded = true;
			std::cout << "press enter to exit...";
		}
		else if (GameState == WIN){
			system("cls");
			PrintBoard();
			std::cout << '\n';
			std::cout << "player " << X_Or_Y << " win!" << std::endl;
			GameEnded = true;

			std::cout << "press enter to exit...";
		}
	}
	void ChangePlayer() {
		if (ChangeSide == true) {
			if (flag == 0) {
				X_Or_Y = 'X';
				flag++;
			}
			else {
				X_Or_Y = 'O';
				flag--;
			}
		}
	}
};

int main() {
	TicTacToe t;
	t.Run();
}