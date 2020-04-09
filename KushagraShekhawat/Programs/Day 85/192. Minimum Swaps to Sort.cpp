// { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends
/* You are required to complete this method */

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int minSwaps(int A[], int N){
    //selection sort
    int min,count=0,temp;
    for(int i=0;i<N;i++){
        int flag=0;
        min = i;
        for(int j=i+1;j<N;j++)
            if(A[j]<A[min]){
                min=j;
                flag=1;
            }
        if(flag){
            count++;
            swap(A,i,min);
        }
    }
    return count;
}
