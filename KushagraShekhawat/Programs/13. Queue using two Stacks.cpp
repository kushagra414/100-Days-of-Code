// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}
// } Driver Code Ends
/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {

    int element1;
    while(!s1.empty()){
        element1 = s1.top();
        s1.pop();
        s2.push(element1);
    }
    s1.push(x);
    int element2;
    while(!s2.empty()){
        element2 = s2.top();
        s2.pop();
        s1.push(element2);
    }
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        int element;
        if(s1.empty()){
            element = -1;
        }
        else{
            element = s1.top();
            s1.pop();
        }
        return element;
}
