/*
Author: Tristan Andrei L. Pon-an
Year & Section: BSIT - 1A
Subject: Computer Programming 1 (CIS101)
Professor: Asuncion, Ryan Daniel Saladino
Purpose: Finals Output for CIS101
Game Title: Balancing Life
Description:
A life-simulation game where the player must balance Money, Sanity, and Family
over 5 in-game weeks. Each day presents choices that affect these stats.
The goal is to survive without any stat reaching zero while managing bills,
random events, and daily routines.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* -------------------------- GLOBAL VARIABLES -------------------------- */

// Constants
const int WEEK5 = 35;

// Game state variables
int bills = 4;
int userHighscore = 0;

// Player stats (default values)
int userMoney = 5;
int userSanity = 7;
int userFamily = 5;

// Achievements and streaks
int workStreakCheck = 0;
int workStreak = 0;

// Change trackers for daily summary
int moneyChange = 0;
int sanityChange = 0;
int familyChange = 0;
int billsChange = 0;

// Major Event Days
const int eventMajorOne = 6;
const int eventMajorTwo = 17;
const int eventMajorThree = 23;
const int eventMajorFour = 31;

// Minor Event Days
const int eventMinorOne = 4;
const int eventMinorTwo = 8;
const int eventMinorThree = 10;
const int eventMinorFour = 13;
const int eventMinorFive = 18;
const int eventMinorSix = 24;
const int eventMinorSeven = 27;
const int eventMinorEight = 33;

/* -------------------------- UTILITY FUNCTIONS -------------------------- */

void clearScreen() {    // Clears the terminal
    system("cls");
}

/* -------------------------- MAIN MENU -------------------------- */

int mainUI() {
    printf("╔═══════════════════════════╗\n");
    printf("║         Game Menu         ║\n");
    printf("╚═══════════════════════════╝\n");
    printf(" Select a number.            \n");
    printf("  1 | Start                  \n");
    printf("  2 | Settings               \n");
    printf("  3 | Exit                   \n");
    printf("╔═══════════════════════════╗\n");
    printf("╚ Input:");
    int input;
    scanf("%d", &input);
    fflush(stdin); // Clears bad inputs
    return input;
}

/* -------------------------- SETTINGS MENU -------------------------- */

int settingUI() {
    printf("╔═══════════════════════════╗\n");
    printf("║        Settings Tab       ║\n");
    printf("╚═══════════════════════════╝\n");
    printf(" Select a number.            \n");
    printf("  1 | Clear Data             \n");
    printf("  2 | Back                   \n");
    printf("╔═══════════════════════════╗\n");
    printf("╚ Input:");
    int input;
    scanf("%d", &input);
    fflush(stdin); // Clears bad inputs
    return input;
}

/* Reset all progress and variables */
void clearData(int* day) {
    *day = 0;
    userMoney = 5;
    userSanity = 7;
    userFamily = 5;
    moneyChange = 0;
    sanityChange = 0;
    familyChange = 0;
    billsChange = 0;
}

/* -------------------------- EVENT HANDLERS -------------------------- */

