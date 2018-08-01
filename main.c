#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a>b)? (a):(b))

//see : https://geeksforgeeks.org

//1) Searching & Sorting
//1.1) Linear Search
//PB : Given an array arr[] of n elements, write a function to search a given element x in arr[].

int LinearSearch(int arr[], int n, int x);


int LinearSearch(int arr[],int n, int x)
{
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

//1.2) Binary Search (dichotomie)
//PB : Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].
int BinarySearch(int arr[], int l , int r, int x);

int BinarySearch(int arr[],int l,int r,int x)
{
    if (r>=l)
    {
       int mid = l + (r-l)/2;

       if (arr[mid] == x)
       {
            return mid;
       }

       if (arr[mid] > x)
       {
            return BinarySearch(arr,l,mid-1,x);
       }
       return BinarySearch(arr,mid+1,r,x);

    }
    return -1;

}

//1.3) Jump Search
//PB : LIke BinarySearch this algo search on a sorted list. The idea is to check fewer elements by jumping ahead by fixed steps.
//     The best step size is sqrt(n) where n is the size of the list.

int JumpSearch(int arr[], int x);

int JumpSearch(int arr[], int x)
{
    int length = sizeof(arr);
    int step = sqrt(length);
    int prev = 0;

    while (arr[MIN(step,length)-1] < x)
    {
        prev = step;
        step += sqrt(length);
        if (prev >= length)
        {
            return -1;
        }
    }

    // perform LInearSearch for x in block beginning with prev
    while (arr[prev] <x)
    {
        prev++;
        //If we reached next block or end of
        //array, element is not present
        if (prev == MIN(step,length))
        {
            return -1;
        }
    }
    //If element is found
    if (arr[prev] == x)
        return prev;
    return -1;
}


//1.4) INterpolationSearch :  For example, if the value of the key is
//closer to the last element, interpolation search is likely to start
//search toward the end side.
//
//to find the position to be searched, it uses following formula:
// pos = lo + [(x-arr[lo])*(hi-lo)/(arr[hi]-arr[lo])]
//
//where : x: element to be searched
//        lo: starting index in arr[]
//        hi: ending index in arr[]

//If elements are uniformly distributed, time complexity is O(log(log(n)))
//else, it's O(n) in the worst case.
//Auxilliary Space : O(1)

int InterpolationSearch(int arr[], int x);

int InterpolationSearch(int arr[],int x)
{
    int lo = 0;
    int hi = (sizeof(arr) - 1);
    while (lo <= hi && x>= arr[lo] && x<= arr[hi])
    {
        //Probing the position with keeping
        //uniform distribution in mind
        int pos = lo + ((double)(hi-lo)/(arr[hi]-arr[lo])*(x-arr[lo]));

        //Condition of target found
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}

//1.5) Exponential Search : in sorted array in O(log(n))
// First, we have to find range where element is present
// Then, do  binary Search in above found range

int ExponentialSearch(int arr[], int x);
int BinarySearch(int arr[],int,int,int);

int ExponentialSearch(int arr[], int x)
{
    //If x is present at first location itself
    if (arr[0] == x)
        return 0;
    //find range for binary search by
    //repeating doubling
    int i = 1;
    while (i < sizeof(arr) && arr[i] <= x)
    {
        i = i*2;
    }
    //call binary search for the found range
    return BinarySearch(arr,i/2,MIN(i,sizeof(arr)),x);
}


//2.1) Selection Sort

void SelectionSort(int arr[],int n);

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SelectionSort(int arr[],int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//2.2) Bubble sort
// the simplest one (just have to swap)
void BubbleSort(int arr[],int n);

void BubbleSort(int arr[],int n)
{
    for(int der = n-1; der >= 0; der--)
    {
        for(int i = 0; i < der; i++)
        {
            if (arr[i]>arr[i+1])
            {
                swap(&arr[i],&arr[i+1]);
            }
        }
    }
}

//2.3) Insertion Sort
//the same of sorting cards in our hand
void InsertionSort(int arr[],int n);

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i< n;i++)
    {
        int test = arr[i];
        int pos = i-1;
        while (pos >= 0 && test < arr[pos])
        {
            arr[pos+1] = arr[pos];
            pos -= 1;
        }
        arr[pos+1] = test;
    }

}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{

  //time complexity : O(nlogn)
  //space complexity : O(n)
  // Paradigm : divide and conquer
  // Application : 1) sorting linked lists in O(nlogn) time ==> because of memory allocation
  // linked lists nodes may not be adjacent in memory
  // 2) Inversion count problem (if array is sorted then the count is 0, elseif in reverse order, the count is maximum )
  // two elements a[i] and a[j] form an inversion if a[i] > a[j] and i<j
  // 3) External Sorting
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

//to see more sort, see : https://www.geeksforgeeks.org/fundamentals-of-algorithms/

int main (void)
{
    int arr[] = {64, 28, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
