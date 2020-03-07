#include<iostream>
#include<stack>
using namespace std;
int Operation(char c,int op1,int op2){
    switch(c){
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<int> s1;
        int N=s.length();
        for(int i=0;i<N;i++){
            if(s[i]=='+'|| s[i]=='-' || s[i]=='*' || s[i]=='/'){
                int operand2=s1.top();
                s1.pop();
                int operand1=s1.top();
                s1.pop();
                int res=Operation(s[i],operand1,operand2);
                s1.push(res);
            }
            else{
                s1.push((s[i]-'0'));
            }
        }
        cout<<(s1.top())<<endl;

    }

    return 0;
}


