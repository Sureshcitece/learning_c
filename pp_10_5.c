#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool flush, straight, four, three, royal, ace_low_straight;
int pair = 0;

void read_cards(int num_in_rank[], int num_in_suit[]){
    bool cards[NUM_RANKS][NUM_SUITS];
    int cards_read = 0;
    char ch, rank_ch, suit_ch; 
    int rank, suit;
    bool bad_card;

    for (int rank = 0; rank < NUM_RANKS; rank++){
        num_in_rank[rank] = 0;
        for (int suit = 0; suit < NUM_SUITS; suit++){
            cards[rank][suit] =  false;
            num_in_suit[suit] = 0;
        }
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
        if (bad_card) printf("Bad card. Ignored\n");
        else if (cards[rank][suit]) printf("Duplicate card. Ignored\n");
        else {
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            cards[rank][suit] = true;
            cards_read++;
        }
    }
}

void analyze_hand(int num_in_rank[], int num_in_suit[]){
    /*check for royal flush (ace, king, queen, jack , ten of same suit)*/
    for(int i = 0; i < NUM_CARDS; i++)
    {
        if (num_in_suit[i] == NUM_CARDS && num_in_rank[8] && num_in_rank[9] && num_in_rank[10] && num_in_rank[11] && num_in_rank[12]) 
        royal = true;
    }

    /* check for flush*/
    for(int i = 0; i < NUM_CARDS; i++)
    {
        if (num_in_suit[i] == NUM_CARDS) flush = true;
    }
    
    /* check for straight*/
    int rank = 0;
    int consec = 0;
    while(num_in_rank[rank] == 0) rank++;
    for(; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++){
        consec++;
    }
    if(consec == NUM_CARDS) {straight = true; return;}

    /*check for ace low straight (a, 2, 3, 4, 5)*/
       /* check for straight*/
    ace_low_straight = true;
    for (rank = 0; rank < 4; rank++){
        if(!num_in_rank[rank] && num_in_rank[12]) ace_low_straight = false;
    }
 
    for(rank = 0; rank < NUM_RANKS; rank++){
        if(num_in_rank[rank] == 4) four = true;
        if(num_in_rank[rank] == 3) three = true;
        if(num_in_rank[rank] == 2) pair++;
    }
}

void print_result(void){
    if(royal) printf("Royal flush.");
    else if(straight && flush) printf("Straight & flush.");
    else if (four) printf("Four of a kind");
    else if (three && pair == 1) printf("Full house");
    else if (flush) printf("Flush");
    else if (three) printf("Three of a kind");
    else if (pair == 2) printf("Twi pairs");
    else if (pair ==  1) printf("Pair");
    else if (ace_low_straight) printf("Ace low straight");
    else printf("High card");

    printf("\n\n");
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