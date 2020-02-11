#include <stdio.h>
#include <stdlib.h>

struct MinHeap{
    int *array;
    int count;
    int heapSize;
};

// Function Prototype
int LeftChild(struct MinHeap *heap, int i);
int RightChild(struct MinHeap *heap, int i);
struct MinHeap *CreateAndBuildHeap(int array[], int N);
struct MinHeap *CreateHeap(int N);
void Heapify(struct MinHeap *heap, int i);
long long int FindMinCost(int array[], int N);
int ExtractMinEle(struct MinHeap *heap);
void InsertEle(struct MinHeap *heap, long long int ele);
void buildMinHeap(struct MinHeap *heap);

//Main Function
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N];
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    printf("%lld\n",FindMinCost(array,N));
    }
    return 0;
}

int LeftChild(struct MinHeap *heap, int i){
    int left = 2*i+1;
    if(left>=heap->count)
        return -1;
    return left;
}

int RightChild(struct MinHeap *heap, int i){
    int right = 2*i+2;
    if(right>=heap->count)
        return -1;
    return right;
}

void InsertEle(struct MinHeap *heap, long long int ele){
    heap->count++;
    int i=heap->count-1;
    while(i&&ele<(heap->array[(i-1)/2])){
        heap->array[i]=heap->array[(i-1)/2];
        i=(i-1)/2;
    }
    heap->array[i]=ele;
}


void Heapify(struct MinHeap *heap, int i){
    int left=LeftChild(heap, i);
    int right=RightChild(heap, i);
    //printf("Heapify1\n");
    int min=i,temp;
    if(left!=-1&&heap->array[min]>heap->array[left])
        min = left;
    if(right!=-1&&heap->array[min]>heap->array[right])
        min = right;
    if(min!=i){
    	//printf("Swapping\n");

        temp=heap->array[i];
        heap->array[i]=heap->array[min];
        heap->array[min]=temp;
        //printf("min is %d and Minimum Array is :%d\n",min,heap->array[i]);
        Heapify(heap,min);
    }
}

int ExtractMinEle(struct MinHeap *heap){
    int min = heap->array[0];
    heap->array[0]=heap->array[heap->count-1];
    heap->count--;
    Heapify(heap,0);
    //printf("Returning %d\n",min);
    return min;
}

void buildMinHeap(struct MinHeap *heap){
    int N=heap->count-1;
    for(int i=(N-1)/2;i>=0;--i)
        Heapify(heap,i);
}


struct MinHeap *CreateHeap(int N){
    struct MinHeap *heap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    heap->array = (int *)malloc(sizeof(int)*N);
    heap->heapSize=N;
    heap->count =0;
    return heap;
}

struct MinHeap *CreateAndBuildHeap(int array[], int N){
    struct MinHeap *heap = CreateHeap(N);
    for(int i=0;i<N;i++)
        heap->array[i]=array[i];
    heap->count=N;
    buildMinHeap(heap);
    return heap;
}


long long int FindMinCost(int array[], int N){
    struct MinHeap *heap = CreateAndBuildHeap(array,N);
    long long int cost=0,min1=0,min2=0;
    while(heap->heapSize>1){
    	    //printf("Working0\n");
    	    min1 = ExtractMinEle(heap);
    	    min2 = ExtractMinEle(heap);
    	    cost+=min1+min2;
    	    InsertEle(heap,min1+min2);
    	    //printf("Cost is %d\n",cost);
    	    heap->heapSize-=1;
    }
    return cost;
}

