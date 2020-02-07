#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,M,i,temp,ans=99999;
        cin>>N;
        int A[N];
        for(i=0;i<N;i++){
            cin>>A[i];
        }
        cin>>M;
        sort(A,A+N);
        for(i=0;i<N-M+1;i++){
            temp=A[i+M-1]-A[i];
            if(temp<ans){
                ans=temp;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
