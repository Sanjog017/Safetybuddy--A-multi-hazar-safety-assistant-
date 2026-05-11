#include <stdio.h>

struct inventory {
    char items[50];
};

int firstaidInventory();
int emergencyInventory();
int foodWaterInventory();
int toolsEquipmentInventory();
int importantDocumentsInventory();

int inventory()
{
    int c;

    printf("== Welcome to Inventory Management ==\n");
    printf("Choose inventory:\n");
    printf("1. First Aid Inventory\n");
    printf("2. Emergency Supplies Inventory\n");
    printf("3. PPE Inventory\n");
    printf("4. Food and Water Inventory\n");
    printf("5. Tools and Equipment Inventory\n");
    printf("6. Important Documents\n");
    printf("7. Back to Main Menu\n");

    scanf("%d", &c);

    switch (c)
    {
        case 1:
            firstaidInventory();
            break;

        case 2:
            emergencyInventory();
            break;

        case 3:
            printf("PPE Inventory\n");
            break;

        case 4:
            printf("Food and Water Inventory\n");
            break;

        case 5:
            printf("Tools and Equipment Inventory\n");
            break;

        case 6:
            printf("Important Documents\n");
            break;

        case 7:
            return 0;   // go back safely

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

int firstaidInventory()
{
    struct inventory item;

    printf("Enter first aid item: ");
    scanf("%s", item.items);

    printf("Stored: %s\n", item.items);

    return 0;
}

int emergencyInventory()
{
    struct inventory item;

    printf("Enter emergency item: ");
    scanf("%s", item.items);

    printf("Stored: %s\n", item.items);

    return 0;
}