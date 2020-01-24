#include<iostream>
using namespace std;
void array_init(int N,int A[])
{
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
}
void leaders(int N,int A[])
{
    int maxx = 0,e = 0,E[N];
    for(int i=N-1;i>=0;i--)
    {
        if(A[i]>=maxx)
        {
            maxx = A[i];
            E[e] = maxx;
            e++;
        }
    }
    for(int i=e-1;i>=0;i--)
        {
            cout<<E[i]<<" ";
        }
}
int main()
{
    int N,t;
    //test cases
    cin>>t;
    while(t--)
    {
        cin>>N;
        int A[N];
        array_init(N, A);
        leaders(N,A);
        cout<<"\n";
    }
}
