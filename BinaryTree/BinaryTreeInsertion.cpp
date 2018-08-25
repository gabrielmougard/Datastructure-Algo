//C++ program to insert element in a binary tree
#include <iostream>
#include <queue>
using namespace std;

//a binary tree node structure
struct Node
{
  int key;
  struct Node* left, *right;
};

//function to create a new node of tree and returns pointer

struct Node* newNode(int key) {
  struct Node* temp = new Node;
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

//inorder traversal of a binary tree
void inorder(struct Node* root)
{
  if(!root)
    return;

  inorder(root->left);
  cout << root->key << " ";
  inorder(root->right);
}

void insert(struct Node* temp, int key)
{
  queue<struct Node*> q;
  q.push(temp);

  //do level order traversal until we find an empty place
  while(!q.empty()) {
    struct Node* temp = q.front();
    q.pop();

    if(!temp->left) {
      temp->left = newNode(key);
      break;
    } else
        q.push(temp->left);
    if(!temp->right) {
      temp->right = newNode(key);
      break;
    } else
        q.push(temp->right);
  }
}
//driver code
int main()
{
  struct Node* root = newNode(10);
  root->left = newNode(11);
  root->left->left = newNode(7);
  root->right = newNode(9);
  root->right->left = newNode(15);
  root->right->right = newNode(8);

  cout << "Inorder traversal before insertion:";
  inorder(root);

  int key = 12;
  insert(root,key);
  cout << endl;
  cout << "Inorder traversal after insertion:";
  inorder(root);

  return 0;
}
