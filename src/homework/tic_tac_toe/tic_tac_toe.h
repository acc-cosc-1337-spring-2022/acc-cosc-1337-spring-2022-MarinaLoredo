#include <iostream>
#include <string>
#include <vector>


//Header Guards
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe
{

friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
friend std::istream& operator>>(std::istream& in, TicTacToe& game);

public:
    TicTacToe(){}
    TicTacToe(int size): pegs(size * size, " "){};
    TicTacToe(std::vector <std::string> p, std::string win): pegs(p), winner(win){};
    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player() const{return player;}
    std::string get_winner() {return winner;};
    std::vector <std::string> get_pegs() const {return pegs;}; //*

protected:
    std::vector<std::string> pegs;
    virtual bool check_column_win();
    virtual bool check_row_win();	
    virtual bool check_diagonal_win();

private: 
    std::string player;
    std::string winner;
    void set_next_player();
    bool check_board_full();
    void set_winner();
    void clear_board();
}; 

#endif