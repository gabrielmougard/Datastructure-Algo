#include <stdlib.h>
#include <stdio.h>

//A linked list node
typedef struct Node
{
  int data;
  struct Node *right;
  struct Node *down;
} Node;


void push(Node** head_ref, int new_data) {
  //allocate node
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->right = NULL;
  new_node->data = new_data;
  new_node->down = (*head_ref);
  //move the head to point to new node
  (*head_ref) = new_node;
}

void printLists(Node *node) {

  while(node != NULL) {
    printf("%d ",node->data );
    node = node->down;
  }
}

//a utility function to merge two sorted linked lists
Node* merge(Node* head1,Node* head2) {
  //if first list is empty
  if (head1 == NULL) {
    return head2;
  }

  //if the second is empty
  if (head2 == NULL) {
    return head1;
  }

  Node* result;
  if (head1->data < head2->data) {
    result = head1;
    result->down = merge(head1->down,head2);
  }
  else
  {
    result = head2;
    result->down = merge(head1, head2->down);
  }
  return result;
}

Node* flatten(Node* root) {
  //base cases
  if (root == NULL || root->right == NULL) {
    return root;
  }

  return merge(root,flatten(root->right));
}

//test above functions
int main()
{
    Node* root = NULL;

    /* Let us create the following linked list
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    // Let us flatten the list
    root = flatten(root);

    // Let us print the flatened linked list
    printLists(root);

    return 0;
}
