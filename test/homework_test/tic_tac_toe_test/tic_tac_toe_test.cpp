#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
REQUIRE(true == true);
}

TEST_CASE("Test tic tac toe game over for a tie") {
TicTacToe game;
game.start_game("X");
game.mark_board(1);
REQUIRE(game.game_over() == false);
game.mark_board(3);
REQUIRE(game.game_over() == false);
game.mark_board(2);
REQUIRE(game.game_over() == false);
game.mark_board(4);
REQUIRE(game.game_over() == false);
game.mark_board(6);
REQUIRE(game.game_over() == false);
game.mark_board(5);
REQUIRE(game.game_over() == false);
game.mark_board(7);
REQUIRE(game.game_over() == false);
game.mark_board(8);
REQUIRE(game.game_over() == false);
game.mark_board(9);
REQUIRE(game.game_over() == true);
REQUIRE(game.get_winner() == "C");
}


TEST_CASE("Test first player set to X") {
TicTacToe game;
game.start_game("X");
REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
TicTacToe game;
game.start_game("O");
REQUIRE(game.get_player() == "O");
}




TEST_CASE("Test win by first column") {
TicTacToe game;
game.start_game("X");
game.mark_board(1);
REQUIRE(false == game_one.game_over());
game.mark_board(2);
REQUIRE(false == game_one.game_over());
game.mark_board(4);
REQUIRE(false == game_one.game_over());
game.mark_board(5);
REQUIRE(false == game_one.game_over());
game.mark_board(7);
REQUIRE(game.game_over() == true);
REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column") {
TicTacToe game;
game.start_game("X");
game.mark_board(2);
REQUIRE(false == game_one.game_over());
game.mark_board(1);
REQUIRE(false == game_one.game_over());
game.mark_board(5);
REQUIRE(false == game_one.game_over());
game.mark_board(4);
REQUIRE(false == game_one.game_over());
game.mark_board(7);
REQUIRE(game.game_over() == true);
REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column") {
TicTacToe game;
game.start_game("X");
game.mark_board(3);
REQUIRE(false == game_one.game_over());
game.mark_board(2);
REQUIRE(false == game_one.game_over());
game.mark_board(6);REQUIRE(false == game_one.game_over());
game.mark_board(5);
REQUIRE(false == game_one.game_over());
game.mark_board(9);
REQUIRE(game.game_over() == true);
REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row") {
TicTacToe game;
game.start_game("X");
game.mark_board(1);
REQUIRE(false == game_one.game_over());
game.mark_board(4);
REQUIRE(false == game_one.game_over());
game.mark_board(2);
REQUIRE(false == game_one.game_over());
game.mark_board(5);
REQUIRE(false == game_one.game_over());
game.mark_board(3);
REQUIRE(game.game_over() == true);
REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row") {
TicTacToe game;
game.start_game("X");
game.mark_board(4);
REQUIRE(false == game_one.game_over());
game.mark_board(1);
REQUIRE(false == game_one.game_over());
game.mark_board(5);
REQUIRE(false == game_one.game_over());
game.mark_board(2);
REQUIRE(false == game_one.game_over());
game.mark_board(6);
REQUIRE(game.game_over() == true);
REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row") {
TicTacToe game;
game.start_game("X");
game.mark_board(7);
REQUIRE(false == game_one.game_over());
game.mark_board(1);
REQUIRE(false == game_one.game_over());
game.mark_board(8);
REQUIRE(false == game_one.game_over());
game.mark_board(2);
REQUIRE(false == game_one.game_over());
game.mark_board(9);
REQUIRE(game.game_over() == true);
REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left") {
TicTacToe game;
game.start_game("O");
game.mark_board(7);
REQUIRE(false == game_one.game_over());
game.mark_board(1);
REQUIRE(false == game_one.game_over());
game.mark_board(5);
REQUIRE(false == game_one.game_over());
game.mark_board(2);
REQUIRE(false == game_one.game_over());
game.mark_board(3);
REQUIRE(game.game_over() == true);
REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Test win diagonally from top left") {
TicTacToe game;
game.start_game("X");
game.mark_board(1);
REQUIRE(false == game_one.game_over());
game.mark_board(2);
REQUIRE(false == game_one.game_over());
game.mark_board(5);
REQUIRE(false == game_one.game_over());
game.mark_board(3);
REQUIRE(false == game_one.game_over());
game.mark_board(9);
REQUIRE(game.game_over() == true);
REQUIRE(game.get_winner() == "X");
}

TEST_CASE("TicTacToe manager get winner total function")
{
    TicTacToe game_one;
    TicTacToe game_two;
    TicTacToe game_three;
    TicTacToeManager manager;
    int o,w,t;

    //X win
    game_one.start_game("X");
    game_one.mark_board(1);
    REQUIRE(false == game_one.game_over());
    game_one.mark_board(2);
    REQUIRE(false == game_one.game_over());
    game_one.mark_board(4);
    REQUIRE(false == game_one.game_over());
    game_one.mark_board(5);
    REQUIRE(false == game_one.game_over());
    game_one.mark_board(7);
    REQUIRE(game_one.game_over() == true);
    REQUIRE(game_one.get_winner() == "X");
    manager.save_game(game_one);
    
    //O win
    game_two.start_game("O");
    game_two.mark_board(1);
    REQUIRE(false == game_two.game_over());
    game_two.mark_board(2);
    REQUIRE(false == game_two.game_over());
    game_two.mark_board(4);
    REQUIRE(false == game_two.game_over());
    game_two.mark_board(5);
    REQUIRE(false == game_two.game_over());
    game_two.mark_board(7);
    REQUIRE(game_two.game_over() == true);
    REQUIRE(game_two.get_winner() == "O");
    manager.save_game(game_two);
    
    //It's a tie!
    game_three.mark_board(1);
    REQUIRE(false == game_three.game_over());
    game_three.mark_board(2);
    REQUIRE(false == game_three.game_over());        
    game_three.mark_board(3);
    REQUIRE(false == game_three.game_over());
    game_three.mark_board(4);
    REQUIRE(false == game_three.game_over());
    game_three.mark_board(5);
    REQUIRE(false == game_three.game_over());
    game_three.mark_board(7);
    REQUIRE(false == game_three.game_over());
    game_three.mark_board(6);
    REQUIRE(false == game_three.game_over());
    game_three.mark_board(9);
    REQUIRE(false == game_three.game_over());
    game_three.mark_board(8);
    REQUIRE(true == game_three.game_over());
    REQUIRE(game_three.get_winner() == "C");
    manager.save_game(game_three);
   
    manager.get_winner_total(o,w,t);
    REQUIRE(o == 1);
    REQUIRE(w == 1);
    REQUIRE(t == 1);
}