// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends

// Function to find the transition point

int BinarySearch(int arr[], int low, int high){
    if(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==1){
            if(mid-1>=0 and arr[mid-1]==0)
                return mid;
            else if(mid-1<0)
                return 0;
            else if(arr[mid-1]==1)
                return BinarySearch(arr,low,mid-1);
        }
        else{
            return BinarySearch(arr,mid+1,high);
        }
    }
    return -1;
}

int transitionPoint(int arr[], int n) {
    return BinarySearch(arr, 0,n);
}