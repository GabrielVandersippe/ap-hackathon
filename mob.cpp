#include "mob.hpp"
mob::mob(int x0, int y0, char symbol, int PV):x(x0), y(y0), symbol(symbol), PV(PV){}

int mob::get_x(){return this->x;};
int mob::get_y(){return this->y;};


//snake::snake(int x, int y ): mob(x, y, 'S', 5){}

