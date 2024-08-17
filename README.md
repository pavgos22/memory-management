# Memory management in C

This C program simulates a system for managing and manipulating a set of poles and discs. It allows users to add discs to poles, move discs between poles, and display the current state of the poles. The program tracks how many times each disc has been moved. This project is a simplified implementation that somewhat mimics the Tower of Hanoi problem.

## Data Structures

### Disc
A structure representing a disc with the following fields:
- **`char* str`**: A dynamically allocated string holding the disc's text (up to 20 characters).
- **`int n_moved`**: An integer tracking how many times the disc has been moved between poles.

### Pole
A structure representing a pole with the following fields:
- **`int n_discs`**: An integer tracking the current number of discs on the pole.
- **`Disc* discs[20]`**: An array of pointers to `Disc` structures. Each pole can hold up to 20 discs.

## Core Functions

### `move_disc(Pole** poles, int i, int j)`
Moves the top disc from pole `i` to pole `j`. The function:
- Checks if the move is possible, i.e., the destination pole is not full, and the source pole is not empty.
- If the move is within the same pole (`i == j`), it increments the move count without transferring the disc.
- Updates the disc count on both poles and frees the memory associated with the moved disc from the source pole.

### `copystr(char* s2, char* s1)`
Copies the content of the string `s1` into `s2`. This function is a simple implementation of the `strcpy` function.

### `add_disc(Pole** poles, int i, char* c)`
Adds a new disc with the text `c` to the pole at index `i`. The function:
- Allocates memory for the disc and its text if necessary.
- Increments the disc count for the pole.

## Main Functionality

### Initialization
- The program begins by asking the user to input the number of poles (`n_poles`).
- It dynamically allocates an array of `Pole` structures based on this input.
- Each pole is initialized with zero discs, and memory is allocated for up to 20 discs per pole.

### User Input and Actions
The program enters a loop where it accepts commands from the user:
- **`A i disc_text`**: Adds a new disc with `disc_text` to the pole at index `i`. If the pole is full, it prints `x`.
- **`M i j`**: Moves the top disc from pole `i` to pole `j`. If the move is impossible, it prints `!`.
- **`P`**: Prints the current state of all poles, listing discs from top to bottom along with their move count.
- **`Q`**: Exits the program, cleaning up all allocated memory.

### Memory Management
- The program ensures that all dynamically allocated memory is freed before it exits. This includes the memory for each disc and each pole.
