#include <ncurses.h>
#include <unistd.h> // For usleep() function

int x = 0, y = 0;
int timer = 0;  // Timer to track elapsed time
int score = 0;
int rows, columns;
int ch;
#define CHARACTER_WIDTH 3
#define CHARACTER_HEIGHT 2
#define fallInterval 1000 // Time interval for automatic falling (in microseconds)
bool stat = 0;
char gameCharacter[CHARACTER_HEIGHT][CHARACTER_WIDTH] = {
    {'@', ' ', ' '},
    {'@', '@', '@'},

};
char gameCharacter1[CHARACTER_HEIGHT][CHARACTER_WIDTH] = {
    {' ', '@', ' '},
    {' ', '@', '@'},

};
void drawGameCharacter(int y, int x, char gameCharacter[CHARACTER_HEIGHT][CHARACTER_WIDTH], int rows, int columns)
{
    mvprintw(6, 5, "x: %d", x); // Print the value of x
    mvprintw(7, 5, "y: %d", y);
    mvprintw(8, 5, "S: %d", score); 
    mvprintw(4, 5, "R: %d", rows);
    mvprintw(5, 5, "C: %d", columns);
    if(stat == 1){ 
        score++;
        stat = 0;
    }
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
void buildTerarian(int rows, int columns, char** Terarian){ //prints 2 dimetional arra
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
void insertArray(char** mainTerarian, int y, int x, char insertObject[2][3]) {
    for (int i = 0; i < CHARACTER_HEIGHT; i++) {
        for (int j = 0; j < CHARACTER_WIDTH; j++) {
            mainTerarian[y + i][x + j] = insertObject[i][j];
        }
    }
}               
bool checkScore(char arr[], int columns)
{
    int count = 0; // Reset count to 0 for each row
    for (int i = 0; i < columns; i++) // Include first and last elements of row
    {
        if (arr[i] == '@') // Use function argument 'ch' instead of hardcoding '@'
        {
            count++;
        }
        if (count >= columns-1)
        {
            return true;
        }
    }
    return false;
}
void empty2DArray(char** Array, int rows, int columns){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if(j == columns/3 || i == rows-1 && j <= columns/3 || j==0){
                Array[i][j] = '#';
                }
           else{
                Array[i][j] = ' ';
            }

        }
    }
}
bool chechCollosion(char** Matrix, int X, int Y, int rows, int columns){
    if (
        X-2 >= 0 && Matrix[Y][X-2] == '@' || 
        Y+2 >= 0 && Matrix[Y+2][X] == '@' ||
        Y+2 >= 0 && Matrix[Y+2][X+1] == '@'||
        Y+2 >= 0 && Matrix[Y+2][X+2] == '@' ){
        return false;
    }
    else{
        return true;
    }
}
int main()
{
    
   
    
    initscr();          /* Start curses mode */
    noecho();           /* Don't echo user input */
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, rows, columns);
    char (*obj)[3] = gameCharacter;
    
    bool bottom = 0;
    timeout(100); // Set getch() to non-blocking mode
    char** terarian =  startTerarian(rows, columns);
    char** matrixForUpdate =  startTerarian(rows, columns);
    x = columns/3/2;
    while ((ch = getch()) != 27)
    {
        
        clear();
         // Print the value of y
        buildTerarian(rows, columns, terarian);
        
        drawGameCharacter(y, x, gameCharacter1, rows, columns);
        
        
       bool checkCol = chechCollosion(terarian, x, y, rows, columns);
        mvprintw(3, 5, "A: %d", checkCol);
        // Check if it's time to make the character fall
        if (timer >= fallInterval )
        {
            
            if (y <= rows - 4 && checkCol == true)
            {
                y++;
                empty2DArray(matrixForUpdate, rows, columns);
                insertArray(matrixForUpdate, y, x, obj);
                bottom = 0;
            }
            else{
                bottom = 1;
            }
            timer = 0; // Reset timer
        }
        if(bottom == 1 || checkCol == false){
            
            insertArray(terarian, y, x, obj);
            bool check = checkScore(terarian[y+1], columns/3);
            if(check){
                stat = 1;
            }
            x = columns/3/2;
            y = 0;
            bottom = 0;

        }
        // Process user input
        if (ch == KEY_UP && y >= 1)
        {
            y--;
            
        }
        else if (ch == KEY_DOWN && y <= rows - 4)
        {
            checkCol = chechCollosion(terarian, x, y, rows, columns);
            if(checkCol == true){
               y++; 
            }
            
            
            
        }
        else if (ch == KEY_LEFT && x >= 2)
        {
            checkCol = chechCollosion(terarian, x, y, rows, columns);
            if(checkCol == true){
                x--; 
            }
           
            
            
        }
        else if (ch == KEY_RIGHT && x < columns/3-3)
        {
            checkCol = chechCollosion(terarian, x, y, rows, columns);
            if(checkCol == true){
               x++; 
            }
           
            
        }
        
        timer += 150; // Update timer with elapsed time
        for(int a = 0; a < columns; a++)
        {
            for(int b = 0; b < rows+rows+rows+1; b++)
            {
            mvaddch(a, b+50, matrixForUpdate[a][b]);
            }
            
        } 
    }

    endwin(); /* End curses mode */

    return 0;
}
