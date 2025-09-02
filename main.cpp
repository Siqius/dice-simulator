#include "game.h"

int main() {
    Game game = Game(15000, 5000);
    while (game.running) {
        game.init();
    }
    return 0;
}