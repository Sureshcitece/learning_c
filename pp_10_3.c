#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool flush, straight, four, three;
int pair = 0;
char hand[NUM_CARDS][2];

void read_card(){
    int num_read = 0;
    bool bad_card = false;
    char rank, suit, ch;
    while (num_read < NUM_CARDS){
        printf("Enter card:");
        rank = getchar();
        if (rank == '2' || rank == '3' || rank == '4' || rank == '5' || rank == '6' || rank == '7' || rank == '8' || rank == '9' || rank == 't' || rank == 'q' || rank == 'k' || rank == 'a')
            hand[num_read][0] = rank;
        else bad_card =  true;
        suit = getchar();
        if (suit == 'c' || suit == 'd' || suit == 'h' || suit == 's')
            hand[num_read][1] = suit;
        else bad_card = true;

        while((ch = getchar()) != '\n'){
            if(ch != ' ') bad_card =  true;
        }

        if (bad_card) printf("Bad card, ignored\n");
        else num_read++;
    }
}

void analyze_hand(void){
    //check for flush
    flush = false;
    for(int i = 0; i < NUM_CARDS; i++){
        if(hand[i][1] == hand[i+1][1]){
            if (i == 3) flush = true;
        }
        else break;
    }

    //check for straight
}

void print_result(void){
    if(flush) printf("Flush\n");
}

int main(){
    read_card();
    for(int i = 0; i < NUM_CARDS; i++)
            printf("%c %c\n", hand[i][0], hand[i][1]);
    analyze_hand();
    print_result();

    return 0;
}
