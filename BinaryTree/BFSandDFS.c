#include <stdlib.h>
#include <stdio.h>

//BFS : bread first traversal (or level order traversal)
//DFS : depth first traversal
// DFS coulb be either : Preorder traversal (root-left-right)
//                       Inorder traversal (Left-root-right)
//                       Postorder traversal (left-right-root)

/*
for ex :                                 (1)
                                        /   \
                                      (2)   (3)
                                     /  \
                                  (4)   (5)

BFS :  1 2 3 4 5
DFS
    PreT : 1 2 4 5 3
    IT : 4 2 5 1 3
    PostT : 4 5 2 3 1

    The most important points is, BFS starts visiting nodes
    from root while DFS starts visiting nodes from leaves.
    So if our problem is to search something that is more
    likely to closer to root, we would prefer BFS. And if the target node
    is close to a leaf, we would prefer DFS.

*/


/*

trees can be repreented in two ways :
  1) Dynamic Node representation (Linked representation)
  2) Array representation (Sequential Representation)

      A(0)
    /   \
   B(1)  C(2)
 /   \      \
D(3)  E(4)   F(5)

OR,
     A(1)
    /   \
   B(2)  C(3)
 /   \      \
D(4)  E(5)   F(6)

For the first case :

if father = p;
then left_son = 2*p+1;
and right_son = 2*p+2;


For the second case :

if father = p;
then left_son = 2*p;
and right_son = 2*p+1;
