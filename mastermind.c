#include "mastermind.h"

int main(int argc, char* argv[]) {
    char secretCode[10]; // initializing your variable for secret code with size of 10 bytes.
    char userInput[10]; // initializing the variable for the input of the player
    int wellPlaced, misplaced; // initializing the variables for the wellPlaced and misplaced digits.

    // Check if a secret code was specified as a command-line argument
    if (argc > 1 && strcmp(argv[1], "-c") == 0){ 
        for (int i =0; i < CODE_LENGTH; i++){ //initializing a for loop
            secretCode[i] = argv[2][i]; // assigning each element of the array into secretCode array
        }
        secretCode[CODE_LENGTH] = '\0'; // assigning  a null value to variable.
    } 
    else{
        generateSecretCode(secretCode); // if no command-line arguments are passed, this will generate a random code.
    }

   
    int guess_attempt = 0; // initializing the guess_attempt variable with zero.
    // Main game loop
    while (guess_attempt < MAX_ATTEMPTS){ // loop control the while loop
        if (guess_attempt == 0){ // if condition
            printf("Will you find the secret code?\nPlease enter a valid guess\n"); // print message
        }
        printf("---\nRound %d\n", guess_attempt); //print message
        
        do { // initiate a do while loop
            int bytesRead = getInput(userInput); // get input from player   
            userInput[bytesRead - 1] = '\0';// assigning the null value.
            
            if (bytesRead == 0){ // ctrl + d, handling the End of File (EOF)
                return 0;  // end the program.
            }
            else if (bytesRead != (CODE_LENGTH + 1)){ // comparing the number of bytes
                printf("Wrong input!\n"); // print message.
            }
            else{
                if (is_valid_input(userInput)){ // checks if the input is valid
                    break; // breaks the do while loop.
                }
                else{
                    printf("Wrong input!\n"); // if input is not valid, print message.
                }
            }
        }while(1); //continous loop

        
        checkInput(secretCode, userInput, &wellPlaced, &misplaced); //checks the secretCode and the players input code.

        if (wellPlaced == CODE_LENGTH){ // if wellplaced digits equals the CODE_LENGTH
            printf("Congratz! You did it!"); //print message
            break; // end program
        }
        else{
            printFeedback(wellPlaced, misplaced); // if the condition is not met, printFeedback
        }
        

        guess_attempt++; //increase the guess_attempt value by 1
    }

    return 0; // end game.
}
