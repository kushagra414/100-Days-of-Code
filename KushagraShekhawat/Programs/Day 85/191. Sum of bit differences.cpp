#include<iostream>
using namespace std;

int bin(unsigned n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,count=0,totalCombinations;
	    cin>>N;
	    unsigned int arr[N],hash[11]={0};
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    for(int i=0;i<N;i++){
	        for(int j=i+1;j<N;j++){
	            unsigned int z = arr[i]^arr[j];
	            count+=bin(z);
	        }
	    }
	    for(int i=N-1;i>=0;i--){
	        for(int j=i-1;j>=0;j--){
	            unsigned int z = arr[i]^arr[j];
	            count+=bin(z);
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}

int bin(unsigned n) 
{ 
    unsigned i;
    int count=0;
    for (i = 1 << 24; i > 0; i = i / 2) 
        count+=(n & i)? 1: 0; 
    return count;
} 