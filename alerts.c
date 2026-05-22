#include<stdio.h>
#include<stdlib.h>
#include<string.h>  

int main(); //function prototype for main menu
int readAlert(char location[]); //function prototype for reading specific alert message from file
int alerts(); //function prototype for alerts menu
int clearscreen(); //function prototype for clearing the screen
void getLocation(char location[]); //function prototype for getting user's location
void saveLocation(char location[]); //function prototype for saving user's location to file





int alerts() //function for alerts menu
{
    int choice;
    char location[50];
    clearscreen();
    getLocation(location);

    do
    {
        clearscreen();

        printf("===== ALERT SYSTEM =====\n");
        printf("Current Location: %s\n\n", location);

        printf("1. View Alerts\n");
        printf("2. Change Location\n");
        printf("3. Return to Main Menu\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if(choice == 1)
        {
            clearscreen();
            printf("===== ALERTS FOR %s =====\n\n", location);

            readAlert(location);

            printf("\nPress Enter...");
            getchar();
        }

        else if(choice == 2)
        {
            printf("\nEnter new location: ");
            fgets(location, 50, stdin);
            location[strcspn(location, "\n")] = 0;

            saveLocation(location);

            printf("\nLocation updated!\n");
            printf("Press Enter...");
            getchar();
        }
        else if(choice == 3)
        {
            printf("\nReturning to main menu...\n");
        }
        else
        {
            printf("\nInvalid choice!\n");
            printf("Press Enter...");
            getchar();
        }

    }
    while(choice != 3);

    return 0;
}





void getLocation(char location[]) //function for getting user's location from file
{
    FILE *fp;

    fp = fopen("location.txt", "r");

    if(fp == NULL)
    {
        fp = fopen("location.txt", "w");

        printf("Enter your location: ");
        fgets(location, 50, stdin);

        location[strcspn(location, "\n")] = 0;

        fprintf(fp, "%s", location);

        fclose(fp);
    }
    else
    {
        fgets(location, 50, fp);

        location[strcspn(location, "\n")] = 0;

        fclose(fp);
    }
}





void saveLocation(char location[]) //function for saving user's location to file
{
    FILE *fp;

    fp = fopen("location.txt", "w");

    if(fp == NULL)
    {
        printf("Error saving location!\n");
        return;
    }

    fprintf(fp, "%s", location);

    fclose(fp);
}





int readAlert(char location[]) //function for reading specific alert message from file
{
    FILE *fp;
    char line[200];
    int found = 0;

    fp = fopen("alerts.txt", "r");

    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[')
        {
            if(strstr(line, location) && strstr(line, "_END") == NULL)
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
