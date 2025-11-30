#  Mastermind Game - C Implementation

This project is a command-line application that implements the classic code-breaking game **Mastermind**. It was developed entirely in the **C programming language**.

The code is structured based on **Modular Programming** principles, separating concerns to ensure clean, readable, and maintainable source files.

---

##  Key Features

* **Modular Design:** The project is logically divided into separate files for specific roles:
    * `main.c`: Manages the main game loop (`do/while` structure) and user interaction flow.
    * `game.c`: Contains the core game logic (code generation and the `evaluate_guess` function).
    * `io.c`: Handles Input/Output operations (displaying instructions and screen clearing).
    * `game.h` (Used as Header File): Contains all necessary constants (like `CODE_LENGTH`, `MAX_ATTEMPTS`) and function declarations.
* **Color Feedback:** Uses **ANSI Escape Codes** to provide clear, visual feedback (Green, Yellow, Red) to the user on their guesses.
* **Robust Input Handling:** Employs safe input reading methods (`fgets`) to ensure the stability of the program when reading the player's name and guesses.

---

##  How to Compile and Run

To compile and run this program, you will need a standard C compiler (like GCC or the one integrated into Code::Blocks).

1.  Gather all source files (`main.c`, `game.c`, `io.c`) and the header file (`game.h`).
2.  Compile and link all files together.
3.  Run the executable from the console.