#include <iostream>
#include <stack>
using namespace std;

void printLeafNodes(int arr[], int N);

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int preOrder[N];
	    for(int i=0;i<N;i++)
	        cin>>preOrder[i];
	    printLeafNodes(preOrder,N);
	}
	return 0;
}

void printLeafNodes(int arr[], int n){
    stack<int>s;
    
    for(int i=0,j=1;j<n;i++,j++){
        bool found = false;
        if(arr[i]>arr[j])
            s.push(arr[i]);
        else{
            while(!s.empty())
                if(arr[j]>s.top()){
                    s.pop();
                    found=true;
                }
                else
                    break;
            }
            if(found)
                cout<<arr[i]<<" ";
    }
    cout<<arr[n-1]<<endl;
}