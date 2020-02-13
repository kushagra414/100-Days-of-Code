// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i);

void buildHeap(int arr[], int n);

// main function to do heap sort
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()

int LeftChild(int n, int i){
    int left = 2*i+1;
    if(left>=n)
        return -1;
    return left;
}

int RightChild(int n, int i){
    int right = 2*i+2;
    if(right>=n)
        return -1;
    return right;
}


void heapify(int array[], int n, int i)  {
    int left=LeftChild(n, i);
    int right=RightChild(n, i);
    //printf("Heapify1\n");
    int min=i,temp;
    if(left!=-1&&array[min]<array[left])
        min = left;
    if(right!=-1&&array[min]<array[right])
        min = right;
    if(min!=i){
    	//printf("Swapping\n");

        temp=array[i];
        array[i]=array[min];
        array[min]=temp;
        //printf("min is %d and Minimum Array is :%d\n",min,heap->array[i]);
        heapify(array,n,min);
    }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    int N=n;
    for(int i=(N-1)/2;i>=0;--i)
        heapify(arr,n,i);
}
