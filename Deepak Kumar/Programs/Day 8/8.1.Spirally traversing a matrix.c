#include <stdio.h>

int print_spiral(int m,int n,int mat[][n]){
    int i=0,start_m=0,start_n=0;
    while(start_m<m && start_n<n){
        for(i=start_n;i<n;i++){
            printf("%d ",mat[start_m][i]);
        }
        start_m++;
        for(i=start_m;i<m;i++){
            printf("%d ",mat[i][n-1]);
        }
        n--;
        if(start_m<m){
            for(i=n-1;i>=start_n;i--){
                printf("%d ",mat[m-1][i]);
            }
            m--;
        }
        if(start_n<n){
            for(i=m-1;i>=start_m;i--){
                printf("%d ",mat[i][start_n]);
            }
            start_n++;
        }
    }
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
	    int m=0,n=0,i=0,j=0;
	    scanf("%d%d",&m,&n);
	    int mat[m][n];
	    for(i=0;i<m;i++){
	        for(j=0;j<n;j++){
	            scanf("%d",&mat[i][j]);
	        }
	    }
        print_spiral(m,n,mat);
        printf("\n");
	}
	return 0;
}
