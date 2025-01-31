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

std::vector<std::vector<TypeCase>> starting_board = {{TypeCase::EMPTY, TypeCase::VERTIWALL, TypeCase::HORIWALL,},
{TypeCase::FLOR, TypeCase::HERO, TypeCase::STAIRS}};


class Board {
    const int nb_rows;
    const int nb_cols;
    std::vector<std::vector<TypeCase>> board;
public:
    Board(int nb_rows = 30, int nb_cols = 30) : nb_rows(starting_board.size()), nb_cols(starting_board[0].size()), board(starting_board) {}
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
                        std::cout << '_';
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
};