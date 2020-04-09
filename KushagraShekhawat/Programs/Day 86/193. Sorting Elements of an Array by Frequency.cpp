// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int a[1000000];

void sortByFreq(int arr[],int n);

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    
	    sortByFreq(a,n);
	    cout << endl;
	}
	
	return 0;
}

// } Driver Code Ends
//Complete this function
//The array is declared globally

/*struct Elements{
    int ele;
    int frequency=0;
};*/

bool Compare(pair<int,int>p1, pair<int,int>p2){
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second>p2.second;
}

void sortByFreq(int arr[],int n)
{
    unordered_map<int, int>ump;
    for(int i=0;i<n;i++)
        ump[arr[i]]++;
        
    vector<pair<int,int>>vec(ump.begin(),ump.end());
    sort(vec.begin(),vec.end(),Compare);
    for(auto it=vec.begin();it!=vec.end();++it)
        while(it->second--)
            cout<<it->first<<" ";
}