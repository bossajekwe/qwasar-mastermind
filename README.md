
# Welcome to My Mastermind
## Task
The Task was to design a mastermind game.

# Description
For the implementation of the Mastermind game, I've developed a set of seven functions encapsulated within the `mastermind.h` header file. These functions encompass:

1. `void generateSecretCode(char* SecretCode)`: This function is tasked with generating random and distinct 4-digit passcodes.

2. `int getInput(char *guess)`: Responsible for retrieving input from the user.

3. `int is_valid_input(char* guess)`: Validates the entered guess to ensure it's not repeated or contains letters.

4. `int countWellPlaced(char* secretCode, char* userInput)`: Calculates the count of digits in the passcode that are correctly positioned.

5. `int countMisplaced(char* secretCode, char* userInput)`: Counts the number of digits present in the passcode but not positioned correctly.

6. `void checkInput(char* secretCode, char* userInput, int* wellPlaced, int* misplaced)`: This function invokes both `countWellPlaced` and `countMisplaced` to assess the user input.

7. `void printFeedback(int wellPlaced, int misplaced)`: Displays the values of `countWellPlaced` and `countMisplaced` in standard output.

Through the synergy of these meticulously crafted functions, the Mastermind game is brought to life, delivering an engaging and interactive experience for players.

# Installation
the executable file can be downloaded and run from your local machine.

# Usage
The Mastermind game is a coding-based activity designed for two players, namely yourself and a computer program. Originally played with the task of guessing the arrangement of four distinct colors—either randomly generated or established by the first player—the C implementation of this game utilizes unique numbers to represent these colors.

1. To initiate the game on your local machine, enter the command `make` in your terminal.
2. Setting the distinct password involves using either `./mastermind -c 1234` or simply `./mastermind` to generate a random password.
3. At this juncture, the game becomes active, requiring you to input a valid 4-digit passcode to progress to the next round. You're allotted 10 attempts for each valid code.
4. With each attempt, you'll receive feedback indicating the count of digits correctly placed and those in an incorrect order.
5. The game continues until you successfully guess the correct password or employ keyboard shortcuts like `ctrl + d` or `ctrl + c` to exit the game.



# The Core Team
Ajekwe Moses Zanzan