#include <algorithm>
#include <string>
#include <iostream>
#include <thread>

#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include "Game.h"


int main(int argc, char* argv[]) {
    Game game{30, 15};

    game.startGame();
    std::thread thread(&Game::keypressListener, &game);

    thread.join();
    
	return 0;
}
