#include<stdio.h>


void Earthquake()
{
    printf("Earthquake safety\n");
    printf("1. Cover your head and neck\n");
    printf("2. Stay away from windows and heavy furniture\n");
    printf("3. Drop, Cover, and Hold On\n");
}

void Flood(){
    printf("Flood safety\n");
    printf("1. Move to higher ground\n");
    printf("2. Avoid walking or driving through flooded areas\n");
    printf("3. Stay informed about flood warnings\n");
}

void fire(){
    printf("Fire safety\n");
    printf("1. Install smoke alarms and test them regularly\n");
    printf("2. Create and practice a fire escape plan\n");
    printf("3. Keep flammable materials away from heat sources\n");
}

void roadAccident(){
    printf("Road Accident safety\n");
    printf("1. Always wear a seatbelt\n");
    printf("2. Follow traffic rules and speed limits\n");
    printf("3. Avoid distractions while driving\n");
}

void landslide(){
    printf("Landslide safety\n");
    printf("1. Stay away from steep slopes and unstable ground\n");
    printf("2. Be alert for signs of landslides, such as cracks in the ground or leaning trees\n");
    printf("3. Move to higher ground if you are in a landslide-prone area\n");
}

void strome(){
    printf("Storm safety\n");
    printf("1. Stay indoors and away from windows\n");
    printf("2. Avoid using electrical appliances during a storm\n");
    printf("3. Have an emergency kit ready with essentials like water, food, and flashlights\n");
}
void emergencyContact(){
    printf("Emergency Contacts\n");
    printf("1. Local Emergency Services: 911\n");
    printf("2. Poison Control: 1-800-222-1222\n");
    printf("3. National Disaster Hotline: 1-800-123-4567\n");
}
void addEmergencyContact(){
    char name[50];
    char number[15];
    
    printf("Enter the name of the emergency contact: ");
    scanf("%s", name);
    
    printf("Enter the phone number of the emergency contact: ");
    scanf("%s", number);
    
    printf("Emergency contact added: %s - %s\n", name, number);
}
void firstAidInstructions(){
    printf("First Aid Instructions\n");
    printf("1. For cuts and scrapes: Clean the wound, apply an antibiotic ointment, and cover with a bandage.\n");
    printf("2. For burns: Cool the burn with cool (not cold) water for at least 10 minutes, then cover with a   sterile bandage.\n");
    printf("3. For choking: Perform the Heimlich maneuver if the person is conscious and unable to breathe.\n");
}
void aboutProgram(){
    printf("About This Program\n");
    printf("SafetyBuddy is a multi-hazard safety assistant designed to provide safety tips and emergency contact information for various hazards, including earthquakes, floods, fires, road accidents, landslides, and storms. It also offers first aid instructions and allows users to add their own emergency contacts for quick access during emergencies.\n");
}   

void main()
{
    int choice;
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
            roadAccident();
            break;
        case 5:
            landslide();
            break;
        case 6:
            strome();
            break;
        default:
            printf("Invalid choice. Please select a number between 1 and 6.\n");
    }
}