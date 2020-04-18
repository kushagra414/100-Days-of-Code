// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends
/*You are required to complete this function*/
int maxLen(int arr[], int n) {
    unordered_map<int,int>ump;
    int sum=0,maxLen=0;
    ump[0]=-1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(ump.find(sum)==ump.end()){
            ump[sum]=i;
        }
        else{
            maxLen=i-ump[sum]>maxLen?i-ump[sum]:maxLen;
        }
    }
    return maxLen;
}
