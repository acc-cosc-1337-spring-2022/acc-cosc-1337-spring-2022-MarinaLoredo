#include <iostream>
#include "tic_tac_toe.h"
#include <string>
#include <vector>
#include <memory>
using std::unique_ptr;
using std::make_unique;

//Header Guards
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager
{


public: 
    void save_game(unique_ptr<TicTacToe>& b);
    void get_winner_total(int& o, int& w, int& t);
    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

private:
    std::vector<unique_ptr<TicTacToe>> games;

    int x_win = 0;
    int o_win = 0;
    int ties = 0; 

    void update_winner_count(std::string winner); 
};

#endif