#include "tic_tac_toe.h"

using std::string, std::cout, std::cin;
int main()
{
    // declaration of variables
    TicTacToe game;
    string first_player;
    char choice;
    int position;

    do {
        cout << "Enter first player (X or O): ";
        cin >> first_player;
        for (int i = 0; i < first_player.length(); i++)
        {
          first_player[i] = toupper(first_player[i]);
        }
        while (first_player != "X" && first_player != "O") {
            cout << "Invalid entry!\n";
            cout << "Entry must be an X or O. \n\n";
            cout << "Enter first player (X or O): ";
            cin >> first_player;
            for (int i = 0; i < first_player.length(); i++)
            {
                first_player[i] = toupper(first_player[i]);
            }
        }
        game.start_game(first_player);

        while (!game.game_over()) {  // end program & game over
            cout << "Enter position [1-9]: ";
            cin >> position;
            game.mark_board(position);
            game.display_board();
        }
        cout << "\nThe winner is " << game.get_winner() << "!\n\n"; //announces the winner
        cout << "Continue? Type y: ";
        cin >> choice;
    } while (choice == 'Y'|| choice == 'y');  //continuation loop for user/s


    return 0;
}