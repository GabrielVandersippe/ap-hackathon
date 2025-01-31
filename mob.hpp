#pragma once

struct mob{
    private:
    int x; int y;
    char symbol;
    int PV;
    mob (int x0, int y0, char symbol, int PV);
    public:
    int get_x ();
    int get_y ();
};

//struct snake :mob {
//    snake(int x, int y);
//        //move
//};