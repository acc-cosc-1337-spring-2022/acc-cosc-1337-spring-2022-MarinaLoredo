#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
#include <memory>

void TicTacToeData::save_games(std::vector <std::unique_ptr<TicTacToe>>& games)
{
    ofstream save_file; 
    save_file.open("saved_games.txt");
    if (save_file.is_open())
    {
        for(auto& game: games)
        {
            for(auto& peg: game -> get_pegs())
            {
                save_file << peg;
            }
            save_file << game -> get_winner() << "\n";
        }
    }
    writer.close();
}

std::vector <std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    std::vector <std:unique_ptr<TicTacToe>> boards;
    std::ifstream retrieve_saves;
    retrieve_saves.open("saved_games.txt");
    std::string line;

    if(retrieve_saves.is_open())
    {
        while(std::getline(retrieve_saves, line))
        {
            std::vector <std::string> pegs;
            for(int i = 0; i < (line.length()-1); i++)
            {
                std::string p(1, line[i]);
                pegs.push_back(p);
            }
            std::string winner{line[line.size()-1]};
            std::unique_ptr<TicTacToe> board;
            if(pegs.size() == 9)
            {
                board = std::make_unique<TicTacToe3>(pegs, winner);
            }
            else if(pegs.size() == 16)
            {
                board = std::make_unique<TicTacToe4>(pegs, winner);
            }
            boards.push_back(std::move(board));
        }
        retrieve_saves.close();
    }
    return boards;
}
