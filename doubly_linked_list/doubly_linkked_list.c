#include <stdlib.h>
#include <stdio.h>

// A Doubly linked list (DLL) contains an extra pointer, typically
//called previous pointer

//node of a DLL
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

//1) a DLL can be traversed in both forward and backward direction
//2) The delete operation is more efficient if pointer to the Node
//   to be deleted is given
//3) We can quickly insert a new node before a given node.

//Insertion

//at the front
void push(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  new_node->prev = NULL;
  if ((*head_ref) != NULL) {
    (*head_ref)->prev = new_node;
  }
  (*head_ref) = new_node;
}

//at a given node
void insertAfter(struct Node* prev_node, int new_data) {
  //1 check if the given prev_node is NULL
  if (prev_node == NULL) {
    printf("the given previous node cannot be NULL \n");
    return;
  }
  //2 allocate new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  //3 put in data
  new_node->data = new_data;
  //4 make next of new node the next of prev_node
  new_node->next = prev_node->next;
  //5 make the next of prev_node as new_node
  prev_node->next = new_node;
  //6 make prev_node as previous of new_node
  new_node->prev = prev_node;
  //7 Changes previous of new_node's next node
  if (new_node->next != NULL) {
    new_node->next->prev = new_node;
  }
}

//add at the end
void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}


// This function prints contents of linked list starting from the given node
void printList(struct Node* node)
{
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}
/* Function to delete a node in a Doubly Linked List.
   head_ref --> pointer to head node pointer.
   del  -->  pointer to node to be deleted. */
void deleteNode(struct Node** head_ref, struct Node* del) {
  if (*head_ref == NULL || del == NULL) {
    return;
  }
  //if node to be deleted is head node
  if (*head_ref == del) {
    *head_ref = del->next;
  }
  //change next only if node to be deleted is not the last Node
  if (del->next != NULL) {
    del->next->prev = del->prev;
  }
  /* Change prev only if node to be deleted is NOT the first node */
  if(del->prev != NULL){
    del->prev->next = del->next;
  }
  //finally free memory occupied by del
  free(del);
  return;
} //time and spacecomplexity : O(1)


/////
void reverse(struct Node** head_ref) {
  struct Node* temp = NULL;
  struct Node* current = (*head_ref);

  /* swap next and prev for all nodes of
       doubly linked list */
  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;

  }

  if (temp != NULL) {
    *head_ref = temp->prev;
  }
}


int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
    push(&head, 7);

    push(&head, 1);

    push(&head, 4);

    // Insert 8, after 1. So linked list becomes 4->8->1->7->NULL
    insertAfter(head->next, 8);

    printf("Created DLL is: ");
    printList(head);

    reverse(&head);
    printList(head);

    getchar();
    return 0;
}
