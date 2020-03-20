// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends
/*You are required to complete this method*/
int maxLen(int arr[], int n) {
    unordered_map<int , int>ump;
    int sum=0,count=0;
    ump[0]=0;
    for(int i=0;i<n;i++){
        sum += arr[i]==0?-1:1;
        ump[sum]++;
    }
    int total_fre=0;
    for(auto it = ump.begin();it!=ump.end();++it){
        int frequency = it->second;
        if(frequency>1)
            count +=frequency*(frequency-1)/2;
        }
    if(ump.find(0) != ump.end())
		count += ump[0];
	return count;
}
 
