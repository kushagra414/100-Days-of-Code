#include <stdio.h>

void answer(int x,int y,int k,int n,int m,int mat[][m],int target){
    if(x<0 || x>=n || y<0 || y>=m){
        return;
    }
    else if(mat[x][y]!=target){
        return;
    }
    else{
        mat[x][y]=k;
        answer(x+1,y,k,n,m,mat,target);
        answer(x-1,y,k,n,m,mat,target);
        answer(x,y-1,k,n,m,mat,target);
        answer(x,y+1,k,n,m,mat,target);
    }
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
	    int n=0,m=0,i=0,j=0;
	    scanf("%d%d",&n,&m);
	    int mat[n][m];
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            scanf("%d",&mat[i][j]);
	        }
	    }
	    int x,y,k,target;
	    scanf("%d%d%d",&x,&y,&k);
	    target=mat[x][y];
	    answer(x,y,k,n,m,mat,target);
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            printf("%d ",mat[i][j]);
	        }
	    }
	    printf("\n");
	}
	return 0;
}
