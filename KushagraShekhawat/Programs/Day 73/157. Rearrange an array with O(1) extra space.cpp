 
#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N];
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    for(int i=0;i<N;i++)
	        printf("%d ",array[array[i]]);
	    printf("\n");
	}
	return 0;
}
