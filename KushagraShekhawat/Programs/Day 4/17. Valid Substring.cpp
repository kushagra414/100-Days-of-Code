#include <iostream>
#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

int count_lognest_adjacent_number_of_zeros(int array[]);

int main() {
    int T;
	cin>>T;
	while(T){
	    char str[110];
	    int valid_array[110];
	    int limit = 110;
	    while(limit>=0){
            valid_array[--limit] = -1;
	    }
	    scanf("%s",str);
	    int N = strlen(str),max_valid_str_len =0,j=1,k=0,size;
	    //printf("size : %d",strlen(str));
	    stack <int> s1,s2;
	    for(int i=0;i<N;i++){
	        if(str[i]=='('){
                //printf("Pushing %d\n",j);
	            s1.push(j);
	            valid_array[j]=j;
	            j++;
	        }
	        else if(str[i]==')' && !s1.empty()){
                //printf("Popping %d\n",s1.top());
                valid_array[s1.top()]=0;
	            s1.pop();
	        }
	        else{
                j++;
                valid_array[j]=-1;
	        }
	    }
	    k = 110;
	    max_valid_str_len = count_lognest_adjacent_number_of_zeros(valid_array);
	    printf("%d\n",max_valid_str_len*2);
	    T--;
	}
	return 0;
}


int count_lognest_adjacent_number_of_zeros(int array[]){
    int count=0,max=0;
    for(int i=0;i<110;i++){

        if(array[i]==0)
            count++;
        else{
                if(max<count)
                    max = count;
                count = 0;
        }
    }
    return max;
}
