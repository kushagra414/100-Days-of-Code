#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int M,N,i,j;
	    cin>>M>>N;
	    int mat[M][N],row[M],column[N];;
	    for(i=0;i<M;i++){
	        for(j=0;j<N;j++){
	            cin>>mat[i][j];
	            column[j]=0;
	        }
	        row[i]=0;
	    }
	    for(i=0;i<M;i++){
	        for(j=0;j<N;j++){
	            if(mat[i][j]==1){
	                row[i]=1;
	                column[j]=1;
	            }
	        }
	    }
	    for(i=0;i<M;i++){
	        for(j=0;j<N;j++){
	            if(row[i]==1 || column[j]==1){
	                mat[i][j]=1;
	            }
	        }
	    }
	    for(i=0;i<M;i++){
	        for(j=0;j<N;j++){
	            cout<<mat[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
