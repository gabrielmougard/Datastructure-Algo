#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node {
  struct node* left;
  struct node* right;
  int data;
};

struct node* newNode(int data) {

  //memory allocation
  struct node* Node = (struct node*)malloc(sizeof(struct node));
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  return(Node);
}

//Inorder traversal of a BinaryTree
void inorder (struct node* temp) {
  if (!temp)
    return;
  inorder(temp->left);
  printf("%d ",temp->data);
  inorder(temp->right);
}

////Queue structure for nodes////
struct Queue
{
  int size;
  unsigned capacity;
  struct node* front,rear;
  struct node** array;
};
//////////////////////////////////
int isFull(struct Queue* queue) {
  return (queue->size == queue->capacity);
}

void enqueue(struct Queue* queue, struct node* item) {
  if (isFull(queue))
    return
  queue->rear = (queue->rear + 1)%(queue->capacity);
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
  printf("%d enqueued to queue\n",item);
}

void insert(struct node* temp) {

  //memory allocation
  struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
  enqueue(q,temp);

  //TODO : finish this shit !
}

int main(int argc, char const *argv[]) {

  struct node* root = newNode(1);
  /* following is the tree after above statement

        1
      /   \
     NULL  NULL
  */
  root->left = newNode(2);
  root->right = newNode(3);
  /* 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
  */
  root->left->left = newNode(4);
  insertion(root,5);

  /* it should be :
           1
         /   \
        2      3
     /    \    /  \
    4     5 NULL NULL
  */
  int a = lenTree(root,1);
  printf("%d\n",a);
  getchar();

  //now we draw the tree...
  //draw(root);
  return 0;
}
