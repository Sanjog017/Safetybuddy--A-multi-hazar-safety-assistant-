#include<stdio.h>
#include<stdlib.h>

int clearscreen(); //function prototype for clearing screen
int userMenu(); //function prototype for user menu
int adminPortal(); //function prototype for admin portal

int exitProgram() //function for exiting the program
{
    clearscreen();
    printf("Thank you for using Safety Buddy!\n");
    exit(0); //exit the program
}

int main() //function for role selection
{
    int choice;

    do {
        clearscreen();

        printf("\n");
        printf("================================\n");
        printf("\tSafety Buddy \n");
        printf("================================\n\n");
        printf("1. User\n");
        printf("2. Admin\n");
        printf("3. Exit\n\n");

        printf("Select your role (1-3): ");
        scanf("%d", &choice);
        getchar(); // consume the newline character left by previous input

        switch(choice)
        {
            case 1:
                userMenu();
                break;

            case 2:
                adminPortal();
                break;

            case 3:
                exitProgram();
                break;

            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
                printf("Press Enter...");
                getchar();
                break;
        }

    } while(choice != 3);

    return 0;
}
