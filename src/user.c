#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(); //function prototype for role selector
int adminPortal(); //function prototype for admin portal
int userSettings(); //function prototype for user settings
int clearscreen(); //function prototype for clearing screen
int exitProgram(); //function prototype for exiting the program

/*function used in emc.c*/
int emergencyContact(); //function prototype for emergency contact

/*function used in quiz.c*/
int quizGame(); //function prototype for quiz game

/*function used in alert.c*/
int alerts(); //function prototype for alerts menu

/*function used in emc.c and alerts.c*/
int readSection(char section[]); //function prototype for reading section
void getLocation(char location[]); //function prototype for getting location
void saveLocation(char location[]); //function prototype for saving location

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
    getchar(); // consume the newline character left by previous input
    getchar(); // wait for user to press Enter

    return 0;
}

//case 4
int landslide() //function for landslide safety tips
{
    clearscreen();
    readSection("LANDSLIDE");

    printf("\n\n Press Enter to return to main menu\n");
    getchar(); // consume the newline character left by previous input
    getchar(); // wait for user to press Enter

    return 0;
}

//case 5
int storm() //function for storm safety tips
{
   clearscreen();
    readSection("STORM");

    printf("\n\n Press Enter to return to main menu\n");
    getchar(); // consume the newline character left by previous input
     getchar(); // wait for user to press Enter

    return 0;
}

//case 6
int roadAccident() //function for road accident safety tips
{
    clearscreen();
    readSection("ROADACCIDENT");

    printf("\n\n Press Enter to return to main menu\n");
    getchar(); // consume the newline character left by previous input
    getchar(); // wait for user to press Enter

    return 0;
}

//case 10 = in emc.c file

//case 7
int firstAidInstructions() //function for first aid instructions
{
     clearscreen();
    readSection("FIRSTAID");
    printf("\n\n Press Enter to return to main menu\n");
  getchar(); // consume the newline character left by previous input
  getchar(); // wait for user to press Enter
    return 0;
}

//case 11 = on quiz.c

//case 9
int wildfire() //function for wildfire safety tips
{
    clearscreen();
    readSection("WILDFIRE");

    printf("\n\n Press Enter to return to main menu\n");
    getchar(); // consume the newline character left by previous input
    getchar(); // wait for user to press Enter

    return 0;
}

//case 8
int snakeBite() //function for snake bite and poisoning safety tips
{
    clearscreen();
    readSection("SNAKEBITE");

    printf("\n\n Press Enter to return to main menu\n");
    getchar(); // consume the newline character left by previous input
    getchar(); // wait for user to press Enter

    return 0;
}

//case 12
int aboutProgram() //function for about this program
{
 clearscreen();
readSection("ABOUT");

    printf("\n\n Press Enter to return to main menu\n");
    getchar(); // consume the newline character left by previous input
    getchar(); // wait for user to press Enter
    return 0;
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
            if(strstr(line, section) && strstr(line, "_END") == NULL)
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

//function to clear screen
int clearscreen()
{
   #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return 0;
}
//case 13
int userSettings() //function for user settings menu
{
    int choice;
    char location[50];

    do
    {
        clearscreen();
        printf("===== USER SETTINGS =====\n\n");
        printf("1. Change Location\n");
        printf("2. Switch to Admin Role\n");
        printf("3. Back to User Menu\n\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                clearscreen();
                printf("===== CHANGE LOCATION =====\n\n");
                printf("Enter your new location: ");
                fgets(location, sizeof(location), stdin);
                location[strcspn(location, "\n")] = 0;
                saveLocation(location);
                printf("\nLocation updated to '%s'!\n", location);
                printf("Press Enter...");
                getchar();
                break;

            case 2:
                printf("\nSwitching to Admin role...\n");
                return 1;

            case 3:
                break;

            default:
                printf("\nInvalid choice!\n");
                printf("Press Enter...");
                getchar();
        }
    } while(choice != 3);

    return 0;
}

int userMenu() //function for user menu
{
    int choice;

    do {
            clearscreen();

        printf("\n");
        printf("================================\n");
        printf("\tSafety Buddy - User \n");
        printf("================================\n\n");
        printf("0. Alerts\n");
        printf("1. Earthquake Safety\n");
        printf("2. Flood Safety\n");
        printf("3. Fire Safety\n");
        printf("4. Landslide Safety\n");
        printf("5. Storm/Tornado Safety\n");
        printf("6. Road Accident Safety\n");
        printf("7. First Aid Instructions\n");
        printf("8. Snake Bite & Poisoning Safety\n");
        printf("9. Wildfire Safety\n");
        printf("10. Emergency Contacts\n");
        printf("11. Quiz Game\n");
        printf("12. About This Program\n");
        printf("13. Settings\n");
        printf("14. Return to Menu\n\n");

        printf("Enter your choice (0-14): ");

        scanf("%d", &choice);

        switch(choice)
        {

            case 0:
                alerts();
                break;

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
                firstAidInstructions();
                break;

            case 8:
                snakeBite();
                break;

            case 9:
                wildfire();
                break;

            case 10:
                emergencyContact();
                break;

            case 11:
                quizGame();
                break;

            case 12:
                aboutProgram();
                break;

            case 13:
                if(userSettings() == 1)
                {
                    choice = 14;
                }
                break;

            case 14:
                printf("\nReturning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please select a number between 0 and 14.\n");
                break;
        }

    }while(choice != 14);

    return 0;
}
