#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


void main(){
    srand(time(NULL));
    WINDOW *win = initscr();
    keypad(win, true);
    nodelay(win, true);
    curs_set(0);
    int posX = COLS / 2;
    int posY = LINES / 2;
    int chaserX = rand() % COLS;
    int chaserY = rand() % LINES;
    int chaser2X = rand() % COLS;
    int chaser2Y = rand() % LINES;
    int chaser3X = rand() % COLS;
    int chaser3Y = rand() % LINES;
    int dirX = 1;
    int dirY = 0;
    
    while (true){
        int pressed = wgetch(win);
        if (pressed == KEY_LEFT){
            dirX = -4;
            dirY = 0;
        } 
        if (pressed == KEY_RIGHT){
            dirX = 4;
            dirY = 0;
        } 
        if (pressed == KEY_UP){
            dirX = 0;
            dirY = -4;
        }
        if (pressed == KEY_DOWN){
            dirX = 0;
            dirY = 4;
        }
        posX += dirX;
        posY += dirY;

        if (posX < 0) posX = 0;
        if (posX >= COLS) posX = COLS - 1;
        if (posY < 0) posY = 0;
        if (posY >= LINES) posY = LINES - 1;

        if (chaserX < posX) chaserX++;
        else if (chaserX > posX) chaserX--;
        if (chaserY < posY) chaserY++;
        else if (chaserY > posY) chaserY--;

        if (chaser2X < posX) chaser2X++;
        else if (chaser2X > posX) chaser2X--;
        if (chaser2Y < posY) chaser2Y++;
        else if (chaser2Y > posY) chaser2Y--;

        if (chaser3X < posX) chaser3X++;
        else if (chaser3X > posX) chaser3X--;
        if (chaser3Y < posY) chaser3Y++;
        else if (chaser3Y > posY) chaser3Y--;

        erase();
        mvaddstr(posY, posX, "*");
        mvaddstr(chaserY, chaserX, "#");
        mvaddstr(chaser2Y, chaser2X, "#");
        mvaddstr(chaser3Y, chaser3X, "#");
        if (chaserX == posX && chaserY == posY){
            mvaddstr(LINES / 2, (COLS - 9) / 2, "Game Over");
            refresh();
            usleep(2000000);
            break;
        }
        usleep(100000);
    }
    endwin();
}