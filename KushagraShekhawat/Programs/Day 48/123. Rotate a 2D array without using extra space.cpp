#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N][N];
	    for(int i=0;i<N;i++)
	        for(int j=0;j<N;j++)
	            scanf("%d",&array[i][j]);
	    
	    for(int col=0;col<N;col++)
	        for(int row=N-1;row>=0;row--)
	            printf("%d ",array[row][col]);
	    printf("\n");
	}
	return 0;
}
