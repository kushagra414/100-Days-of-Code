#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int A,N,len;
	    cin>>A>>N;
	    
	    string num;
	    for(int i=1;i<=N;i++){
	        int x = pow(A,i);
	        num+=to_string(x);
	    }
	    
	    len = num.length(); 
	    vector<int>vec;
	    
	    for(int i=0;i<len;i++){
	        int val = num[i]-48;
	        if(val)
	            vec.push_back(val);
	    }
	    sort(vec.begin(),vec.end());
	    for(auto it=vec.begin();it!=vec.end();++it)
	        cout<<*it;
	    cout<<endl;
	}
	return 0;
}