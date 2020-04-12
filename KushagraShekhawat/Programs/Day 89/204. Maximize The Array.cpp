#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr1[N],arr2[N];
	    vector<int>vec;
	    for(int i=0;i<N;i++){
	       cin>>arr1[i];
	       vec.push_back(-1*arr1[i]);
	    }
	    for(int i=0;i<N;i++){
	       cin>>arr2[i];
	       vec.push_back(-1*arr2[i]);
	    } 
	    

	    sort(vec.begin(),vec.end());
	    unordered_set<int>us;
	    
	    int i=0;
	    for(auto it=vec.begin();i<N and it!=vec.end();++it){
	        int x = -1*(*it);
	        if(us.find(x)==us.end()){
	            us.insert(x);
	            i++;
	        }
	    }
	    
	    for(int i=0;i<N;i++)
	       if(us.find(arr2[i])!=us.end()){
	           cout<<arr2[i]<<" ";
	           us.erase(arr2[i]);
	       }

	    for(int i=0;i<N;i++)
	       if(us.find(arr1[i])!=us.end()){
	           cout<<arr1[i]<<" ";
	           us.erase(arr1[i]);
	       }
	    cout<<endl;
	}
	return 0;
}