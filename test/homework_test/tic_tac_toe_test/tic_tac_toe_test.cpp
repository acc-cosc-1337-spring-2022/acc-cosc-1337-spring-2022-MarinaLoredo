#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test tic tac toe game over for a tie")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();

    game -> mark_board(1);
    REQUIRE(false == game -> game_over());

    game -> mark_board(2);
    REQUIRE(false == game -> game_over());        

    game -> mark_board(3);
    REQUIRE(false == game -> game_over());

    game -> mark_board(4);
    REQUIRE(false == game -> game_over());

    game -> mark_board(5);
    REQUIRE(false == game -> game_over());

    game -> mark_board(7);
    REQUIRE(false == game -> game_over());

    game -> mark_board(6);
    REQUIRE(false == game -> game_over());

    game -> mark_board(9);
    REQUIRE(false == game -> game_over());

    game -> mark_board(8);
    REQUIRE(true == game -> game_over());
    REQUIRE(game -> get_winner() == "C");
} 

TEST_CASE("Test first player set to X")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game ->start_game("X");
    REQUIRE(game -> get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game -> start_game("O");
    REQUIRE(game -> get_player() == "O");
}

TEST_CASE("Test win by first column")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game -> start_game("X");
    game -> mark_board(1);
    REQUIRE(false == game -> game_over());
    game -> mark_board(2);
    REQUIRE(false == game -> game_over());
    game -> mark_board(4);
    REQUIRE(false == game -> game_over());
    game -> mark_board(5);
    REQUIRE(false == game -> game_over());
    game -> mark_board(7);
    REQUIRE(game -> game_over() == true);
    REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by second column")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game -> start_game("X");
    game -> mark_board(2);
    REQUIRE(false == game -> game_over());
    game -> mark_board(3);    
    REQUIRE(false == game -> game_over());
    game -> mark_board(5);
    REQUIRE(false == game -> game_over());
    game -> mark_board(6);
    REQUIRE(false == game -> game_over());
    game -> mark_board(8);
    REQUIRE(game -> game_over() == true);
    REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by third column")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game -> start_game("X");
    game -> mark_board(3);
    REQUIRE(false == game -> game_over());
    game -> mark_board(2);
    REQUIRE(false == game -> game_over());
    game -> mark_board(6);
    REQUIRE(false == game -> game_over());
    game -> mark_board(5);
    REQUIRE(false == game -> game_over());
    game -> mark_board(9);
    REQUIRE(game -> game_over() == true);
    REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by first row")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game -> start_game("X");
    game -> mark_board(1);
    REQUIRE(false == game -> game_over());
    game -> mark_board(4);
    REQUIRE(false == game -> game_over());
    game -> mark_board(2);
    REQUIRE(false == game -> game_over());
    game -> mark_board(5);
    REQUIRE(false == game -> game_over());
    game -> mark_board(3);
    REQUIRE(game -> game_over() == true);
    REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by second row")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game -> start_game("X");
    game -> mark_board(4);
    REQUIRE(false == game -> game_over());
    game -> mark_board(1);
    REQUIRE(false == game -> game_over());
    game -> mark_board(5);
    REQUIRE(false == game -> game_over());
    game -> mark_board(7);
    REQUIRE(false == game -> game_over());
    game -> mark_board(6);
    REQUIRE(game -> game_over() == true);
    REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win by third row")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game -> start_game("X");
    game -> mark_board(7);
    REQUIRE(false == game -> game_over());
    game -> mark_board(1);
    REQUIRE(false == game -> game_over());
    game -> mark_board(8);
    REQUIRE(false == game -> game_over());
    game -> mark_board(4);
    REQUIRE(false == game -> game_over());
    game -> mark_board(9);
    REQUIRE(game -> game_over() == true);
    REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game -> start_game("X");
    game -> mark_board(1);
    REQUIRE(false == game -> game_over());
    game -> mark_board(2);
    REQUIRE(false == game -> game_over());
    game -> mark_board(5);
    REQUIRE(false == game -> game_over());
    game -> mark_board(4);
    REQUIRE(false == game -> game_over());
    game -> mark_board(9);
    REQUIRE(game -> game_over() == true);
    REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left ")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game -> start_game("X");
    game -> mark_board(7);
    REQUIRE(false == game -> game_over());
    game -> mark_board(2);
    REQUIRE(false == game -> game_over());
    game -> mark_board(5);
    REQUIRE(false == game -> game_over());
    game -> mark_board(4);
    REQUIRE(false == game -> game_over());
    game -> mark_board(3);
    REQUIRE(game -> game_over() == true);
    REQUIRE(game -> get_winner() == "X");
}

