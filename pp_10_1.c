#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void stack_overflow(){
    printf("Stack overflow\n");
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
        return stack_overflow();
    }
    else{
        contents[top++] = c;
    }
}

int pop(){
    if(is_empty()){
        return stack_underflow();
    }
    else{
        return contents[--top];
    }
}

int main(){
    printf("Enter parantheses and / braces:");
    while(true){
        char c = getchar();
        if(c == '(' || c == '{'){
            push(c);
        }
        else if (c == ')' || c == '}'){
            pop();
        }
    }
 
    return 0;   
}