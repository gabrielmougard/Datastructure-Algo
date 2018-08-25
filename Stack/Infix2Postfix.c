#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack {
  int top;
  unsigned capacity;
  int* array;
};

//Infix expression : the expression of the form a op b. When an operator
// is followed for every pair of operands

//Postfix expression : The expression of the form a b op.
//When an operator is followed for every pair of operands

//Consider the below expression: a op1 b op2 c op3 d
//If op1 = +, op2 = *, op3 = +

//the postfix form is : abc*+d+

//Algo :
//1) Scan the infix expression from leftto right
//2) If the scanned character is an operand, output it
//3) Else,
  //3.1) If the precedence of the scanned operator is greater than the
  //     precedence of the operator in the stack (or the stack is empty)
  //     push it.
  //3.2) Else, Pop ht eoperator from the stack until the precedence of
  //     the scanned operator is less-equal to the precedence of the operator
  //     resziding on the top of the stack.Push the scannedoperator to the stack.
//4) If the scannedcharacter is an '(', push it to the stack
//5) If the scannedcharacter is an ')', pop and output from the stack,
//   until an '(' is encountered.
//6) Repeat steps 2-6 until infix expression is scanned.
//7) Pop and output from the stack until it is not empty


//Stack operations
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

//A utility function to return precedence of a given operator
//Higher returnedvalue means higher precedence
int Prec(char ch) {
  switch (ch) {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;
  }
  return -1;
}

//the main function that converts given infix expression
// to postfix expression


int infixToPostfix(char* exp) {

  int i,k;

  //create stack of capacity equal to expression size
  struct Stack* stack = createStack(strlen(exp));
  if (!stack) //see if stack was created successfully
    return -1;

  for (i = 0, k = -1;exp[i];i++) {

    //if the scanned character is an operand
    if (isOperand(exp[i]))
      exp[++k] = exp[i];

    //If the scanned character is an '(' , push it to the stack
    else if (exp[i] == '(') {
      push(stack,exp[i]);
    }

    //If the scanned character is a ')', pop  and output from the stack
    //until an '(' is encountered.
    else if (exp[i] == ')') {

      while (!isEmpty(stack) && peek(stack) != '(') {
        exp[++k] = pop(stack);
      }
      if (!isEmpty(stack) && peek(stack) != '(')
        return -1; // invalid expression
      else
        pop(stack);
    }

    else { // an operator is encountered
      while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack))) {
        exp[++k] = pop(stack);
      }
      push(stack,exp[i]);
    }
  }

  //pop all the operators from the stack
  while(!isEmpty(stack)) {
    exp[++k] = pop(stack);
  }
  exp[++k] = '\0';
  printf("%sn",exp);
}

// Driver program to test above functions
int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
