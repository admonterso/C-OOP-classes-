#include <ncurses.h>
char Map [120][120];
int x = 11, y = 4;
int Move(char c){
   if   (c == KEY_UP    && Map[y-1][x] == ' ') y--;
        else if(c == KEY_DOWN  && Map[y+1][x] == ' ') y++;
        else if(c == KEY_LEFT  && Map[y][x-1] == ' ') x--;
        else if(c == KEY_RIGHT && Map[y][x+1] == ' ') x++;  
        mvaddch(y, x, '@');
        return 0;

}
int dungeon(int rows, int cols){
    for(int yy = 0; yy<=rows; yy++){
        for(int xx = 0; xx<=cols; xx++){
            mvaddch(yy,xx,'#');
            Map [yy][xx] = '#';
        }
    }

    for(int yy = 4; yy<=rows/2; yy++){
        for(int xx = 10; xx<=cols/2; xx++){
            mvaddch(yy,xx,' ');
                Map [yy][xx] = ' ';
        }
    }
return 0;

}
int main() {
    int c;
    int cols, rows;
    
    
    initscr();          /* Start curses mode */

        keypad(stdscr, TRUE); // allow arrows (not only) 
        noecho(); // dont display input 
        
        curs_set(0);
        getmaxyx(stdscr, rows, cols);
        do{
            dungeon(rows, cols); 
            Move(c);
        }while((c = getch()) != 27); //27 == ESC
        
        
    
    endwin();           /* End curses mode */

    return 0;
}