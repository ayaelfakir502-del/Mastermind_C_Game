
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"

// Helper function to remove the newline character left by fgets.
void remove_newline(char *s) {
    s[strcspn(s, "\n")] = 0;
}

int main() {
    char name[MAX_NAME_LENGTH];
    int play_again = 0;

    // 1. INITIAL SETUP (Outside the Loop)

    // Read user's name safely (only asks once).
    printf("Welcome to the Mastermind challenge! What is your name? ");
    if (fgets(name, sizeof(name), stdin) != NULL) {
        remove_newline(name);
    } else {
        strcpy(name, "Player");
    }

    // Display initial instructions (only once).
    display_instructions(name);

    printf("\nPress ENTER to start the challenge, %s...", name);
    // Use getchar() to wait for ENTER, handling any pending newline if necessary.
    getchar();
    clear_screen();

    // 2. MAIN GAME LOOP (do/while)
    do {
        int secret_code[CODE_LENGTH];
        char guess_input[CODE_LENGTH + 2];
        int guess[CODE_LENGTH];

        int attempts = 0;
        int is_game_won = 0;
        int correct_pos = 0;
        int correct_val = 0;
        char choice[5]; // To read the user's choice (1 or any other input)

        // Generate a new secret code for EACH game iteration.
        generate_secret_code(secret_code);

        // --- Inner Loop (Attempts) ---
        while (attempts < MAX_ATTEMPTS && !is_game_won) {
            attempts++;

            printf("\n--- Attempt %d of %d ---\n", attempts, MAX_ATTEMPTS);

            // Get User Guess Safely
            printf("Enter your 4-digit guess: ");

            if (fgets(guess_input, sizeof(guess_input), stdin) == NULL || strlen(guess_input) < CODE_LENGTH + 1) {
                 printf("%sError: Invalid input. Please enter exactly 4 digits!%s\n", RED, REST);
                 attempts--;
                 continue;
            }

            // Convert input string to integer array
            for (int i = 0; i < CODE_LENGTH; i++) {
                // Validate if input is a digit
                if (guess_input[i] < '0' || guess_input[i] > '9') {
                    printf("%sError: Input must contain only digits (0-9).%s\n", RED, REST);
                    attempts--;
                    goto end_guess; // Skip evaluation and repeat attempt
                }
                guess[i] = guess_input[i] - '0';
            }

            // Evaluate the guess
            evaluate_guess(secret_code, guess, &correct_pos, &correct_val);

            // Check for Win and display detailed, colored feedback
            if (correct_pos == CODE_LENGTH) {
                is_game_won = 1;
                printf("%sCONGRATULATIONS, %s! You cracked the code in %d attempts!%s\n", GREEN, name, attempts, REST);
            } else {
                int red_count = CODE_LENGTH - (correct_pos + correct_val);

                printf("Report: ");
                printf("%s%d Green%s, ", GREEN, correct_pos, REST);
                printf("%s%d Yellow%s, ", YELLOW, correct_val, REST);
                printf("%s%d Red%s.\n", RED, red_count, REST);
            }

            end_guess:; // Label for goto to handle invalid input
        } // End of attempts loop

        // 3. End Game Result
        if (!is_game_won) {
            printf("\n%sGAME OVER! You ran out of attempts.%s\n", RED, REST);
            printf("The secret code was: %d%d%d%d\n", secret_code[0], secret_code[1], secret_code[2], secret_code[3]);
        }

        // Ask user to play again
        printf("\nDo you want to play again? Enter '1' for YES, or any other key for NO: ");
        if (fgets(choice, sizeof(choice), stdin) != NULL) {
            remove_newline(choice);
            if (choice[0] == '1' && choice[1] == '\0') {
                play_again = 1;
                clear_screen(); // Clear screen for the next round
            } else {
                play_again = 0;
            }
        } else {
            play_again = 0;
        }

    } while (play_again == 1); // Continues if user enters '1'

    // 4. Final Thank You Message (Outside the loop)
    printf("\nThank you for playing, %s! Your partner Mastermind appreciates your effort.%s\n", name, REST);

    return 0;
}
