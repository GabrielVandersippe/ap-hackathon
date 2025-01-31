#include <iostream>
#include "game.hpp"

/// Affichage
const int SCREEN_WIDTH = 30;
const int SCREEN_HEIGHT = 30;



int main(){
    bool game = true;
    char input;
    Board board = Board(SCREEN_WIDTH, SCREEN_HEIGHT);
    board.initialize();
    board.create_room(2,2,4,5);
    backgroundClear();
    board.print_board();
    Hero hero("Brandon", 3, 3);
    while(game){
        if(keyEvent()){
            std::cin >> input;
            if(input == 'p'){}
            else if(input == 'z'){
                hero.y++;
            }
            else if(input == 'q'){
                hero.x--;
            }
            else if(input == 's'){
                hero.y--;
            }
            else if(input == 'd'){
                hero.x++;
            }
        }
    }
    return 1;
}