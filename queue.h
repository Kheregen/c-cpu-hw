#ifndef my_assert
#include <assert.h>
#define my_assert(x) assert(x)
#endif

#ifndef QUEUE_H
#define QUEUE_H


enum Instruction_type{
    INST_ADD,
    INST_SUB,
    INST_INC,
    INST_DEC,
    INST_MUL,
    INST_DIV
};

struct Instruction{
    struct Instruction* next;
    enum Instruction_type type;
    int arg;
};

struct Queue{
    struct Instruction* first;
    struct Instruction* last;
};

#endif
