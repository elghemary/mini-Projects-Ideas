#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

int find_mysnum_mode1(int num,int mysterynumber,const int MAX,const int MIN, int shot) //function 1
// compare the mystery number and the user's number :
// if it's equal, congratulations !
//if it's not, give the player a hint !
{
    if (num>mysterynumber)
    {
        if (num>MAX)
            printf("Please enter a number smaller than %d",MAX);
        else // case 1.2 | mystery number < num |
            printf("it's smaller !");
    }
    else if (num<mysterynumber) //case 2
    {
        if (num<MIN) // case 2.1 | num < 1 <= mystery number |
            printf("Please enter a number greater than %d",MIN);
        else if (num>=MIN) // case 2.2 | num < mystery number |
            printf("it's greater !");
    }
    else //case 3 : num=mysterynumber
        if(shot==1) //grammar
            printf("\n\n        Congratulations, you find the mystery number in %d shot \n\n",shot);
        else
            printf("\n\n        Congratulations, you find the mystery number in %d shots \n\n",shot);
return 0;
}


int find_mysnum_mode2(int num,int mysteryNumber,const int MAX,const int MIN, int shot) //function 2
// compare first player's number and second player's number :
// if it's equal, congratulations !
//if it's not, give the second player a hint !
{
    if (num>mysteryNumber) //case 1
        {
            if (num>MAX) // case 1.1 | mystery number <= 100 < num |
                printf("Player 2 : Please Enter a number smaller than %d",MAX);
            else // case 1.2 | mystery number < num <= 100  |
                printf("it's smaller !");
        }
        else if (num<mysteryNumber) //case 2
        {
            if (num<MIN) // case 2.1 | num < 1 <= mystery number |
                printf("Player 2 : Please enter a number greater than %d",MIN);
            else if (num>=MIN) // case 2.2 | 1 <= num < mystery number |
                printf("it's greater !");
        }
        else // case 3 num = mystery number
            if(shot==1)
                printf("\n\n        Congratulations Player 2, you find the mystery number in %d shot \n\n",shot);
            else
                printf("\n\n        Congratulations Player 2, you find the mystery number in %d shots \n\n",shot);
return 0;
}

int get_mysnum(int mysteryNumber,const int MIN,const int MAX) // function 3
//make sure that player 1 gives relevant mystery numbers to the chosen level
// if it's not, ask again !
{
    while (mysteryNumber<MIN||mysteryNumber>MAX) // repeat asking for the mystery number until it respect the LEVEL 1 rules
    {
        if (mysteryNumber<MIN) // case 1
        {
            printf("Player 1 : Please Enter a number greater than %d \n\n",MIN);
            scanf("%d",&mysteryNumber);
        }
        else if (mysteryNumber>MAX) // case 2
        {
            printf("Player 1 : Please Enter a number smaller than %d\n\n",MAX);
            scanf("%d",&mysteryNumber);
        }
    }
    return mysteryNumber;
}


bool continueplaying(int continuegame) //function 4
// asking the player for a second round
{
    printf("                  ___________________________________\n");
    printf("                 (                                   )\n");
    printf("                 (    press 1 to continue playing    )\n");
    printf("                 (    press 0 to exit                )\n");
    printf("                 (___________________________________)\n\n");
    scanf("%d",&continuegame);
    return continuegame;
}
#endif
