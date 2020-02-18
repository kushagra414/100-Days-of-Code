#include <algorithm>
using namespace std;

int main() {
	int N,T,X,i=0,j=0,sum=0;
	cin>>T;
	while(T--){
		cin>>N;
		int A[N];
		cin>>X;
		for(i=0;i<N;i++){
			cin>>A[i];
		}
		sort(A, A+N);
		i=0;
		j=N-1;
		while(i<j){
			sum=A[i]+A[j];
			if(sum==X){
				cout<<"Yes"<<endl;
				break ;
			}
			else if(sum>X){
				j--;
			}
			else if(sum<X){
				i++;
			}
		}
		if(i==j){
			cout<<"No"<<endl;
		}
	}
	return 0;
}
