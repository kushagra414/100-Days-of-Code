#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    long long int ele;
	    unordered_set<unsigned long int>us;
	    for(int i=0;i<N;i++){
	        cin>>ele;
	        us.insert(abs(ele));
	    }
	    cout<<us.size()<<endl;
	}
	return 0;
}