#include <iostream>
using namespace std;

/* Here is my attempt at developing OOP-based tic-tac-toe in C++
There are two classes:
1) Board: to control and evaluate the board
2) Player: to control the move and the winner 
The function names are self-explanatory, no comments needed :p */

class Board{

    public:
    	string arr[9] = {};

		void show_board(){  // Manual board creation :p
			cout << "\n";
			cout << " ---+---+---" << endl; 
			cout << "| " << arr[0] << " | " << arr[1] << " | " << arr[2] << " |" << endl;
			cout << " ---+---+---" << endl;
			cout << "| " << arr[3] << " | " << arr[4] << " | " << arr[5] << " |" << endl;
			cout << " ---+---+---" << endl;
			cout << "| " << arr[6] << " | " << arr[7] << " | " << arr[8] << " |" << endl;
			cout << " ---+---+---" << endl;
			cout << "\n";
		}

		void reset_board(){
			for(int i=0; i<9; i++){
				arr[i] = " ";
			}
		}

		bool check_availab(int input){
			if (input > 8 || input < 0){  
				return false;
			}
			else if (arr[input] != " "){  // beware of segfault in here, out of index array
				return false;
			}
			return true;
		}

		void update_board(int input, string sym){
			arr[input] = sym;
		}

		bool check_draw(){
			for(int i=0; i<9; i++){
				if (arr[i] == " "){
					return false;
				}
			}	
			return true;
		}
};

class Player{
	
	public:
		string current_player = "X";

		int get_move_human(){
			int move;
			cout << "Enter your move: ";
			cin >> move;
			return move;
		}

		bool check_win(string arr[9]){  // Manual board checking :p
			if (
				((arr[0] != " ") && (arr[0] == arr[1]) && (arr[1] == arr[2])) ||
				((arr[3] != " ") && (arr[3] == arr[4]) && (arr[4] == arr[5])) ||
				((arr[6] != " ") && (arr[6] == arr[7]) && (arr[7] == arr[8])) ||
				((arr[0] != " ") && (arr[0] == arr[3]) && (arr[3] == arr[6])) ||
				((arr[1] != " ") && (arr[1] == arr[4]) && (arr[4] == arr[7])) ||
				((arr[2] != " ") && (arr[2] == arr[5]) && (arr[5] == arr[8])) ||
				((arr[0] != " ") && (arr[0] == arr[4]) && (arr[4] == arr[8])) ||
				((arr[6] != " ") && (arr[6] == arr[4]) && (arr[4] == arr[2]))
				){
				return true;
			}
			return false;
		}		

		void swap_player(string current){
			if (current == "X"){
				current_player = "O";
			}
			else{
				current_player = "X";
			}
		}
};

int main() {
	Board board_obj;
	Player player_obj;
	board_obj.reset_board();
	board_obj.show_board();

	while (true){  // main game loop
		
		// taking move
		string current_player = player_obj.current_player;
		cout << "\n";
		cout << current_player <<"'s turn" << endl;
		int move = player_obj.get_move_human() - 1; // to align with indexing

		while (!board_obj.check_availab(move)){
			cout << "Invalid square. Enter your move again: ";
			cin >> move;
			move--;  // to align with indexing
		}

		// updating board
		board_obj.update_board(move, current_player);
		board_obj.show_board();

		cout << "\n";

		// board checking
		if (player_obj.check_win(board_obj.arr)){
			cout << current_player << " wins!" << endl;
			break;
		}
		else if(board_obj.check_draw()){
			printf("It is drawn!");
			break;
		}

		// switch player
		player_obj.swap_player(current_player);		
	}
}



