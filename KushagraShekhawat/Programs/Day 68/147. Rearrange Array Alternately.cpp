#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    long int N,count=0;
	    scanf("%ld",&N);
	    long int array[N];
	    for(long int i=1;i<N;i+=2)
	       scanf("%ld",&array[i]);
	    
	    long int j = N%2==0?N-2:N-1;;   
	    for(;j>=0;j-=2)
	        scanf("%ld",&array[j]);
	    
	    for(long int i=0;i<N;i++)
	        printf("%ld ",array[i]);
	        
	    printf("\n");
	}
	return 0;
}