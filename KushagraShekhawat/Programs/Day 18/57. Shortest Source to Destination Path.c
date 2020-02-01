#include<stdio.h>

int minPath=0,foundMinPath=0,foundZero=0;
void FindMinPath(int M, int N, int array[][M],int index[][M],int x, int y);

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d",&N,&M);
        int array[N][M],index[N][M];
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                scanf("%d",&array[i][j]);
                index[i][j]=0;
                }

        int x,y;
        scanf("%d%d",&x,&y);
        foundMinPath=0,minPath=0;
        if(array[0][0]==0 || array[x][y]==0)
            printf("-1\n");
        else{
            FindMinPath(M, N, array,index, x, y);
            if(foundMinPath==0 || foundMinPath==-1)
                printf("-1\n");
            else
                printf("%d\n",minPath);
        }
    }
    return 0;
}

void FindMinPath(int M, int N, int array[][M],int index[][M], int x, int y){
        if(x<0 ||y<0||x>=N||y>=M || foundMinPath==1)
            return;
        else if(x==0&&y==0&&foundMinPath==0){
            foundMinPath=1;
            //printf("Found Min Path :%d\n",minPath);
            return;
        }
        else if(array[x][y]==0){
             //printf("Making Index 1: x:%d, y:%d\n",x,y);
             index[x][y]=1;
            return;
            }
        if(foundMinPath==0&&index[x][y]==0){
            index[x][y]=1;
            if(foundMinPath==0){
                //printf("Go Up, x: %d and y: %d and minPath : %d\n",x,y,minPath);
                FindMinPath(M,N,array,index,x-1,y);
                if(foundMinPath==1)
                    minPath++;}
            if(foundMinPath==0){
                //printf("Go Left, x: %d and y: %d and minPath : %d\n",x,y,minPath);
                FindMinPath(M,N,array,index,x,y-1);
                if(foundMinPath==1)
                    minPath++;}
            if(foundMinPath==0){
                //printf("Go Right, x: %d and y: %d and minPath : %d\n",x,y,minPath);
                FindMinPath(M,N,array,index,x,y+1);
                if(foundMinPath==1)
                    minPath++;}
            if(foundMinPath==0){
                //printf("Go Bottom, x: %d and y: %d and minPath : %d\n",x,y,minPath);
                FindMinPath(M,N,array,index,x+1,y);
                if(foundMinPath==1)
                    minPath++;}
        }
}

