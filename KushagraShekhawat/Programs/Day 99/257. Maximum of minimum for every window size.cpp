#include<bits/stdc++.h>
using namespace std;

void findMaxofMin(int arr[],int n);

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
	    findMaxofMin(arr,N);
	    cout<<endl;
	}
	return 0;
}

void findMaxofMin(int arr[],int n){
    int left[n],right[n],result[n+1];
    stack<int>st;
    memset(result,0,(n+1)*sizeof(int));
    
    //Find nearest min element in left of array
    for(int i=0;i<n;i++){
        while(!st.empty() and arr[st.top()]>=arr[i])
            st.pop();
        
        left[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    
    while(!st.empty())
        st.pop();
        
    //Find nearest min element in right of array
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and arr[st.top()]>=arr[i])
            st.pop();
        
        right[i]=st.empty()?n:st.top();
        st.push(i);
    }
    
    //Now we can find out the window in which the element is min.
    for(int i=0;i<n;i++){
        int window=right[i]-left[i]-1;
        result[window]=max(result[window],arr[i]);
    }
    for(int i=n-1; i>=1; i--) 
        result[i] = max(result[i], result[i+1]); 

    for(int i=1;i<=n;i++)
        cout<<result[i]<<" ";
}