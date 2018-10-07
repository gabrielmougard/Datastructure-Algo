//C program to implement basic operations (search, insert and delete)
// on a BST that handles duplicates by storing count with every node

#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  int count;
  struct node *left, *right;
};

//utility function to create a new BST node
struct node *newNode(int item)
{
  struct node* temp =(struct node*)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  temp->count = 1;
  return temp;
}

//utility func to do inorder traversal of BST
void inorder(struct node* root){
  if (root != NULL) {
    inorder(root->left);
    printf("%d(%d) ", root->key,root->count);
    inorder(root->right);
  }
}

//a utility function to insert a new node with given key in BST
struct node* insert(struct node* node, int key)
{
  //if tree is empty, return new node
  if (node == NULL) return newNode(key);

  //if key already exists in BST, increment count and return
  if (key == node->key) {
    (node->count)++;
    return node;
  }

  //otherwise, recur down the tree
  if (key < node->key){
    node->left = insert(node->left,key);
  }
  else {
    node->right = insert(node->right,key);
  }
  //return the inchanged node pointer
  return node;
}

struct node* minValueNode(struct node* node)
{
  struct node* current = node;

  //loop down to find the leftmost leaf
  while (current->left != NULL)
    current = current->left;
  return current;
}

/* Given a binary search tree and a key, this function
   deletes a given key and returns root of modified tree */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key
    else
    {
        // If key is present more than once, simply decrement
        // count and return
        if (root->count > 1)
        {
           (root->count)--;
           return root;
        }

        // ElSE, delete the node

        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
             12(3)
          /        \
       10(2)      20(1)
       /   \
    9(1)  11(1)   */
    struct node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 12);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 12\n");
    root = deleteNode(root, 12);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 9\n");
    root = deleteNode(root, 9);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}
