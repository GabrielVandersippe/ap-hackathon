#pragma once

#include<iostream>
#include<vector>
#include <array>
#include "keyboard_event.hpp"
#include "mob.hpp"
#include "hero.hpp"
#include <random>

enum class TypeCase {
    EMPTY,
    VERTIWALL,
    HORIWALL,
    GROUND,
    GATE,
    CORRIDOR,
    STAIRS,
    HERO,
    MOB
};

class Board {
    const int nb_rows;
    const int nb_cols;
    TypeCase is_over;
    TypeCase is_overMob;
    std::vector<std::vector<TypeCase>> board;
    std::vector<std::array<int, 4>> rooms;
public:
    Board(int nb_rows = 30, int nb_cols = 30) : nb_rows(nb_rows), nb_cols(nb_cols), board(nb_rows, std::vector<TypeCase>(nb_cols)), is_over(TypeCase::GROUND) {}
    void change_case(int row, int col, TypeCase new_case) {
        board[row][col] = new_case;
    }
    void print_board() const {
        for (int i = 0; i < nb_rows; i++) {
            for (int j = 0; j < nb_cols; j++) {
                switch (board[i][j]) {
                    case TypeCase::EMPTY:
                        std::cout << ' ';
                    break;
                    case TypeCase::VERTIWALL:
                        std::cout << '|';
                    break;
                    case TypeCase::HORIWALL:
                        std::cout << '-';
                    break;
                    case TypeCase::GROUND:
                        std::cout << '.';
                    break;
                    case TypeCase::GATE:
                        std::cout << '+';
                    break;
                    case TypeCase::CORRIDOR:
                        std::cout << '#';
                    break;
                    case TypeCase::STAIRS:
                        std::cout << '=';
                    break;
                    case TypeCase::HERO:
                        std::cout << '@';
                    break;
                    case TypeCase::MOB:
                        std::cout << 'S';
                    break;
                }
            }
            std::cout << std::endl;
        }
    }
    void create_room(int row, int col, int height, int width) {
        for (int i = row; i < row + height; i++) {
            for (int j = col; j < col + width; j++) {
                board[i][j] = TypeCase::GROUND;
            }
        }
        for (int i = row; i < row + height + 1; i++) {
            board[i][col] = TypeCase::VERTIWALL;
            board[i][col + width] = TypeCase::VERTIWALL;
        }
        for (int j = col; j < col + width + 1; j++) {
            board[row][j] = TypeCase::HORIWALL;
            board[row + height][j] = TypeCase::HORIWALL;
        }
    }
    void random_room() {
        srand(time(0));
        int deb_row = rand() % (nb_rows/4);
        int deb_col = rand() % (nb_cols/4);
        int height = 4 + rand() % (nb_rows/2-deb_row - 5);
        int width = 4 + rand() % (nb_cols/2-deb_col - 5);
        create_room(deb_row, deb_col, height, width);
        rooms.push_back({deb_row, deb_col, height, width});
    }
    void initialize_empty() {
        for (int i = 0; i < nb_rows; i++) {
            for (int j = 0; j < nb_cols; j++) {
                board[i][j] = TypeCase::EMPTY;
            }
        }
    }
    void initialize(Hero* hero){
        initialize_empty();
        random_room();
        bool quit = false;
        for (int i = 0; i < nb_rows; i++) {
            for (int j = 0; j < nb_cols; j++) {
                if (board[i][j] == TypeCase::GROUND) {
                    hero->y = i;
                    hero->x = j;
                    board[i][j] = TypeCase::HERO;
                    quit = true;
                }
                if (quit) {break;}
            }
            if (quit) {break;}
        }
    }
    void deplace_hero(Hero& hero) {
        int previous_row;
        int previous_col;
        for (int i=0;i<nb_rows;i++) {
            for (int j=0;j<nb_cols;j++) {
                if (board[i][j] == TypeCase::HERO) {previous_row = i; previous_col = j;}
            }
        }
        board[previous_row][previous_col] = is_over;
        is_over = board[hero.y][hero.x];
        board[hero.y][hero.x] = TypeCase::HERO;
    } // actualise la position du hero
    //void place_mob(mob mob) {} // TODOOOOOOOOOOOO
    snake* initialize_snake(){
        bool quit = false;
        bool trouve = false;
        is_overMob = TypeCase::GROUND;
        for (int i = 0; i < nb_rows; i++) {
            for (int j = 0; j < nb_cols; j++) {
                if (board[i][j] == TypeCase::HERO) {
                    trouve = true;
                } if(board [i][j] == TypeCase::GROUND&&trouve){
                    board[i][j] = TypeCase::MOB;
                    snake* S = new snake(j,i);
                    return S;
                    quit = true;
                }
                if (quit) {break;}
            }
            if (quit) {break;}
        }
        return nullptr;
    }
    void deplace_mob(mob& mob) {
        int previous_row;
        int previous_col;
        for (int i=0;i<nb_rows;i++) {
            for (int j=0;j<nb_cols;j++) {
                if (board[i][j] == TypeCase::MOB) {previous_row = i; previous_col = j;}
            }
        }
        board[previous_row][previous_col] = is_overMob;
        is_overMob = board[mob.get_y()][mob.get_x()];
        board[mob.get_y()][mob.get_x()] = TypeCase::MOB;
    }

