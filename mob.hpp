<<<<<<< HEAD
#pragma once

struct mob{
    private:
=======
int get_player_y();// TODOOOOOO
int get_player_x();// TODOOOOOO

struct position{
    int x; int y;
    position(int x, int y);
    friend position operator - (const position& p, const position& q);
    bool friend alvaliable(const position& p);// TODOOOOOO
};
class mob{
    protected:
>>>>>>> 6011ef869dc641494fe9e633210a1aa10d064460
    int x; int y;
    char symbol;
    int PV;
    mob (int x0, int y0, char symbol, int PV);
    public:
    int get_x () const ;
    int get_y () const ;
};

<<<<<<< HEAD
//struct snake :mob {
//    snake(int x, int y);
//        //move
//};
=======
class snake:mob{
    snake(int x, int y);
    bool move();
};
>>>>>>> 6011ef869dc641494fe9e633210a1aa10d064460
