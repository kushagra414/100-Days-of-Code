#include<stdio.h> 
  
// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 

        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  

int main() 
{ 
    int T;
    scanf("%d",&T);
    while(T){
        int N;
        scanf("%d",&N);
        int array[N],window;
        for(int i=0;i<N;i++)
            scanf("%d",&array[i]);
        scanf("%d",&window);
        // Sort the array
        int n = sizeof(array)/sizeof(array); 
        quickSort(array, 0, N-1);
        //After Sorting use sliding window to find minimum difference
        window = window-1;
        int minimum_difference = array[N-1];
        for(int i=0;i<N,i+window<N;i++){
            if(array[i+window]-array[i]<minimum_difference)
                minimum_difference = array[i+window]-array[i];
        }
        printf("%d\n",minimum_difference);
        T--;
    }
    return 0;
} 