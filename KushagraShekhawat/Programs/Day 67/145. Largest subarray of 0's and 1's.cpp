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
    int sum=0,Max=0;
    for(int i=0;i<n;i++){
        sum += arr[i]==0?-1:1;
        if(sum==0)
            Max = max(i+1,Max);
        if(ump.find(sum)!=ump.end()){
            int j = ump[sum];
            Max = max(i-j,Max);
        }
        else
            ump[sum]=i;
        
    }
    return Max;
}
 
