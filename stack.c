#include "stack.h"

stackType * init () {
   stackType * s = (stackType*) malloc (sizeof(stackType));
   
   if (s == NULL)
      return 0;

   s->head = NULL;
   s->tail = NULL;
   s->nElem = 0;

   return s;	 
}

stackElem * tail (stackType * s) {
   if (s == NULL)
      return NULL;
   return s->tail;
} 

stackElem * top (stackType * s) {
   if (s == NULL)
      return NULL;
   return s->head;
} 

int clear (stackType * s) {
   int nElem = 0;

   if (s == NULL)
      return nElem;
      
   while (pop(s) != NULL) {
      ++nElem;
   }
   return nElem;
}

int push(stackType * s, stackElem * i) {
   int res = 0;   

   if (s != NULL) {
     stackElem * e = top(s);
     
     if (e != NULL) {
        i->prev = e;
        e->next = i;
     }
     else {
        s->tail = i;
     }
     
     s->head = i;        
     s->nElem++;
     res = 1;
   }
   return res;
}

void * pop(stackType * s) {
   stackElem * t = top(s);
   
   if (t == NULL)
      return NULL;
   
   s->head = t->prev;
   void * value = t->value;

   if (s->head != NULL)
      s->head->next = NULL;
   else {
      s->head = NULL;
      s->tail = NULL;
   }

   free(t);      
   s->nElem--;

   return value;
}

stackElem * newElem (void * val) {
   stackElem * s = (stackElem*)malloc (sizeof(stackElem));

   if (s!= NULL) {
      s->next = NULL;
      s->prev = NULL;
      s->value = val;
      s->value_size = (size_t) sizeof(val);
   }
   return s;
}

