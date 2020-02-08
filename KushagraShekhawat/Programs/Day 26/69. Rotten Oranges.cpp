#include <bits/stdc++.h>
using namespace std;

struct IndexMatrix{
    int row;
    int col;
};

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,M;
	    scanf("%d%d",&N,&M);
	    int Matrix[N][M];
	    queue <IndexMatrix> q;
	    for(int i=0;i<N;i++)
	        for(int j=0;j<M;j++){
	            scanf("%d",&Matrix[i][j]);
	            if (Matrix[i][j]==2)
	                q.push({i,j});
	        }

	   //Program
	    q.push({-1,-1});
	    int maxTime=0,Time=0;
	    bool notRotten=0;
	    while(!q.empty()){
	        IndexMatrix indices = q.front();
	        q.pop();
	        if(indices.row==-1&&q.empty()){
	            maxTime = Time?maxTime+1:maxTime;
	            break;
	        }
	        else if(indices.row==-1){
	            q.push({-1,-1});
	            maxTime = Time?maxTime+1:maxTime;
	            Time=0;
	        }
	        else{
	            int i=indices.row,j=indices.col;
	            //Rot Up, Down, Left, Right and if they are not rotten then increase time
	            //printf("i:%d and j%d\n",i,j);
	            if(i-1>=0&&Matrix[i-1][j]==1){
	                Matrix[i-1][j]=2;
	                Time=1;
	                q.push({i-1,j});
	            }
	            if(i+1<N&&Matrix[i+1][j]==1){
	                Matrix[i+1][j]=2;
	                Time=1;
	                q.push({i+1,j});
	            }
	            if(j-1>=0&&Matrix[i][j-1]==1){
	                Matrix[i][j-1]=2;
	                Time=1;
	                q.push({i,j-1});
	            }
	            if(j+1<M&&Matrix[i][j+1]==1){
	                Matrix[i][j+1]=2;
	                Time=1;
	                q.push({i,j+1});
	            }
	        }
	    }
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            if(Matrix[i][j]==1){
	                notRotten=1;
	                break;
	                }
	        }
	        if(notRotten)
	            break;
	    }
	    if(!notRotten)
	        printf("%d\n",maxTime);
	    else
	        printf("-1\n");
	}
	return 0;
}
