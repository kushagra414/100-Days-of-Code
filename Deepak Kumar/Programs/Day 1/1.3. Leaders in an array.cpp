using namespace std;

int main(){
	int T=0,i=0,N=0,max=0;
	cin>>T;
	while(i<T){
		i++;
		cin>>N;
		int A[N],j=0,k=0,B[N];
		while(j<N){
			cin>>A[j];
			j++;
		}
		max=A[N-1];
		for(j=N-1;j>=0;j--){
			if(j==(N-1)){
				B[k]=A[j];
				k++;
			}
			else if(max<=A[j]){
				max=A[j];
				B[k]=max;
				k++;
			}
		}
		for(j=k-1;j>=0;j--){
		    cout<<B[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}