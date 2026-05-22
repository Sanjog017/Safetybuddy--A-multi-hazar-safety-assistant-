#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(); //function prototype for main menu
int addEmergencyContact(); //function prototype for adding emergency contact information
int clearscreen(); //function prototype for clearing the screen
int readSection(char section[]); //function prototype for reading specific section from file


int displaySavedContacts() //function for displaying all saved contacts from both files
{
    FILE *fp;
    char line[200];
    int count = 0;

    printf("\n--- Predefined Contacts ---\n");
    fp = fopen("emc_predefined.txt", "r");
    if(fp != NULL)
    {
        while(fgets(line, sizeof(line), fp))
        {
            line[strcspn(line, "\n")] = 0;
            if(strlen(line) > 0)
            {
                count++;
                printf("%d. %s\n", count, line);
            }
        }
        fclose(fp);
    }
    if(count == 0) printf("(No predefined contacts)\n");

    count = 0;
    printf("\n--- Your Saved Contacts ---\n");
    fp = fopen("emc.txt", "r");
    if(fp != NULL)
    {
        while(fgets(line, sizeof(line), fp))
        {
            line[strcspn(line, "\n")] = 0;
            if(strlen(line) > 0)
            {
                count++;
                printf("%d. %s\n", count, line);
            }
        }
        fclose(fp);
    }
    if(count == 0) printf("(No saved contacts)\n");

    return 0;
}

int emergencyContact() //function for emergency contact menu
{
    clearscreen();
    readSection("EMERGENCYCONTACT");

    displaySavedContacts();

    int c;
    printf("\nEnter 1 to add a new emergency contact\n ");
    printf("Enter any other number to return to main menu\n ");
    printf("Your choice: ");
    scanf("%d", &c);

    if(c == 1)
    {
        addEmergencyContact();
    }
    else if (c != 1)
    {
        printf("Returning to main menu...\n");
        return 0;
    }

    return 0;
}


int addEmergencyContact() // function for adding emergency contact information
{
    char name[50];
    char number[20];

    FILE *fp;

    fp = fopen("emc.txt", "a"); // append mode

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the name of the emergency contact:\n");
    scanf("%s", name);

    printf("Enter the phone number of the emergency contact:\n");
    scanf("%s", number);

    // Save into file
    fprintf(fp, "%s %s\n", name, number);

    fclose(fp);

    printf("Emergency contact added successfully!\n");

    return 0;
}
