#include <stdlib.h>
#include <stdio.h>

int InversionCount(int arr[], int n) {
  // (if array is sorted then the count is 0, elseif in reverse order, the count is maximum )
  // two elements a[i] and a[j] form an inversion if a[i] > a[j] and i<j

  // O(n²) solution
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (arr[i] > arr[j]) {
        res += 1;
      }
    }
  }
  return res;

}

int merge(int arr[], int temp[], int l, int m, int r) {
  int i,j,k;
  int inv_count = 0;
  i = l;
  j = m;
  k = l;
  while ((i <= m -1) && (j<= r)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    }
    else {
      temp[k++] = arr[j++];
    }

    inv_count = inv_count + (m-1);
  }

  //copy the remaining elements of the left subarray
  while (i <= m-1) {
    temp[k++] = arr[i++];
  }

  //same for the right subarray
  while (j <= r) {
    temp[k++] = arr[j++];
  }

  //copy back the merged elements to original array
  for(i=l;i <= r; i++) {
    arr[i] = temp[i];
  }

  return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right;);
//an auxilliary recursive function that sorts the input array and
// returns the numberof inversions in the array
int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;

    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);

    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

int InversionCountOptimized(int arr[], int n) {
  //we'll use mergeSort to have a complexity of O(nlogn)

  int *temp = (int *)malloc(sizeof(int)*n);
  return _mergeSort(arr,temp,0,n-1);
}



int main(void) {

  int arr[] = {64, 28, 12, 22, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
  int res = InversionCountOptimized(arr, n);

  printf("%d\n",res);
  return 0;

}
