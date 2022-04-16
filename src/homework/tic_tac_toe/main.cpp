#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

using std::cout; using std::cin; using std::string;

int main() 
{

    TicTacToe game;
    TicTacToeManager manager;
    string first_player;
    char choice;
    int o, w, t; 

    do
    {
        do
        {
            cout << "Enter first player (X or O): ";
            cin >> first_player;
            for (int i = 0; i < first_player.length(); i++)
            {
                first_player[i] = toupper(first_player[i]);
            }
            if (first_player != "X" && first_player != "O")
            {
                cout<< "Sorry that was an invalid input. \n";
            }
        } while(first_player != "X" && first_player != "O");

		game.start_game(first_player);
        
		while(game.game_over() == false)
        {
            cin >> game;
            cout << game;
        }

        cout << " \nThe winner is: " << game.get_winner() << "\n";
        manager.save_game(game);
        manager.get_winner_total(o, w, t);

        cout << "Continue type Y: ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');
    
    cout << " \n Every Game Played";
    cout << manager;

    return 0;
}