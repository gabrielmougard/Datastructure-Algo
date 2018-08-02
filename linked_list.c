#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//linked list : unlike arrays Linked List are not stored at contiguous location
// the elements are linked using pointers

//why linked list ? - dynamic size compared to arrays
//                  - ease ofinsertion/deletion
// drawbacks : - random access is not allowed. we have to access elements sequentially starting from the first node
// so we cannot do binary search with linkedlist
//            - extra memory space is needed for a pointer is required with each element

//A linked list node
struct Node
{
  int data;
  struct Node *next;
};


//this function prints content of a linkedlist starting from the given node
void printList(struct Node *n) {
   while (n != NULL) {
     printf("%d ", n->data );
     n = n->next;
   }
}

//Add a node at the front
//this functionmust receive a pointer to the head pointer bc push must change the head pointer
//to point to the new node
void push(struct Node** head_ref, int new_data) {

  //allocate node
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

  //put in the Data
  new_node->data = new_data;

  //make next of new node as head
  new_node->next = (*head_ref);

  //move the head to point to the new nodes
  (*head_ref) = new_node;

}

//given a node prev_node, insert a new node after prev_node
void insertAfter(struct Node* prev_node, int new_data) {

  //check if the prev_node is NULL
  if (prev_node == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }

  //allocate node
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  //put Data
  new_node->data = new_data;
  //make next of new node as next of prev node
  new_node->next = prev_node->next;
  //move the next of prev_node as new_node
  prev_node->next = new_node;

}


//add a node at the endi
void append(struct Node** head_ref, int new_data) {

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref; //used in step 5
  new_node->data = new_data;
  //this new node is going to be the last one, so make next of it as NULL
  new_node->next = NULL;
  //if the linked list is empty, then make then make the node as head
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  //else traverse until reachingthe last node
  while (last->next != NULL) {
    last = last->next;
  }
  //change the next of last node
  last->next = new_node;
  return;

}

//deleting a node
//1) Find previous node of the node to be deleted
//2) Changed next of previous node
//3) Free memory for the node to be deleted
void delete(struct Node** head_ref, int key) {
  //1
  //store head node
  struct Node* temp = *head_ref, *prev;
  //if head node itself holds the key to be deleted
  if (temp != NULL && temp->data == key) {
    *head_ref = temp->next; //changed head
    free(temp);
    return;
  }

  //search for the key to be deleted, keep track of
  //the previopus node as we need to change 'prev->next'
  while (temp != NULL && temp->data !=key) {
    prev = temp;
    temp = temp->next;
  }

  //if key was not present in linked list
  if (temp == NULL) return;

  //else
  prev->next = temp->next;
  free(temp); //free memory

}

//delete a linked list node at a given position
// ex : position = 1, Linked list = 8->2->3->1->7
//          output = 8->3->1->7
void deleteNode(struct Node** head_ref, int position) {

  //if linked list is empty
  if(*head_ref->next == NULL) {
    return;
  }
  //Store head node
  struct Node* temp = *head_ref;

  //if head needs to be removed
  if (position == 0) {
    *head_ref = temp->next; //change head
    free(temp); //free old head
    return;
  }

  //find previous node of the node to be deleted
  for (int i = 0; temp !=NULL && i < position-1; i++) {
    *head_ref = temp->next;
  }

  //if position is more than numbers of nodes
  if (temp == NULL || temp->next == NULL) return;

  //Node temp->next is the node to be deleteNode
  //Store pointer to the next node  to be deleted
  struct Node* next = temp->next->next;
  free(temp->next);
  temp->next = next;
}

//function to delete linked list
void deleteLinkedList(struct Node** head_ref) {

  //deref head_ref to get the real head
  struct Node* current = *head_ref;
  struct Node* next;

  while (current != NULL ) {
    next = current->next;
    free(current);
    current = next;
  }

  //deref head_ref to affect the real head back in the caller
  *head_ref = NULL;
}

//find length of a Linked list
//ex : length(1->3->1->2->1) return 5
int length(struct Node* head) {
  int i = 0; //for counting
  struct Node* current = head;

  while (current != NULL) {
    i++
    current = current->next;
  }
  return i;
}

//find length of linked list with recursive process
int length_recur(struct Node* head) {

  if( head == NULL) {
    return 0;
  }
  return 1+length_recur(head->next);
}

//seach for elements in linkedlist
bool search(Node *head, int x) {
  struct Node* current = head;
  while (current != NULL) {
    if(current->data == x) return true;

    current = current->next;
  return false;
  }
}

bool search_recur(struct Node* head, int x)
{
    // Base case
    if (head == NULL)
        return false;

    // If key is present in current node, return true
    if (head->key == x)
        return true;

    // Recur for remaining list
    return search(head->next, x);
}

//function that returns the value of a given node
int GetNth(struct Node* head_ref, int index) {

  int i;
  struct Node* current = head_ref;
  for(i = 0; current != NULL && i <= index;i++) {
    current = current->next;
  }
  return current->data;
}

//function that returns the value of a node from end of the linked List
int GetNthFromEnd(struct Node* head, int index) {
  int len  = length_recur(head);
  return GetNth(head,len-index+1);
}

//count occurence in a given linked list
int Count(struct Node* head, int occurence) {
  int i = 0;
  struct Node* current = head;
  while (current != NULL) {
    if (current->data == occurence) {
      i++;
    }
    current = current->next;
  }
  return i;
}

//detect is linked list has a loop
//Floyd's Cycle-Finding Algorithm : Traverse linked list using two pointers
//Move one pointer by one and the other pointer by two.If these pointers
//meet at some node then there is a loop. If pointers do not meet then linked List
//doesn't have loop
int detectLoop(struct Node *list) {
  struct Node *slow_p = list, *fast_p = list;
  while (slow_p && fast_p && fast_p->next) {
    slow_p = slow_p->next;
    fast_p = fast_p->next->next;
    if (slow_p == fast_p) {
      printf("Found loop");
      return 1;
    }
  }
  return 0;
}

//program to create a simple linked list with 3 nodes
int main(void) {

  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  //allocate three nodes in the heap
  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));

  /* Three blocks have been allocated  dynamically.
     We have pointers to these three blocks as first,
     second and third
       head           second           third
        |                |               |
        |                |               |
    +---+-----+     +----+----+     +----+----+
    | #  | #  |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+

   # represents any random value.
   Data is random because we haven’t assigned
   anything yet  */

   head->data = 1; //assign data in first node
   head->next = second; //link first node with the second

   /* data has been assigned to data part of first
     block (block pointed by head).  And next
     pointer of first block points to second.
     So they both are linked.

       head          second         third
        |              |              |
        |              |              |
    +---+---+     +----+----+     +-----+----+
    | 1  | o----->| #  | #  |     |  #  | #  |
    +---+---+     +----+----+     +-----+----+
  */

  //assign data to second node
  second->data = 2;
  second->next = third;

  //and finally..
  third->data = 3;
  third->next = NULL;
  printList(head);
  return 0;

}
