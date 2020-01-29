

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        char character;
        int InStream[N],flag=0,charCount[26];
        memset(charCount,0,26*sizeof(int));
        for(int i=0;i<N;i++){
            scanf(" %c",&character);
            InStream[i]=character;
        }
        queue <int> q;
        for(int i=0;i<N;i++){
            q.push(InStream[i]-97);
            charCount[InStream[i]-97]++;
            while(!q.empty()){
                if(charCount[q.front()]>1){
                    q.pop();
                }
                else{
                    printf("%c ",q.front()+97);
                    break;
                }
            }
            if(q.empty())
                printf("-1 ");
        }

        printf("\n");
    }
    return 0;
}
