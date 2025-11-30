
#ifndef GAME_H
#define GAME_H

// Game Constants
#define CODE_LENGTH 4       // The length of the secret code (4 digits)
#define MAX_ATTEMPTS 10     // The maximum number of guesses allowed
#define MAX_NAME_LENGTH 50

// ANSI Escape Codes for Terminal Colors
#define REST   "\x1b[0m"    // Resets the color to default
#define RED    "\x1b[31m"    // Red color for wrong values/positions
#define GREEN  "\x1b[32m"    // Green color for correct position
#define YELLOW "\x1b[33m"    // Yellow color for correct value, wrong position

// Function Prototypes (Declarations)
// Generates a random 4-digit secret code.
void generate_secret_code(int code[]);

// Compares the user's guess against the secret code to calculate the report.
void evaluate_guess(const int secret[], const int guess[], int *correct_pos, int *correct_val);

// Clears the console screen.
void clear_screen();

// Displays the game rules and color codes.
void display_instructions(const char* name);

#endif // GAME_H
