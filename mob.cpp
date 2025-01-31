#include "mob.hpp"
position::position(int x, int y):x(x), y(y){}; 
position operator -(const position& p, const position& q){
    return position (p.x-q.x, p.y-q.y);
};

mob::mob(int x0, int y0, char symbol, int PV):x(x0), y(y0), symbol(symbol), PV(PV){}

int mob::get_x() const {return this->x;};
int mob::get_y() const {return this->y;};


snake::snake(int x, int y ): mob(x, y, 'S', 5){}

bool snake::move(){
    int xp = get_player_x(); int yp = get_player_y();
    int xd = xp-this->x; int yd = yp-this->y;
    if(xd<0&& alvaliable (position(this->x-1, this->y))){
        this->x--; return true;
    }else if (xd>0&& alvaliable (position(this->x+1, this->y))){
        this->x++; return true;
    } else if(yd<0&& alvaliable (position(this->x, this->y-1))){
        this->y--; return true;
    }else if (yd>0&& alvaliable (position(this->x, this->y+1))){
        this->x++;return true;
    }
    return false;
}

