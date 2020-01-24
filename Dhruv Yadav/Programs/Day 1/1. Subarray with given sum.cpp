#include<iostream>
using namespace std;
void array_init(int N,int A[])
{
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
}
void subarray(int N,int A[],int S)
{
    int sum = 0,i1 = 0,i2 = 0;
    for(int i=0;i<N && sum!=S ;i++)
    {
        sum = 0;
        i1 = i+1;
        for(int j=i;j<N;j++)
        {
            sum = sum+A[j];
            if(sum == S)
            {
                i2 = j+1;
                break;
            }
            else if(sum>S)
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }
    if(i2!=0)
    {
        cout<<i1<<" "<<i2;
    }
    else
    {
        cout<<-1;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,S;
        cin>>N;
        cin>>S;
        int A[N];
        array_init(N,A);
        subarray(N,A,S);
        cout<<"\n";
    }
}
