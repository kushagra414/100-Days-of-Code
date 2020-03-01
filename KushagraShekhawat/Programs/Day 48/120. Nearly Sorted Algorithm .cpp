#include <iostream>
using namespace std;

void swap(int array[], int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    cin>>N>>K;
	    int array[N];
	    for(int i=0;i<N;i++)
	        cin>>array[i];
	    for(int i=0;i<N;i++)
	        for(int j=i+1;j<i+K and j<N;j++)
	            if(array[i]>array[j])
	                swap(array,i,j);
	                
	   for(int i=0;i<N;i++)
	        cout<<array[i]<<" ";
	   cout<<endl;
	}
	return 0;
}
