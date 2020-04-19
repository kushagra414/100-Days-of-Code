// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void printDuplicates(int arr[], int n);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        printDuplicates(a, n);
        cout << endl;
    }
    return 0;
}// } Driver Code Ends
/*Complete the function below*/
void printDuplicates(int arr[], int n) {
    bool flag=0;
    map<int,int>ump;
    for(int i=0;i<n;i++){
        ump[arr[i]]++;
    }
    for(auto it=ump.begin();it!=ump.end();++it){
        if(it->second>1){
            cout<<it->first<<" ";
            flag=1;
        }
    }
    if(flag==0)
        cout<<"-1";
}