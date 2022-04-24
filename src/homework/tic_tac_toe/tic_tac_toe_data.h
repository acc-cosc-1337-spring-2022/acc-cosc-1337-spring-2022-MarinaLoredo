#include<fstream>
#include<ostream>
#include "tic_tac_toe.h"

using std::ofstream, std::ifstream;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToeData
{
public:
    void save_games(std::vector<std::unique_ptr<TicTacToe>>& games);
    std::vector<std::unique_ptr<TicTacToe>> get_games();
};

#endif