TEST_CASE("TicTacToe manager get winner total function")
{
    unique_ptr<TicTacToe> game_one = make_unique<TicTacToe3>();
    unique_ptr<TicTacToe> game_two = make_unique<TicTacToe3>();
    unique_ptr<TicTacToe> game_three = make_unique<TicTacToe3>();
    TicTacToeManager manager;
    int o,w,t;

    //first game 
    game_one -> start_game("X");
    game_one -> mark_board(7);
    REQUIRE(false == game_one -> game_over());
    game_one -> mark_board(2);
    REQUIRE(false == game_one -> game_over());
    game_one -> mark_board(5);
    REQUIRE(false == game_one -> game_over());
    game_one -> mark_board(4);
    REQUIRE(false == game_one -> game_over());
    game_one -> mark_board(3);
    REQUIRE(game_one -> game_over() == true);
    REQUIRE(game_one -> get_winner() == "X");
    manager.save_game(game_one);
    //second game
    game_two -> start_game("O");
    game_two -> mark_board(7);
    REQUIRE(false == game_two -> game_over());
    game_two -> mark_board(2);
    REQUIRE(false == game_two -> game_over());
    game_two -> mark_board(5);
    REQUIRE(false == game_two -> game_over());
    game_two -> mark_board(4);
    REQUIRE(false == game_two -> game_over());
    game_two -> mark_board(3);
    REQUIRE(game_two -> game_over() == true);
    REQUIRE(game_two -> get_winner() == "O");
    manager.save_game(game_two);
    //third game
    game_three -> mark_board(1);
    REQUIRE(false == game_three -> game_over());
    game_three -> mark_board(2);
    REQUIRE(false == game_three -> game_over());        
    game_three -> mark_board(3);
    REQUIRE(false == game_three -> game_over());
    game_three -> mark_board(4);
    REQUIRE(false == game_three -> game_over());
    game_three -> mark_board(5);
    REQUIRE(false == game_three -> game_over());
    game_three -> mark_board(7);
    REQUIRE(false == game_three -> game_over());
    game_three -> mark_board(6);
    REQUIRE(false ==  game_three -> game_over());
    game_three -> mark_board(9);
    REQUIRE(false == game_three -> game_over());
    game_three -> mark_board(8);
    REQUIRE(true == game_three -> game_over());
    REQUIRE(game_three -> get_winner() == "C");
    manager.save_game(game_three);
    //recall winner 
    manager.get_winner_total(o,w,t);
    REQUIRE(o == 1);
    REQUIRE(w == 1);
    REQUIRE(t == 1);

}
//TicTacToe 4x4 test
TEST_CASE("Test tic tac toe game over for a tie 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(16);
	REQUIRE(game->game_over() == false);
	game->mark_board(12);
	REQUIRE(game->game_over() == false);
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(14);
	REQUIRE(game->game_over() == false);
	game->mark_board(15);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test first player set to X, 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O, 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column, 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(13);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second column, 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(14);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third column, 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(15);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by fourth column, 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(12);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first row, 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by second row, 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by third row, 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(12);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by fourth row, 4")
 {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(14);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(15);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left, 4") 
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(16);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left, 4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(10);
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test TicTacToe manager get winner total function, 4") 
{
    unique_ptr<TicTacToe> game1 = make_unique<TicTacToe4>();
    unique_ptr<TicTacToe> game2 = make_unique<TicTacToe4>();
    unique_ptr<TicTacToe> game3 = make_unique<TicTacToe4>();
	TicTacToeManager manager;
	
    int o, w, t; 
    //first game 
	game1->start_game("X");
	game1->mark_board(13);
	REQUIRE(game1->game_over() == false);
	game1->mark_board(5);
	REQUIRE(game1->game_over() == false);
	game1->mark_board(14);
	REQUIRE(game1->game_over() == false);
	game1->mark_board(1);
	REQUIRE(game1->game_over() == false);
	game1->mark_board(15);
	REQUIRE(game1->game_over() == false);
	game1->mark_board(6);
	REQUIRE(game1->game_over() == false);
	game1->mark_board(16);
	REQUIRE(game1->game_over() == true);
	REQUIRE(game1->get_winner() == "X");
	manager.save_game(game1);
    //second game
	game2->start_game("X");
	game2->mark_board(1);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(3);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(2);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(4);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(6);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(5);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(7);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(8);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(9);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(10);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(11);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(16);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(12);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(13);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(14);
	REQUIRE(game2->game_over() == false);
	game2->mark_board(15);
	REQUIRE(game2->game_over() == true);
	REQUIRE(game2->get_winner() == "C");
	manager.save_game(game2);
	//third game
	game3->start_game("O");
	game3->mark_board(13);
	REQUIRE(game3->game_over() == false);
	game3->mark_board(2);
	REQUIRE(game3->game_over() == false);
	game3->mark_board(10);
	REQUIRE(game3->game_over() == false);
	game3->mark_board(1);
	REQUIRE(game3->game_over() == false);
	game3->mark_board(7);
	REQUIRE(game3->game_over() == false);
	game3->mark_board(11);
	REQUIRE(game3->game_over() == false);
	game3->mark_board(4);
	REQUIRE(game3->game_over() == true);
	REQUIRE(game3->get_winner() == "O");
	manager.save_game(game3);
    //recall winner 
	manager.get_winner_total(o,w,t);
	REQUIRE(o == 1);
	REQUIRE(w == 1);
	REQUIRE(t == 1);
}