void eventGameHandler(const int* day) {
    /* Handles random events such as increased rent or achievements */
    if (*day == 14 || *day == 25 || *day == 32) {
        printf("╔═════════════════════════════╗\n");
        printf("║ Your landlord increased     ║\n");
        printf("║ the rent all of a sudden!   ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        bills += 1;
        billsChange += 1;
        fflush(stdin);
        getchar();
    }
    else if (*day == 25) {
        printf("╔═════════════════════════════╗\n");
        printf("║ Your child's treatment got  ║\n");
        printf("║ more expensive!             ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        bills += 1;
        billsChange += 1;
        fflush(stdin);
        getchar();
    }
    else if (workStreakCheck == 1) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You've worked so hard you   ║\n");
        printf("║ managed to pay off some of  ║\n");
        printf("║ your debts!                 ║\n");
        printf("║          (-2 Bills)         ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        bills -= 2;
        billsChange -= 2;
        fflush(stdin);
        getchar();
    }

    // Reward for maintaining a 3-day work streak
    if (workStreak == 3 && workStreakCheck == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You've been working so hard ║\n");
        printf("║ your boss gave you a bonus! ║\n");
        printf("║          (+5 Money)         ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        userMoney += 5;
        workStreakCheck += 1;
        moneyChange += 5;
        fflush(stdin);
        getchar();

    }
}

/* Handles daily random and major life events (choices affect stats) */
void eventHandler(const int *day) {
    clearScreen();
    int choice = 0;
    // MAJOR EVENTS
    if (*day == eventMajorOne) {
        printf("╔══════════════════════════════════════════════════╗\n");
        printf("║ Medical Bill | Event                             ║\n");
        printf("║                                                  ║\n");
        printf("║                Your child got sick.              ║\n");
        printf("║                                                  ║\n");
        printf("║══════════════════════════════════════════════════║\n");
        printf("║  1 | Ignore it               2 | Pay treatment   ║\n");
        printf("║    (-4 Fam -1 San)             (+1 Bills +2 Fam) ║\n");
        printf("╚══════════════════════════════════════════════════╝\n");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1) {
            userFamily -= 5;
            userSanity -= 1;
            familyChange -= 4;
            sanityChange -= 1;
        }
        else {
            bills += 1;
            userFamily += 2;
            billsChange += 1;
            familyChange += 2;
        }
    }
    else if (*day == eventMajorTwo) {
        printf("╔══════════════════════════════════════════════════╗\n");
        printf("║ Financial Offer | Event                          ║\n");
        printf("║                                                  ║\n");
        printf("║       A coworker suggests shady accounting..     ║\n");
        printf("║                                                  ║\n");
        printf("║══════════════════════════════════════════════════║\n");
        printf("║  1 | Accept               2 | Refuse             ║\n");
        printf("║    (+5 Mon -3 San)          (+2 Fam -1 Mon)      ║\n");
        printf("╚══════════════════════════════════════════════════╝\n");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1) {
            userMoney += 5;
            userSanity -= 3;
            moneyChange += 5;
            sanityChange -= 3;
        }
        else {
            userMoney -= 1;
            userFamily += 2;
            moneyChange -= 1;
            familyChange += 2;
        }
    }
    else if (*day == eventMajorThree) {
     printf("╔══════════════════════════════════════════════════╗\n");
     printf("║ Company Scandal | Event                          ║\n");
     printf("║                                                  ║\n");
     printf("║        Your boss asks you to lie for him.        ║\n");
     printf("║                                                  ║\n");
     printf("║══════════════════════════════════════════════════║\n");
     printf("║  1 | Agree                   2 | Decline         ║\n");
     printf("║    (+5 Mon -2 San -3 Fam)      (+3 San -2 Mon)   ║\n");
     printf("╚══════════════════════════════════════════════════╝\n");
     scanf("%d", &choice);
     fflush(stdin);
     if (choice == 1) {
      userMoney += 5;
      userSanity -= 2;
      userFamily -= 3;
         moneyChange += 5;
         sanityChange -= 2;
         familyChange -= 3;
     }
     else {
      userMoney -= 2;
      userSanity += 3;
         moneyChange -= 2;
         sanityChange += 3;
     }
    }
    else if (*day == eventMajorFour) {
     printf("╔══════════════════════════════════════════════════╗\n");
     printf("║ Family Ultimatum | Event                         ║\n");
     printf("║                                                  ║\n");
     printf("║       Your partner says you’re never home.       ║\n");
     printf("║                                                  ║\n");
     printf("║══════════════════════════════════════════════════║\n");
     printf("║  1 | Promise to change      2 | Defend yourself  ║\n");
     printf("║    (+5 Fam -3 Mon)            (-3 Fam +1 San)    ║\n");
     printf("╚══════════════════════════════════════════════════╝\n");
     scanf("%d", &choice);
     fflush(stdin);
     if (choice == 1) {
      userMoney -= 3;
      userFamily += 5;
         moneyChange -= 3;
         familyChange += 5;
     }
     else {
      userFamily -= 3;
      userSanity += 1;
         familyChange -= 3;
         sanityChange += 1;
     }
    }
    // MINOR EVENTS
    else if (*day == eventMinorOne) {
     printf("╔══════════════════════════════════════════════════╗\n");
     printf("║ Alarm Failure | Event                            ║\n");
     printf("║                                                  ║\n");
     printf("║                 You overslept.                   ║\n");
     printf("║                                                  ║\n");
     printf("║══════════════════════════════════════════════════║\n");
     printf("║  1 | Rush to work          2 | Take your time    ║\n");
     printf("║    (-1 San +1 Mon)           (+1 San -1 Mon)     ║\n");
     printf("╚══════════════════════════════════════════════════╝\n");
     scanf("%d", &choice);
     fflush(stdin);
     if (choice == 1) {
      userMoney += 1;
      userSanity -= 1;
         moneyChange += 1;
         sanityChange -= 1;
     }
     else {
      userSanity += 1;
      userMoney -= 1;
         sanityChange += 1;
         moneyChange -= 1;
     }
    }
    else if (*day == eventMinorTwo) {
     printf("╔══════════════════════════════════════════════════╗\n");
     printf("║ Coffee Spill | Event                             ║\n");
     printf("║                                                  ║\n");
     printf("║     You spilled coffee on a coworker’s report.   ║\n");
     printf("║                                                  ║\n");
     printf("║══════════════════════════════════════════════════║\n");
     printf("║  1 | Apologize        2 | Pretend it wasn't you  ║\n");
     printf("║    (-1 San +1 Fam)      (-1 Fam +1 San)          ║\n");
     printf("╚══════════════════════════════════════════════════╝\n");
     scanf("%d", &choice);
     fflush(stdin);
     if (choice == 1) {
      userSanity -= 1;
      userFamily += 1;
         sanityChange -= 1;
         familyChange += 1;
     }
     else {
      userFamily -= 1;
      userSanity += 1;
         familyChange -= 1;
         sanityChange += 1;
     }
    }
    else if (*day == eventMinorThree) {
     printf("╔══════════════════════════════════════════════════╗\n");
     printf("║ Family Ultimatum | Event                         ║\n");
     printf("║                                                  ║\n");
     printf("║     You’re offered a high-paying job in          ║\n");
     printf("║     another city.                                ║\n");
     printf("║                                                  ║\n");
     printf("║══════════════════════════════════════════════════║\n");
     printf("║  1 | Accept                2 | Stay              ║\n");
     printf("║    (-2 Bills -4 Fam)         (+3 Fam -2 Mon)     ║\n");
     printf("╚══════════════════════════════════════════════════╝\n");
     scanf("%d", &choice);
     fflush(stdin);
     if (choice == 1) {
      bills -= 2;
      userFamily -= 4;
         billsChange -= 2;
         familyChange -= 4;
     }
     else {
      userFamily += 3;
      userMoney -= 2;
         familyChange += 3;
         moneyChange -= 2;
     }
    }
    else if (*day == eventMinorFour) {
     printf("╔══════════════════════════════════════════════════╗\n");
     printf("║ Missed Message | Event                           ║\n");
     printf("║                                                  ║\n");
     printf("║     Your partner texted but you didn’t reply.    ║\n");
     printf("║                                                  ║\n");
     printf("║══════════════════════════════════════════════════║\n");
     printf("║  1 | Call back later         2 | Ignore it       ║\n");
     printf("║    (-1 San +1 Fam)             (-2 Fam +1 San)   ║\n");
     printf("╚══════════════════════════════════════════════════╝\n");
     scanf("%d", &choice);
     fflush(stdin);
     if (choice == 1) {
      userSanity -= 1;
      userFamily += 1;
         sanityChange -= 1;
         familyChange += 1;
     }
     else {
      userFamily -= 2;
      userSanity += 1;
         familyChange -= 2;
         sanityChange += 1;
     }
    }
    else if (*day == eventMinorFive) {
     printf("╔══════════════════════════════════════════════════╗\n");
     printf("║ Late Train | Event                               ║\n");
     printf("║                                                  ║\n");
     printf("║               You’re stuck waiting.              ║\n");
     printf("║                                                  ║\n");
     printf("║══════════════════════════════════════════════════║\n");
     printf("║  1 | Read a book         2 | Run to work         ║\n");
     printf("║    (+1 San)                (+1 Mon -1 San)       ║\n");
     printf("╚══════════════════════════════════════════════════╝\n");
     scanf("%d", &choice);
     fflush(stdin);
     if (choice == 1) {
      userSanity += 1;
         sanityChange += 1;
     }
     else {
      userMoney += 1;
      userSanity -= 1;
         moneyChange += 1;
         sanityChange -= 1;
     }
    }
    else if (*day == eventMinorSix) {
     printf("╔══════════════════════════════════════════════════╗\n");
     printf("║ Family Dinner | Event                            ║\n");
     printf("║                                                  ║\n");
     printf("║           You’re invited to eat together.        ║\n");
     printf("║                                                  ║\n");
     printf("║══════════════════════════════════════════════════║\n");
     printf("║  1 | Join                2 | Skip                ║\n");
     printf("║    (+1 Fam -1 San)         (-1 Fam +1 San)       ║\n");
     printf("╚══════════════════════════════════════════════════╝\n");
     scanf("%d", &choice);
     fflush(stdin);
     if (choice == 1) {
      userFamily += 1;
      userSanity -= 1;
         familyChange += 1;
         sanityChange -= 1;
     }
     else {
      userFamily -= 1;
      userSanity += 1;
         familyChange -= 1;
         sanityChange += 1;
     }
    }
    else if (*day == eventMinorSeven) {
     printf("╔══════════════════════════════════════════════════╗\n");
     printf("║ Rainstorm | Event                                ║\n");
     printf("║                                                  ║\n");
     printf("║             Your commute gets soaked.            ║\n");
     printf("║                                                  ║\n");
     printf("║══════════════════════════════════════════════════║\n");
     printf("║  1 | Work anyway         2 | Stay home           ║\n");
     printf("║    (+1 Mon -1 San)         (-1 Mon +1 San)       ║\n");
     printf("╚══════════════════════════════════════════════════╝\n");
     scanf("%d", &choice);
     fflush(stdin);
     if (choice == 1) {
      userMoney += 1;
      userSanity -= 1;
         moneyChange += 1;
         sanityChange -= 1;
     }
     else {
      userMoney -= 1;
      userSanity += 1;
         moneyChange -= 1;
         sanityChange += 1;
     }
    }
    else if (*day == eventMinorEight) {
     printf("╔══════════════════════════════════════════════════╗\n");
     printf("║ Power Outage | Event                             ║\n");
     printf("║                                                  ║\n");
     printf("║   Electricity went out while you were resting.   ║\n");
     printf("║                                                  ║\n");
     printf("║══════════════════════════════════════════════════║\n");
     printf("║  1 | Wait calmly         2 | Go home             ║\n");
     printf("║    (+1 Mon +1 San)         (+1 Fam +1 San)       ║\n");
     printf("╚══════════════════════════════════════════════════╝\n");
     scanf("%d", &choice);
     fflush(stdin);
     if (choice == 1) {
      userMoney += 1;
      userSanity += 1;
         moneyChange += 1;
         sanityChange += 1;
     }
     else {
      userFamily += 1;
      userSanity += 1;
         familyChange += 1;
         sanityChange += 1;
     }
    }
    else {
        printf("\v");
    }
}

/* -------------------------- DAILY PROMPTS -------------------------- */

void morningOnePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You made a simple breakfast ║\n");
        printf("║ and felt ready for the day. ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You brewed coffee and sat   ║\n");
        printf("║ quietly before work.        ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void morningTwoPrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You skipped breakfast and   ║\n");
        printf("║ rushed to prepare for work. ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You left home hungry but    ║\n");
        printf("║ saved a few coins today.    ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void morningThreePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You read the morning paper  ║\n");
        printf("║ and sighed at the headlines.║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You scrolled through news,  ║\n");
        printf("║ feeling drained by it all.  ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void morningFourPrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You left home early and saw ║\n");
        printf("║ the sunrise on your way.    ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You hurried to work, hoping ║\n");
        printf("║ to make a good impression.  ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void morningFivePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You rolled over and took a  ║\n");
        printf("║ few more minutes of peace.  ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You stayed in bed longer,   ║\n");
        printf("║ ignoring your schedule.     ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void morningUI(const int* day) {
    printf("╔═════════════════════════════════════════════════════════╗\n");
    printf("║                      Morning Routine                    ║\n");
    printf("╚═════════════════════════════════════════════════════════╝\n");
    printf(" You just woke up choose on how to start your day!\n");
    printf("\n");
    printf("  1 | Eat a decent breakfast    (+1 Sanity)\n");
    printf("  2 | Skip breakfast            (+1 Money -1 Sanity)\n");
    printf("  3 | Read the news             (+1 Sanity -1 Family)\n");
    printf("  4 | Leave early for work      (+1 Money -1 Family)\n");
    printf("  5 | Sleep in a bit            (+1 Sanity -1 Money)\n");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════╗\n");
    printf("╚ Input: ");
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            morningOnePrompt(day);
            userSanity += 1;
            sanityChange += 1;
            break;
        case 2:
            morningTwoPrompt(day);
            userSanity -= 1;
            userMoney += 1;
            sanityChange -= 1;
            moneyChange += 1;
            break;
        case 3:
            morningThreePrompt(day);
            userSanity += 1;
            userFamily -= 1;
            sanityChange += 1;
            familyChange -= 1;
            break;
        case 4:
            morningFourPrompt(day);
            userMoney += 1;
            userFamily -= 1;
            moneyChange += 1;
            familyChange -= 1;
            break;
        case 5:
            morningFivePrompt(day);
            userSanity += 1;
            userMoney -= 1;
            sanityChange += 1;
            moneyChange -= 1;
            break;
        default:
            printf("\n");
            break;
    }
}

