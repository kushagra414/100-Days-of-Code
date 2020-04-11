#include<bits/stdc++.h>
using namespace std;

long long int findTotalComb(int arr[], int n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    
	    cout<<findTotalComb(arr,N)<<endl;
	}
	return 0;
}

long long int findTotalComb(int arr[], int n){
    	long long int Remainder[3]={0};
    	long long int multipleOf3=0;
	    
	    for(int i=0;i<n;i++)
	        Remainder[arr[i]%3]++;
	    
	    //Total possibilites for group of two
	    {
    	    //Case 1: When both numbers are multiple of 3. nC2
    	    multipleOf3+=(Remainder[0]*(Remainder[0]-1))/2;
    	    //Case 2: When one number has 1 remainder and other has
    	    // remainder as 2. eg:- 1+2
    	    multipleOf3+=(Remainder[1]*(Remainder[2]));
	    }
	    
	    //Totla possibilites for group of three
	    {
	        //Case 1: When all three number are multiple of 3. nC3
	        multipleOf3+=(Remainder[0]*(Remainder[0]-1)*(Remainder[0]-2))/6;
	        //Case 2: When all three number have 1 as remainder. nC3
	        multipleOf3+=(Remainder[1]*(Remainder[1]-1)*(Remainder[1]-2))/6;
	        //Case 3: When all three number have 2 as remainder. nC3
	        multipleOf3+=(Remainder[2]*(Remainder[2]-1)*(Remainder[2]-2))/6;
	        //Case 4: When one number have 0,1, and 2 as remainder.
	        multipleOf3+=(Remainder[0]*(Remainder[1])*(Remainder[2]));
	    } 
	    return multipleOf3;
}