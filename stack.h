#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include<stdlib.h>

typedef struct stackElemType {
   struct stackElemType * next;
   struct stackElemType * prev;

   void * value;
   size_t value_size;
} stackElem;

typedef struct stackStrType {
  stackElem * head;
  stackElem * tail;
  int nElem;
} stackType;

// Start
stackType * init();

// Top
stackElem * top (stackType * s);

// Clear stack
int clear (stackType * s);

//Nail
stackElem * tail (stackType * s);

// Push
int push(stackType * s, stackElem * i);

// Pop
void * pop(stackType * s);

stackElem * newElem (void * val);
#endif /* STACK_H */
