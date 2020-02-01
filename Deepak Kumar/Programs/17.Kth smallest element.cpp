#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int i,N;
	    cin>>N;
	    int arr[N];
	    for(i=0;i<N;i++){
	        cin>>arr[i];
	    }
	    int K;
	    cin>>K;
	    sort(arr, arr+N);
	    cout<<arr[K-1]<<endl;
	}
	return 0;
}
