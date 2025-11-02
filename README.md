# Balancing Life

**Author:** Tristan Andrei L. Pon-an  
**Year & Section:** BSIT - 1A  
**Subject:** Computer Programming 1 (CIS101)  
**Professor:** Asuncion, Ryan Daniel Saladino  
**Purpose:** Finals Output for CIS101  
**Language:** C  

---

## 1. About the Game

**Balancing Life** is a text-based life simulation game where the player must manage three main stats:
- Money  
- Sanity  
- Family  

Each day presents new choices such as working, resting, or spending time with family. The goal is to survive for 5 in-game weeks without letting any stat reach zero.

The game also includes:
- Random major and minor life events  
- Daily and nightly routine options  
- Dynamic stat changes and summaries  
- Work streak bonuses and bills management  

---

## 2. Game Objective

Survive for **35 in-game days (5 weeks)**.  

If any of the following stats reach zero, the game ends:  
- **Money = 0** → Broke Ending  
- **Sanity = 0** → Lost Sanity Ending  
- **Family = 0** → Divorce Ending  

If the player completes 5 weeks successfully, they unlock the **Good Ending**.

---

## 3. How to Play

1. Run the compiled program.  
2. From the main menu, select:  
   - **Start:** Begin the game  
   - **Settings:** Manage saved data  
   - **Exit:** Quit the game  
3. Each day, choose how to spend your time.  
4. Make smart choices to balance your stats.  
5. Survive all 5 weeks to win.

---

## 4. Game Controls

- Input numbers **(1–5)** when prompted.  
- Press **Enter** to continue after each message.  
- Choices affect stats positively or negatively.

---

## 5. System Requirements

- Windows OS (uses `system("cls")` and `system("color")`)  
- C compiler (e.g., GCC, Code::Blocks, or Dev-C++)  
- Console capable of UTF-8 characters

---

## 6. Source Code Structure

```
main.c
│
├── Global Variables
│   Handles game state, constants, and player stats.
│
├── Menus
│   - Main Menu
│   - Settings Menu
│
├── Game Modules
│   - Work, Rest, and Family systems
│   - Event and morning/night routines
│
├── Utility Functions
│   - clearScreen()
│   - clearData()
│
└── Main Loop
    Controls program flow and win/loss logic.
```

---

## 7. Author’s Note

This project was created as part of the final output for **Computer Programming 1 (CIS101)**.  
It demonstrates the use of:
- Conditional statements  
- Functions and modular logic  
- Loops and user input handling  
- Console-based interface formatting

---

**End of File**