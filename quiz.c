#include <stdio.h>
#include <stdlib.h>

int clearscreen(); //function prototype for clearing screen
int readSection(char section[]); //function prototype for reading specific section from file
int main(); //function prototype for main menu

int quizGame() //function for quiz game
{
    clearscreen();

    FILE *fp; //file pointer

    char question[200];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];

    char correct; //correct answer
    char answer;  //user answer

    //opening file
    fp = fopen("quiz.txt", "r");

    //checking file
    if(fp == NULL)
    {
        printf("File not found!\n");
        return 0;
    }

    //loop until end of file
    while(fgets(question, sizeof(question), fp) != NULL)
    {
        //reading options
        fgets(optionA, sizeof(optionA), fp);
        fgets(optionB, sizeof(optionB), fp);
        fgets(optionC, sizeof(optionC), fp);
        fgets(optionD, sizeof(optionD), fp);

        //reading correct answer
        fscanf(fp, " %c", &correct);

        //consume newline after answer
        fgetc(fp);

        //printing question
        printf("%s", question);
        printf("%s", optionA);
        printf("%s", optionB);
        printf("%s", optionC);
        printf("%s", optionD);

        //taking user answer
        printf("Answer: ");
        scanf(" %c", &answer);

        //checking answer
        if(answer == correct || answer == correct + 32)
        {
            printf("Correct!\n\n");
        }
        else
        {
            printf("Wrong! Correct answer is %c\n\n", correct);
        }

        //skip blank line between questions
        fgets(question, sizeof(question), fp);
    }

    fclose(fp);

    //return to main menu
    printf("Quiz completed! Press Enter to return to main menu\n");
    getchar(); // consume the newline character left by previous input
    getchar(); // wait for user to press Enter

    return 0;
}
