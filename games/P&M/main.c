#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "headers.h"

int find_mysnum_mode1(int num,int mysterynumber,const int MAX,const int MIN, int shot); //function 1
int find_mysnum_mode2(int num,int mysteryNumber,const int MAX,const int MIN, int shot); //function 2
int get_mysnum(int mysteryNumber,const int MIN,const int MAX); // function 3
bool continueplaying (int continuegame); //function 4


int main()
{
    int mode=0,level=0;
    int continuegame=1;
    bool continueGame=1;

    printf("\n\n\n\n");
    printf("                          (--+-+-+-+-+-+-+-+-+-+-+--)\n");
    printf("                          (|-+-+-+-+-+-+-+-+-+-+-+-|)\n");
    printf("                          (|                       |)\n");
    printf("                          (|  Welcome to P&M Game  |)\n");
    printf("                          (|                       |)\n");
    printf("                          (|-+-+-+-+-+-+-+-+-+-+-+-|)\n");
    printf("                          (--+-+-+-+-+-+-+-+-+-+-+--)\n");
    printf("\n\n\n\n");

    do  // replay game while continuGame is True
    {
        printf("     ______________________________________________________________________\n");
        printf("    (                                                                      )\n");
        printf("    (                                                                      )\n");
        printf("    (                                 MODES                                )\n");
        printf("    (                                                                      )\n");
        printf("    (                       press 1 for one player                         )\n");
        printf("    (                       press 2 for two players                        )\n");
        printf("    (                                                                      )\n");
        printf("    (                                                                      )\n");
        printf("    (______________________________________________________________________)\n\n");

        scanf("%d",&mode); //Choosing playing Mode

        //Choosing difficulty
        printf("     ______________________________________________________________________\n");
        printf("    (                                                                      )\n");
        printf("    (                                                                      )\n");
        printf("    (                                LEVELS                                )\n");
        printf("    (                                                                      )\n");
        printf("    (                                                                      )\n");
        printf("    (           Press 1 for LEVEL 1 | 1<= mystery number <= 100            )\n");
        printf("    (           press 2 for LEVEL 2 | 1<= mystery number <= 1000           )\n");
        printf("    (           press 3 for LEVEL 3 | 1<= mystery number <= 10000          )\n");
        printf("    (                                                                      )\n");
        printf("    (______________________________________________________________________)\n\n");

        scanf("%d",&level);

        int num,shot=0;
        int mysteryNumber,mysteryNumber1,mysteryNumber2,mysteryNumber3;
        const int MAX1=100,MIN=1;
        const int MAX2=1000;
        const int MAX3=10000;

        srand(time(NULL)); //*the computer choose a random mystery number
        mysteryNumber1=(rand()%(MAX1-MIN+1))+MIN; // LEVEL 1 |Easy   | 1<=mystery number<=100
        mysteryNumber2=(rand()%(MAX2-MIN+1))+MIN; // LEVEL 2 |Medium | 1<=mystery number<=1000
        mysteryNumber3=(rand()%(MAX3-MIN+1))+MIN; // LEVEL 3 |Hard   | 1<=mystery number<=10000

        switch (mode)
        {
        case 1: //MODE 1
            switch (level)
            {
            case 1: //MODE 1, LEVEL 1
                do //replaying until we find the mystery number
                {
                    printf("\n\n\nEnter a number\n\n");
                    scanf("%d",&num);
                    shot++; // how many shoots before winning

                    find_mysnum_mode1(num, mysteryNumber1, MAX1, MIN, shot); //function 1
                } while (num!=mysteryNumber1); //Congratulations :D

                    //Asking for a second round
                    continueGame=continueplaying(continuegame); //function 4
                break;

            case 2: //MODE 1, LEVEL 2
                do
                {
                    printf("\n\n\nEnter a number\n\n");
                    scanf("%d",&num);
                    shot++;

                    find_mysnum_mode1(num, mysteryNumber2, MAX2, MIN, shot);//function 1

                } while (num!=mysteryNumber2);

                continueGame=continueplaying(continuegame); //function 4
                break;

            case 3: //MODE 1, LEVEL 3
                do
                {
                    printf("\n\n\nEnter a number\n\n");
                    scanf("%d",&num);
                    shot++;

                    find_mysnum_mode1(num, mysteryNumber3, MAX3, MIN, shot); //function 1

                } while (num!=mysteryNumber3);

                continueGame=continueplaying(continuegame); //function 4
                break;
            default:
                printf("Please Enter 1, 2 or 3\n\n");
                break;
            }
            break;

        case 2: // MODE 2
            switch (level)
            {
            case 1: //MODE 2, LEVEL 1
                // Player 1 : choose a number
                // Player 2 : Tries to find it
                printf("\n\nPlayer 1 : Enter a mystery number greater than 1 and smaller than 100\n\n"); // Asking for the mystery number
                scanf("%d",&mysteryNumber);

                // the mystery number should respect the LEVEL 1 rules | 1 <= mystery number <= 100|
                mysteryNumber=get_mysnum(mysteryNumber,MIN,MAX1); //function 3

                // we got the mystery number :D

                system("cls"); // clear the screen to hide the mystery number

                do // player 2 guess the 1st player's mystery number
                {
                    printf("\n\n\nPlayer 2 : Enter a number\n\n");
                    scanf("%d",&num);
                    shot++;

                    find_mysnum_mode2(num,mysteryNumber,MAX1,MIN,shot); //function 2

                } while (num!=mysteryNumber);
                // Congratulations again :D

                // Asking for a second round
                continueGame=continueplaying(continuegame); //function 4
                break;

            case 2: //MODE 2, LEVEL 2
                printf("Player 1 : Enter a mystery number greater than 1 and smaller than 1000\n\n");
                scanf("%d",&mysteryNumber);

                mysteryNumber=get_mysnum(mysteryNumber,MIN,MAX2); //function 3
                do
                {
                    printf("\n\n\nPlayer 2 : Enter a number\n\n");
                    scanf("%d",&num);
                    shot++;

                    find_mysnum_mode2(num,mysteryNumber,MAX2,MIN,shot); //function 2
                } while (num!=mysteryNumber);

                continueGame=continueplaying(continuegame); //function 4
                break;

            case 3: //MODE 2, LEVEL 3
                printf("Player 1 : Enter a mystery number greater than 1 and smaller than 10000\n\n ");
                scanf("%d",&mysteryNumber);

                mysteryNumber=get_mysnum(mysteryNumber,MIN,MAX3); //function 3
                do
                {
                    printf("\n\n\nEnter a number\n\n");
                    scanf("%d",&num);
                    shot++;

                    find_mysnum_mode2(num,mysteryNumber,MAX3,MIN,shot); //function 2
                } while (num!=mysteryNumber);

                continueGame=continueplaying(continuegame); //function 4
            default:
                printf("Please Enter 1, 2 or 3\n\n"); // the user should press 1,2 or 3 to choose levels
            break;
            }
            break;
        default:
            printf("Please Enter 1 or 2\n\n"); //the player should press 1 or 2 to choose playing mode
            break;
        }
    }while(continueGame==1);//continue playing if bool=1, if not exit the game!
}
