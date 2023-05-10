//the folowind code with its commit history you can see on my hithub account https://github.com/admonterso/C-OOP-classes-/tree/main/ncurses 
// command for compilation is "g++ ncurses.cpp -o pr1 -lncurses"
// his code is not finished and has some bugs in it... sorry for that. I do not used OOP becouse I forgot and currently do not have time to change something
// thank you in advance 
#include <ncurses.h>
#include <unistd.h> // For usleep() function
#include <random>
int x = 0, y = 0;
int timer = 0;  // Timer to track elapsed time
int score = 0;
int rows, columns;
int ch;
int insideValue;
#define CHARACTER_WIDTH 3
#define CHARACTER_HEIGHT 2
#define fallInterval 1000 // Time interval for automatic falling (in microseconds)
bool stat = 0;
bool isDivisibleByThree(int value) {
  
    int sum = 0;
    while (value != 0) {
        sum += value % 10;  // Extract the last digit and add it to the sum
        value /= 10;  // Remove the last digit
    }
    
    return sum % 3 == 0;  // Return true if sum is divisible by 3, false otherwise
}
char gameCharacter[CHARACTER_HEIGHT][CHARACTER_WIDTH] = {
    {'@', ' ', ' '},
    {'@', '@', '@'},
};
char gameCharacter1[CHARACTER_HEIGHT][CHARACTER_WIDTH] = {
    {' ', '@', ' '},
    {'@', '@', '@'},
};
char gameCharacter2[CHARACTER_HEIGHT][CHARACTER_WIDTH] = {
    {' ', ' ', '@'},
    {'@', '@', '@'},
};
void drawGameCharacter(int y, int x, char gameCharacter[CHARACTER_HEIGHT][CHARACTER_WIDTH], int rows, int columns)
{
    mvprintw(6, 50, "x: %d", x); // Print the value of x
    mvprintw(7, 50, "y: %d", y);
    mvprintw(8, 50, "S: %d", score); 
    mvprintw(4, 50, "R: %d", rows);
    mvprintw(5, 50, "C: %d", columns);
    mvprintw(1, 50, "X: %d", insideValue);
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
    insideValue = columns/4;
    while(isDivisibleByThree(insideValue)== false){
        insideValue--;
    }
    insideValue+=1;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<columns; j++){
            if(j == insideValue || i == rows-1 && j <= insideValue || j==0){
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
int chechCollosion(char** Matrix, int x, int y, int rows, int columns){
    if ((y + 1 >= 0 && Matrix[y + 2][x] == '@') ||
        (y + 1 >= 0 && Matrix[y + 2][x + 1] == '@') ||
        (y + 1 >= 0 && Matrix[y + 2][x + 2] == '@')) {
        return 0; // Collision with '@' detected below
    } else if ((x >= 0 && Matrix[y][x - 1] == '@') ||
               (x >= 0 && Matrix[y][x + 3] == '@')) {
        return 2; // Collision with '@' detected on left or right
    } else {
        return 1; // No collision detected
    }
}
bool checkEndGame(char** Matrix, int rows, int columns){
    for(int i = 0; i < columns; i++) {
        if(Matrix[1][i] == '@') {
            return true; // '@' symbol found, game over
        }
    }
    return false; // '@' symbol not found, game continues
}
int generateRandomNumber() {
    std::random_device rd; // Obtain a random seed from the system
    std::mt19937 gen(rd()); // Seed the Mersenne Twister engine with the random device
    std::uniform_int_distribution<int> distribution(1, 3); // Define a uniform distribution from 1 to 2
    return distribution(gen); // Generate and return the random number
}
int generateRandomNumberForSpawn() {
    std::random_device rd; // Obtain a random seed from the system
    std::mt19937 gen(rd()); // Seed the Mersenne Twister engine with the random device
    std::uniform_int_distribution<int> distribution(3, 20); // Define a uniform distribution from 1 to 2
    return distribution(gen); // Generate and return the random number
}
void print_centered_text(int score) {
    // Initialize Ncurses
    clear();
    
    // Set up color pairs
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    // Set a larger font using Ncurses attributes
    attron(COLOR_PAIR(1));
    attron(A_BOLD); // Make text bold
    // Calculate the center position
    int center_y = (LINES - 1) / 2;
    int center_x = (COLS - 7) / 2; // 7 is the length of "THE END"
    // Print the text "THE END" at the center of the screen
    mvprintw(center_y, center_x, "YOU REACHED THE TOP WITH SCORE %d", score);
    attroff(A_BOLD); // Turn off bold attribute
    usleep(1000000);
}
int main()
{
    
   
    
    initscr();          /* Start curses mode */
    noecho();           /* Don't echo user input */
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, rows, columns);
    char (*obj)[3] = gameCharacter;
    char (*obj1)[3] = gameCharacter1;
    char (*obj2)[3] = gameCharacter2;
    bool bottom = 0;
    timeout(100); // Set getch() to non-blocking mode
    char** terarian =  startTerarian(rows, columns);
    x = columns/3/2;
    int rand = generateRandomNumber();
    while ((ch = getch()) != 27)
    {
        
        clear();
         // Print the value of y
        buildTerarian(rows, columns, terarian);
        
        if(rand == 1){
            drawGameCharacter(y, x, gameCharacter1, rows, columns);
        }
        if(rand == 2){
            drawGameCharacter(y, x, gameCharacter, rows, columns);
        }
        if(rand == 3){
            drawGameCharacter(y, x, gameCharacter2, rows, columns);
        }
        
       int checkCol = chechCollosion(terarian, x, y, rows, columns);
       bool checkEnd = checkEndGame(terarian, rows, columns);
       if(checkEnd) {
            print_centered_text(score);
            
            
            
            
       }
        
        // Check if it's time to make the character fall
        if (timer >= fallInterval )
        {
            
            if (y <= rows - 4 && checkCol == 1)
            {
                y++;
                bottom = 0;
            }
            else{
                bottom = 1;
            }
            timer = 0; // Reset timer
        }
        if(bottom == 1 || checkCol == 0){
            if(rand == 1 ){
                insertArray(terarian, y, x, obj1);
            }
            if(rand == 2 ){
                insertArray(terarian, y, x, obj);
            }
            if(rand == 3 ){
                insertArray(terarian, y, x, obj2);
            }
            bool check = checkScore(terarian[y+1], columns/3);
            if(check){
                stat = 1;
            }
            x = generateRandomNumberForSpawn();
            y = 0;
            bottom = 0;
            rand = generateRandomNumber();
        }
        // Process user input
        if (ch == KEY_UP && y >= 1)
        {
            y--;
            
        }
        else if (ch == KEY_DOWN && y <= rows - 4)
        {
            checkCol = chechCollosion(terarian, x, y, rows, columns);
            if(checkCol == 1){
               y++; 
            }
            
            
            
        }
        else if (ch == KEY_LEFT && x >= 2)
        {
            checkCol = chechCollosion(terarian, x, y, rows, columns);
            if(checkCol != 2){
                x--; 
            }
           
            
            
        }
        else if (ch == KEY_RIGHT && x < insideValue-3)
        {
            checkCol = chechCollosion(terarian, x, y, rows, columns);
            if(checkCol != 2){
               x++; 
            }
           
            
        }
        
        timer += 150; // Update timer with elapsed time
       
    }
end:
    endwin(); /* End curses mode */
    return 0;
}