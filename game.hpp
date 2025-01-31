#include<iostream>
#include<vector>

#include <iostream>

enum class TypeCase {
    EMPTY,
    VERTIWALL,
    HORIWALL,
    FLOR,
    GATE,
    CORRIDOR,
    STAIRS,
    HERO
};

class Board {
    const int nb_rows;
    const int nb_cols;
    std::vector<std::vector<TypeCase>> board;
public:
    Board(int nb_rows = 30, int nb_cols = 30) : nb_rows(nb_rows), nb_cols(nb_cols), board(nb_rows, std::vector<TypeCase>(nb_cols)) {}
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
                    case TypeCase::FLOR:
                        std::cout << '.';
                    break;
                    case TypeCase::GATE:
                        std::cout << '+';
                    break;
                    case TypeCase::CORRIDOR:
                        std::cout << '#';
                    break;
                    case TypeCase::STAIRS:
                        std::cout << '*';
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
        for (int i = row; i < col + height; i++) {
            for (int j = col; j < row + width; j++) {
                board[i][j] = TypeCase::FLOR;
            }
        }
        for (int i = row; i < col + height; i++) {
            board[i][col] = TypeCase::VERTIWALL;
            board[i][col + width] = TypeCase::VERTIWALL;
        }
        for (int j = col; j < row + width + 1; j++) {
            board[row][j] = TypeCase::HORIWALL;
            board[row + height][j] = TypeCase::HORIWALL;
        }
    }
    void place_hero(int row, int col) {
        board[row][col] = TypeCase::HERO;
    }
};