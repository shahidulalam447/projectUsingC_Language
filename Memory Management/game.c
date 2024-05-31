#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Simple Game to Understand Memory Management, Multithreading, and CPU Utilization 

// Define the maximum number of attempts a player has to guess the secret number
#define MAX_ATTEMPTS 10

// Structure to hold game data
typedef struct {
    int secretNumber;  // The secret number the player has to guess
    int attempts;      // The current number of attempts made by the player
} GameData;

// Function executed by the player thread
void* playerThread(void* arg) {
    GameData* data = (GameData*)arg;  // Cast the argument to GameData pointer
    int guess;  // Variable to store the player's guess

    // Loop until the maximum number of attempts is reached
    while (data->attempts < MAX_ATTEMPTS) {
        printf("Enter your guess: ");
        scanf("%d", &guess);  // Read the player's guess
        data->attempts++;  // Increment the number of attempts

        // Provide feedback based on the player's guess
        if (guess < data->secretNumber) {
            printf("Too low!\n");
        } else if (guess > data->secretNumber) {
            printf("Too high!\n");
        } else {
            printf("Correct! You win!\n");
            pthread_exit(NULL);  // Exit the thread if the guess is correct
        }
    }
    // If the player runs out of attempts, print a losing message
    printf("Out of attempts! You lose!\n");
    pthread_exit(NULL);  // Exit the thread
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    GameData gameData;  // Declare a variable of type GameData
    gameData.secretNumber = rand() % 100 + 1;  // Generate a random secret number between 1 and 100
    gameData.attempts = 0;  // Initialize the number of attempts to 0

    pthread_t thread;  // Declare a thread variable
    // Create a new thread to run the playerThread function
    if (pthread_create(&thread, NULL, playerThread, (void*)&gameData)) {
        printf("Error creating thread\n");
        return 1;  // Return an error code if thread creation fails
    }

    // Wait for the player thread to finish
    pthread_join(thread, NULL);

    return 0;  // Return 0 to indicate successful execution
}
