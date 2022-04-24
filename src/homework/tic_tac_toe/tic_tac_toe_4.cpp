#include "tic_tac_toe_4.h"

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/
bool TicTacToe4::check_column_win()
{
    bool column_win = false;
    if ((pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X" && pegs[12] == "X") || 
    (pegs[1] == "X" && pegs[5] == "X" && pegs[9] == "X" && pegs[13] == "X") || 
    (pegs[2] == "X" && pegs[6] == "X" && pegs[10] == "X" && pegs[14] == "X") || 
    (pegs[3] == "X" && pegs[7] == "X" && pegs[11] == "X" && pegs[15] == "X"))
    {
        column_win = true;
    }   
    else if((pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O" && pegs[12] == "O") || 
    (pegs[1] == "O" && pegs[5] == "O" && pegs[9] == "O" && pegs[13] == "O") || 
    (pegs[2] == "O" && pegs[6] == "O" && pegs[10] == "O" && pegs[14] == "O") || 
    (pegs[3] == "O" && pegs[7] == "O" && pegs[11] == "O" && pegs[15] == "O"))
    {
        column_win = true;
    }
    else
    {
        column_win = false;
    }
    return  column_win;     
}

/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/
bool TicTacToe4::check_row_win()
{
    bool row_win = false;
    if ((pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X" && pegs[3] == "X") || 
    (pegs[4] == "X" && pegs[5] == "X" && pegs[6] == "X" && pegs[7] == "X") || 
    (pegs[8] == "X" && pegs[9] == "X" && pegs[10] == "X" && pegs[11] == "X")|| 
    (pegs[12] == "X" && pegs[13] == "X" && pegs[14] == "X" && pegs[15] == "X"))
    {
        row_win = true;
    }   
    else if((pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O" && pegs[3] == "O") || 
    (pegs[4] == "O" && pegs[5] == "O" && pegs[6] == "O" && pegs[7] == "O") || 
    (pegs[8] == "O" && pegs[9] == "O" && pegs[10] == "O" && pegs[11] == "O")|| 
    (pegs[12] == "O" && pegs[13] == "O" && pegs[14] == "O" && pegs[15] == "O"))
    {
        row_win = true;
    }
    else
    {
        row_win = false;
    }
    return  row_win; 
}	

/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15
*/
bool TicTacToe4::check_diagonal_win()
{
    bool diagonal_win = false;
    if ((pegs[0] == "X" && pegs[5] == "X" && pegs[10] == "X" && pegs[15] == "X") || 
    (pegs[3] == "X" && pegs[6] == "X" && pegs[9] == "X" && pegs[12] == "X"))
    {
        diagonal_win = true;
    }   
    else if((pegs[0] == "O" && pegs[5] == "O" && pegs[10] == "O" && pegs[15] == "O") || 
    (pegs[3] == "O" && pegs[6] == "O" && pegs[9] == "O" && pegs[12] == "O"))
    {
        diagonal_win = true;
    }
    else
    {
        diagonal_win = false;
    }
    return  diagonal_win; 

}