    TypeCase get_case(const int & row, const int & col) {
        return board[row][col];
    }
    bool is_in_the_room(int room_row, int room_col, int room_height, int room_width, int object_row, int object_col) {
        return (room_row <= object_row && object_row <= room_row + room_height) && (room_col <= object_col && object_col <= room_col + room_width);
    }
    bool is_in_the_room(std::array<int, 4> room, int object_row, int object_col) {
        return is_in_the_room(room[0], room[1], room[2], room[3], object_row, object_col);
    }
    void add_room(bool on_rows = true) {
        int min_bool = INT_MAX;
        int deb_row;
        int deb_col;
        srand(time(0));
        if (on_rows) {
            for (std::array<int, 4> room : rooms) {
                min_bool = std::min(min_bool, room[0]+room[2]);
            }
            deb_row = min_bool + 2 + rand() % (nb_rows/2-min_bool);
            deb_col = rand() % (nb_cols-5);
        } else {
            for (std::array<int, 4> room : rooms) {
                min_bool = std::min(min_bool, room[1]+room[3]);
            }
            deb_row = rand() % (nb_rows-5);
            deb_col = min_bool + 2 + rand() % (nb_cols/2-min_bool);
        }
        int height = 4 + rand() % (nb_rows/2-deb_row-5);
        int width = 4 + rand() % (nb_cols/2-deb_col-5);
        create_room(deb_row,deb_col, height, width);

        int gate1_row = rooms.back()[0] + rooms.back()[2];
        int gate1_col = rooms.back()[1] + 1 + rand() % (rooms.back()[3]-1);
        change_case(gate1_row, gate1_col, TypeCase::GATE);
        int gate2_row = deb_row;
        int gate2_col = deb_col + 1 + rand() % (width-1);
        change_case(gate2_row, gate2_col, TypeCase::GATE);

        for (int i = gate1_row+1; i < gate2_row; i++) {
            change_case(i, gate1_col, TypeCase::CORRIDOR);
        }
        int epsilon = (gate1_col <= gate2_col) ? 1 : -1;
        switch (epsilon) {
            case 1:
                for (int i = gate1_col+1; i <= gate2_col ; i = i + epsilon) {
                    change_case(gate2_row-1, i, TypeCase::CORRIDOR);
                }
            break;
            case -1:
                for (int i = gate1_col-1;  i >= gate2_col ; i = i + epsilon) {
                    change_case(gate2_row-1, i, TypeCase::CORRIDOR);
                }
        }

        rooms.push_back({deb_row, deb_col, height, width});

    }
};
