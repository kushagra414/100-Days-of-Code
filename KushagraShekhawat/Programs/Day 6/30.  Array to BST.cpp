#include <stdio.h>

void binarySearch(int array[],int low,int high);

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N];
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);

	    binarySearch(array,0,N-1);
	    printf("\n");
	}
	return 0;
}

void binarySearch(int array[],int low,int high){
    if(high>=low){
        int mid = low + (high-low)/2;
        //printf("low :%d, high :%d, mid :%d\n",low,high,mid);
        printf("%d ",array[mid]);
        // First go in left
        binarySearch(array,low,mid-1);
        //Then go in right
        binarySearch(array,mid+1,high);
    }
}
