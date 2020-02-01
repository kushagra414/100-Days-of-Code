#include<stdio.h>

int minPath=0,foundMinPath=0,foundZero=0;
int FindMinPath(int M, int N, int array[][M],int x, int y);

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d",&N,&M);
        int array[N][M];
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                scanf("%d",&array[i][j]);

        int x,y;
        scanf("%d%d",&x,&y);
        foundMinPath=0,minPath=0;
        if(array[0][0]==0)
            printf("-1\n");
        else
            FindMinPath(M, N, array, x, y);
        if(foundMinPath==0 || foundMinPath==-1)
            printf("-1\n");
        else
            printf("%d\n",minPath);
    }
    return 0;
}

int FindMinPath(int M, int N, int array[][M], int x, int y){
        if(x<0 || y<0 || x>=N || y>=M)
            return -1;
        if(foundMinPath==1 || foundMinPath== -1){
                return 0;
                }
         if(array[x][y]==0){
            return -1;
            }
        if(x>=y&&foundMinPath==0 || foundZero==-1){
            printf("Go Up, x: %d and y: %d and minPath : %d\n",x,y,minPath);
            foundZero = FindMinPath(M,N,array,x-1,y);
            if(foundZero==0)
                minPath++;
        }
        if(y>=x&&foundMinPath==0 || foundZero==-1){
            printf("Go Left, x: %d and y: %d and minPath : %d\n",x,y,minPath);
            foundZero=FindMinPath(M,N,array,x,y-1);
            if(foundZero==0)
                minPath++;
            }
        if(foundZero==-1){
            printf("Go Right, x: %d and y: %d and minPath : %d\n",x,y,minPath);
            foundZero=FindMinPath(M,N,array,x,y+1);
            if(foundZero==0)
                minPath++;
            printf("Go Bottom, x: %d and y: %d and minPath : %d\n",x,y,minPath);
            foundZero=FindMinPath(M,N,array,x+1,y);
            if(foundZero==0)
                minPath++;
            }
        if(x==0&&y==0&&foundMinPath==0){
                foundMinPath=1;
            return 0;
        }
        if(foundZero==-1){
            foundMinPath=-1;
            return 0;
        }
}
