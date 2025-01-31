#include <iostream>
#include "game.hpp"
#include "hero.hpp"
/// Affichage
const int SCREEN_WIDTH = 30;
const int SCREEN_HEIGHT = 30;



int main(){
    Board board = Board(SCREEN_WIDTH, SCREEN_HEIGHT);
    board.initialize();
    board.create_room(2,2,4,5);
    board.print_board();
    return 1;
}