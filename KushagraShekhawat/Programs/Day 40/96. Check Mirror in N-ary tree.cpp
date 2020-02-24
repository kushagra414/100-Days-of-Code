#include <bits/stdc++.h>
using namespace std;

struct tree{
    int left;
    int right;
    tree(){
        left=0;
        right=0;
    }
};

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,E,flag=0;
	    scanf("%d%d",&N,&E);
	    int tree[2*E],mirrorTree[2*E];
	    for(int i=0;i<2*E;i++){
	        cin>>tree[i];
	    }
	    for(int i=0;i<2*E;i++){
	        cin>>mirrorTree[i];
	    }
	    unordered_map<int, struct tree*>ump;
		unordered_map<int, struct tree*>umpMirror;
	    for(int i=0;i<E*2;i=i+2){
			if(!ump[tree[i]]){
				struct tree *node = new struct tree;
				ump[tree[i]]=node;
				}
	        if(ump[tree[i]]->left==0){
	            ump[tree[i]]->left=tree[i+1];
	        }
	        else if(ump[tree[i]]->right==0){
	            ump[tree[i]]->right=tree[i+1];
	        }
			else{
				ump[tree[i]]->right=tree[i+1];
			}
	    }
	    for(int i=0;i<2*E;i=i+2){
			if(!umpMirror[mirrorTree[i]]){
				struct tree *node = new struct tree;
				umpMirror[mirrorTree[i]]=node;
				}
	        if(umpMirror[mirrorTree[i]]->right==0){
	            umpMirror[mirrorTree[i]]->right=mirrorTree[i+1];
	        }
	        else if(umpMirror[mirrorTree[i]]->left==0){
	            umpMirror[mirrorTree[i]]->left=mirrorTree[i+1];
	        }
			else{
				umpMirror[mirrorTree[i]]->left = mirrorTree[i+1];
			}
		}
		for(int i=0;i<2*E;i=i+2){
		    if(ump[tree[i]] and umpMirror[tree[i]]){
		        if((ump[tree[i]]->left == umpMirror[tree[i]]->left) and (ump[tree[i]]->right == umpMirror[tree[i]]->right))
		        {
		            flag=0;
		        }
				else if((ump[tree[i]]->left == 0 or ump[tree[i]]->right == 0) and (umpMirror[tree[i]]->left == 0 or umpMirror[tree[i]]->right==0)){
					if(ump[tree[i]]->left==umpMirror[tree[i]]->right or ump[tree[i]]->right == umpMirror[tree[i]]->left)
						flag=0;
				}
		        else{
		            flag=1;
					break;
					}
		    }
		    else{
		        flag=1;
				break;
				}
		}
	    if(flag==1)
	        printf("0\n");
	    else
	        printf("1\n");
	}
	return 0;
}
