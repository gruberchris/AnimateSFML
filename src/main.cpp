#include "Game.h"

int main() {
    AnimateSFML::Game game;

    while(game.isRunning()) {
        game.update();
        game.render();
    }

    return 0;
}
