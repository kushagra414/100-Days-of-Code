// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
	if(s.empty())
	return -1;
	else
   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
	int t = -1;
	if(s.empty())
	return t;
	else
	{
		if(s.top()==minEle)
		{
			t=s.top();
			s.pop();
			if(s.empty())
			return t;
			else
			{
			minEle = s.top();
			stack<int> a(s);
			a.pop();
			while(!a.empty())
			{
				if(a.top()<minEle)
				minEle = a.top();
				a.pop();
			}
			}
		}
		else
		{
			t=s.top();
			s.pop();
		}
		return t;
	}
}

/*push element x into the stack*/
void _stack::push(int x)
{
	if(s.empty())
	minEle = x;
	else
	{
		if(minEle>x)
		minEle = x;
	}
    s.push(x);
}
