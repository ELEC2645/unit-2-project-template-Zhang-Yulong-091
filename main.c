#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcs.h"

/* Prototypes used only inside main.c */
static void main_menu(void);          /* runs in the main loop          */
static void print_main_menu(void);    /* output the main menu text      */
static int  get_user_input(void);     /* get a valid integer menu choice*/
static void select_menu_item(int);    /* dispatch based on user's choice*/
static int  is_integer(const char*); /* validate integer string        */

int main(void)
{
    /* main loop: will run until Exit is selected */
    for (;;) {
        main_menu();
    }

    /* not reached */
    return 0;
}

static void main_menu(void)
{
    int input;

    print_main_menu();
    input = get_user_input();
    select_menu_item(input);
}

static void print_main_menu(void)
{
    printf("\n-------------- Main menu --------------\n\n");
    printf("\t1. Linear algebra library\n");
    printf("\t2. Basic statistical tools\n");
    printf("\t3. Simple electrical circuit\n");
    printf("\t4. Simple calculator\n");
    printf("\t5. Query assistant\n");
    printf("\t6. Exit\n");
    printf("---------------------------------------\n");
}

/* Read a valid integer choice between 1 and MENU_ITEMS (6) */
static int get_user_input(void)
{
    enum { MENU_ITEMS = 6 };
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        /* strip trailing newline */
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Please enter an integer!\n");
            valid_input = 0;
        }
        else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            }
            else {
                printf("Invalid menu item! Please choose 1-%d.\n", MENU_ITEMS);
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

static void select_menu_item(int input)
{
    switch (input) {
    case 1:
        menu_linear_algebra();
        break;
    case 2:
        menu_statistics();
        break;
    case 3:
        menu_circuit();
        break;
    case 4:
        menu_calculator();
        break;
    case 5:
        menu_query_assistant();
        break;
    case 6:
    default:
        printf("Bye!\n");
        exit(0);
    }
}

/* Return 1 if s is an optional +/- followed by one-or-more digits, else 0. */
static int is_integer(const char* s)
{
    if (!s || !*s) return 0;

    /* optional sign */
    if (*s == '+' || *s == '-') s++;

    /* must have at least one digit */
    if (!isdigit((unsigned char)*s)) return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}