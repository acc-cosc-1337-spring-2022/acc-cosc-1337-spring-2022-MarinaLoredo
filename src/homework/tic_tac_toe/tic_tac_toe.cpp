#include "tic_tac_toe.h"

using std::string; using std::cout; using std::cin;

bool TicTacToe::game_over()
{
    bool game_done;
    if(check_diagonal_win() == true || check_row_win() == true || check_column_win() == true)
    {
        set_winner();
        game_done = true;
    }
    else if(check_board_full() == true)
    {
        game_done = true; 
        winner = "C";
    }
    else 
    {
        game_done = false;
    }
    return game_done;
}

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

//displays the board
std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    for(int i=0 ; i < 9 ; i+=3)
    {
        out << game.pegs[i] << "|" << game.pegs[i+1] << "|" << game.pegs[i+2] << "\n";
    }
    return out; 
}

//gets position
std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    cout << "Enter position [1-9]"; 
    in >> position;
    game.mark_board(position);
    return in;
}

void TicTacToe::set_next_player()
 {
    if (player == "X") 
    {
        player = "O";
    } 
    else 
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full()
{
    for(auto peg: pegs)
    {
        if (peg == " ")
        {
            return false;
        } 
    }

    return true;
}

void TicTacToe::clear_board()
{
    for (auto& peg: pegs)
    {
        peg = " ";
    }
} 

bool TicTacToe::check_column_win()
{
    bool column_win = false;
    if ((pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X") || 
    (pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X") || 
    (pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X"))
    {
        column_win = true;
    }   
    else if((pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O") || 
    (pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O") || 
    (pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O"))
    {
        column_win = true;
    }
    else
    {
        column_win = false;
    }
    return  column_win;     
}

bool TicTacToe::check_row_win()
{
    bool row_win = false;
    if ((pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X") || 
    (pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X") || 
    (pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X"))
    {
        row_win = true;
    }   
    else if((pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O") || 
    (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O") || 
    (pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O"))
    {
        row_win = true;
    }
    else
    {
        row_win = false;
    }
    return  row_win; 
}	

bool TicTacToe::check_diagonal_win()
{
    bool diagonal_win = false;
    if ((pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X") || 
    (pegs[2] == "X" && pegs[4] == "X" && pegs[6] == "X"))
    {
        diagonal_win = true;
    }   
    else if((pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O") || 
    (pegs[2] == "O" && pegs[4] == "O" && pegs[6] == "O"))
    {
        diagonal_win = true;
    }
    else
    {
        diagonal_win = false;
    }
    return  diagonal_win; 

}

void TicTacToe::set_winner()
{
    if(player == "X")
    {
        winner  = "O";
    }
    else
    {
        winner = "X";
    }
}