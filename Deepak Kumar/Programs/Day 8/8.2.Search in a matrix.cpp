#include <iostream>
using namespace std;

int search(int X,int N, int M, int *mat){
    int i=0,j=0,flag=0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(*(mat+i*M+j)==X)
                flag=1;
        }
    }
    if(flag==1){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N=0,M=0,i=0,j=0;
	    cin>>N>>M;
	    int mat[N][M];
	    for(i=0;i<N;i++){
	        for(j=0;j<M;j++){
	            cin>>mat[i][j];
	        }
	    }
	    int X;
	    cin>>X;
	    cout<<search(X,N,M,(int *)mat)<<endl;
	}
	return 0;
}
