// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


long long getSum(int [],int n);
main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<getSum(a,n)<<endl;
	}
	return 0;
}// } Driver Code Ends
/*You are required to complete this method */

long long int factorial(long long int n){
    if(n==1 or n==0)
        return 1;
    else
        return n*factorial(n-1);
}

long long getSum(int arr[],int n)
{
    long long int fact = factorial(n);
    long long int sum=0,digitSum=0,k=1;
    for(int i=0;i<n;i++)
        digitSum+=arr[i];
    
    digitSum*=(fact/n);
    
    for(int i=0;i<n;i++){
        sum+=digitSum*k;
        k*=10;
    }
    return sum%1000000007;
}