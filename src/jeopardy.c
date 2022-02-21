/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"


// Terminal Color Codes
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

// Constants
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players){
    int max = 0;
    
    for(int i = 0; i < num_players; i++){
        printf( GREEN "Player %15s: Score is %4i\n", players[i].name, players[i].score);

        if (players[i].score > players[max].score){
            max = i;    
        }
    
    }
    
    // Print winner
    printf("\n%s WINS!!!", players[max].name);
}

int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();
    int counter = 0;

    // Prompt for players names
    // initialize each of the players in the array
    for(int i = 0; i < NUM_PLAYERS; i++){
        
       char name[MAX_LEN];
       printf("Enter a name for your player %i: ", i);
       scanf("%s", name);
        
       player play;
       strcpy(play.name, name);
       play.score  = 0;
        
       players[i] = play;
       printf("Player %i is %s and balance is %i \n", i, play.name, play.score);
    }
    

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Display Game Board
        display_categories();

        // Random Order to be used for player order
        int playc = rand() % 4;
        
        printf("\n\nPlayer %i: %s it is your turn!", playc, &players[playc].name);
        
        // Request Player Category selection
        printf("\n\nWhat category would you like to choose: ");
        char cat[MAX_LEN];
        int points;
        char temp[256];
        scanf("%s", cat);
        
         // Execute the game until all questions are answered
        if(strcmp(cat, categories[0]) == 0 || strcmp(cat, categories[1]) == 0 || strcmp(cat, categories[2]) == 0){
            printf("For how many points: ");
            scanf("%i", &points);
            
            if(points == questions[0].value || points == questions[1].value || points == questions[2].value || points == questions[3].value){
                
                // if question is not already answered
                if(!already_answered(cat, points)){
                    
                    //display question and get user input
                    display_question(cat, points);
                    scanf("%s",temp);
                    
                    // check answer and update score
                    if (valid_answer(cat, points, temp))
                        update_score(players, NUM_PLAYERS, players[playc].name, points);
                    
                    //increment counter
                    counter++;
                }
                
            } else {
                // if question does not exists inform user
                printf("Question DNE");
            }
            
        } else {
            // if question does not exists inform user
            printf("Category DNE");
        }
        
        
        // Display the final results and exit
        if(counter >= 12){
            show_results(players, NUM_PLAYERS);
            break;
        }

    }

    return EXIT_SUCCESS;
}
