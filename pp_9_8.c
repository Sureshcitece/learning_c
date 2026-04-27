//simulate a game of craps

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void seed_rng(void){
    srand((unsigned)time(NULL));
}

int roll_dice(void){
    int n1 = rand() % 6 + 1;
    int n2 = rand() % 6 + 1;
    printf("You rolled %d\n", n1 + n2);
    return n1 + n2;
}

bool subsequent_roll(int point){
    int n = roll_dice();
    if(n == point){
        return true;
    }
    else if (n==7){
        return false;
    }
    else return subsequent_roll(point);

}

bool play_game(void){
    int n = roll_dice();
    if (n == 7 || n == 11){
        return true; //player wins
    }
    else if (n == 2 || n == 3 || n == 12){
        return false; //player loses
    }
    else {
        printf("Your point is %d\n", n);
        return subsequent_roll(n);
    }
}

int main(){
    int win = 0; int loss = 0;
    int ch;
    seed_rng();
    for(;;){
        if(play_game()){
          printf("You win!\n");
          win++;  
        }
        else {
            printf("You lose\n");
            loss++;
        }
        printf("Play again?");
        scanf("%d", &ch);
        if(ch == 'n' || ch == 'N')  {
            printf("Wins: %d Losses: %d", win, loss);
            break;
        }
        else continue;
    }
    
    return 0;
}
