
#include<stdio.h>

struct inventory{
    char items[50];
    
};


int main(); //function prototype for main menu
int inventory()
{

    int c;
    printf("==Welcome to the Inventory Management ==\n");
    printf("choose the number according to inventory you want to check or add\n");
    printf("1. First Aid Inventory\n");
    printf("2. Emergency Supplies Inventory\n");
    printf("3. Personal Protective Equipment Inventory\n");
    printf("4. Food and Water Inventory\n");
    printf("5. Tools and Equipment Inventory\n");
    printf("6. Where are your documents and important papers?\n\n");
    printf("7. Back to main menu\n");
    scanf("%d", &c);
    switch (c)
    {
        case 1:
        
        break;
        case 2:
            
            break;
        case 3:
           
            break;
        case 4:
      
            break;
        case 5:
            
            break;
        case 6:
           
            break;
        case 7:
            main();
            break;

        default:
           printf("Invalid choice. Please select a number between 1 and 7.\n");
           
    }
}



int firstaidInventory()
{

    return 0;
}
