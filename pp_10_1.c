#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void stack_overflow(){
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void make_empty(){
    top = 0;
}

bool is_empty(){
    return top == 0;
}

bool is_full(){
    return top == STACK_SIZE;
}

void push(char c){
    if(is_full()){
        stack_overflow();
    }
    else{
        contents[top++] = c;
    }
}

int pop(){
    if(is_empty()){
        stack_overflow();
    }
    else{
        return contents[--top];
    }
}

int main(){
    printf("Enter parantheses and / braces:");
    char ch;
    while((ch = getchar()) != '\n'){
        if(ch == '(' || ch == '{')  push(ch);
        else if(ch == ')' || ch == '}') pop();
    }

    if(is_empty()){
        printf("Parantheses and / braces are nested properly\n");
    }
    else{
        printf("Parantheses and / braces are not nested properly\n");
    }
 
    return 0;   
}