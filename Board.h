//
//  Board.h
//  Minesweeper
//
//  Created by Jonathan Demelo on 2013-03-27.
//  Copyright (c) 2013 Jonathan Demelo. All rights reserved.
//

#ifndef __Minesweeper__Board__
#define __Minesweeper__Board__

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>  

class Board
{
private:
    std::vector<int> v_board;
    std::vector<int> v_chosen;
    int board_size;
    int number_of_mines;
public:
    Board();
    Board(int, int);
    void display_mine_board();
    void display_visiable_board();
    void display_board();
    bool win_check();
    std::vector<int> build_board();
    int pick_spot(int, int);
};

#endif /* defined(__Minesweeper__Board__) */
