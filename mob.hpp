#pragma once


class Board; 
class Hero;
struct position {
    int x; int y;
    position(int x, int y);
    friend position operator - (const position& p, const position& q);
    bool friend alvaliable(const position& p, Board board);
};
class mob {
protected:
    int x; int y;
    char symbol;
    int PV;
    mob(int x0, int y0, char symbol, int PV);
    public:
    int get_x() const ;
    int get_y() const ;
};

class snake: public mob {
    public:
    bool move(Hero hero, Board board);
    snake(int x, int y);
};