void dayRecapUI(const int* day) {
    clearScreen();
    printf("╔═════════════════════════════════════════════════════════╗\n");
    printf("║                    End of Day Summary                   ║\n");
    printf("╚═════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("                     Day %d Summary\n", *day);
    printf("  -------------------------------------------------------\n");
    printf("   Money Change : %d -> %+d\n", *day, moneyChange);
    printf("   Sanity Change: %d -> %+d\n", userSanity, sanityChange);
    printf("   Family Change: %d -> %+d\n", userFamily, familyChange);
    printf("   Bills Change: %d -> %+d\n ", bills, billsChange);
    printf("  -------------------------------------------------------\n");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════╗\n");
    printf("║   Press Enter to continue...                            ║\n");
    printf("╚═════════════════════════════════════════════════════════╝\n");
    fflush(stdin);
    getchar();

    // Reset after
    moneyChange = 0;
    sanityChange = 0;
    familyChange = 0;
    billsChange = 0;
}

void nightOnePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You got on the bed and      ║\n");
        printf("║ went to sleep early.        ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You flopped onto the bed    ║\n");
        printf("║ and fall asleep quietly.    ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
    dayRecapUI(day);
}

void nightTwoPrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You scrolled endlessly,     ║\n");
        printf("║ losing track of time.       ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You stared at the screen,   ║\n");
        printf("║ feeling oddly empty.        ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
    dayRecapUI(day);
}

void nightThreePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You had a quiet talk about  ║\n");
        printf("║ the day’s small moments.    ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You listened to your partner║\n");
        printf("║ vent and felt closer.       ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
    dayRecapUI(day);
}

void nightFourPrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You stayed up working on    ║\n");
        printf("║ your side projects.         ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You spent hours typing,     ║\n");
        printf("║ eyes aching from the glow.  ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
    dayRecapUI(day);
}

void nightFivePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You turned on the TV and    ║\n");
        printf("║ let the noise fill the room.║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You watched reruns alone,   ║\n");
        printf("║ feeling time blur by.       ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
    dayRecapUI(day);
}

void nightUI(const int* day) {
    printf("╔═════════════════════════════════════════════════════════╗\n");
    printf("║                      Night Routine                      ║\n");
    printf("╚═════════════════════════════════════════════════════════╝\n");
    printf(" Choose how to end your day:\n");
    printf("\n");
    printf("  1 | Sleep early               (+1 Sanity)\n");
    printf("  2 | Scroll on your phone      (+1 Sanity -1 Family)\n");
    printf("  3 | Talk with your partner    (+1 Family -1 Sanity)\n");
    printf("  4 | Do side-hustles           (+2 Money -2 Sanity)\n");
    printf("  5 | Watch TV alone            (+1 Sanity -1 Family)\n");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════╗\n");
    printf("╚ Input: ");
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            nightOnePrompt(day);
            userSanity += 1;
            sanityChange += 1;
            break;
        case 2:
            nightTwoPrompt(day);
            userSanity += 1;
            userFamily -= 1;
            sanityChange += 1;
            familyChange -= 1;
            break;
        case 3:
            nightThreePrompt(day);
            userFamily += 1;
            userSanity -= 1;
            familyChange += 1;
            sanityChange -= 1;
            break;
        case 4:
            nightFourPrompt(day);
            userMoney += 2;
            userSanity -= 2;
            moneyChange += 2;
            sanityChange -= 2;
            break;
        case 5:
            nightFivePrompt(day);
            userSanity += 1;
            userFamily -= 1;
            sanityChange += 1;
            familyChange -= 1;
            break;
        default:
            printf("\n");
            break;
    }
}

