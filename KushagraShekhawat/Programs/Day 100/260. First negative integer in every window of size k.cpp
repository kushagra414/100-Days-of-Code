#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K,count=0,i,firstNeg=0;
	    vector<int>vec;
	    bool foundNeg=0;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    cin>>K;
	    for(i=0;i<K;i++){
	        if(arr[i]!=abs(arr[i])){
	            foundNeg=1;
	            vec.push_back(i);
	        }
	    }
	    if(foundNeg==0)
	        cout<<"0 ";
	    else
	        cout<<arr[vec[0]]<<" ";
	        
	    for(i;i<N;i++){
	        if(arr[i]!=abs(arr[i]))
	            vec.push_back(i);
	        if(!vec.empty() and i-K==vec[0])
	            vec.erase(vec.begin());
	        if(vec.empty())
	            cout<<"0 ";
	        else
	            cout<<arr[vec[0]]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}