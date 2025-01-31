#include <iostream>
#include <string>
#include "game.hpp"
#include "hero.hpp"
/// Affichage
const int SCREEN_WIDTH = 30;
const int SCREEN_HEIGHT = 20;



int main(){
    bool game = true;
    char input;
    Board board = Board(SCREEN_WIDTH, SCREEN_HEIGHT);
    //backgroundClear();
    Hero hero("Brandon", 3, 3);
    board.initialize(&hero);
    board.print_board();
    while(game){
        board.deplace_hero(hero);
        board.print_board();
        std::cin >> input;
        if(input == 'p'){}
        else if(input == 'z'){
            TypeCase _case = board.get_case(hero.y + 1, hero.x);
            if((_case==TypeCase::GROUND)||(_case==TypeCase::GATE)||(_case==TypeCase::CORRIDOR)||(_case==TypeCase::STAIRS)){
                hero.y++;
            }
            else{
                std::cout << "You try to walk into a wall and hurt your nose... (-1HP)" << std::endl;
                hero.current_hp--;
            }
        }
        else if(input == 'q'){
            TypeCase _case = board.get_case(hero.y, hero.x - 1);
            if((_case==TypeCase::GROUND)||(_case==TypeCase::GATE)||(_case==TypeCase::CORRIDOR)||(_case==TypeCase::STAIRS)){
                hero.x--;
            }
        }
        else if(input == 's'){
            TypeCase _case = board.get_case(hero.y - 1, hero.x);
            if((_case==TypeCase::GROUND)||(_case==TypeCase::GATE)||(_case==TypeCase::CORRIDOR)||(_case==TypeCase::STAIRS)){
                hero.y--;
            }
        }
        else if(input == 'd'){
            TypeCase _case = board.get_case(hero.y, hero.x + 1);
            if((_case==TypeCase::GROUND)||(_case==TypeCase::GATE)||(_case==TypeCase::CORRIDOR)||(_case==TypeCase::STAIRS)){
                hero.x++;
            };
        }
    }
    return EXIT_SUCCESS;
}