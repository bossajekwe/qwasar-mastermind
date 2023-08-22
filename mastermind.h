#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

#define MAX_ATTEMPTS 10
#define CODE_LENGTH 4


void generateSecretCode(char* secretCode) {

    // Generating a random secret code using digits from 0 to 9
    srand(time(NULL));
    for (int i = 0; i < CODE_LENGTH; i++) {
        secretCode[i] = '0' + (rand() % 10);
    }
    secretCode[CODE_LENGTH] = '\0';
}

int getInput(char *guess) {
 
    int maxLength = read(STDIN_FILENO, guess, sizeof(guess));
    
    return maxLength;

}


int is_valid_input(char* guess) {
    int digits = 0;
    int counter[10] = {0};
    int n = strlen(guess);

  
    for (int i = 0; i < n; i++) {
        if (guess[i] >= '0' && guess[i] <= '9') {
            counter[guess[i] - '0']++;
        } else {
            return 0; // Invalid input if non-digit character found
        }
    }

    for (int i = 0; i < 10; i++) {
        if (counter[i] > 1) {
            digits++;
        }
    }

    return (digits == 0); // Return 1 if no repeated digits, 0 otherwise
}


int countWellPlaced(char* secretCode, char* userInput) {
    int wellPlaced = 0;
    int n = strlen(secretCode);
    for (int i = 0; i < n; i++) {
        if (secretCode[i] == userInput[i]) {
            wellPlaced++;
        }
    }
    return wellPlaced;
}


int countMisplaced(char* secretCode, char* userInput) {
    int misplaced = 0;
    
    for (int i = 0; i < CODE_LENGTH; i++){
        for(int j = 0; j < CODE_LENGTH; j++){
            if (i == j || userInput[i]==secretCode[i]){
                continue;
            }
            
            if (userInput[i]==secretCode[j]){
                misplaced ++;
            }
        }
    }
    

    return misplaced;
}


void checkInput(char* secretCode, char* userInput, int* wellPlaced, int* misplaced) {
    *wellPlaced = countWellPlaced(secretCode, userInput);
    *misplaced = countMisplaced(secretCode, userInput);
}


void printFeedback(int wellPlaced, int misplaced) {
    printf("Well placed pieces: %d\nMisplaced pieces: %d\n", wellPlaced,misplaced);
    
}