void tutorialUI(const int* day,const int* tempUserMoney,const int* tempUserSanity,const int* tempUserFamily) {
    clearScreen();
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("║                  Tutorial | Balancing Life                  ║\n");
    printf("╚═════════════════════════════════════════════════════════════╝\n");
    printf("  Goal:\n");
    printf("    The goal of the game is to survive for 5 WEEKS\n");
    printf("  Losing Conditions:\n");
    printf("    If any of your stats (Money, Sanity, Family) goes 0\n");
    printf("    you lose the game.\n");
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("║ This is the information tab where you can see your progress ║\n");
    printf("║ and status. Daily bills? it's what you have to pay every day║\n");
    printf("║ your daily bills can change throughout the game depending   ║\n");
    printf("║ on your choices or random events.                           ║\n");
    printf("╚═════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf(" Information:                                                  \n");
    printf("  Day:    %d\n", *day);
    printf(" The first number is your initial stat the > no. is your NEW stat\n");
    printf("  Money:  %d > %d\n", *tempUserMoney, userMoney);
    printf("  Sanity: %d > %d\n", *tempUserSanity, userSanity);
    printf("  Family: %d > %d\n", *tempUserFamily, userFamily);
    printf("  Daily bills:   %d", bills);
    printf("\n");
    printf("  Goal: Survive for 5 weeks! \n");
    printf("       (Do not let one reach 0)              \n");
    printf("  \n");
    printf("      !!  IF YOU'RE READY TO START THE GAME PRESS ENTER  !!     \n");
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("╚ Input:");
    fflush(stdin);
    getchar();
}

int startUI(const int* day,const int* tempUserMoney,const int* tempUserSanity,const int* tempUserFamily) {
    if (*day == 0) {
        tutorialUI(day, tempUserMoney, tempUserSanity, tempUserFamily);
    }
    clearScreen();
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("║                          Balancing Life                     ║\n");
    printf("╚═════════════════════════════════════════════════════════════╝\n");
    printf(" Select a number.                           \n");
    printf("  1 | Go to Work                            \n");
    printf("  2 | Rest                                  \n");
    printf("  3 | Spend Time with Family                \n");
    printf("  4 | Main Menu             (Save Progress) \n");
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf(" Information:                                                  \n");
    printf("  Day:    %d\n", *day);
    printf("  Money:  %d > %d\n", *tempUserMoney, userMoney);
    printf("  Sanity: %d > %d\n", *tempUserSanity, userSanity);
    printf("  Family: %d > %d\n", *tempUserFamily, userFamily);
    printf("  Daily bills:   %d", bills);
    printf("  \n");
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("╚ Input:");
    int input;
    scanf("%d", &input);
    fflush(stdin); // Clears bad inputs
    return input;
}

void workOnePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You organized today's paper ║\n");
        printf("║ work before reviewing them. ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
    else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You start code-proofing the ║\n");
        printf("║ team's program earnestly.   ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void gotoWorkOne(int* day) {
    workOnePrompt(day);
    (*day)++;
    if (*day > userHighscore) {
        userHighscore = *day;
    }
    userMoney += 3;
    userSanity -= 1;
    userFamily -= 1;
    moneyChange += 3;
    sanityChange -= 1;
    familyChange -= 1;
    workStreak += 1;
    nightUI(day);
}

void workTwoPrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You maintain the company’s  ║\n");
        printf("║ client database today.      ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You cleaned and updated old ║\n");
        printf("║ employee records.           ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void gotoWorkTwo(int* day) {
    workTwoPrompt(day);
    (*day)++;
    if (*day > userHighscore) {
        userHighscore = *day;
    }
    userMoney += 4;
    userSanity -= 2;
    userFamily -= 1;
    moneyChange += 4;
    sanityChange -= 2;
    familyChange -= 1;
    workStreak += 1;
    nightUI(day);
}

void workThreePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You stayed late to finish   ║\n");
        printf("║ the pending project tasks.  ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You handled last-minute bug ║\n");
        printf("║ reports from the clients.   ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void gotoWorkThree(int* day) {
    workThreePrompt(day);
    (*day)++;
    if (*day > userHighscore) {
        userHighscore = *day;
    }
    userMoney += 5;
    userSanity -= 2;
    userFamily -= 2;
    moneyChange += 5;
    sanityChange -= 2;
    familyChange -= 2;
    workStreak += 1;
    nightUI(day);
}

int workUI(int* day) {
    printf("╔══════════════════════════════════════════╗\n");
    printf("║               Work Tab | Co.             ║\n");
    printf("╚══════════════════════════════════════════╝\n");
    printf(" Select a number.                           \n");
    printf("  1 | Do your menial paper work             \n");
    printf("      > (+3 Money) (-1 Family) (-1 Sanity)  \n");
    printf("                                            \n");
    printf("  2 | Maintain Company Database             \n");
    printf("      > (+4 Money) (-1 Family) (-2 Sanity)  \n");
    printf("                                            \n");
    printf("  3 | Work Overtime                         \n");
    printf("      > (+5 Money) (-2 Family) (-2 Sanity)  \n");
    printf("                                            \n");
    printf("  4 | Back                   (back to menu) \n");
    printf("╔══════════════════════════════════════════╗\n");
    printf("╚ Input:");
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            gotoWorkOne(day);
            break;
        case 2:
            gotoWorkTwo(day);
            break;
        case 3:
            gotoWorkThree(day);
            break;
        case 4:
            return 4;
        default:
            printf("\n");
            printf("System ║ Invalid input!\n");
            break;

    }
    return 0;
}

void familyOnePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You spent a quiet evening   ║\n");
        printf("║ talking with your family.   ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You helped your family with ║\n");
        printf("║ small chores at home.       ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void gotoFamilyOne(int* day) {
    familyOnePrompt(day);
    (*day)++;
    if (*day > userHighscore) {
        userHighscore = *day;
    }
    userMoney -= bills;
    userSanity -= 1;
    userFamily += 1;
    moneyChange -= bills;
    sanityChange -= 1;
    familyChange += 1;
    workStreak = 0;
    nightUI(day);
}

void familyTwoPrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You treated your family to  ║\n");
        printf("║ a cozy dinner downtown.     ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You shared a simple meal at ║\n");
        printf("║ your favorite diner.        ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void gotoFamilyTwo(int* day) {
    familyTwoPrompt(day);
    (*day)++;
    if (*day > userHighscore) {
        userHighscore = *day;
    }
    userMoney -= bills + 2;
    userSanity -= 1;
    userFamily += 3;
    moneyChange -= bills + 2;
    sanityChange -= 1;
    familyChange += 3;
    workStreak = 0;
    nightUI(day);
}

void familyThreePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You went on a short trip to ║\n");
        printf("║ the countryside together.   ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You took your family on a   ║\n");
        printf("║ weekend holiday by the sea. ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void gotoFamilyThree(int* day) {
    familyThreePrompt(day);
    (*day)++;
    if (*day > userHighscore) {
        userHighscore = *day;
    }
    userMoney -= bills + 4;
    userSanity -= 2;
    userFamily += 5;
    moneyChange -= bills + 4;
    sanityChange -= 2;
    familyChange += 5;
    workStreak = 0;
    nightUI(day);
}

int familyUI(int* day) {
    printf("╔══════════════════════════════════════════╗\n");
    printf("║           Family Bonding | Tab           ║\n");
    printf("╚══════════════════════════════════════════╝\n");
    printf(" Select a number.                           \n");
    printf("  1 | Spend time with them                  \n");
    printf("      > (+1 Family) (-1 Sanity)             \n");
    printf("                                            \n");
    printf("  2 | Take them out to eat                  \n");
    printf("      > (-2 Money) (+3 Family) (-1 Sanity)  \n");
    printf("                                            \n");
    printf("  3 | Go on a family holiday                \n");
    printf("      > (-4 Money) (-5 Family) (-2 Sanity)  \n");
    printf("                                            \n");
    printf("  4 | Back                   (back to menu) \n");
    printf("╔══════════════════════════════════════════╗\n");
    printf("╚ Input:");
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            gotoFamilyOne(day);
            break;
        case 2:
            gotoFamilyTwo(day);
            break;
        case 3:
            gotoFamilyThree(day);
            break;
        case 4:
            return 4;
        default:
            printf("\n");
            printf("System ║ Invalid input!\n");
            break;

    }
    return 0;
}

void restOnePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You took a long nap and     ║\n");
        printf("║ woke up feeling lighter.    ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You slept through most of   ║\n");
        printf("║ the day to recharge.        ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void gotoRestOne(int* day) {
    restOnePrompt(day);
    (*day)++;
    if (*day > userHighscore) {
        userHighscore = *day;
    }
    userMoney -= bills;
    userSanity += 1;
    moneyChange -= bills;
    sanityChange += 1;
    workStreak = 0;
    nightUI(day);
}

void restTwoPrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You treated yourself to a   ║\n");
        printf("║ warm meal and quiet time.   ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You bought something small  ║\n");
        printf("║ to lift your mood.          ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void gotoRestTwo(int* day) {
    restTwoPrompt(day);
    (*day)++;
    if (*day > userHighscore) {
        userHighscore = *day;
    }
    userMoney -= bills + 1;
    userSanity += 2;
    userFamily -= 1;
    moneyChange -= bills + 1;
    sanityChange += 2;
    familyChange -= 1;
    workStreak = 0;
    nightUI(day);
}

void restThreePrompt(const int* day) {
    clearScreen();
    if (*day % 2 == 0) {
        printf("╔═════════════════════════════╗\n");
        printf("║ You tried painting for the  ║\n");
        printf("║ first time in a while.      ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    } else {
        printf("╔═════════════════════════════╗\n");
        printf("║ You started learning guitar ║\n");
        printf("║ to relax your mind.         ║\n");
        printf("║═════════════════════════════║\n");
        printf("║  Enter any key to continue  ║\n");
        printf("╚═════════════════════════════╝\n");
        fflush(stdin);
        getchar();
    }
}

void gotoRestThree(int* day) {
    restThreePrompt(day);
    (*day)++;
    if (*day > userHighscore) {
        userHighscore = *day;
    }
    userMoney -= bills + 3;
    userSanity += 5;
    userFamily -= 1;
    moneyChange -= bills + 3;
    sanityChange += 5;
    familyChange -= 1;
    workStreak = 0;
    nightUI(day);
}

int restUI(int* day) {
    printf("╔══════════════════════════════════════════╗\n");
    printf("║           Resting Tab | Soothe           ║\n");
    printf("╚══════════════════════════════════════════╝\n");
    printf(" Select a number.                           \n");
    printf("  1 | Sleep it off                          \n");
    printf("      > (+1 Sanity)             \n");
    printf("                                            \n");
    printf("  2 | Treat yourself                        \n");
    printf("      > (-1 Money) (-1 Family) (+2 Sanity)  \n");
    printf("                                            \n");
    printf("  3 | Start a new Hobby                     \n");
    printf("      > (-3 Money) (-1 Family) (+5 Sanity)  \n");
    printf("                                            \n");
    printf("  4 | Back                   (back to menu) \n");
    printf("╔══════════════════════════════════════════╗\n");
    printf("╚ Input:");
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            gotoRestOne(day);
            break;
        case 2:
            gotoRestTwo(day);
            break;
        case 3:
            gotoRestThree(day);
            break;
        case 4:
            return 4;
        default:
            printf("\n");
            printf("System | Invalid input!\n");
            break;

    }
    return 0;
}

