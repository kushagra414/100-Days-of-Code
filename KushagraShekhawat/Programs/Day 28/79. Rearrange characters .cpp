#include <bits/stdc++.h>
using namespace std;

struct charFrequency{
    char c;
    int frequency;
    charFrequency(char ch, int freq){
        c=ch;
        frequency=freq;
    }
    charFrequency();
};

struct CompareFrequency{
    bool operator()(charFrequency const& cf1, charFrequency const& cf2)
    {
    return cf1.frequency<cf2.frequency;
    }
};

int main() {
	int T;
	cin>>T;
	while(T--){
	    fflush(stdin);
	    char s[10000];
	    string result="";
	    cin>>s;
	    //cout<<"String is :"<<s<<endl;
	    int len = strlen(s),i=0;
	    int alphabet[26];
	    memset(alphabet,0,26*sizeof(int));
	    while(i<len){
	        alphabet[s[i]-'a']++;
	        i++;
	    }
	    priority_queue <struct charFrequency, vector<struct charFrequency>, CompareFrequency> pq;
	    i=0;
	    while(i<26){
	        if(alphabet[i]>0){
                charFrequency ele(i+'a',alphabet[i]);
	            pq.push(ele);
	            }
	        i++;
	    }
	    charFrequency previous('#',-1);
	    while(!pq.empty()){
	       charFrequency element = pq.top();
	       pq.pop();
    	   result+=element.c;
    	   element.frequency--;
	       if(previous.frequency>0)
	            pq.push(previous);
	        previous=element;
	    }
	    if(strlen(s)==result.length())
	        cout<<"1"<<endl;
	    else
	        cout<<"0"<<endl;
	}
	return 0;
}