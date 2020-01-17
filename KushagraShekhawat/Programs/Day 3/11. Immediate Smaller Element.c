#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T){
	    int N;
	    scanf("%d",&N);
	    int array[N];
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    for(int i=0;i<N-1;i++){
	        if(array[i]>array[i+1])
	            printf("%d ",array[i+1]);
	        else
	            printf("-1 ");
	    }
	    printf("-1\n");
	    T--;
	}
	return 0;
}