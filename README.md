# SafetyBuddy - Multi Hazard Safety Assistant

This was my first semester C programming project. Its a console based application that gives you safety information about different natural disasters and emergencies. I made this with my group for our college project.

## What does it do?

Basically you can pick from lot of options and get safety tips about different things like earthquakes, floods, fires, landslides, storms, road accidents, snake bites, first aid and more. There is also a quiz to test your knowledge and an alert system for different locations.

## Who can use it?

There are two modes:


### User Mode
- Read safety tips for 10 hazard/disaster topics (Earthquake, Flood, Fire, Landslide, Storm/Tornado, Road Accident, First Aid, Wildfire, Snake Bite/Poisoning)
- Check location-based alerts (77 districts of Nepal)
- View emergency contact numbers (9 predefined + custom)
- Add your own emergency contacts
- Play a quiz with 40 multiple-choice questions
- Change your location

### Admin Mode (password protected)
Default password: **admin123**
- Manage safety tips (list, edit, delete lines from sections)
- Manage emergency contacts (add predefined, delete from either list)
- Manage alerts for all 77 districts (edit, delete lines)
- Manage quiz questions (add, edit, delete, list all)

## How to run it

### Compile
```bash
gcc main.c user.c admin.c alerts.c emc.c quiz.c -o safetybuddy
```

### Run
```bash
./safetybuddy
```

## Files in this project

| File | What it does |
|------|-------------|
| main.c | Main menu, role selection, and exit handler |
| user.c | User mode features: safety tips viewer, settings, screen control |
| admin.c | Admin portal: full CRUD for tips, contacts, alerts, and quiz |
| alerts.c | Location-based alert system for 77 Nepali districts |
| emc.c | Emergency contacts viewer and add feature |
| quiz.c | 40-question multiple-choice quiz game |
| safetytips.txt | Safety information for 10 hazard topics in `[SECTION]` format |
| alerts.txt | Alert messages for 77 districts of Nepal |
| quiz.txt | 40 quiz questions with 4 options each and correct answers |
| emc.txt | User-added emergency contacts (name + number) |
| emc_predefined.txt | 9 predefined emergency contacts (Police, Fire, Ambulance, etc.) |
| admin_config.txt | Admin password (default: admin123) |
| location.txt | Saves the user's current district location |

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

- The quiz doesn't keep score, you just get right/wrong
- No user accounts, everything is local
- The alert system is manual, admin has to update it

## Built with

- C language
- GCC compiler
- Terminal/Command Prompt
- A lot of late night debugging sessions

---

*This was our first ever programming project so go easy on us. Made by 3 first semester students trying to figure out how pointers work.*
