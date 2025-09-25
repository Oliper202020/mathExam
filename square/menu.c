/* square/menu.c – submenu that calls the two calculators directly */
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>
#include "rootCalc.h"
#include "squareCalc.h"

/* ------------------------------------------------------------------ */
static int getch(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    /* read first non‑newline character */
    do {
        ch = getchar();
    } while (ch == '\n');

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

/* ------------------------------------------------------------------ */
static void show_submenu(void) {
    printf("\n=== Square Menu ===\n");
    printf("1 – Run square calculator\n");
    printf("2 – Run square root calculator\n");
    printf("R – Return to main menu\n");
    printf("ESC – Exit\n");
    printf("Select an option: ");
    fflush(stdout);
}

/* ------------------------------------------------------------------ */
void square_menu(void) {          /* public entry point */
    int running = 1;
    while (running) {
        show_submenu();
        int ch = getch();
        printf("%c\n", ch);

        switch (toupper(ch)) {
            case '1':
                square_calc();
                break;
            case '2':
                root_calc();
                break;
            case 'R':
                running = 0;         /* return to caller (main menu) */
                break;
            case 27:   /* ESC */
                running = 0;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
