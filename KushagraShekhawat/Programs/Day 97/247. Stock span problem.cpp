#include<iostream>
#include<stack>
using namespace std;

struct Stocks{
    int data;
    int count=1;
};

void calSpan(Stocks arr[],int n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    Stocks arr[N];
	    for(int i=0;i<N;i++){
	        cin>>arr[i].data;
	    }
	    calSpan(arr,N);
	    cout<<endl;   
	}
	return 0;
}

void calSpan(Stocks arr[],int n){
    stack<Stocks>st;
    st.push(arr[0]);
    cout<<"1 ";
    for(int i=1;i<n;i++){
        Stocks top = st.top();
        if(top.data>arr[i].data){
            st.push(arr[i]);
            cout<<arr[i].count<<" ";
        }
        if(top.data<=arr[i].data){
            while(!st.empty() and top.data<=arr[i].data){
                arr[i].count=arr[i].count+top.count;
                st.pop();
                if(!st.empty())
                    top=st.top();
            }
            cout<<arr[i].count<<" ";
            st.push(arr[i]);
        }
    }
}