#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(); //function prototype for main menu

/*function used in main.c*/
int emergencyContact(); //function prototype for emergency contact
int Earthquake(); //function prototype for earthquake safety tips
int Flood(); //function prototype for flood safety tips
int fire(); //function prototype for fire safety tips
int landslide(); //function prototype for landslide safety tips
int storm(); //function prototype for storm safety tips
int roadAccident(); //function prototype for road accident safety tips
int firstAidInstructions(); //function prototype for first aid instructions
int aboutProgram(); //function prototype for about this program
int exitProgram(); //function prototype for exiting the program

/*function used in quiz.c*/
int quizGame(); //function prototype for quiz game

/*Function used in emc.c*/
int addEmergencyContact(); //function prototype for adding emergency contact information

/*function to read specific section from file*/
int readSection(char section[]);



//function to clear screen after every choices given by a user
int clearscreen()
{
    system("clear");
    return 0;
}



//case 1
int Earthquake() //function for earthquake safety tips
{
    clearscreen();
    readSection("EARTHQUAKE");

 printf("\n\n Press Enter to return to main menu\n");
getchar(); // consume the newline character left by previous input
getchar(); // wait for user to press Enter
    return 0;
}





//case 2
int Flood() //function for flood safety tips
{
    clearscreen();
    readSection("FLOOD");

    printf("\n\n Press Enter to return to main menu\n");
  getchar(); // consume the newline character left by previous input
  getchar(); // wait for user to press Enter
    return 0;
}




//case 3
int fire() //function for fire safety tips
{
    clearscreen();
    readSection("FIRE");

    printf("\n\n Press Enter to return to main menu\n");
    getchar(); 
    getchar(); 

    return 0;
}





//case 4
int landslide() //function for landslide safety tips
{
    clearscreen();
    readSection("LANDSLIDE");

    printf("\n\n Press Enter to return to main menu\n");
    getchar();
    getchar();

    return 0;
}





//case 5
int storm() //function for storm safety tips
{
   clearscreen();
    readSection("STORM");

    printf("\n\n Press Enter to return to main menu\n");
    getchar();
     getchar(); 

    return 0;
}



//case 6
int roadAccident() //function for road accident safety tips
{
    clearscreen();
    readSection("ROADACCIDENT");

    printf("\n\n Press Enter to return to main menu\n");
    getchar(); 
    getchar(); 

    return 0;
}




//case 7 = in emc.c file




//case 8
int firstAidInstructions() //function for first aid instructions
{
     clearscreen();
    readSection("FIRSTAID");

    printf("\n\n Press Enter to return to main menu\n");
  getchar();
  getchar();
    return 0;
}



//case 9 = on quiz.c


//case 10
int aboutProgram() //function for about this program
{
 clearscreen();
readSection("ABOUT");            
 
    printf("\n\n Press Enter to return to main menu\n");
    getchar();
    getchar();
    return 0;
}




//case 11
int exitProgram() //function for exiting the program
{
    clearscreen();
    exit(0);
}




//function to read specific section from file
int readSection(char section[])
{
    FILE *fp;
    char line[200];
    int found = 0;

    fp = fopen("safetytips.txt", "r");

    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[')
        {
            if(strstr(line, section))
            {
                found = 1;
                continue;
            }
            else if(found)
            {
                break;
            }
        }

        if(found)
        {
            printf("%s", line);
        }
    }

    fclose(fp);

    return 0;
}




int main() //function for main menu
{
    int choice;

    do {
            clearscreen();

        printf("\n");
        printf("================================\n");
        printf("\tSafety Buddy \n");
        printf("================================\n");

        printf("1. Earthquake Safety\n");
        printf("2. Flood Safety\n");
        printf("3. Fire Safety\n");
        printf("4. Landslide Safety\n");
        printf("5. Storm/Tornado Safety\n");
        printf("6. Road Accident Safety\n");
        printf("7. Emergency Contacts\n");
        printf("8. First Aid Instructions\n");
        printf("9. Quiz Game\n");
        printf("10. About This Program\n");
        printf("11. Exit\n\n");

        printf("Enter your choice (1-11): ");

        scanf("%d", &choice);

        switch(choice)
        {

            case 1:
                Earthquake();
                break;

            case 2:
                Flood();
                break;

            case 3:
                fire();
                break;

            case 4:
                landslide();
                break;

            case 5:
                storm();
                break;

            case 6:
                roadAccident();
                break;

            case 7:
                emergencyContact();
                break;

            case 8:
                firstAidInstructions();
                break;

            case 9:
                quizGame();
                break;

            case 10:
                aboutProgram();
                break;

            case 11:
                exitProgram();
                break;

            default:
                printf("Invalid choice. Please select a number between 1 and 11.\n");
                break;
        }

    }while(choice != 11);

    return 0;
}