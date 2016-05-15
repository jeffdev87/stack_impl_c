#include "stack.h"

typedef struct x_struct {
   int a;
   double b;
   char * c;
}x_type;

int main(void) {
   stackType * s = init();
   
   if (s == NULL)
      return 0;
   
   /*
    *  Using stack to store int  
    */
   printf("Integers...\n");
   printf("Initial size: %d\n", s->nElem);

   int * v = NULL;     
   int i = 0;
   for (i = 0; i <= 12; i++) {
      v = (int*) malloc(sizeof(int)); 
      *v = i;
      push(s, (stackElem*) newElem((int *) v));
   } 

   printf("Size:%d\n", s->nElem); 
   // Should cast first from void * to int * and then get
   // the content of the pointer. To avoid warnings.
   printf("Top: %d\n",  *(int *) top(s)->value);   
   printf("Tail: %d\n", *(int *) tail(s)->value);  
   
   clear(s);
 
   /*
    *  Using stack to store strings
    */
   printf("\nStrings....\n");
   printf("Initial size: %d\n", s->nElem);

   push(s, (stackElem*) newElem((char *) "banana"));
   push(s, (stackElem*) newElem((char *) "jajajaj && ddd"));
   push(s, (stackElem*) newElem((char *) "melao da maezinha"));
     
   printf("Size:%d\n", s->nElem);
   printf("Top: %s\n", (char *) top(s)->value);         
   printf("Tail: %s\n", (char *) tail(s)->value);  
  
   clear(s);

   /*
    * Using a user defined data type
    */
   printf("\nx_type...\n");
   printf("Initial size: %d\n", s->nElem);
   
   x_type * x = (x_type *) malloc(sizeof(x_type));
   x->a = 1;
   x->b = 2.5;
   x->c = "polenta frita";
   push(s, (stackElem*) newElem((x_type *) x));
   
   x_type * y = (x_type *) malloc(sizeof(x_type));
   y->a = 2;
   y->b = 1.5;
   y->c = "jujubinha";
   push(s, (stackElem*) newElem((x_type *) y));

   printf("Size:%d\n", s->nElem);
   x = (x_type *) top(s)->value;
   y = (x_type *) tail(s)->value;

   printf("Top: %d-%.2f-%s\n", x->a, x->b, x->c);         
   printf("Tail: %d-%.2f-%s\n", y->a, y->b, y->c);  

   clear(s);
   
   printf("\nFinal size: %d\n", s->nElem);    
   return 1;
}
