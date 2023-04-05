#include <ncurses.h>

int main() {
    int x = 0, y = 0;
    int ch;
    int rows, columns;
    initscr();          /* Start curses mode */
    noecho();           /* Don't echo user input */
    keypad(stdscr, TRUE);/* Enable arrow keys */
    getmaxyx(stdscr, rows, columns);
    while (1) {
        clear();        /* Clear the screen */
        curs_set(false);
        /* Draw the character at the current position */
        mvaddch(y, x, '@');
        mvprintw((rows - 1), (columns - 50), "rows: %d  columns: %d", rows, columns);

        mvprintw((rows - 1), (columns - 15), "X: %d  Y: %d", x, y);
        curs_set(true);

        /* Wait for user input */
        ch = getch();

        /* Move the character based on user input */
            if (ch == KEY_UP && y >= 1) {
                y--;
            } else if (ch == KEY_DOWN && y <= rows - 3) {
                y++;
            } else if (ch == KEY_LEFT && x >=1) {
                x--;
            } else if (ch == KEY_RIGHT && x<columns - 1) {
                x++;
            } else if (ch == 27) { /* Exit if user presses 'Esc' key */
                goto END;
            }
    }

END:
    endwin();           /* End curses mode */

    return 0;
}
