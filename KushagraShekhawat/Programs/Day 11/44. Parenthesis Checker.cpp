#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    char string[100000],para;
	    scanf("%s",string);
	    int length = strlen(string),isBalanced=1;
	    //printf("Length :%d\n",length);
	    stack <char> s;
	    for(int i=0;i<length;i++){
	        if(string[i]=='{' || string[i]=='(' || string[i]=='['){
	            s.push(string[i]);
	            //printf("String[%d]: %c\n",i,string[i]);
	        }
	        else if(!s.empty()){
	            //printf("%c and %c\n",s.top(),string[i]);
	            para=s.top();
	            if(para=='{' && string[i]=='}'){
	                s.pop();
	            }
	            else if(para=='[' && string[i]==']'){
	                s.pop();
	            }
	            else if(para=='(' && string[i]==')'){
	                s.pop();
	            }
	            else{
                    isBalanced=0;
	                break;
	            }
	        }
	        else{
                isBalanced=0;
                break;
	        }
	    }
	    if(isBalanced &&s.empty())
	        printf("balanced\n");
	    else
	        printf("not balanced\n");
	  }
	return 0;
}
