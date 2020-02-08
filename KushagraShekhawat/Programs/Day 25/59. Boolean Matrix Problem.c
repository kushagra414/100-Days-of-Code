#include <stdio.h>
#include <string.h>

void FillOne(int row,int column, int M, int N, int Matrix[][N]){
    if(row>=0){
        for(int j=0;j<N;j++)
            Matrix[row][j]=1;
    if(column>=0)
        for(int i=0;i<M;i++)
            Matrix[i][column]=1;
    }
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int M,N;
	    scanf("%d%d",&M,&N);
	    int Matrix[M][N],CopyMatrix[M][N],row[M],column[N];
	    memset(row,0,M*sizeof(int));
	    memset(column,0,N*sizeof(int));
	    for(int i=0;i<M;i++)
	        for(int j=0;j<N;j++){
	            scanf("%d",&Matrix[i][j]);
	            CopyMatrix[i][j]=Matrix[i][j];
	        }
	   int rowOne,colOne;
	    for(int i=0;i<M;i++)
	        for(int j=0;j<N;j++){
	            if(Matrix[i][j]==1){
	                if(row[i]==0){
	                    row[i]=1;
	                    rowOne=i;
	                }
	                else
	                rowOne=-1;
	                if(column[j]==0){
	                    column[j]=1;
	                    colOne=j;
	                }
	                else
	                    colOne=-1;
	                FillOne(rowOne,colOne,M,N,CopyMatrix);
	                
	            }
	        }
	   	    for(int i=0;i<M;i++)
    	        for(int j=0;j<N;j++){
    	            printf("%d ",CopyMatrix[i][j]);
    	            if(j==N-1)
    	                printf("\n");
    	        }
	}
	return 0;
}
