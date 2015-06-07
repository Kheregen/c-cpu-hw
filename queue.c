#include "queue.h"




unsigned int queue_empty (const struct Queue* container){
    my_assert(container != NULL);
    if(container->first == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void queue_create (struct Queue* container){
    my_assert(container != NULL);
    container->first = NULL;
    container->last = NULL;
}

void queue_push (struct Queue* container, struct Instruction* item){
    my_assert(container != NULL);
    if(item == NULL){
        printf("Item is null\n");
    }
    if(queue_empty(container)){
        container->first = item;
        container->last = item;
        return;
    }
    container->last->next = item;
}


struct Instruction* queue_pop (struct Queue* container){
    my_assert(container == NULL);
    if(queue_empty(container) == 1){
        printf("Queue is empty.\n");
        return NULL;
    }
    struct Instruction* returned = container->first;
    container->first = container->first->next;
    return returned;
}

unsigned int queue_size (const struct Queue* container){
    my_assert(container == NULL);
    int count = 0;
    if(queue_empty(container) == 1){
        return count;
    }
    struct Instruction* temp = container->first;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

unsigned int queue_clear (struct Queue* container){
    my_assert(container == NULL);
    int count = 0;
    if(queue_empty(container) == 1){
        return count;
    }
    struct Instruction* temp = container->first;
    while(temp != NULL){
        count++;
        struct Instruction* deleted = temp;
        temp = temp->next;
        free(deleted);
    }
    return count;
}
