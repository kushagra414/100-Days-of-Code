#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,M;
	    unordered_set<int>us;
	    cin>>N>>M;
	    int arr1[N],arr2[M],sum1=0,sum2=0;
	    bool found=0;
	    for(int i=0;i<N;i++){
	        cin>>arr1[i];
	        sum1+=arr1[i];
	    }
	    for(int i=0;i<M;i++){
	        cin>>arr2[i];
	        us.insert(arr2[i]);
	        sum2+=arr2[i];
	    }
	    if(sum1!=sum2 and (sum1+sum2)%2==0){    
	        int diff=sum2-(sum1+sum2)/2;

	        for(int i=0;i<N;i++)
	            if(us.find(arr1[i]+diff)!=us.end()){
	                found=true;
	                break;
	            }
	    }
	    if(found)
	        cout<<"1"<<endl;
	    else
	        cout<<"-1"<<endl;
	        
	}
	return 0;
}