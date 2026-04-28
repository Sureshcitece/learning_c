#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

bool flush, straight, four, three;
int pair = 0;
int hand[NUM_CARDS][2];

void read_cards(){
    int cards_read = 0;
    char ch, rank_ch, suit_ch; 
    int rank, suit;
    bool bad_card;
    bool duplicate_card;

    for (int i = 0; i < NUM_CARDS; i++){
        hand[i][RANK] = 0;
        hand[i][SUIT] = 0;
    }

    while (cards_read < NUM_CARDS) {
        printf("Enter a card:");
        bad_card = false;
        rank_ch = getchar();
        switch (rank_ch)
        {
        case '0': exit(EXIT_SUCCESS);
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
        suit_ch = getchar();
        switch (suit_ch)
        {
        case 'c': suit = 0; break;
        case 'd': suit = 1; break;
        case 'h': suit = 2; break;
        case 's': suit = 3; break;
        default: bad_card = true;
        }
        while((ch = getchar()) != '\n'){
            if(ch != ' ') bad_card = true;
        }
        if (bad_card) {printf("Bad card. Ignored\n"); continue;}
        
        //check for duplicate

        for(int i = 0; i < cards_read; i++){
            if (hand[i][RANK] == rank && hand[i][SUIT] == suit){
                duplicate_card = true;
                printf("Duplicate card. Ignored\n");
            }
        }
        if(!duplicate_card){
            hand[cards_read][RANK] = rank;
            hand[cards_read][SUIT] = suit;
            cards_read++;
        }
    }
}

void analyze_hand(){

    int suit, rank, pass, cards, run;

    //sort

    for(pass = 1; pass < NUM_CARDS; pass++){
        for(cards = 0; cards < NUM_CARDS - pass; cards++){
            rank  = hand[cards][RANK];
            suit = hand[cards][SUIT];
            if(rank > hand[cards+1][RANK]){
                hand[cards][RANK] = hand[cards+1][RANK];
                hand[cards][SUIT] = hand[cards+1][SUIT];
                hand[cards+1][RANK] = rank;
                hand[cards+1][SUIT] =  suit; 
            }
        }
    }

    flush = true;
    /* check for flush*/
    suit = hand[0][SUIT];
    for(cards = 1; cards < NUM_CARDS; cards++)
    {
        if(hand[cards][SUIT] != suit)
            flush = false;
    }
    /* check for straight*/
    for(cards = 0; cards < NUM_CARDS - 1; cards++){
        if(hand[cards][RANK] != hand[cards+1][RANK])
        straight = true;
    }

     /* check for 4-of-a-kind, 3-of-a-kind, and pairs by
     looking for "runs" of cards with identical ranks */
  cards = 0;
  while (cards < NUM_CARDS) {
    rank = hand[cards][RANK];
    run = 0;
    do {
      run++;
      cards++;
    } while (cards < NUM_CARDS && hand[cards][RANK] == rank);
    switch (run) {
      case 2: pair++;      break;
      case 3: three = true; break;
      case 4: four = true;  break;
    }
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

    printf("\n\n");
}

int main() {
    for(;;){
        read_cards();
        analyze_hand();
        print_result();
    }
    return 0;
}