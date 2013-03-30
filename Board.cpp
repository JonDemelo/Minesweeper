//
//  Board.cpp
//  Minesweeper
//
//  Created by Jonathan Demelo on 2013-03-27.
//  Copyright (c) 2013 Jonathan Demelo. All rights reserved.
//

#include "Board.h"

Board::Board()
{
    // empty default constructor
}

Board::Board(int n, int b)
{
    number_of_mines = n; // number of mines
    board_size = b; // size of board size
    
    /* 
    Check if there are more bombs then spaces available.
    If there are more, cap the amount of bombs to the maximum.
    */
    if(number_of_mines >= (board_size*board_size))
    {
        number_of_mines = board_size*board_size;
    }
    
    for (int i = 0; i < board_size*board_size; i++)
    {
        v_board.push_back(0); // empty board
        v_chosen.push_back(0); // empty chosen board
    }
    
    srand((int)time(NULL)); // random seeding for rand
    
    int counter = 1;
    do
    {
        int i_rand = rand() % (board_size*board_size); // random number between 0 and 24
        
        if(v_board.at(i_rand) == 0) // if the generated number is empty
        {
            v_board.at(i_rand) = 1; // place the number at the board point
            counter++; // one bomb has been placed
        }
    } while (counter <= number_of_mines); // while there are no more bombs to place.
}


void Board::display_mine_board()
{
    for (std::vector<int>::iterator iter = v_board.begin(); iter != v_board.end(); ++iter)
    {
        std::cout << *iter << " ";
        
        if ((iter - v_board.begin()) % board_size == board_size - 1)
        {
            std::cout << "\n";
        }
    }
}


std::vector<int> Board::build_board()
{
    std::vector<int> board;
    
    for (std::vector<int>::iterator iter = v_board.begin(); iter != v_board.end(); ++iter)
    {
        
        if (*iter == 1) // is bomb
        {
            board.push_back(9); // 9 is used as the placeholder for a bomb spot.
        }
        else // adjust to reflect bombs around it.
        {
            int current_spot = (int)(iter - v_board.begin());
            int count = 0;
            
            // check left
            if ((current_spot-1) >= 0 && current_spot % board_size != 0)
            {
                if (v_board.at(current_spot-1) == 1)
                {
                    count++;
                }
            }
            
            // check right
            if ((current_spot+1) < (board_size*board_size) && current_spot % board_size != (board_size-1))
            {
                if (v_board.at(current_spot+1) == 1)
                {
                    count++;
                }
            }
            
            // check above
            if ((current_spot-board_size) >= 0)
            {
                if (v_board.at(current_spot-board_size) == 1)
                {
                    count++;
                }
            }
            
            // check below
            if ((current_spot+board_size) < (board_size*board_size))
            {
                if (v_board.at(current_spot+board_size) == 1)
                {
                    count++;
                }
            }
            
            // check top left
            if ((current_spot-board_size-1) >= 0 && (current_spot % board_size != 0))
            {
                if (v_board.at(current_spot-board_size-1) == 1)
                {
                    count++;
                }
            }
            
            // check top right
            if ((current_spot-board_size+1) >= 0 && current_spot % board_size != (board_size-1))
            {
                if (v_board.at(current_spot-board_size+1) == 1)
                {
                    count++;
                }
            }
            
            // check bottom left
            if ((current_spot+board_size-1) < (board_size*board_size) && (current_spot % board_size != 0))
            {
                if (v_board.at(current_spot+board_size-1) == 1)
                {
                    count++;
                }
            }
            
            // check bottom right
            if ((current_spot+board_size+1) < (board_size*board_size) && current_spot % board_size != (board_size-1))
            {
                if (v_board.at(current_spot+board_size+1) == 1)
                {
                    count++;
                }
            }
            
            board.push_back(count);
        }
        
    }

    
    return board;
}

void Board::display_board()
{
    std::vector<int> board = this->build_board();
    
    for (std::vector<int>::iterator iter = board.begin(); iter != board.end(); ++iter)
    {
        if (*iter == 9) // 9 is the placeholder for a bomb within the vector
        {
            std::cout << "B ";
        }
        else
        {
            std::cout << *iter << " ";
        }

        if ((iter - board.begin()) % board_size == board_size - 1) // new line after the row is done.
        {
            std::cout << "\n";
        }
    }
}


void Board::display_visiable_board()
{
    std::vector<int> board = this->build_board();
    std::cout << "\n";
    
    for (std::vector<int>::iterator iter = v_chosen.begin(); iter != v_chosen.end(); ++iter)
    {
        int current_spot = (int)(iter - v_chosen.begin());
        
        if(*iter == 1) // visiable
        {
            if(board.at(current_spot) == 9)
            {
                std::cout << " B ";
            }
            else
            {
                std::cout << " " << board.at(current_spot) << " ";
            }
        }
        else // not visiable, thus placeholder
        {
            std::cout << "[ ]";
        }
    
        if ((iter - v_chosen.begin()) % board_size == board_size - 1) // new line after the row is done.
        {
            std::cout << "\n";
        }
    }
}


bool Board::win_check()
{
    std::vector<int> board = this->build_board();
    
    for (std::vector<int>::iterator iter = v_chosen.begin(); iter != v_chosen.end(); ++iter)
    {
        int current_spot = (int)(iter - v_chosen.begin());
        
        if(*iter == 0 && board.at(current_spot) != 9)
        {
            return false;
        }
    }
    return true;
}

int Board::pick_spot(int x, int y)
{
    int position = ((y-1)*board_size)+(x-1); // NOTE: user input will be 1..x, and 1...y, thus subtracting 1 to get proper vector position
    
    v_chosen.at(position) = 1;
    
    // LOSE CHECK
    if (v_board.at(position) == 1)
    {
        return 1; // picked a mine
    }
    
    if (win_check())
    {
        return 2; // won
    }
    
    return 0; // didn't pick a mine but also didn't win
}