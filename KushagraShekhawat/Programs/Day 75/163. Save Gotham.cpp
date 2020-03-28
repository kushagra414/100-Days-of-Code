#include <iostream>
#include <stack>
using namespace std;

void nextGreater(int Towers[],int N);

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int Towers[N];
	    for(int i=0;i<N;i++)
	        cin>>Towers[i];
	    nextGreater(Towers,N);
	}
	return 0;
}

void nextGreater(int Towers[],int N){
    stack<int>s;
    int i=0;
    long long int sum=0;
    while(N--){
        if(s.empty() or s.top()>=Towers[i])
            s.push(Towers[i++]);
        else{
            while(!s.empty() and s.top()<Towers[i]){
                s.pop();
                sum+=Towers[i];
            }
            s.push(Towers[i++]);
        }
    }
    if(sum>=1000000001)
        cout<<sum%1000000001<<endl;
    else
        cout<<sum<<endl;
}