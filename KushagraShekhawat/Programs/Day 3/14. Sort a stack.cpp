// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
int compare(const void *a, const void *b){
    return (*(int*)a-*(int*)b);
}
void SortedStack :: sort()
{
    int size = s.size();
    int array[size],i=0;
   while(!s.empty()){
       array[i] = s.top();
       s.pop();
       i++;
   }
   qsort(array,size,sizeof(int),compare);
   for(int i=0;i<size;i++){
       s.push(array[i]);
   }
}