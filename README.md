# SafetyBuddy - Multi Hazard Safety Assistant

This was my first semester C programming project. Its a console based application that gives you safety information about different natural disasters and emergencies. I made this with my group for our college project.

## What does it do?

Basically you can pick from lot of options and get safety tips about different things like earthquakes, floods, fires, landslides, storms, road accidents, snake bites, first aid and more. There is also a quiz to test your knowledge and an alert system for different locations.

## Who can use it?

There are two modes:

### User Mode
- Read safety tips for 10 different topics
- Check location based alerts (it has 77 districts of Nepal)
- View emergency contact numbers
- Add your own emergency contacts
- Play a quiz with 40 questions
- Change your location

### Admin Mode (password protected)
Default password: **admin123**
- Edit safety tips content
- Manage emergency contacts (add/delete)
- Manage alerts for different locations
- Add, edit or delete quiz questions

## How to run it

### Compile
```bash
gcc main.c user.c admin.c alerts.c emc.c quiz.c -o run
```

### Run
```bash
./run
```

## Files in this project

| File | What it does |
|------|-------------|
| main.c | Main menu and role selection |
| user.c | All the user features and menus |
| admin.c | Admin login and management features |
| alerts.c | Location based alert system |
| emc.c | Emergency contacts feature |
| quiz.c | The quiz game |
| safetytips.txt | Contains all the safety information |
| alerts.txt | Alert messages for different Nepali districts |
| quiz.txt | All 40 quiz questions |
| emc.txt | User added emergency contacts |
| emc_predefined.txt | 9 predefined emergency contacts (Police, Fire, Ambulance, etc.) |
| admin_config.txt | Admin password (change it if you want) |
| location.txt | Saves your current location |

## Things I learned

- How C programming works (loops, functions, arrays, strings, pointers)
- File handling (reading and writing to txt files)
- Making menus in console
- Working with strings in C (which is honestly kinda hard)
- How to split code into multiple files

## This is just a prototype

Right now its a basic console app but if we ever turn this into a GUI app or web app in the future, we want to add:

- AI chatbot to answer safety questions in real time
- GPS based alerts that detect your location automatically
- Alert sounds and notifications
- User accounts with login/signup
- Real time weather and disaster data from internet
- Multiple languages (Nepali, English, etc.)
- Pictures and videos for safety demonstrations
- A proper database instead of txt files
- Mobile app version

## Known issues (stuff I would fix if I had more time)

- The quiz doesnt keep score, you just get right/wrong
- No user accounts, everything is local
- The alert system is manual, admin has to update it


## Built with

- C language
- GCC compiler
- Terminal/Command Prompt
- A lot of late night debugging sessions

---

*This was our first ever programming project so go easy on us. Made by 3 first semester students trying to figure out how pointers work.*
