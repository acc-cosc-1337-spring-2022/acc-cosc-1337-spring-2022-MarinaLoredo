//cpp
#include "tic_tac_toe.h"

#include <utility>
using std::string, std::cout;

void TicTacToe::start_game(string first_player) {
    player = std::move(first_player);
    clear_board();
}

void TicTacToe::mark_board(int position) {
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::display_board()const { //displaying the board
    for(int i = 0; i < 9; i+=3) {
        cout << pegs[i] << "|" << pegs[i +1] << "|" << pegs[i+2] << "\n";
    }
}

void TicTacToe::set_next_player() {  // next player
    if (player == "X") {
        player = "O";
    } else {
        player = "X";
    }
}

bool TicTacToe::check_board_full() {
    for (const auto& peg: pegs) {
        if (peg == " " ) {
            return false;
        }
    }
    return true;
}
void TicTacToe::clear_board() {
    for (int i = 0; i < 9; i++) {
        pegs[i] = " ";
    }
}

bool TicTacToe::game_over() {
    /* update class function to determine a win by checking for row win or
    column win or diagonal win.
    */

    bool over;
    if (check_diagonal_win() || check_row_win() || check_column_win()) {
        set_winner();
        over = true;
    } else if (check_board_full()) {
        over = true;
        winner = "C";
    } else {
        over = false;
    }
    return over;
}

bool TicTacToe::check_column_win() {
    /* A column wins with marked values 1,4,7 or 2,5,8, or 3,6,9 with all Os or Xs
    (Remember a vector index starts at 0)
    */
    bool win;
    if (pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X") {
        win = true;
    } else if (pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X") {
        win = true;
    } else if (pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X") {
        win = true;
    } else if (pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O") {
        win = true;
    } else if (pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O") {
        win = true;
    } else if (pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O") {
        win = true;
    } else {
        win = false;
    }
    return win;
}

bool TicTacToe::check_row_win() {
    /* A row wins with marked values 1,2,3 or 4,5,6 or 7,8,9 with all Os or Xs
    */
    bool win;
    if (pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X") {
        win = true;
    } else if (pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X") {
        win = true;
    } else if (pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X") {
        win = true;
    } else if (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O") {
        win = true;
    } else if (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O") {
        win = true;
    } else if (pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O") {
        win = true;
    } else {
        win = false;
    }
    return win;
}
bool TicTacToe::check_diagonal_win() {
    /* A diagonal wins with marked values 1,5,9 or 7,5,3 with all Os or Xs
    */
    bool win;
    if (pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X") {
        win = true;
    } else if (pegs[6] == "X" && pegs[4] == "X" && pegs[2] == "X") {
        win = true;
    } else if (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O"){
        win = true;
    } else if (pegs[6] == "O" && pegs[4] == "O" && pegs[2] == "O") {
        win = true;
    } else {
        win = false;
    }
    return win;
}

void TicTacToe::set_winner() {
    /* If player is X set winner to O otherwise set winner to X
    */
    if (player == "X") {
        winner = "O";
    } else {
        winner = "X";
    }
}