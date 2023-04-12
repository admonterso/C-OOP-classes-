#include <ncurses.h>
#include <unistd.h> // For usleep() function
int x = 0, y = 0;
int timer = 0;  // Timer to track elapsed time

int rows, columns;
int ch;
#define CHARACTER_WIDTH 3
#define CHARACTER_HEIGHT 2
#define fallInterval 1000 // Time interval for automatic falling (in microseconds)

char gameCharacter[CHARACTER_HEIGHT][CHARACTER_WIDTH] = {
    {'@', ' ', ' '},
    {'@', '@', '@'},

};
char gameCharacter1[CHARACTER_HEIGHT][CHARACTER_WIDTH] = {
    {' ', '@', ' '},
    {'@', '@', '@'},

};
void drawGameCharacter(int y, int x, char gameCharacter[CHARACTER_HEIGHT][CHARACTER_WIDTH], int rows, int columns)
{
    for (int i = 0; i < CHARACTER_HEIGHT; i++)
    {
        for (int j = 0; j < CHARACTER_WIDTH; j++)
        {
            int new_y = y + i;
            int new_x = x + j;
            if (new_y >= 0 && new_y < rows && new_x >= 0 && new_x < columns)
            {
                mvaddch(new_y, new_x, gameCharacter[i][j]);
            }
        }
    }
}

void buildTerarian(int rows, int columns, char** Terarian){
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<columns; j++){
                
                        mvaddch(i,j,Terarian[i][j]);
                        
                }
            }
    }
char** startTerarian(int rows, int columns){
    char** array = new char*[rows];
    for (char i = 0; i < rows; i++) {
        array[i] = new char[columns];
    }

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<columns; j++){
            if(j == columns/3 || i == rows-1 && j <= columns/3 || j==0){
                mvaddch(i,j,'#');
                array[i][j] = '#';
                }
            else{
                array[i][j] = ' ';
            }
        }
    }
    return array;
}
               
int main()
{
    
   
    
    initscr();          /* Start curses mode */
    noecho();           /* Don't echo user input */
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, rows, columns);


    timeout(100); // Set getch() to non-blocking mode
    char** terarian =  startTerarian(rows, columns);
    while ((ch = getch()) != 27)
    {
        clear();
        buildTerarian(rows, columns, terarian);
        drawGameCharacter(y, x, gameCharacter1, rows, columns);
        // if(y == rows - 3){
        //     x = 0; 
        //     y = 0;
        //     printw("-------------rows:%d-------------", rows);
        //     //drawGameCharacter(y, x, gameCharacter1, rows, columns);
        // }
        
        //printw("-------------------%c----------",Terarian[0][0]);
        // Check if it's time to make the character fall
        if (timer >= fallInterval )
        {
            if (y <= rows - 4)
            {
                y++;
            }
            timer = 0; // Reset timer
        }

        // Process user input
        if (ch == KEY_UP && y >= 1)
        {
            y--;
        }
        else if (ch == KEY_DOWN && y <= rows - 4)
        {
            y++;
        }
        else if (ch == KEY_LEFT && x >= 2)
        {
            x--;
        }
        else if (ch == KEY_RIGHT && x < columns/3-3)
        {
            x++;
        }

        timer += 150; // Update timer with elapsed time
    }

    endwin(); /* End curses mode */

    return 0;
}
