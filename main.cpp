//
//  main.cpp
//  Minesweeper
//
//  Created by Jonathan Demelo on 2013-03-27.
//  Copyright (c) 2013 Jonathan Demelo. All rights reserved.
//

#include <iostream>
#include "Game.h"

int main(int argc, const char * argv[])
{
    Game current_game = Game();
    current_game.start();
    // current_game.end();
    return 0;
}

