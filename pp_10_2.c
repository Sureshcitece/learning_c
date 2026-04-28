#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool flush, straight, four, three;
int pair = 0;

void read_cards(int num_in_rank[], int num_in_suit[]){
    bool cards[NUM_RANKS][NUM_SUITS];
    int cards_read = 0;
    char ch;
    int rank; int suit;

    for (int rank = 0; rank < NUM_RANKS; rank++){
        num_in_rank[rank] = 0;
        for (int suit = 0; suit < NUM_SUITS; suit++){
            cards[rank][suit] =  false;
            num_in_suit[suit] = 0;
        }
    }


    while (cards_read < NUM_CARDS) {
        printf("Enter a card:");
        bool bad_card;
        ch = getchar();
        switch (ch)
        {
        case '2': rank = 0; break;
        case '3': rank = 1; break;
        case '4': rank = 2; break;
        case '5': rank = 3; break;
        case '6': rank = 4; break;
        case '7': rank = 5; break;
        case '8': rank = 6; break;
        case '9': rank = 7; break;
        case 't': rank = 8; break;
        case 'j': rank = 9; break;
        case 'q': rank = 10; break;
        case 'k': rank = 11; break;
        case 'a': rank = 12; break;
        default: bad_card = true;
        }
        ch = getchar();
                switch (ch)
        {
        case 'c': suit = 0; break;
        case 'd': suit = 1; break;
        case 'h': suit = 2; break;
        case 's': suit = 3; break;
        default: bad_card = true;
        }
        if((ch = getchar()) == '\n'){
            cards[rank][suit] = true;
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            cards_read++;
        }
        else if (bad_card) printf("Bad card. Ignored");
        else if (cards[rank][suit]) printf("Bad card. Ignored");
    }
}

void analyze_hand(int num_in_rank[], int num_in_suit[]){
    /* check for flush*/
    for(int i = 0; i < NUM_CARDS; i++)
    {
        if (num_in_suit[i] == NUM_CARDS) flush = true;
    }
    
    /* check for straight*/
    int rank = 0;
    int consec = 0;
    while(num_in_rank[rank] == 0) rank++;
    for(; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
        consec++;
    if(consec == NUM_RANKS) {straight = true; return;};

    for(int rank = 0; rank < NUM_RANKS; rank++){
        if(num_in_rank[rank] == 4) four = true;
        if(num_in_rank[rank] == 3) three = true;
        if(num_in_rank[rank] == 2) pair++;
    }
}

void print_result(void){
    if(straight && flush) printf("Straight & flush.");
    else if (four) printf("Four of a kind");
    else if (three && pair == 1) printf("Full house");
    else if (flush) printf("Flush");
    else if (three) printf("Three of a kind");
    else if (pair == 2) printf("Twi pairs");
    else if (pair ==  1) printf("Pair");
    else printf("High card");
}

int main() {
    int num_in_rank[NUM_RANKS];
    int num_in_suit[NUM_SUITS];
    for(;;){
        read_cards(num_in_rank, num_in_suit);
        analyze_hand(num_in_rank, num_in_suit);
        print_result();
    }
    return 0;
}