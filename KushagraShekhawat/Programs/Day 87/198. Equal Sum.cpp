#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    bool flagL=1,flagR=1;
	    int arr[N],sumLeft=0,sumRight=0;
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    for(int i=0,j=N-1;j-i>1;){
	        sumLeft+=arr[i];
	        sumRight+=arr[j];
	        if(sumLeft>sumRight){
	            j--;
	            sumLeft-=arr[i];
	        }
	        else if(sumLeft<sumRight){
	            i++;
	            sumRight-=arr[j];
	        }
	        else{
	            i++;
	            j--;
	        }
	    }
	    
	    if(N==2)
	        cout<<"NO"<<endl;
	    else if(sumLeft==sumRight)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	return 0;
}