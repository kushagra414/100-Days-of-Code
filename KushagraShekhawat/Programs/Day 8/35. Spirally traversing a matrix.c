#include <stdio.h>

void printSpiral(int rows,int columns,int array[][columns]);

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,M;
	    scanf("%d",&N);
	    scanf("%d",&M);
	    int array[N][M];
	    for(int i=0;i<N;i++)
	        for(int j=0;j<M;j++)
	            scanf("%d",&array[i][j]);
	    printSpiral(N,M,array);
	    printf("\n");
	}
	return 0;
}

void printSpiral(int rows,int columns,int array[][columns]){
    int start_row = 0,start_column = 0,end_row = rows-1,end_column = columns-1;
    int traverse = rows*columns;
    //printf("Traverse1 : %d, ",traverse);
    while(traverse>0){
            if(traverse>0)
                for(int j=start_column,i=start_row;j<=end_column;j++){
                    printf("%d ",array[i][j]);
                    traverse--;
                    //printf("Traverse : %d, ",traverse);
                }
                start_row++;
            if(traverse>0)
                for(int i=start_row,j=end_column;i<=end_row;i++){
                    printf("%d ",array[i][j]);
                    traverse--;
                    //printf("Traverse : %d, ",traverse);
                }
                end_column--;
            if(traverse>0)
                for(int j=end_column,i=end_row;j>=start_column;j--){
                    printf("%d ",array[i][j]);
                    traverse--;
                    //printf("Traverse : %d, ",traverse);
                }
                end_row--;
            if(traverse>0)
                for(int i=end_row,j=start_column;i>=start_row;i--){
                    printf("%d ",array[i][j]);
                    traverse--;
                    //printf("Traverse : %d, ",traverse);
                }
                start_column++;
    }
}
