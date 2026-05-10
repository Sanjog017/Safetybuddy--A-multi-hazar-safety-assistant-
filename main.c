#include<stdio.h>

int main(); //function prototype for main menu




int Earthquake() //function for earthquake safety tips
{
    int c;
do{
    printf("Earthquake safety\n");
    printf("1. Cover your head and neck\n");
    printf("2. Stay away from windows and heavy furniture\n");
    printf("3. Drop, Cover, and Hold On\n\n\n");
    printf("press 0 for main menu\n");
    scanf("%d", &c);

    switch (c)
    {
        case 0:
            main();
            break;

        default:
           printf("Invalid choice. Please press 0 to return to the main menu.\n");
    }
}while (c != 0); //loop to keep the program a run until choosing a proper choice by a user

    return 0;
     
}




int Flood() //function for flood safety tips
{ 
    int c;
    do {
    printf("Flood safety\n");
    printf("1. Move to higher ground\n");
    printf("2. Avoid walking or driving through flooded areas\n");
    printf("3. Stay informed about flood warnings\n");
    printf("press 0 for main menu\n");
    scanf("%d", &c);

     switch (c)
    {
        case 0:
            main();
            break;

        default:
           printf("Invalid choice. Please press 0 to return to the main menu.\n");
           
    }
    }while (c != 0); //loop to keep the program a run until choosing a proper choice by a user
             return 0;
}





int fire() //function for fire safety tips
{
    int c;
    do {
    printf("Fire safety\n");
    printf("1. Install smoke alarms and test them regularly\n");
    printf("2. Create and practice a fire escape plan\n");
    printf("3. Keep flammable materials away from heat sources\n");
    printf("press 0 for main menu\n");
    scanf("%d", &c);

      switch (c)
    {
        case 0:
            main();
            break;

        default:
           printf("Invalid choice. Please press 0 to return to the main menu.\n");
           
    }
    }while (c != 0); //loop to keep the program a run until choosing a proper choice by a user
             return 0;
}




int roadAccident() //function for road accident safety tips
{
    int c;
    do{
    printf("Road Accident safety\n");
    printf("1. Always wear a seatbelt\n");
    printf("2. Follow traffic rules and speed limits\n");
    printf("3. Avoid distractions while driving\n");
    printf("press 0 for main menu\n");
    scanf("%d", &c);
 switch (c)
    {
        case 0:
            main();
            break;

        default:
           printf("Invalid choice. Please press 0 to return to the main menu.\n");
           
    }
    }while (c != 0); //loop to keep the program a run until choosing a proper choice by a user
             return 0;
}




int landslide() //function for landslide safety tips
{
    int c;
    do {
    printf("Landslide safety\n");
    printf("1. Stay away from steep slopes and unstable ground\n");
    printf("2. Be alert for signs of landslides, such as cracks in the ground or leaning trees\n");
    printf("3. Move to higher ground if you are in a landslide-prone area\n");
    printf("press 0 for main menu\n");
    scanf("%d", &c);

      switch (c)
    {
        case 0:
            main();
            break;

        default:
           printf("Invalid choice. Please press 0 to return to the main menu.\n");
           
    }
    }while (c != 0); //loop to keep the program a run until choosing a proper choice by a user
             return 0;
}




int storm() //function for storm safety tips
{
    int c;
    do {
    printf("Storm safety\n");
    printf("1. Stay indoors and away from windows\n");
    printf("2. Avoid using electrical appliances during a storm\n");
    printf("3. Have an emergency kit ready with essentials like water, food, and flashlights\n");
    printf("press 0 for main menu\n");
    scanf("%d", &c);
  switch (c)
    {
        case 0:
            main();
            break;

        default:
           printf("Invalid choice. Please press 0 to return to the main menu.\n");
           
    }
    }while (c != 0); //loop to keep the program a run until choosing a proper choice by a user
             return 0;
}




int emergencyContact() //function for emergency contact information
{
    int c;
    do {
    printf("Emergency Contacts\n");
    printf("1. Local Emergency Services: 911\n");
    printf("2. Poison Control: 1-800-222-1222\n");
    printf("3. National Disaster Hotline: 1-800-123-4567\n");
    printf("press 0 for main menu\n");
    scanf("%d", &c);

     switch (c)
    {
        case 0:
            main();
            break;

        default:
           printf("Invalid choice. Please press 0 to return to the main menu.\n");
           
    }
    }while (c != 0); //loop to keep the program a run until choosing a proper choice by a user
             return 0;
}




int firstAidInstructions() //function for first aid instructions
{
    int c;
    do {
    printf("First Aid Instructions\n");
    printf("1. For cuts and scrapes: Clean the wound, apply an antibiotic ointment, and cover with a bandage.\n");
    printf("2. For burns: Cool the burn with cool (not cold) water for at least 10 minutes, then cover with a sterile bandage.\n");
    printf("3. For choking: Perform the Heimlich maneuver if the person is conscious and unable to breathe.\n");
    printf("press 0 for main menu\n");
    scanf("%d", &c);

  switch (c)
    {
        case 0:
            main();
            break;

        default:
           printf("Invalid choice. Please press 0 to return to the main menu.\n");
           
    }
    }while (c != 0); //loop to keep the program a run until choosing a proper choice by a user
             return 0;
}




int aboutProgram() //function for about this program
{
    int c;
    do {
    printf("About This Program\n");
    printf("SafetyBuddy is a multi-hazard safety assistant designed to provide safety tips and emergency contact information for various hazards,  including earthquakes, floods, fires, road accidents, landslides, and storms. It also offers first aid instructions and allows users to add their own emergency contacts for quick access during emergencies.\n");
    printf("press 0 for main menu\n");
    scanf("%d", &c);

     switch (c)
    {
        case 0:
            main();
            break;

        default:
           printf("Invalid choice. Please press 0 to return to the main menu.\n");
           
    }
    }while (c != 0); //loop to keep the program a run until choosing a proper choice by a user
             return 0;
}




int addEmergencyContact() //function for adding emergency contact information
{
    return 0;
}




int exitProgram() //function for exiting the program
{
    printf("Exiting the program. Stay safe!\n");
    return 0;
}




int main() //function for main menu
{
    int choice;
    do {
                   printf("Select a hazard to learn safety tips:\n");
                   printf("1. Earthquake Safety\n");
                   printf("2. Flood Safety\n");
                   printf("3. Fire Safety\n");
                   printf("4. Landslide Safety\n");
                   printf("5. Storm/Tornado Safety\n");
                   printf("6. Emergency Contacts\n");
                   printf("7. Add Emergency Contact\n");
                   printf("8. First Aid Instructions\n");
                   printf("9. About This Program\n");
                   printf("10. Exit\n");

    scanf("%d", &choice);

    switch(choice) //switch case for main menu options
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
            emergencyContact();
            break;

        case 7:
            addEmergencyContact();
            break;

        case 8:
            firstAidInstructions();
            break;

        case 9:
            aboutProgram();
            break;

        case 10:
            exitProgram();
            break;

     default: 
     printf("Invalid choice. Please select a number between 1 and 10.\n");
    }
    
    }while (choice != 10); //loop to keep the program a run until choosing a proper choice by a user 
  
    
    return 0;
}