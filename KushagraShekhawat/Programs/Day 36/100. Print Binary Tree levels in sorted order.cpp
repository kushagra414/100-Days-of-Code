#include <bits/stdc++.h>
using namespace std;
void print(int arr[],int l,int h,int n){
    h=min(h,n);
    set<int> s;
    for(int i=l;i<h;i++)
        s.insert(arr[i]);
    set<int>::iterator it=s.begin();
    while(it!=s.end()){
        cout<<*it<<" ";
        it++;
    }
    cout<<"\n";
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    int i=0;
	    int l=0;
	    while(1){
	        int h=min(l+(int)pow(2,i),n);
	        print(arr,l,l+pow(2,i),n);
	        l+=pow(2,i);
	        i++;
	        if(l>=n)
	            break;
	    }
	}
	return 0;
}