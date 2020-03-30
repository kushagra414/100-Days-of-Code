// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main()
{   
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}// } Driver Code Ends
/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree

bool isOperand(char c){
    switch(c){
        case '+': return true;
        case '-': return true;
        case '*': return true;
        case '/': return true;
        case '^': return true;
        default : return false;
    }
}

et* constructTree(char postfix[])
{
    stack<et *>st;
    int size = strlen(postfix);
    for(int i=0;i<size;i++){
        if(!isOperand(postfix[i])){
            et *Operand = (et *)(malloc(sizeof(et)));
            Operand->value = postfix[i];
            Operand->left = Operand->right = NULL;
            st.push(Operand);
        }
        else{
            et *op1,*op2,*Operator;
            Operator = (et *)(malloc(sizeof(et)));
            op1 = st.top(); st.pop();
            op2 = st.top(); st.pop();
            Operator->value = postfix[i];
            Operator->right = op1;
            Operator->left = op2;
            st.push(Operator);
        }
    }
    return st.top();
}
