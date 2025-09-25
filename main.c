/* /main.c – top‑level menu that calls other modules as functions
 *
 * Compile (single executable):
 *   gcc -o myapp main.c \
 *       percentage/menu.c \
 *       percentage/percentageCalc.c \
 *       percentage/momsCalc.c \
 *       file2.c \
 *  -lm
 *
 * Only this file contains `int main(void)`.  All other source files
 * provide ordinary functions that are linked into the same binary.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>

/* ------------------------------------------------------------------ */
/* Prototypes of the functions defined in the other source files      */
#include "percentage/menu.h"      /* declares: void percentage_menu(void); */
#include "square/menu.h"                /* declares: void apply_factor(void);   */

/* ------------------------------------------------------------------ */
/* Simple getch implementation for Unix‑like systems */
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
static void show_menu(void) {
    printf("\n=== Main Menu ===\n");
    printf("1 – Percentage menu\n");
    printf("2 – Square menu\n");
    printf("R – Return to menu (after a child process ends)\n");
    printf("ESC – Exit\n");
    printf("Select an option: ");
    fflush(stdout);
}

/* ------------------------------------------------------------------ */
int main(void) {
    int running = 1;
    while (running) {
        show_menu();
        int ch = getch();
        printf("%c\n", ch);               /* echo the key */

        switch (toupper(ch)) {
            case '1':
                printf("Launching percentage menu...\n");
                percentage_menu();        /* call submenu directly */
                break;

            case '2':
                printf("Launching factor calculator...\n");
                square_menu();           /* call file2's function */
                break;

            case 'R':
                /* nothing – loop will redisplay the menu */
                break;

            case 27:   /* ESC */
                printf("Exiting program.\n");
                running = 0;
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
