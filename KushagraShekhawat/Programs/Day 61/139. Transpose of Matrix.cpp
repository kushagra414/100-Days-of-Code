#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	int N;
	scanf("%d",&N);
	int arr[N][N];
	for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++)
	        scanf("%d",&arr[i][j]);
	        
	for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++)
	        printf("%d ",arr[j][i]);
	printf("\n");
	}
	
	return 0;
}