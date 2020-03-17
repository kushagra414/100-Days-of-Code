#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str,pat,minStr;
	    int len = 0,temp,minLen=INT_MAX,count=0;
	    cin>>str;
	    cin>>pat;
	    int Strlen = str.length();
	    int Patlen = pat.length();
	    int strAscii[256]={0},patAscii[256]={0};
	    for(int i=0;i<Patlen;i++)
	        patAscii[pat[i]]++;
	    for(int i=0,j=0;i<Strlen;i++){
	        strAscii[str[i]]++;
	        if(patAscii[str[i]]!=0 and strAscii[str[i]]<=patAscii[str[i]]){
	            count++;
	        }
	            
	        if(count==Patlen){
	            while(strAscii[str[j]]>patAscii[str[j]] or patAscii[str[j]]==0){
	                if(strAscii[str[j]]>patAscii[str[j]])
	                    strAscii[str[j]]--;
	                j++;
	            }
	        temp = i-j+1;
	        if(temp<minLen){
	            minStr = str.substr(j,temp);
	            minLen = temp;
	            }
	        }
	    }
	    if(minStr.length()==0)
	        cout<<"-1"<<endl;
	    else
	        cout<<minStr<<endl;
	}
	return 0;
}