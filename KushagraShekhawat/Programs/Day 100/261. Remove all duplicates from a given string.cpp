#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    bool character[256];
	    string str;
	    memset(character,0,256);
	    cin>>str;
	    int len=str.length();
	    for(int i=0;i<len;i++)
	        character[str[i]]=1;
	        
	 
	    for(int i=0;i<len;i++)
	        if(character[str[i]]){
	            cout<<str[i];
	            character[str[i]]=0;
	        }
	    cout<<endl;
	}
	return 0;
}