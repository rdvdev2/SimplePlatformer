#include <iostream>

#include "Game.h"

int main() {
    SP::Game game;

    try {
        game.Run();
    } catch (const std::exception& e) {
        fprintf(stderr, "Fatal exception: %s", e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}