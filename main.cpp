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
    snake S = snake(2, 2);
    board.print_board();
    while(game){
        std::string message = "";
        std::cin >> input;
        if(input == 'p'){}
        else if(input == 's'){
            TypeCase _case = board.get_case(hero.y + 1, hero.x);
            if((_case==TypeCase::GROUND)||(_case==TypeCase::GATE)||(_case==TypeCase::CORRIDOR)||(_case==TypeCase::STAIRS)){
                hero.y++;
            }
            else{
                message.append("You try to walk into a wall and hurt your nose... (-1HP)\n");
                hero.current_hp--;
            }
        }
        else if(input == 'q'){
            TypeCase _case = board.get_case(hero.y, hero.x - 1);
            if((_case==TypeCase::GROUND)||(_case==TypeCase::GATE)||(_case==TypeCase::CORRIDOR)||(_case==TypeCase::STAIRS)){
                hero.x--;
            }
            else{
                message.append("You try to walk into a wall and hurt your nose... (-1HP)\n");
                hero.current_hp--;
            }
        }
        else if(input == 'z'){
            TypeCase _case = board.get_case(hero.y - 1, hero.x);
            if((_case==TypeCase::GROUND)||(_case==TypeCase::GATE)||(_case==TypeCase::CORRIDOR)||(_case==TypeCase::STAIRS)){
                hero.y--;
            }
            else{
                message.append("You try to walk into a wall and hurt your nose... (-1HP)\n");
                hero.current_hp--;
            }
        }
        else if(input == 'd'){
            TypeCase _case = board.get_case(hero.y, hero.x + 1);
            if((_case==TypeCase::GROUND)||(_case==TypeCase::GATE)||(_case==TypeCase::CORRIDOR)||(_case==TypeCase::STAIRS)){
                hero.x++;
            }
            else{
                message.append("You try to walk into a wall and hurt your nose... (-1HP)\n");
                hero.current_hp--;
            }
        }

        else if (input == 'i') {
            hero.showInventory();
        }
        board.deplace_hero(hero);
        //board.deplace_mob(S);
        board.print_board();
        if(hero.current_hp <= 0){
            message.append("You died, maybe better luck next time !\n");
            game = false;
        }
        std::printf("%s", message.c_str());
        
    }
    return EXIT_SUCCESS;
}