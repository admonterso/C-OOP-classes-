#include <ncurses.h>
void moveCharacter(int& x, int& y, int rows, int columns) {
    curs_set(false);
    clear();
    /* Draw the character at the current position */
    mvaddch(y, x, '@');
    mvprintw((rows - 1), (columns - 50), "rows: %d  columns: %d", rows, columns);
    mvprintw((rows - 1), (columns - 15), "X: %d  Y: %d", x, y);
    curs_set(true);

    /* Wait for user input */
    int ch = getch();

    /* Move the character based on user input */
    if (ch == KEY_UP && y >= 1) {
        y--;
    } else if (ch == KEY_DOWN && y <= rows - 3) {
        y++;
    } else if (ch == KEY_LEFT && x >=1) {
        x--;
    } else if (ch == KEY_RIGHT && x<columns - 1) {
        x++;
    }
    else if (ch == 27) {
    }

}
int main() {
    int x = 0, y = 0;
    int rows, columns;
    char c;
    initscr();          /* Start curses mode */
    
    noecho();           /* Don't echo user input */
    
    keypad(stdscr, TRUE);/* Enable arrow keys */
    
    getmaxyx(stdscr, rows, columns);
    

    
    while ((c = getch()) != 27) {
    
    moveCharacter(x, y, rows, columns);

    
}


    endwin();           /* End curses mode */

    return 0;
}