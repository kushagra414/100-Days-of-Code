#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,M;
	    scanf("%d%d",&N,&M);
	    int arr[N][M];
	    for(int i=0;i<N;i++)
	        for(int j=0;j<M;j++)
	            scanf("%d",&arr[i][j]);
	    
	    int X1,Y1,X2,Y2;
	    scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
	    int sum=0,i=X1-1,start=1,end;
	    
	    for(int i=X1-1;i<X2;i++){
	        for(int j=Y1-1;j<Y2;j++){
	            start=0;
	            sum+=arr[i][j];
	        }
	    }
	   printf("%d\n",sum);
	}
	return 0;
}
