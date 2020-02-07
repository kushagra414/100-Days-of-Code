#include <iostream>
#include <stack>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    char str[100];
	    cin>>str;
	    stack <char> s;
        int flag=1,i=0;
	    while(str[i]!='\0'){
            if((str[i]=='(')||(str[i]=='{')||(str[i]=='[')){
                s.push(str[i]);
            }
            else if((!s.empty())&&((s.top()=='(')&&(str[i]==')')||(s.top()=='{')&&(str[i]=='}')||(s.top()=='[')&&(str[i]==']'))){
                s.pop();
            }
            else{
                flag=0;
                break;
            }
            i++;
        }
        if(s.empty()&&(flag==1)){
            cout<<"balanced"<<endl;
        }
        else{
            cout<<"not balanced"<<endl;
        }
	}
	return 0;
}
