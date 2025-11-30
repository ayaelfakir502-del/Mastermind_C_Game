
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

// Clears the console screen (Windows/Linux/macOS compatible).
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Displays instructions and welcome message.
void display_instructions(const char* name) {
    clear_screen();
    printf("%sWelcome to the Mastermind challenge, %s!%s\n", GREEN, name, REST);
    printf("The rules are simple: Guess the 4-digit secret code in %d tries.\n", MAX_ATTEMPTS);
    printf("--------------------------------------------------\n");
    printf("%sGAME INSTRUCTIONS:%s\n", YELLOW, REST);
    printf("- %sGreen%s: Position and value are correct.\n", GREEN, REST);
    printf("- %sYellow%s: Value is correct, but position is wrong.\n", YELLOW, REST);
    printf("- %sRed%s: Value and position are wrong.\n", RED, REST);
    printf("--------------------------------------------------\n");
}

