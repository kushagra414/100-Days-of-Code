#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    char string[50];
	    scanf("%s",string);
	    int len = strlen(string);
	    float openingBrackets=0,closingBrackets=0;
	    stack <char> s;
	    for(int i=0;i<len;i++){
	        if(s.empty()||string[i]=='{')
	            s.push(string[i]);
	        else if(s.top()=='{'&&string[i]=='}')
	            s.pop();
	        else
	            s.push(string[i]);
	    }
	    while(!s.empty()){
	        if(s.top()=='{')
	            openingBrackets++;
	        else
	            closingBrackets++;
	        s.pop();
	    }
	    if(int(openingBrackets+closingBrackets)%2==1)
	        printf("-1\n");
	    else
	        printf("%d\n",int(ceil(openingBrackets/2)+ceil(closingBrackets/2)));
	}
	return 0;
}