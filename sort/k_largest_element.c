#include <stdlib.h>
#include <stdio.h>
#include "heapsort.c"

//k largest (or smallest) elemnts in an array (with heapsort)

void k_largest_elements(int arr[],int k, int n) {

    Heapsort(arr,n);
    for (int i = n-1; i>=n-k;i--) {
      printf("%d\n", arr[i]);
    }
}

int main(void) {

  int arr[] = {1,56,768,45,67,4,89,90};
  int n = sizeof(arr)/sizeof(arr[0]);
  k_largest_elements(arr,3,n); // we want the 3 largest elemnts of arr
  return 0;
}
