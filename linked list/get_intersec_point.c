#include <stdlib.h>
#include <stdio.h>

//A linked list node
typedef struct Node
{
  int data;
  struct Node* next;
} Node;


int get_intersec_point(Node* head);
int get_intersec_point(Node* head) {
  Node* ptr1 = head1;
  Node* ptr2 = head2;

  while (ptr1 != NULL) {
    while (ptr2 != NULL) {
      if (ptr2->next == ptr1) {
        return ptr1->data;
      }
      ptr2 = ptr2->next;
    }
    ptr2 = head2;
    ptr1 = ptr1->next;
  }
}
