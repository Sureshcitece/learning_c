#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void){
    int n1 = rand() % 6 + 1;
    int n2 = rand() % 6 + 1;
    printf("You rolled %d\n", n1+n2);
    return n1 + n2;
}

bool play_game(void){
    int n = roll_dice();
    if(n == 7 || n == 11){
        printf("You win!\n");
        return true;
    }
    else if(n == 2 || n == 3 || n == 12){
        printf("You lose!\n");
        return false;
    }
    else{
        printf("Your point is %d\n", n);
        while(true){
            int n2 = roll_dice();
            if(n2 == n){
                printf("You win!\n");
                return true;
            }
            else if(n2 == 7){
                printf("You lose!\n");
                return false;
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int wins = 0, losses = 0;
    for(;;){
        printf("Do you want to play a game of craps? (y/n) ");
        char c = getchar();
        while(getchar() != '\n');
        if(c == 'y' || c == 'Y'){
            if(play_game()){
                wins++;
            }
            else{
                losses++;
            }
        }
        else if(c == 'n' || c == 'N'){
            break;
        }
    }
    printf("Wins: %d, Losses: %d\n", wins, losses);
    return 0;
}