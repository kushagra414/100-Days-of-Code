#include<bits/stdc++.h>
using namespace std;

string ones(int n);
string seconds(int n);
string tens(int n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[4]={0},i=0;
	    bool And=0,isOne=0;
	    string num;
	    while(N){
	        arr[i++]=N%10;
	        N=N/10;
	    }
	    {
	        //Thousands place
    	    if(arr[3]!=0){
    	        num+=ones(arr[3]);
    	        num+= " thousand ";
    	        And=1;
    	    }
    	    //Hundreds place
    	    if(arr[2]!=0){
    	        num+=ones(arr[2]);
    	        num+= " hundred ";
    	        And=1;
    	    }
    	    
    	    //Place and
            if((arr[1]!=0 or arr[0]!=0) and And==1){
                    num+="and ";
                }
    	    
    	    //Tens place
            if(arr[1]!=0){
                if(arr[1]==1){
                    num+=tens(arr[1]*10+arr[0]);
                    num+=" ";
                    isOne=1;
                }
                else{
        	        num+=seconds(arr[1]);
        	        num+=" ";
                }
    	    }
    	    if(arr[0]!=0 and isOne==0){
    	        num+=ones(arr[0]);
    	    }
    	    
	    }
	    cout<<num<<endl;
	}
	return 0;
}

string ones(int n){
    switch(n){
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
    }
}

string seconds(int n){
    switch(n){
        case 2: return "twenty";
        case 3: return "thirty";
        case 4: return "forty";
        case 5: return "fifty";
        case 6: return "sixty";
        case 7: return "seventy";
        case 8: return "eighty";
        case 9: return "ninety";
    }
}
string tens(int n){
    switch(n){
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
    }
}