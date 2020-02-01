using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int i,N;
	    cin>>N;
	    int A[N];
	    for(i=0;i<N;i++){
	        cin>>A[i];
	    }
	    int zero=0,one=0,two=0;
	    for(i=0;i<N;i++){
	        if(A[i]==0){
	            zero++;
	        }
	        if(A[i]==1){
	            one++;
	        }
	        if(A[i]==2){
	            two++;
	        }
	    }
	    for(i=0;i<zero;i++){
	        cout<<"0"<<" ";
	    }
	    for(i=0;i<one;i++){
	        cout<<"1"<<" ";
	    }
	    for(i=0;i<two;i++){
	        cout<<"2"<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
