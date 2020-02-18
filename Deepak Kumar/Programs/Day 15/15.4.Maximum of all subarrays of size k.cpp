#include <iostream>
#include <deque>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,k,i,j;
        cin>>N>>k;
        int A[N];
        for(i=0;i<N;i++){
            cin>>A[i];
        }
        deque<int> d(N);
        for(i=0;i<k;i++){
            while((!d.empty())&&(A[i]>=A[d.back()])){
                d.pop_back();
            }
            d.push_back(i);
        }
        for(i=k;i<N;i++){
            cout<<A[d.front()]<<" ";
            while((!d.empty())&&(d.front()<i-k+1)){
                d.pop_front();
            }
            while((!d.empty())&&(A[i]>=A[d.back()])){
                d.pop_back();
            }
            d.push_back(i);
        }
        cout <<A[d.front()]<<endl;
    }
	return 0;
}
