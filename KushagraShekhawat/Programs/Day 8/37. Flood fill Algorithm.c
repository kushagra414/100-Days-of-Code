#include <stdio.h>

void colorPixels(int x, int y, int k, int N, int M, int previous_color, int array[][M]);

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,M;
	    scanf("%d%d",&N,&M);
	    int array[N][M];
	    for(int i=0;i<N;i++)
	        for(int j=0;j<M;j++)
	            scanf("%d",&array[i][j]);
	    int x,y,k;
	    scanf("%d%d%d",&x,&y,&k);
	    int previous_color = array[x][y];
	    printf("\n-----------------------------------\n");
	    colorPixels(x, y, k, N, M, previous_color, array);
	    for(int i=0;i<50;i++)
            printf("**");
        printf("\n");
	}
	return 0;
}

void colorPixels(int x, int y, int k, int N, int M, int previous_color, int array[][M]){

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(j==M-1)
                printf("%d\n",array[i][j]);
            else
                printf("%d ",array[i][j]);
    printf("\n-----------------------------------\n");
    if(array[x][y]!=k&&array[x][y]==previous_color)
        array[x][y] = k;
    else if(array[x][y]!=previous_color)
        return;

        if(x+1<N){
            colorPixels(x+1, y, k, N, M, previous_color, array);}
        if(x-1>=0){
            colorPixels(x-1, y, k, N, M, previous_color, array);}
        if(y+1<M){
            colorPixels(x, y+1, k, N, M, previous_color, array);}
        if(y-1>=0){
            colorPixels(x, y-1, k, N, M, previous_color, array);}
}
