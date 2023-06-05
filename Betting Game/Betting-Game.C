#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void Play(int bet){
    char C[3] = {'J','Q','K'};
    printf("Shuffling.......\n");
    srand(time(0));
    for (int i =0; i<5; i++)
    {
        int x = (rand()%3);
        int y = (rand()%3);
        //swap five times
        char temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }
    int position;
    printf("Guess the position of Queen - 1, 2 or 3: ");
    scanf("%d",&position);
    if (C[position-1]=='Q')
    {
        cash+= 3*bet;
        printf("You Won\n");
    }
    else
    {
        cash-= bet;
        printf("You Lost\n");
    }
    printf("Cash youhave currently is $%d\n",cash);
}


int main(){
    int bet;
    printf("Welcome to Virtual Game\n");
    printf("~--~--~--~--~--~--~--~--~--~\n");
    printf("You have $100 right now.\n");
    while (cash>0)
    {
        printf("Enter amount you want to bet: $");
        scanf("%d",&bet);
        if (bet == 0 || bet>cash) break;
        Play(bet);
    }
    printf("Game Over!!");
    return 0;
}
