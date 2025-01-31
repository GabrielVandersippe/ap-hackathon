#pragma once

#include<iostream>
#include<vector>
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
    HERO
};

class Board {
    const int nb_rows;
    const int nb_cols;
    TypeCase is_over;
    std::vector<std::vector<TypeCase>> board;
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
                }
            }
            std::cout << std::endl;
        }
    }
    void initialize() {
        for (int i = 0; i < nb_rows; i++) {
            for (int j = 0; j < nb_cols; j++) {
                board[i][j] = TypeCase::EMPTY;
            }
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
    void deplace_hero(Hero hero) {
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
    void place_mob(mob mob) {} // TODOOOOOOOOOOOO
    TypeCase get_case(int row, int col) {
        return board[row][col];
    }
    void random_room() {
        int deb_row = rand() % (nb_rows-4);
        int deb_col = rand() % (nb_cols-4);
        int height = 3 + rand() % (nb_rows-3-deb_row);
        int width = 3 + rand() % (nb_cols-3-deb_col);
        create_room(deb_row, deb_col, height, width);
    }

};
