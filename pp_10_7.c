#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 10

int segments[MAX_DIGITS][7] = { 
        {1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1},
        {1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1}
    };

char digits[4][MAX_DIGITS*4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

void clear_digits_array(){
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < MAX_DIGITS * 4; j++)
            digits[i][j] = ' ';
}

void process_digit(int digit, int position){
    for (int i = 0; i < 7; i++){
        switch (i)
        {
        case 0:
            if(segments[digit][i]) digits[0][position*4+1] = '_';
            break;
        case 1:
            if(segments[digit][i]) digits[1][position*4+2] = '|';
            break;
        case 2:
            if(segments[digit][i]) digits[2][position*4+2] = '|';
            break;
        case 3:
            if(segments[digit][i]) digits[2][position*4+1] = '_';
            break;
        case 4:
            if(segments[digit][i]) digits[2][position*4+0] = '|';
            break;
        case 5:
            if(segments[digit][i]) digits[1][position*4+0] = '|';
            break;
        case 6:
            if(segments[digit][i]) digits[1][position*4+1] = '_';
            break;                    
        default:
            break;
        }
    }
}

void print_digits_array(){
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < MAX_DIGITS * 4; j++){
            printf("%c",digits[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int position; 
    char digit;
    bool loop_end;
    clear_digits_array();
    printf("Enter a number:");
    position = 0;
    for(;;){
        loop_end = false;
        scanf("%c", &digit);
        switch (digit)
        {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            process_digit(digit - 48, position);
            position++;
            break;
        case '\n':
            loop_end = true;
            break;
        default:
            break;
        }
        if (loop_end) break;       
    }
    print_digits_array();
    return 0;
}
