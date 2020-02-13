#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int i,j,N,S,sum=0,low=0,high=0,flag=0;
        cin>>N;
        cin>>S;
        int A[N];
        for(i=0;i<N;i++){
            cin>>A[i];
        }
        for(i=0;i<N;i++){
            for(j=i;j<N;j++){
                sum=sum+A[j];
                if(sum>S){
                    sum=0;
                    break;
                }
                else if(sum==S){
                    low=i+1;
                    high=j+1;
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==1){
            cout<<low<<" "<<high<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
	return 0;
}
