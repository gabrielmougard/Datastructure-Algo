#include <stdlib.h>
#include <stdio.h>

//Unlike Arrays, Linked Lists, Stack and queues, which are
//linear data structures, trees are hierarchical data structures.


/*
The topmost node is called root of the tree.
The elements that are directly under an element are called
its children. The element directly above something is called
its parent. For example, a is a child of f and f is
the parent of a. Finally, elements with no children are called
leaves.
*/

/* WHY Trees ?
- Trees provide moderate access/search (quicker than Linked List)
and slower than arrays.
- Trees provide moderate insertion/deletion (quicker than arrays)
and slower than Unordered Linked Lists.
- Like Linked Lists and unlike Arrays, Trees don't have an upper
limit on nnumber of nodes as nodes are linked using pointers.
*/

/* MAIN APPLICATIONS of Trees
- Manipulate hierarchical data.
- Make information easy to search
- Manipulate sorted lists opf data
- As a workflow for composing digital images for visual effects
- Router Algorithms
- Form of az multi-stager decision-making
*/
struct node {
  int data;
  struct node *left;
  struct node *right;
};

//let's create a tree with 4 nodes

struct node* newNode(int data)
{
  //memory allocation
  struct node* node = (struct node*)malloc(sizeof(struct node));
  //assign data
  node->data = data;
  //initialize children at NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}

// NB : the nth Catalan number T(n) = (2n)!/(n+1)!n!
// represents the number of different unlabeled trees with n nodes.

// But how many labeled Binary Trees can be there with n nodes ?
/*
To count labeled trees, we can use above count for unlabeled trees.
The idea is simple, every unlabeled tree with n nodes can create n!
different labeled trees by assigning different permutations of labels
to all nodes.
*/


int main() {
  //create root
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
  getchar();
  return 0;

}
