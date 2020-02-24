#include <bits/stdc++.h>
using namespace std;

bool Compare(string a1,string a2){
    return stoi(a1+a2)>stoi(a2+a1)?1:0;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    string array[N];
	    for(int i=0;i<N;i++)
	        cin>>array[i];
	    
	    sort(array,array+N,Compare);
	    
	    for(int i=0;i<N;i++)
	        cout<<array[i];
	    cout<<endl;
	}
	return 0;
}
