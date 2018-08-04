#include <stdlib.h>
#include <stdio.h>


// circular linked lists : all nodes are connected to form a circle
// There is no NULL at the end. it can be singly or double.

//advantages :
//1 any node can be a starting point
//2 Useful for implementation of queue
//3  Circular lists are useful in applications to repeatedly
//   go around the list. For example, when multiple applications are
//   running on a PC, it is common for the operating system to put the
//   running applications on a list and then to cycle through them,
//   giving each of them a slice of time to execute, and then making
//   them wait while the CPU is given to another application.
//   It is convenient for the operating system to use a circular list
//   so that when it reaches the end of the list it can cycle around
//   to the front of the list.
//4 Circular Doubly Linked Lists are used for implementation of
//  advanced data structures like Fibonacci Heap.

struct Node
{
  int data;
  struct Node* next;
};

void push(struct Node** head_ref, int data)
{
  struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node));
  struct Node *temp = *head_ref;
  ptr1->data = data;
  ptr1->next = *head_ref;

  // if ll is not NULL then set the next of last node
  if (*head_ref != NULL) {
    while (temp->next != *head_ref) {
      temp = temp->next;
    }
    temp->next = ptr1;
  }
  else {
    ptr1->next = ptr1; //for the first node
  }
  *head_ref = ptr1;
}

/* Function to print nodes in a given Circular linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}

int main()
{
    /* Initialize lists as empty */
    struct Node *head = NULL;

    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    printf("Contents of Circular Linked List\n ");
    printList(head);

    return 0;
}
