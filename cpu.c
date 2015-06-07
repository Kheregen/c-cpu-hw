#include "cpu.h"
int mem_register;

void stack_push (struct Stack* stack){
    if(stack == NULL){
        printf("Stack is NULL.\n");
        return;
    }
    if (stack->stack_top >= 20){
        printf("Stack is full\n");
        return;
    }
    stack->stack_values[stack->stack_top] = mem_register;
    stack->stack_top++;
}

void stack_pop (struct Stack* stack){
    if(stack == NULL){
        printf("Stack is NULL.\n");
        return;
    }
    if (stack->stack_top == 0){
        printf("Stack is empty.\n");
        return;
    }
    stack->stack_values[stack->stack_top -1] = 0;
    stack->stack_top--;
}

void print (const struct Stack* stack){
    if(stack == NULL){
        printf("Stack is NULL.\n");
        return;
    }
    printf("# Register %d | ",mem_register);
    printf("Stack ");
    for(unsigned int i = 0; i< stack->stack_top; i++){
        printf("%d ", stack->stack_values[i]);
    }
    printf("\n");
}
