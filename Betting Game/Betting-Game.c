#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void Play(int bet){
    char C[3] = {'J','Q','K'};
    printf("Shuffling.......\n");
    srand(time(0));
    int position = (rand()%3);
    if (C[position]=='Q')
    {
        cash+= 3*bet;
    }
    else
    {
        cash-= bet;
    }
    printf("Cash youhave currently is %d\n",cash);
}


int main(){
    int bet;
    while (cash>0)
    {
        printf("Enter amount you want to bet: ");
        scanf("%d",&bet);
        if (bet == 0 || bet>cash) break;
        Play(bet);
    }
    printf("Game Over!!");
    return 0;
}