/* -------------------------- MAIN GAME LOOP -------------------------- */

int main(void) {
    system("chcp 65001 >nul");
    bool mainState = true;
    int userDay = 0;

    // Main loop controls state navigation
    while(mainState) {
        clearScreen();
        system("color 0B");
        switch (mainUI()) {
            case 1:
                ;
                bool startState = true;

                while (startState) {

                    // Store daily stat snapshots for recap
                    const int tempUserMoney = userMoney;
                    const int tempUserSanity = userSanity;
                    const int tempUserFamily = userFamily;

                    clearScreen();
                    eventHandler(&userDay);
                    eventGameHandler(&userDay);
                    morningUI(&userDay);

                    // Game over conditions
                    if (userMoney <= 0) {
                        clearScreen();
                        printf("\n");
                        printf("╔═══════════════════════════╗\n");
                        printf("║       BROKE ENDING        ║\n");
                        printf("║═══════════════════════════║\n");
                        printf(" You ran out of money.       \n");
                        printf(" The bills piled up, and     \n");
                        printf(" you lost everything.        \n");
                        printf("╔═══════════════════════════╗\n");
                        printf("║        GAME  OVER         ║\n");
                        printf("║ Highscore: %d day(s)      ║\n", userHighscore);
                        printf("║═══════════════════════════║\n");
                        printf("║ Enter any key to continue ║\n");
                        printf("╚═══════════════════════════╝\n");
                        clearData(&userDay);
                        fflush(stdin);
                        getchar();
                        startState = false;
                    }
                    else if (userSanity <= 0) {
                        clearScreen();
                        printf("\n");
                        printf("╔═══════════════════════════╗\n");
                        printf("║     LOST SANITY ENDING    ║\n");
                        printf("║═══════════════════════════║\n");
                        printf(" Your mind gave in.          \n");
                        printf(" The stress became too much. \n");
                        printf(" You couldn't go on.         \n");
                        printf("╔═══════════════════════════╗\n");
                        printf("║        GAME  OVER         ║\n");
                        printf("║ Highscore: %d day(s)      ║\n", userHighscore);
                        printf("║═══════════════════════════║\n");
                        printf("║ Enter any key to continue ║\n");
                        printf("╚═══════════════════════════╝\n");
                        clearData(&userDay);
                        fflush(stdin);
                        getchar();
                        startState = false;
                    }

                    else if (userFamily <= 0) {
                        clearScreen();
                        printf("\n");
                        printf("╔═══════════════════════════╗\n");
                        printf("║       DIVORCE ENDING      ║\n");
                        printf("║═══════════════════════════║\n");
                        printf(" Your family left you.       \n");
                        printf(" The distance grew cold.     \n");
                        printf(" You ended up alone.         \n");
                        printf("╔═══════════════════════════╗\n");
                        printf("║        GAME  OVER         ║\n");
                        printf("║ Highscore: %d day(s)      ║\n", userHighscore);
                        printf("║═══════════════════════════║\n");
                        printf("║ Enter any key to continue ║\n");
                        printf("╚═══════════════════════════╝\n");
                        clearData(&userDay);
                        fflush(stdin);
                        getchar();
                        startState = false;
                    }

                    // If still alive, continue daily actions
                    else if (userDay <= WEEK5) {
                        switch (startUI(&userDay, &tempUserMoney, &tempUserSanity, &tempUserFamily)) {
                            case 1:
                                clearScreen();
                                workUI(&userDay);
                                break;
                            case 2:
                                clearScreen();
                                restUI(&userDay);
                                break;
                            case 3:
                                clearScreen();
                                familyUI(&userDay);
                                break;
                            case 4:
                                startState = false;
                                break;
                            default:
                                break;
                        }
                    }
                    // Win condition
                    else {
                        printf("\n");
                        printf("╔═══════════════════════════════════════╗\n");
                        printf("║              GOOD ENDING              ║\n");
                        printf("║═══════════════════════════════════════║\n");
                        printf("         You survived the week!          \n");
                        printf(" Balanced life is hard, but you made it. \n");
                        printf("╔═══════════════════════════════════════╗\n");
                        printf("║              YOU MADE IT              ║\n");
                        printf("║═══════════════════════════════════════║\n");
                        printf("║       Enter any key to continue       ║\n");
                        printf("╚═══════════════════════════════════════╝\n");
                        clearData(&userDay);
                        fflush(stdin);
                        getchar();
                        break;
                    }
                }
                break;

            case 2:
                ;
                bool settingState = true;

                while (settingState) {
                    clearScreen();
                    switch (settingUI()) {
                        case 1:
                            clearScreen();
                            printf("\n");
                            printf("╔═══════════════════════════╗\n");
                            printf("║        Data Cleared       ║\n");
                            printf("║═══════════════════════════║\n");
                            printf("║ Enter any key to continue ║\n");
                            printf("╚═══════════════════════════╝\n");
                            clearData(&userDay);
                            fflush(stdin);
                            getchar();
                            break;

                        case 2:
                            settingState = false;
                            break;

                        default:
                            printf("\n");
                            printf("System | Invalid input!\n");
                            break;
                    }
                }
                break;

            case 3:
                mainState = false;
                printf("\n");
                printf("System | Exiting Program!");
                break;

            default:
                printf("\n");
                printf("System | Invalid input!\n");
                break;
        }
    }
    return 0;
}