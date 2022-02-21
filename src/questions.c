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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void) {

	printf("Welcome to Jeopardy!!\n");
    
    //create questions
    // category = programming
    //1
    strcpy(questions[0].category,categories[0]);
    strcpy(questions[0].question,"What is the java virtual machine called?");
    strcpy(questions[0].answer, "JVM" );
    questions[0].value = 100;
    questions[0].answered = false;

    //2
    strcpy(questions[1].category,categories[0]);
    strcpy(questions[1].question,"What is the name of the GNU C compiler?");
    strcpy(questions[1].answer, "GCC" );
    questions[1].value = 200;
    questions[1].answered = false;

    //3
    strcpy(questions[2].category,categories[0]);
    strcpy(questions[2].question,"What type of language is Python?");
    strcpy(questions[2].answer, "Interpereted" );
    questions[2].value = 300;
    questions[2].answered = false;

    //4
    strcpy(questions[3].category,categories[0]);
    strcpy(questions[3].question,"What programming language is used for creating webpages?");
    strcpy(questions[3].answer, "HTML" );
    questions[3].value = 400;
    questions[3].answered = false;


    // category = algorithms
    //1
    strcpy(questions[4].category,categories[1]);
    strcpy(questions[4].question,"What sorting algorithm is generally fastest?");
    strcpy(questions[4].answer, "Quick" );
    questions[4].value = 100;
    questions[4].answered = false;

    //2
    strcpy(questions[5].category,categories[1]);
    strcpy(questions[5].question,"What letter describes the runtime of a program?");
    strcpy(questions[5].answer, "O" );
    questions[5].value = 200;
    questions[5].answered = false;

    //3
    strcpy(questions[6].category,categories[1]);
    strcpy(questions[6].question,"What sorting algorithm was used by punchard computers?");
    strcpy(questions[6].answer, "Radix" );
    questions[6].value = 300;
    questions[6].answered = false;

    //4
    strcpy(questions[7].category,categories[1]);
    strcpy(questions[7].question,"What is an mutable array called (in python)?");
    strcpy(questions[7].answer, "List" );
    questions[7].value = 400;
    questions[7].answered = false;

    // category = databases
    //1
    strcpy(questions[8].category,categories[2]);
    strcpy(questions[8].question,"What is the name of the most popular query language?");
    strcpy(questions[8].answer, "SQL" );
    questions[8].value = 100;
    questions[8].answered = false;

    //2
    strcpy(questions[9].category,categories[2]);
    strcpy(questions[9].question,"What is the SQL command to return number of items in table?");
    strcpy(questions[9].answer, "Count" );
    questions[9].value = 200;
    questions[9].answered = false;

    //3
    strcpy(questions[10].category,categories[2]);
    strcpy(questions[10].question,"What SQL command is used to order in ascending order?");
    strcpy(questions[10].answer, "ASC" );
    questions[10].value = 300;
    questions[10].answered = false;

    //4
    strcpy(questions[11].category,categories[2]);
    strcpy(questions[11].question,"Which SQL function is used to join two or more select statements?");
    strcpy(questions[11].answer, "Union" );
    questions[11].value = 400;
    questions[11].answered = false;
}

// Display the category for all possibilities
extern void display_categories(){
    printf("\n");
    for (int i = 0; i < NUM_CATEGORIES; i++){
            if(i == 2){
            printf("|%11s|", categories[i]);
            } 
            else{
            printf("|%11s", categories[i]);     
            }
            
        }
        printf("\n");

        for (int i = 0; i <= NUM_QUESTIONS/4; i++){
            if ((i + 0) % 1 == 0){
                printf("\n");
            }

            printf("|%11i", questions[i].value);
            printf("|%11i", questions[i].value);
            printf("|%11i|", questions[i].value);
            
        }

};

// Displays the question for the category and dollar value
void display_question(char *category, int value){

    if(strcmp(category, categories[0]) == 0){
        printf("%s: ", questions[(value - 100)/100].question);
    }
    else if(strcmp(category, categories[1]) == 0){
        printf("%s: ", questions[(value + 300)/100].question);
    }
    else if(strcmp(category, categories[2]) == 0){
        printf("%s: ", questions[(value + 700)/100].question);
    }

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer) {

    char ans[256];
    int i = 0;

    // get correct answer
    if(strcmp(category, categories[0]) == 0){
        i = (value - 100)/100;
        strcpy(ans, questions[i].answer);
    }
    else if(strcmp(category, categories[1]) == 0){
        i = (value + 300)/100;
        strcpy(ans, questions[i].answer);
    }
    else if(strcmp(category, categories[2]) == 0){
        i = (value + 700)/100;
        strcpy(ans, questions[i].answer);
    }

    if(strcmp(answer,ans) == 0){
        printf("Correct");
        printf("\nThe answer was: %s", ans);
	return true;
    }
    else{
        printf("incorrect");
        printf("\nThe answer was: %s", ans);
	return false;
    }
    
    //tokenize answer and compare to expected output
    // if all tokens match with answer, return match
    // char *token;
    // char delimiter[] = " ";

    // token = strtok(answer, delimiter);

    // if ((strcmp(token, "What") == 0) || (strcmp(token, "Who") == 0) ){
    //     token = strtok(NULL, delimiter);

    //     if (strcmp(token, "is") == 0) {
    //         token = strtok(NULL, delimiter);

    //         if (strcmp(token, ans) == 0){
    //             printf("%s\n", token);
    //         }
    //     }
    // }

    questions[i].answered = true;

}

// Returns true if the question has already been answered
bool already_answered(char *category, int value) {

    int i = 0;
    if(strcmp(category, categories[0]) == 0){
        i = (value - 100)/100;
        if(questions[i].answered == true){
            printf("Answered\n");
            return true;
        }
        else{
            printf("Not answered\n"); 
        }
    }
    else if(strcmp(category, categories[1]) == 0){
        i = (value + 300)/100;
        if(questions[i].answered == true){
            printf("Answered\n");
            return true;
        }
        else{
            printf("Not answered\n"); 
        }
    }
    else if(strcmp(category, categories[2]) == 0){
        i = (value + 700)/100;
        if(questions[i].answered == true){
            printf("Answered\n");
            return true;
        }
        else{
            printf("Not answered\n"); 
        }
    }
    return false;
}
