#include "tic_tac_toe_manager.h"
using std::string; using std::cout;

void TicTacToeManager::save_game(unique_ptr<TicTacToe> &b)
{
    update_winner_count(b -> get_winner());
    games.push_back(move(b));
}

void TicTacToeManager::get_winner_total(int& o, int& w, int& t)
{
    o = o_win; 
    w = x_win;
    t = ties;

    cout<<"O wins: "<< o <<"\n";
    cout<<"X wins: "<< w <<"\n";
    cout<<"Ties: "<< t <<"\n";
    cout<<"\nTotal: "<< o+w+t<<"\n\n";
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager){
    for (auto& games_play: manager.games) 
    {
        out << "\n";
        out << *games_play << "\n";
    }
    return out;
}


void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X")
    {
        x_win += 1;
    }
    else if (winner == "O")
    {
        o_win += 1;
    }
    else
    {
        ties += 1; 
    }
}