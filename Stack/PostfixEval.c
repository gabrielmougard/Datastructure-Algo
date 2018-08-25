#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct Stack {
  int top;
  unsigned capacity;
  int* array;
};



struct Stack* createStack(unsigned capacity)
{
  //memory allocation
  struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));

  //if stack doesn't points to NULL
  if(!newStack)
    return NULL;


  newStack->top = -1;
  newStack->capacity = capacity;
  newStack->array = (int*)malloc(newStack->capacity*sizeof(int));

  if (!newStack->array)
    return NULL;

  return newStack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}

char peek(struct Stack* stack) {
  return stack->array[stack->top];

}

char pop(struct Stack* stack) {
  if (!isEmpty(stack))
    return stack->array[stack->top--];

  return '$';
}

void push(struct Stack* stack, char op) {
  stack->array[++stack->top] = op;
}

//utility Function to check if the given character is operand
int isOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int postfixEval(char* exp) {
  int size = strlen(exp);
  struct Stack* stack = createStack(size);

  // See if stack was created successfully
  if (!stack) return -1;

  for (int i=0; exp[i];++i) {
    if (isdigit(exp[i]))
      push(stack,exp[i] - '0');

    else {
      int first = pop(stack);
      int second = pop(stack);

      switch (exp[i]) {
        case '+':
          push(stack,first + second);
          break;
        case '-':
          push(stack,second - first);
          break;
        case '*':
          push(stack,first*second);
          break;
        case '/':
          push(stack,second/first);
          break;
        case '^':
          push(stack,second^first);
          break;
      }
    }
  }

  return pop(stack);
}


int main()
{
    char exp[] = "231*+9-";
    printf ("Value of %s is %d", exp, postfixEval(exp));
    return 0;
}
