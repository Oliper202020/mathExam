/* menu.c – simple console menu (POSIX‑only version)
 *
 * Compile:  gcc -o menu menu.c
 *
 * The program shows a menu:
 *   1 – run file1 (executable ./file1)
 *   2 – run file2 (executable ./file2)
 *   R – return to the menu after a child process ends
 *   ESC – exit
 *
 * Only this file is provided; the other source files (file1.c, file2.c)
 * should be compiled separately to executables named `file1` and `file2`.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>

/* Simple getch implementation for Unix-like systems */
static int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);   /* disable buffering and echo */
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void show_menu(void) {
    printf("\n=== Main Menu ===\n");
    printf("1 – Percentage\n");
    printf("2 – Run file2\n");
    printf("R – Return to menu (after a program finishes)\n");
    printf("ESC – Exit\n");
    printf("Select an option: ");
    fflush(stdout);
}

int main(void) {
    int running = 1;
    while (running) {
        show_menu();
        int ch = getch();

        /* Echo the pressed key for user feedback */
        printf("%c\n", ch);

        switch (toupper(ch)) {
            case '1':
                printf("Launching percentage calculator...\n");
                (void)system("./percentage/menu");
                break;
            case '2':
                printf("Launching file2...\n");
                (void)system("./file2");
                break;
            case 'R':
                printf("restarting...\n");
                /* No action needed – loop will redisplay the menu */
                break;
            case 27:   /* ESC key ASCII code */
                printf("Exiting program.\n");
                running = 0;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
