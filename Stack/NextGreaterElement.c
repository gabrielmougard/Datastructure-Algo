#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define STACKSIZE 100

struct stack
{
  int top;
  int items[STACKSIZE];
};


//1) Push the first element to the stack
//2) Pick the rest of the elements one by one and do :
//  2.1) Mark the current elmt as next
//  2.2) If stack is not empty, then pop an element from stack
//       compare it with the next
//  2.3) If next is greater than the popped one, then next is
//       the next greater element for the popped element
//  2.4) Keep popping from the stack while the popped element
//      is smaller than the next. next becomes the next greater
//      element for all such popped elements
//3) After the loop in step 2 is over, pop all the elements from
//   stack and print -1 as next element for them


 void push(struct stack *ps, int x) {
   if (ps->top == STACKSIZE-1) {
     printf("Error : stack overflown\n");
     getchar();
     exit(0);
   }
   else
   {
     ps->top += 1;
     int top = ps->top;
     ps->items[top] = x;
   }
 }

 bool isEmpty(struct stack* ps) {
   return (ps->top == -1)? true : false;
 }

 int pop(struct stack *ps) {
   int temp;
   if (ps->top == -1) {
     printf("Error : stack overflown\n");
     getchar();
     exit(0);
   }
   else
   {
     int top = ps->top;
     temp = ps->items[top];
     ps->top -= 1;
     return temp;
   }
 }


 void printNGE(int arr[], int n) {

   int i = 0;
   struct stack s;
   s.top = -1;
   int element, next;

   //push the first element to the stack
   push(&s,arr[0]);

   //iterate forthe rest of elements
   for (i = 1; i < n; i++) {
     next = arr[i];
     if (isEmpty(&s) == false){
       //if sytack is not empty, then pop an element from the stack
       element = pop(&s);
       /* If the popped element is smaller than next, then
          a) print the pair
          b) keep popping while elements are smaller and stack is not empty */

        while (element < next) {
          printf("n %d --> %d",element,next);
          if(isEmpty(&s) == true)
            break;
          element = pop(&s);
        }

        /* If element is greater than next, then push
        the element back */
        if (element > next)
          push(&s, element);
     }
     //push next to stack so that we can find
     //next greater for it
     push(&s,next);
   }

   /* After iterating over the loop, the remaining
       elements in stack do not have the next greater
       element, so print -1 for them */
    while (isEmpty(&s) == false)
    {
        element = pop(&s);
        next = -1;
        printf("n %d --> %d", element, next);
    }
 }


 /* Driver program to test above functions */
int main()
{
    int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    getchar();
    return 0;
}
