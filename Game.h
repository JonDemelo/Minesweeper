//
//  Game.h
//  Minesweeper
//
//  Created by Jonathan Demelo on 2013-03-29.
//  Copyright (c) 2013 Jonathan Demelo. All rights reserved.
//

#ifndef __Minesweeper__Game__
#define __Minesweeper__Game__

#include <iostream>
#include "Board.h"

class Game
{
private:
    Board board;
    bool gamestatus;
    bool boardchange;
public:
    Game();
    void start();
    void end();
    Board get_board();
    void pick(int, int);
};

#endif /* defined(__Minesweeper__Game__) */
