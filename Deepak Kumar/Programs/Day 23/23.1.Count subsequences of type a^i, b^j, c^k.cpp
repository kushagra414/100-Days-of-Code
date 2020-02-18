// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int fun(string &str);
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        cout<<fun(s)<<endl;
    }
	return 0;
}// } Driver Code Ends
//User function template 

// str : given string
// return the expected answer
int fun(string &str) {
    int acount=0,bcount=0,ccount=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='a'){
            acount=(1+2*acount);
        }
        else if(str[i]=='b'){
            bcount=(acount+2*bcount);
        }
        else if(str[i]=='c'){
            ccount=(bcount+2*ccount);
        }
    }
    return ccount;
}
