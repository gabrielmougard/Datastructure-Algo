#include <stdlib.h>
#include <stdio.h>

//Heapsort : based on binaryHeap data structure

//Complete BinaryTree : is a BinaryTree where every level,except the possibly the last,
// is completely filled, and all nodes arre as far left as possible.


// A binaryHeap is a Complete Binary Tree where items are stored in a special order such
//that value in a parent node is greater (or smaller) than the values of the two children nodes.
//The former is called as max heap and the latter is called min heap

//tip : if the parent node is stored at index i, the left child can de calculated by 2*i +1
// and the right child by 2*i+2 (assuming the index starts at 0)

//PROCEDURE
//1) Build a maxheap from the input data
//2) At this point, the largest item is at the root of the heap. Replace it by
//   the last item of the heap followed by reducing the size of the heap by 1.
//   Finally, heapify the root of Tree
//3) Reapeat above steps while size of heap is greater than 1.

// How to build the heap ?
//Heapify procedure can be applied to a node only if its children nodes
//are heapified . So, the heapification must be performed in the bottom up order

void swap(int *a,int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) {
  // time complexity : O(logn)
  // i is the index of the heapify PROCEDURE
  int largest = i; //root
  int l = 2*i+1; //left node
  int r = 2*i+2; //right node

  //if the left child is larger than root
  if (l<n && arr[largest]<arr[l]) {
    largest = l;
  }

  //if the right child is larger than root
  if (r<n && arr[largest]<arr[r]) {
    largest = r;
  }

  //if largest is not root
  if (largest != i) {
    swap(&arr[i],&arr[largest]);

    //recursively heapify the affected sub-Tree
    heapify(arr,n,largest);
  }
}

void Heapsort(int arr[], int n) {

  //Build heap (rearrange array)
  for (int i = n/2 - 1; i >= 0;i--) { //n/2 - 1 is the index of the last parent
    heapify(arr,n,i);
  }

  //one by one extract an element from the heap
  for(int i = n-1;i>=0;i--) {
    //move current root to end
    swap(&arr[0],&arr[i]);

    //call maxheapify on the reduced heap
    heapify(arr,i,0);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i<n; i++) {
    printf("%d \n",arr[i]);
  }
}

int main2(void) {

  int arr[] = {12,11,13,5,6,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  Heapsort(arr,n); //Overall time complexity is O(nlogn)
                   // Space complexity is O(1) (in-place algorithm)
                   // Application : 1) sort nearly sorted arrays
                   //               2) k largest(or smallest) elements in an array

  printArray(arr,n);
  return 0;
}
