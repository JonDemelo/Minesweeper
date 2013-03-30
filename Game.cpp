//
//  Game.cpp
//  Minesweeper
//
//  Created by Jonathan Demelo on 2013-03-29.
//  Copyright (c) 2013 Jonathan Demelo. All rights reserved.
//

#include "Game.h"

Game::Game()
{
    board = Board(5, 5); // number of mines, board size
    gamestatus = true;
    boardchange = true;
}

void Game::start()
{
    while (gamestatus == true) { // until lose
        if (boardchange == true)
        {
            // NOTE: DISPLAY BOARD IS BUILT AROUND THE CONSOLE, USE THE CURRENT
            // FUNCTION AS INSIPRATION TO DO THE APPLICATION BASED ONE.
            
            board.display_visiable_board(); // update board
            boardchange = false;
        }
        
        // NOTE: ADJUST THIS TO GETTING TOUCH INPUT OR SOMETHING
        int x, y;
        std::cout << "\nX-cord (1,2,...,x): ";
        std::cin >> x;
        std::cout << "Y-cord (1,2,...,y): ";
        std::cin >> y;
        
        this->pick(x, y);
    }
}

void Game::end()
{
    gamestatus = false;
}

Board Game::get_board()
{
    return board;
}

void Game::pick(int x, int y) // the coords of the pick within the minesweeper grid.
{
    // NOTE: CURRENTLY NO IMPLIMENTED CHECK TO SEE IF THE INPUT WAS APPROPRIATE VIA CONSOLE SINCE
    // THE ACTUAL IMPLIMENTATION WILL BE TOUCH BASED, THUS IRRELEVENT.
    
    // NOTE: ALSO, THE FRONT END WILL HAVE TO DISABLE THE ABILITY TO PICK A PREVIOUSLY CHOSEN
    // SPOT, BY DISABLING THE ABILITY TO CLICK OR SOMETHING.
    
    boardchange = true;
    
    int result = board.pick_spot(x, y);
    
    if (result == 1 || result == 2) // the game is lost or won
    {
        gamestatus = false;
        if (result == 1) // lost game
        {
            board.display_visiable_board(); // update board
            std::cout << "You lost!"; // NOTE: ADJUST THIS TO OPENING THE LOSE SCREEN OR SOMETHING.
        }
        else if (result == 2) // won game
        {
            board.display_visiable_board(); // update board
            std::cout << "You won!"; // NOTE "ADJUST THIS TO OPENING THE WIN SCREEN OR SOMETHING.
        }
    }
}