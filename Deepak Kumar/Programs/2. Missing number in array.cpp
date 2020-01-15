#include <iostream>
using namespace std;

int main(){
	int T=0,i=0,N=0,j=0,sum=0,real_sum=0,ans=0;
	cin>>T;
	while(i<T){
		i++;
		cin>>N;
		int C[N];
		for(j=0;j<N-1;j++){
			cin>>C[j];
		}
		real_sum=(N*(N+1))/2;
		for(j=0;j<N-1;j++){
			sum=sum + C[j];
		}
		ans=real_sum - sum;
		cout<<ans<<endl;
		sum=0;
	}
	return 0;
}