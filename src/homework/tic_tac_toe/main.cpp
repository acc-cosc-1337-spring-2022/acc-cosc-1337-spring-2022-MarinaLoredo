#include "tic_tac_toe.h"

using std::string, std::cout, std::cin;
int main()
{
    TicTacToe game;
    string first_player;
    char choice;
    int position;

    do {
        cout << "Enter first player (X or O)";
        cin >> first_player;
        game.start_game(first_player);

        while (!game.game_over()) {
            cout << "Enter position [1-9]";
            cin >> position;
            game.mark_board(position);
            game.display_board();
        }
        cout << "Continue? Type Y: ";
        cin >> choice;
    } while (choice == 'Y'|| choice == 'y');


    return 0;
}