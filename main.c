#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cpu.h"
#include "queue.h"
#include "cpu.c"
#include "queue.c"



void instr_run(struct Queue* queue, bool runAll, int instRunNum){

        struct Instruction* temp = queue->first;
        while(queue->first != NULL && instRunNum > 0){
            switch(temp->type){
            case(INST_ADD):
                mem_register += temp->arg;
                break;
            case(INST_SUB):
                mem_register -= temp->arg;
                break;
            case(INST_INC):
                mem_register++;
                break;
            case(INST_DEC):
                mem_register--;
                break;
            case(INST_MUL):
                mem_register *= temp->arg;
                break;
            case(INST_DIV):
                mem_register /= temp->arg;
                break;
            }
            if(!runAll){
                instRunNum--;
            }
            temp = temp->next;
            if(queue->first == queue->last){
                queue->last = temp;
            }
            free(queue->first);

            queue->first = temp;

        }

}

void instr_push(struct Stack* s){
    stack_push(s);
}

void instr_pop(struct Stack* s){
    stack_pop(s);
}

void instr_reset(struct Queue* q){
    struct Instruction* temp = q->first;
    struct Instruction* temp2 = NULL;
    while(temp != NULL){
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    q->first = NULL;
    q->last = NULL;
}



void instr_novalue(struct Queue* q, enum Instruction_type type){
    struct Instruction* ins = malloc(sizeof(struct Instruction));
    ins->arg = 0;
    ins->next = NULL;
    ins->type = type;
    queue_push(q,ins);

}
void instr_value(struct Queue* q,enum Instruction_type type){
    printf("hodnota:");
    int value;
    scanf("%d",&value);
    if(value <= 0){
        printf("Hodnota mensi nez 0");
        return;
    }
    struct Instruction* ins = malloc(sizeof(struct Instruction));
    ins->arg = value;
    ins->next = NULL;
    ins->type = type;
    queue_push(q,ins);
}


int main(int argc, char *argv[])
{
    bool runAll = false;
    int instRunNum = 1;

    if ((argc < 2) || (argc > 3)){
        printf("Wrong arguments");
        return -1;
    }
    if( strcmp(argv[1],"-R") == 0){
        runAll = true;
    }
    else if(strcmp(argv[1],"-r") == 0){
        runAll = false;
        my_assert(atoi(argv[2]) > 0);
        instRunNum = atoi(argv[2]);
    }
    struct Queue* queue = malloc(sizeof(struct Queue));
    struct Stack* stack = malloc(sizeof(struct Stack));
    mem_register = 0;
    queue_create(queue);
    stack->stack_top = 0;
    bool running = true;
    char* inst = NULL;
    do{
        printf(">");
        free(inst);
        inst = calloc(10, sizeof(char));
        scanf("%s",inst);
        if(strcmp(inst,"quit") == 0){
            running = false;
            continue;
        }
        if(strcmp(inst,"run") == 0){
            instr_run(queue, runAll, instRunNum);
            print(stack);
            continue;
        }
        if(strcmp(inst,"push") == 0){
            instr_push(stack);
            continue;
        }
        if(strcmp(inst,"pop") == 0){
            instr_pop(stack);
            continue;
        }
        if(strcmp(inst,"reset") == 0){
            instr_reset(queue);
            continue;
        }
        if(strcmp(inst,"add") == 0){
            instr_value(queue,INST_ADD);
            continue;
        }
        if(strcmp(inst,"sub") == 0){
            instr_value(queue,INST_SUB);
            continue;
        }
        if(strcmp(inst,"inc") == 0){
            instr_novalue(queue,INST_INC);
            continue;
        }
        if(strcmp(inst,"dec") == 0){
            instr_novalue(queue,INST_DEC);
            continue;
        }
        if(strcmp(inst,"mul") == 0){
            instr_value(queue,INST_MUL);
            continue;
        }
        if(strcmp(inst,"div") == 0){
            instr_value(queue,INST_DIV);
            continue;
        }
        if(strcmp(inst,"print") == 0){
            print(stack);
            continue;
        }
    }while(running);



    return 0;
}
