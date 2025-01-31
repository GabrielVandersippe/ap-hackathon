enum class TypeCase {
    EMPTY,
    VERTIWALL,
    HORIWALL,
    FLOR,
    GATE,
    CORRIDOR,
    HERO
};

class Board {
    const int nb_rows;
    const int nb_cols;
    std::vector<std::vector<TypeCase>> board;
public:
    Board(int nb_rows = 30, int nb_cols = 30) : nb_rows(nb_rows), nb_cols(nb_cols) {}
};