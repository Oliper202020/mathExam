/* percentage/menu.c – submenu that calls the two calculators directly */
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>

/* prototypes of the functions we will call */
#include "percentageCalc.h"   /* void percentage_calc(void); */
#include "vatCalc.h"        /* void vat_calc(void); */
#include "menu.h"            /* declares percentage_menu(void) */
#include "wholeFromPartCalc.h"
#include "partToProcentCalc.h"

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
    printf("\n=== Percentage Menu ===\n");
    printf("1 – Run percentage calculator\n");
    printf("2 – Run whole from part calculator\n");
    printf("4 – Run vat calculator\n");
    printf("R – Return to main menu\n");
    printf("ESC – Exit\n");
    printf("Select an option: ");
    fflush(stdout);
}

/* ------------------------------------------------------------------ */
void percentage_menu(void) {          /* public entry point */
    int running = 1;
    while (running) {
        show_submenu();
        int ch = getch();
        printf("%c\n", ch);

        switch (toupper(ch)) {
            case '1':
                percentage_calc();   /* from percentageCalc.c */
                break;
            case '2':
                wholeFromPartCalc();         /* from vatCalc.c */
                break;
            case '3':
                vat_calc();         /* from vatCalc.c */
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
