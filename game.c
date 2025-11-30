
#include <stdlib.h>
#include <time.h>
#include "game.h"

// Generates a random 4-digit secret code.
void generate_secret_code(int code[]) {
    // Seed the random number generator only once.
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }
    
    // Generate 4 random digits (0-9).
    for (int i = 0; i < CODE_LENGTH; i++) {
        code[i] = rand() % 10;
    }
}

// Compares the user's guess against the secret code to calculate the report.
void evaluate_guess(const int secret[], const int guess[], int *correct_pos, int *correct_val) {
    // Reset counters for the current guess.
    *correct_pos = 0;
    *correct_val = 0;

    // Local arrays to track used digits (to prevent double-counting).
    int secret_used[CODE_LENGTH] = {0};
    int guess_used[CODE_LENGTH] = {0};

    // 1. Check for Green (Correct position AND value)
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess[i] == secret[i]) {
            *correct_pos += 1;
            secret_used[i] = 1;
            guess_used[i] = 1;
        }
    }

    // 2. Check for Yellow (Correct value, wrong position)
    for (int i = 0; i < CODE_LENGTH; i++) {
        // Skip digits already counted as Green.
        if (guess_used[i]) continue;

        for (int j = 0; j < CODE_LENGTH; j++) {
            // Skip secret digits already counted as Green or already matched as Yellow.
            if (secret_used[j]) continue;

            // Check if value matches.
            if (guess[i] == secret[j]) {
                *correct_val += 1;
                secret_used[j] = 1; // Mark the secret digit as used.
                break; // Move to the next guess digit.
            }
        }
    }
}
