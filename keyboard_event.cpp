#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <cstdio>
#include <ctime>

static const int STDIN = 0;
static bool initialized = false;

void backgroundClear() {
  int out = system("clear");
  if (out != 0) {
    std::cerr << "clear command failed" << std::endl;
    exit(3);
  }
}


int keyEvent(){
    if(!initialized){
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }
    int bytesWaiting = 0;
    while(!bytesWaiting && ioctl(STDIN, FIONREAD, &bytesWaiting) >= 0){}
    return bytesWaiting;
}

void sleepOneLap(const int ms){
  clock_t end;
  end = clock() + ms * CLOCKS_PER_SEC / 1000;
  while (clock() < end){}
}