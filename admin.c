#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(); //function prototype for role selector
int clearscreen(); //function prototype for clearing screen

int adminPortal(); //function prototype for admin portal
int adminLogin(); //function prototype for admin login
int adminMenu(); //function prototype for admin menu
int manageTips(); //function prototype for manage tips menu
int listSections(); //function prototype for listing all sections
int editSection(); //function prototype for editing a section
int deleteLines(); //function prototype for deleting lines from a section
int manageContactsAdmin(); //function prototype for admin contact management
int addPredefinedContact(); //function prototype for adding predefined contact
int listAllContacts(); //function prototype for listing all contacts
int deleteAnyContact(); //function prototype for deleting a contact
int manageAlertsAdmin(); //function prototype for admin alert management
int listLocations(); //function prototype for listing all locations
int editAlert(); //function prototype for editing location alert
int deleteAlertLines(); //function prototype for deleting alert lines
int adminSettings(); //function prototype for admin settings

#define MAX_LINE 500
#define TEMP_FILE "temp.txt"

int adminLogin() //function for admin login authentication
{
    char pass[50];
    char stored[50] = "admin123";
    FILE *fp;

    fp = fopen("admin_config.txt", "r");
    if(fp != NULL)
    {
        fgets(stored, sizeof(stored), fp);
        stored[strcspn(stored, "\n")] = 0;
        fclose(fp);
    }
    else
    {
        fp = fopen("admin_config.txt", "w");
        if(fp != NULL)
        {
            fprintf(fp, "admin123");
            fclose(fp);
        }
    }

    clearscreen();
    printf("===== ADMIN LOGIN =====\n\n");
    printf("Enter password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0;

    if(strcmp(pass, stored) == 0)
    {
        printf("\nLogin successful!\n");
        printf("Press Enter...");
        getchar();
        return 1;
    }
    else
    {
        printf("\nWrong password!\n");
        printf("Press Enter...");
        getchar();
        return 0;
    }
}

int adminPortal() //function for admin portal entry
{
    if(!adminLogin())
    {
        return 0;
    }

    adminMenu();
    return 0;
}

int adminMenu() //function for admin menu
{
    int choice;

    do
    {
        clearscreen();
        printf("===== ADMIN PORTAL =====\n\n");
        printf("1. Manage Safety Tips\n");
        printf("2. Manage Emergency Contacts\n");
        printf("3. Manage Alerts\n");
        printf("4. Settings\n");
        printf("5. Return to Main Menu\n\n");
        printf("Enter choice (1-5): ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                manageTips();
                break;
            case 2:
                manageContactsAdmin();
                break;
            case 3:
                manageAlertsAdmin();
                break;
            case 4:
                if(adminSettings() == 1)
                {
                    choice = 5;
                }
                break;
            case 5:
                printf("\nReturning to main menu...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                printf("Press Enter...");
                getchar();
        }
    } while(choice != 5);

    return 0;
}

int manageTips() //function for manage tips menu
{
    int choice;

    do
    {
        clearscreen();
        printf("===== MANAGE SAFETY TIPS =====\n\n");
        printf("1. List All Sections\n");
        printf("2. Edit Section\n");
        printf("3. Delete Lines from Section\n");
        printf("4. Back to Admin Menu\n\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                listSections();
                break;
            case 2:
                editSection();
                break;
            case 3:
                deleteLines();
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice!\n");
                printf("Press Enter...");
                getchar();
        }
    } while(choice != 4);

    return 0;
}

int listSections() //function for listing all safety tip sections
{
    FILE *fp;
    char line[MAX_LINE];
    int count = 0;

    clearscreen();
    printf("===== SAFETY TIP SECTIONS =====\n\n");

    fp = fopen("safetytips.txt", "r");
    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        printf("Press Enter...");
        getchar();
        return 1;
    }

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[' && strstr(line, "_END") == NULL)
        {
            count++;
            line[strcspn(line, "\n")] = 0;
            printf("%d. %s\n", count, line);
        }
    }

    fclose(fp);

    if(count == 0)
    {
        printf("No sections found.\n");
    }

    printf("\nPress Enter...");
    getchar();
    return 0;
}

int editSection() //function for editing an existing safety tip section
{
    char target[100];
    char line[MAX_LINE];
    char newContent[1000] = "";
    char buffer[500];
    FILE *fp, *temp;
    int inSection = 0;
    int found = 0;

    clearscreen();
    printf("===== EDIT SECTION =====\n\n");

    listSections();

    printf("\nEnter section name to edit (e.g. EARTHQUAKE): ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = 0;

    clearscreen();
    printf("Current content of [%s]:\n\n", target);

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
            if(strstr(line, target) && strstr(line, "_END") == NULL)
            {
                inSection = 1;
                continue;
            }
            else if(inSection)
            {
                break;
            }
        }

        if(inSection)
        {
            printf("%s", line);
        }
    }
    fclose(fp);

    printf("\n--- Enter new content (type '//end' on a new line to finish):\n");
    while(1)
    {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        if(strcmp(buffer, "//end") == 0)
        {
            break;
        }
        strcat(newContent, buffer);
        strcat(newContent, "\n");
    }

    fp = fopen("safetytips.txt", "r");
    temp = fopen(TEMP_FILE, "w");
    if(fp == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    inSection = 0;
    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[')
        {
            if(strstr(line, target) && strstr(line, "_END") == NULL)
            {
                inSection = 1;
                found = 1;
                fprintf(temp, "%s", line);
                continue;
            }
        }

        if(inSection && found)
        {
            if(line[0] == '[' && strstr(line, "_END"))
            {
                if(strlen(newContent) > 0)
                {
                    fprintf(temp, "%s", newContent);
                }
                fprintf(temp, "%s", line);
                inSection = 0;
                continue;
            }
            else
            {
                fprintf(temp, "%s", line);
                continue;
            }
        }

        fprintf(temp, "%s", line);
    }

    fclose(fp);
    fclose(temp);

    remove("safetytips.txt");
    rename(TEMP_FILE, "safetytips.txt");

    if(found)
    {
        printf("\nSection '[%s]' updated successfully!\n", target);
    }
    else
    {
        printf("\nSection '[%s]' not found!\n", target);
    }

    printf("Press Enter...");
    getchar();
    return 0;
}

int deleteLines() //function for deleting specific lines from a section
{
    char target[100];
    char line[MAX_LINE];
    char linesToDelete[100];
    char content[50][MAX_LINE];
    FILE *fp, *temp;
    int inSection = 0;
    int found = 0;
    int totalLines = 0;
    int deleteNums[50];
    int delCount = 0;
    int i;

    clearscreen();
    printf("===== DELETE LINES FROM SECTION =====\n\n");

    listSections();

    printf("\nEnter section name (e.g. EARTHQUAKE): ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = 0;

    clearscreen();
    printf("Current content of [%s]:\n\n", target);

    fp = fopen("safetytips.txt", "r");
    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        printf("Press Enter...");
        getchar();
        return 1;
    }

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[')
        {
            if(strstr(line, target) && strstr(line, "_END") == NULL)
            {
                inSection = 1;
                continue;
            }
            else if(inSection)
            {
                break;
            }
        }

        if(inSection)
        {
            totalLines++;
            strcpy(content[totalLines], line);
            printf("%d. %s", totalLines, line);
        }
    }
    fclose(fp);

    if(totalLines == 0)
    {
        printf("(No content lines in this section)\n");
        printf("\nPress Enter...");
        getchar();
        return 0;
    }

    printf("\nEnter line numbers to delete (space-separated, e.g. 2 5 7): ");
    fgets(linesToDelete, sizeof(linesToDelete), stdin);
    linesToDelete[strcspn(linesToDelete, "\n")] = 0;

    char *token = strtok(linesToDelete, " ");
    while(token != NULL && delCount < 50)
    {
        deleteNums[delCount] = atoi(token);
        delCount++;
        token = strtok(NULL, " ");
    }

    fp = fopen("safetytips.txt", "r");
    temp = fopen(TEMP_FILE, "w");
    if(fp == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    inSection = 0;
    found = 0;
    int currentLine = 0;

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[')
        {
            if(strstr(line, target) && strstr(line, "_END") == NULL)
            {
                inSection = 1;
                found = 1;
                fprintf(temp, "%s", line);
                continue;
            }
        }

        if(inSection && found)
        {
            if(line[0] == '[' && strstr(line, "_END"))
            {
                fprintf(temp, "%s", line);
                inSection = 0;
                continue;
            }
            else
            {
                currentLine++;
                int skip = 0;
                for(i = 0; i < delCount; i++)
                {
                    if(currentLine == deleteNums[i])
                    {
                        skip = 1;
                        break;
                    }
                }
                if(!skip)
                {
                    fprintf(temp, "%s", line);
                }
                continue;
            }
        }

        fprintf(temp, "%s", line);
    }

    fclose(fp);
    fclose(temp);

    remove("safetytips.txt");
    rename(TEMP_FILE, "safetytips.txt");

    if(found)
    {
        printf("\nLines deleted successfully from '[%s]'!\n", target);
    }
    else
    {
        printf("\nSection '[%s]' not found!\n", target);
    }

    printf("Press Enter...");
    getchar();
    return 0;
}

int manageContactsAdmin() //function for admin contact management menu
{
    int choice;

    do
    {
        clearscreen();
        printf("===== MANAGE EMERGENCY CONTACTS =====\n\n");
        printf("1. List All Contacts\n");
        printf("2. Add Predefined Contact\n");
        printf("3. Delete a Contact\n");
        printf("4. Back to Admin Menu\n\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                listAllContacts();
                break;
            case 2:
                addPredefinedContact();
                break;
            case 3:
                deleteAnyContact();
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice!\n");
                printf("Press Enter...");
                getchar();
        }
    } while(choice != 4);

    return 0;
}

int addPredefinedContact() //function for adding predefined contact by admin
{
    char name[100];
    char number[30];
    FILE *fp;

    clearscreen();
    printf("===== ADD PREDEFINED CONTACT =====\n\n");

    printf("Enter contact name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter phone number: ");
    fgets(number, sizeof(number), stdin);
    number[strcspn(number, "\n")] = 0;

    fp = fopen("emc_predefined.txt", "a");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "%s %s\n", name, number);
    fclose(fp);

    printf("\nPredefined contact '%s' added successfully!\n", name);
    printf("Press Enter...");
    getchar();
    return 0;
}

int listAllContacts() //function for listing all contacts from both files
{
    char line[MAX_LINE];
    FILE *fp;
    int count = 0;

    clearscreen();
    printf("===== ALL EMERGENCY CONTACTS =====\n\n");

    printf("--- Predefined Contacts (Admin) ---\n");
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

    if(count == 0)
    {
        printf("No predefined contacts.\n");
    }

    printf("\n--- User-Added Contacts ---\n");
    count = 0;
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

    if(count == 0)
    {
        printf("No user-added contacts.\n");
    }

    printf("\nPress Enter...");
    getchar();
    return 0;
}

int deleteAnyContact() //function for deleting a contact from either file
{
    char target[100];
    char line[MAX_LINE];
    FILE *fp, *temp;
    int found = 0;
    int choice;

    clearscreen();
    printf("===== DELETE CONTACT =====\n\n");
    printf("Delete from:\n");
    printf("1. Predefined Contacts\n");
    printf("2. User-Added Contacts\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &choice);
    getchar();

    listAllContacts();

    printf("\nEnter name or number to delete: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = 0;

    char *filename;
    if(choice == 1)
        filename = "emc_predefined.txt";
    else
        filename = "emc.txt";

    fp = fopen(filename, "r");
    temp = fopen(TEMP_FILE, "w");
    if(fp == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while(fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = 0;
        if(strstr(line, target) != NULL)
        {
            found = 1;
            printf("Deleted: %s\n", line);
        }
        else
        {
            fprintf(temp, "%s\n", line);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename(TEMP_FILE, filename);

    if(found)
    {
        printf("\nContact deleted successfully!\n");
    }
    else
    {
        printf("\nNo matching contact found.\n");
    }

    printf("Press Enter...");
    getchar();
    return 0;
}

int manageAlertsAdmin() //function for admin alert management menu
{
    int choice;

    do
    {
        clearscreen();
        printf("===== MANAGE ALERTS =====\n\n");
        printf("1. List All Locations\n");
        printf("2. Edit Location Alert\n");
        printf("3. Delete Lines from Location Alert\n");
        printf("4. Back to Admin Menu\n\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                listLocations();
                break;
            case 2:
                editAlert();
                break;
            case 3:
                deleteAlertLines();
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice!\n");
                printf("Press Enter...");
                getchar();
        }
    } while(choice != 4);

    return 0;
}

int listLocations() //function for listing all locations from alerts file
{
    FILE *fp;
    char line[MAX_LINE];
    int count = 0;

    clearscreen();
    printf("===== ALL LOCATIONS =====\n\n");

    fp = fopen("alerts.txt", "r");
    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        printf("Press Enter...");
        getchar();
        return 1;
    }

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[' && strstr(line, "_END") == NULL && line[1] != '/')
        {
            count++;
            line[strcspn(line, "\n")] = 0;
            printf("%d. %s\n", count, line);
        }
    }

    fclose(fp);

    if(count == 0)
    {
        printf("No locations found.\n");
    }

    printf("\nPress Enter...");
    getchar();
    return 0;
}

int editAlert() //function for appending new alert content to a location
{
    int choice;
    char locName[100];
    char line[MAX_LINE];
    char alertText[500] = "";
    char buffer[500];
    char locations[100][100];
    FILE *fp, *temp;
    int found = 0;
    int total = 0;

    clearscreen();
    printf("===== EDIT LOCATION ALERT =====\n\n");

    fp = fopen("alerts.txt", "r");
    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        printf("Press Enter...");
        getchar();
        return 1;
    }

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[' && strstr(line, "_END") == NULL && line[1] != '/')
        {
            total++;
            line[strcspn(line, "\n")] = 0;
            strcpy(locations[total], line);
            printf("%d. %s\n", total, locations[total]);
        }
    }
    fclose(fp);

    if(total == 0)
    {
        printf("No locations found.\n");
        printf("Press Enter...");
        getchar();
        return 0;
    }

    printf("\nEnter location number: ");
    scanf("%d", &choice);
    getchar();

    if(choice < 1 || choice > total)
    {
        printf("\nInvalid choice!\n");
        printf("Press Enter...");
        getchar();
        return 0;
    }

    strcpy(locName, locations[choice] + 1);
    locName[strlen(locName) - 1] = 0;

    clearscreen();
    printf("Current alert for [%s]:\n", locName);

    fp = fopen("alerts.txt", "r");
    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    int inLoc = 0;
    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[')
        {
            if(strstr(line, locName) && strstr(line, "_END") == NULL)
            {
                inLoc = 1;
                continue;
            }
            else if(inLoc)
            {
                break;
            }
        }

        if(inLoc)
        {
            printf("%s", line);
        }
    }
    fclose(fp);

    printf("\n--- Enter new alert lines to add (type '//end' on a new line to finish):\n");
    while(1)
    {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        if(strcmp(buffer, "//end") == 0)
        {
            break;
        }
        strcat(alertText, buffer);
        strcat(alertText, "\n");
    }

    fp = fopen("alerts.txt", "r");
    temp = fopen(TEMP_FILE, "w");
    if(fp == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    inLoc = 0;
    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[')
        {
            if(strstr(line, locName) && strstr(line, "_END") == NULL)
            {
                inLoc = 1;
                found = 1;
                fprintf(temp, "%s", line);
                continue;
            }
        }

        if(inLoc && found)
        {
            if(line[0] == '[' && strstr(line, "_END"))
            {
                if(strlen(alertText) > 0)
                {
                    fprintf(temp, "%s", alertText);
                }
                fprintf(temp, "%s", line);
                inLoc = 0;
                continue;
            }
            else
            {
                fprintf(temp, "%s", line);
                continue;
            }
        }

        fprintf(temp, "%s", line);
    }

    fclose(fp);
    fclose(temp);

    remove("alerts.txt");
    rename(TEMP_FILE, "alerts.txt");

    if(found)
    {
        printf("\nAlert for '%s' updated successfully!\n", locName);
    }
    else
    {
        printf("\nLocation '%s' not found!\n", locName);
    }

    printf("Press Enter...");
    getchar();
    return 0;
}

int deleteAlertLines() //function for deleting specific lines from a location alert
{
    int choice;
    char locName[100];
    char line[MAX_LINE];
    char linesToDelete[100];
    char content[50][MAX_LINE];
    char locations[100][100];
    FILE *fp, *temp;
    int inLoc = 0;
    int found = 0;
    int totalLines = 0;
    int deleteNums[50];
    int delCount = 0;
    int total = 0;
    int i;

    clearscreen();
    printf("===== DELETE LINES FROM LOCATION ALERT =====\n\n");

    fp = fopen("alerts.txt", "r");
    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        printf("Press Enter...");
        getchar();
        return 1;
    }

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[' && strstr(line, "_END") == NULL && line[1] != '/')
        {
            total++;
            line[strcspn(line, "\n")] = 0;
            strcpy(locations[total], line);
            printf("%d. %s\n", total, locations[total]);
        }
    }
    fclose(fp);

    if(total == 0)
    {
        printf("No locations found.\n");
        printf("Press Enter...");
        getchar();
        return 0;
    }

    printf("\nEnter location number: ");
    scanf("%d", &choice);
    getchar();

    if(choice < 1 || choice > total)
    {
        printf("\nInvalid choice!\n");
        printf("Press Enter...");
        getchar();
        return 0;
    }

    strcpy(locName, locations[choice] + 1);
    locName[strlen(locName) - 1] = 0;

    clearscreen();
    printf("Current alert for [%s]:\n\n", locName);

    fp = fopen("alerts.txt", "r");
    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        printf("Press Enter...");
        getchar();
        return 1;
    }

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[')
        {
            if(strstr(line, locName) && strstr(line, "_END") == NULL)
            {
                inLoc = 1;
                continue;
            }
            else if(inLoc)
            {
                break;
            }
        }

        if(inLoc)
        {
            totalLines++;
            strcpy(content[totalLines], line);
            printf("%d. %s", totalLines, line);
        }
    }
    fclose(fp);

    if(totalLines == 0)
    {
        printf("(No content lines for this location)\n");
        printf("\nPress Enter...");
        getchar();
        return 0;
    }

    printf("\nEnter line numbers to delete (space-separated, e.g. 2 5): ");
    fgets(linesToDelete, sizeof(linesToDelete), stdin);
    linesToDelete[strcspn(linesToDelete, "\n")] = 0;

    char *token = strtok(linesToDelete, " ");
    while(token != NULL && delCount < 50)
    {
        deleteNums[delCount] = atoi(token);
        delCount++;
        token = strtok(NULL, " ");
    }

    fp = fopen("alerts.txt", "r");
    temp = fopen(TEMP_FILE, "w");
    if(fp == NULL || temp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    inLoc = 0;
    found = 0;
    int currentLine = 0;

    while(fgets(line, sizeof(line), fp))
    {
        if(line[0] == '[')
        {
            if(strstr(line, locName) && strstr(line, "_END") == NULL)
            {
                inLoc = 1;
                found = 1;
                fprintf(temp, "%s", line);
                continue;
            }
        }

        if(inLoc && found)
        {
            if(line[0] == '[' && strstr(line, "_END"))
            {
                fprintf(temp, "%s", line);
                inLoc = 0;
                continue;
            }
            else
            {
                currentLine++;
                int skip = 0;
                for(i = 0; i < delCount; i++)
                {
                    if(currentLine == deleteNums[i])
                    {
                        skip = 1;
                        break;
                    }
                }
                if(!skip)
                {
                    fprintf(temp, "%s", line);
                }
                continue;
            }
        }

        fprintf(temp, "%s", line);
    }

    fclose(fp);
    fclose(temp);

    remove("alerts.txt");
    rename(TEMP_FILE, "alerts.txt");

    if(found)
    {
        printf("\nLines deleted successfully from '%s'!\n", locName);
    }
    else
    {
        printf("\nLocation '%s' not found!\n", locName);
    }

    printf("Press Enter...");
    getchar();
    return 0;
}

int adminSettings() //function for admin settings menu
{
    int choice;

    clearscreen();
    printf("===== ADMIN SETTINGS =====\n\n");
    printf("1. Switch to User Role\n");
    printf("2. Back to Admin Menu\n\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &choice);
    getchar();

    if(choice == 1)
    {
        printf("\nSwitching to User role...\n");
        return 1;
    }

    return 0;
}
