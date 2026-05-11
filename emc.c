#include<stdio.h>
#include<stdlib.h>
int main(); //function prototype for main menu
int addEmergencyContact(); //function prototype for adding emergency contact information



int emergencyContact() // function for emergency contact information
{
    int c;
    char name[50];
    char number[20];

    FILE *fp;

    do {
        printf("\n===== Emergency Contacts =====\n");
        printf("1. Fire Department: 101\n");
        printf("2. Police: 100\n");
        printf("3. Ambulance: 102\n");
        printf("4. Disaster Management Authority: 108\n");

        // Reading custom contacts from file
        fp = fopen("contacts.txt", "r");

        if (fp != NULL)
        {
            printf("\n--- Custom Contacts ---\n");

            while (fscanf(fp, "%s %s", name, number) != EOF)
            {
                printf("%s : %s\n", name, number);
            }

            fclose(fp);
        }

        printf("\nPress 1 to add custom contact\n");
        printf("Press 0 for main menu\n");
        scanf("%d", &c);

        switch (c)
        {
            case 0:
                main();
                break;

            case 1:
                addEmergencyContact();
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (c != 0);

    return 0;
}


int addEmergencyContact() // function for adding emergency contact information
{
    char name[50];
    char number[20];

    FILE *fp;

    fp = fopen("contacts.txt", "a"); // append mode

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