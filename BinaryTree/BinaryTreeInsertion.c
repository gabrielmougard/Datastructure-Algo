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

void insertion(struct node* root, int label) {
  if ((root->left != NULL) && (root->right != NULL)) { //double recursion
    insertion(root->left,label);
    insertion(root->right,label);
  }
  else
  {
    if(root->left == NULL)
      root->left = newNode(label); //insertion to the left first
    else
      root->right = newNode(label);
    return;
  }
}

int lenTree(struct node* root,int initial_count)
{ //count the nodes in the tree
  int res=initial_count;

  if ((root->left == NULL) && (root->right == NULL)) {
    return res;
  }
  else
  {
    if (root->left != NULL)
      res+=lenTree(root->left,res+1);
    if (root->right != NULL)
      res+=lenTree(root->right,res+1);
  }
}

/*


void draw(struct node* root)
{

}
*/

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
