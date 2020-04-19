// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void countDistinct(int[], int, int);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        countDistinct(a, k, n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
/*You are required to complete below method */
void countDistinct(int arr[], int k, int n) {
    unordered_map<int,int>ump;
    int count=0,i=0;
    for(i=0;i<k;i++){
        ump[arr[i]]++;
        if(ump[arr[i]]==1)
            count++;
    }
    cout<<count<<" ";
    for(;i<n;i++){
        if(ump[arr[i-k]]==1){
            count--;
        }
        ump[arr[i-k]]--;
        if(ump[arr[i]]==0){
            count++;
        }
        ump[arr[i]]++;
        cout<<count<<" ";
    }
}