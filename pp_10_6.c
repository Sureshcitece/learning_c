/*
when operand is encountered, push it into stack
when operator is encountered pop operand, perform operation, and push the result back
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

bool is_empty(){
    return top == 0;
}

bool is_full(){
    return top == STACK_SIZE;
}

void push(int ch){
    if(is_full()){
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    contents[top++] = ch;
}

int pop(){
    if(is_empty()){
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    else return contents[--top];
}

void make_empty(){
    top = 0;
}

void calculator(int operand1, int operand2, char operator){
    if(operator == '+') push(operand1 + operand2);
    if(operator == '*') push(operand1 * operand2);
    if(operator == '-') push(operand2 - operand1);
    if(operator == '/') push(operand2 / operand1);
}

int main(){
    char ch;
    int operand1, operand2;
    for(;;){
        printf("Enter an RPN expression:");
        for(;;){
            bool exit_loop = false;
            scanf(" %c", &ch);
            switch (ch)
            {
                case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                    push(ch - 48);
                    break;
                case '+': case '-': case '*': case '/':
                    operand1 = pop();
                    operand2 = pop();
                    calculator(operand1, operand2, ch);
                    break;
                case '=':
                    printf("Value of expression:%d\n", contents[--top]);
                    make_empty();
                    exit_loop = true;
                    break;
                default:
                    exit(EXIT_SUCCESS);
            }
            if(exit_loop) break;
        }
    }
    return 0;
}