#include<bits/stdc++.h>
using namespace std;

string source = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main()
{
	int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int p=n; 
        vector<int> v;
    	while(n)
    	{
    	    v.push_back(n%62);
    	    n /= 62;
    	}
    	reverse(v.begin(), v.end());
    	string url = "";
    	for(int i=0; i<v.size(); i++)
    	    url += source[v[i]];
    	    
    	cout << url << "\n" << p << endl;
    }
        
	return 0;
}