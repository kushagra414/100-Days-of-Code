// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> , int );

// User code will be pasted here

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int> > arr,res;
        int n,x,y;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            arr.push_back(make_pair(x,y));
        }
        
        res = overlappedInterval(arr,n);
        
        
        for(int i=0;i<res.size();i++)
            cout << res[i].first << " " << res[i].second << " " ;
            
        cout<<endl;
    }
}
// } Driver Code Ends
//User function template for C++

// n : size of the array
// vec : given vector pair containing intervals

bool Compare(pair<int,int> i1,pair<int,int> i2){
    if(i1.first==i2.first)
        return i1.second<i2.second;
    return i1.first<i2.first;
}

vector<pair<int,int>> Merge(vector<pair<int,int>>vec,int n){
    vector<pair<int,int>>newVec;
    newVec.push_back(vec[0]);
    for(int i=1;i<n;i++){
        pair<int,int> previous = newVec.back();
        newVec.pop_back();
        if(previous.second>=vec[i].first){
            if(vec[i].second>previous.second)
                previous.second = vec[i].second;
            newVec.push_back(previous);
        }
        else{
            newVec.push_back(previous);
            newVec.push_back(vec[i]);
        }
    }
    return newVec;
}

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    sort(vec.begin(),vec.end(),Compare);
    vector<pair<int,int>> newVec = Merge(vec,n);
    return newVec;
}