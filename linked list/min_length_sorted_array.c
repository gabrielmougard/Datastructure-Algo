#include <stdlib.h>
#include <stdio.h>

void min_length_sorted_subarray(int arr[], int n) {

  //1) Find the candidate unsorted array
  int s,p;
  int i = 0;
  int j = 1;
  while (arr[i+1] >= arr[i]) {
    i++;
  }
  s = i;

  while (arr[n-1-j] >= arr[n-j]) {
    j++;
  }
  p = n-1-j;

  int min = arr[s];
  int max = arr[s];

  for (int i = s; i <= p;i++) {
      if (arr[i] < min) {
        min = arr[i];
      }
      if (arr[i] > max) {
        max = arr[i];
      }
  }

  for (int i = 0; i < s;i++) {
    if (arr[i] > min) {
      s = i;
      break;
    }
  }

  for (int i = n-1; i >= p+1;i--) {
    if (arr[i] < max) {
      p = i;
      break;
    }
  }

  printf("between %d and %d \n",s,p);

}

int main(void) {
  int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
  int n = sizeof(arr)/sizeof(arr[0]);
  min_length_sorted_subarray(arr,n);
  return 0;
}
