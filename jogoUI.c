#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>

// Function to draw a frame outside a window
void drawFrame(int height, int width, int line, int col);

int main(void) {
    int lin, col, color, exitFlag;
    WINDOW *window;
    char text[11];
    char msg[21];
    int ch;
    const char *output;
    srand(time(NULL));

    initscr();
    start_color();
    erase();
    noecho();
    cbreak();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLUE);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);

    for (int i = 0; i < 125; ++i) {
        lin = rand() % 25;
        col = rand() % 60;
        color = rand() % 3 + 1;
        attron(COLOR_PAIR(color));
        mvaddch(lin, col, 'x');
    }
    refresh();

    attron(COLOR_PAIR(5));
    drawFrame(10, 20, 6, 15);
    window = newwin(10, 20, 6, 15);
    wattrset(window, COLOR_PAIR(4));
    wbkgd(window, COLOR_PAIR(4));
    scrollok(window, TRUE);
    keypad(window, TRUE);
    werase(window);
    wrefresh(window);
    wprintw(window, "Use arrow keys, space, and 'q' to quit\n");
    wrefresh(window);

    exitFlag = 0;
    output = NULL;
    while (exitFlag != 1) {
        ch = wgetch(window);
        switch (ch) {
            case KEY_UP:
                output = "up";
                break;
            case KEY_DOWN:
                output = "down";
                break;
            case KEY_LEFT:
                output = "left";
                break;
            case KEY_RIGHT:
                output = "right";
                break;
            case ' ':
                echo();
                nocbreak();
                wprintw(window, "Enter command: ");
                wrefresh(window);
                wgetstr(window, text); // Use wgetstr to read the string
                if (strncmp(text, "msg ", 4) == 0) {
                    // Process the 'msg' command
                    char nick[11], message[11];
                    if (sscanf(text, "msg %10s %10[^\n]", nick, message) == 2) {
                        // Handle the 'msg' command here
                        sprintf(msg, "Sending message to %s: %s", nick, message);
                        output = msg;
                    } else {
                        output = "Invalid 'msg' command format";
                    }
                } else {
                    output = "Unknown command";
                }
                noecho();
                cbreak();
                break;

            case 'q':
                exitFlag = 1;
                break;
        }
        if (output != NULL) {
            wprintw(window, "%s\n", output);
            output = NULL;
            wrefresh(window);
        }
    }

    endwin();
    return 0;
}

void drawFrame(int height, int width, int line, int col) {
    --line;
    --col;
    height += 2;
    width += 2;

    for (int l = line; l <= line + height - 1; ++l) {
        mvaddch(l, col, '|');
        mvaddch(l, col + width - 1, '|');
    }

    for (int c = col; c <= col + width - 1; ++c) {
        mvaddch(line, c, '-');
        mvaddch(line + height - 1, c, '-');
    }

    mvaddch(line, col, '+');
    mvaddch(line, col + width - 1, '+');
    mvaddch(line + height - 1, col, '+');
    mvaddch(line + height - 1, col + width - 1, '+');
    refresh();
}