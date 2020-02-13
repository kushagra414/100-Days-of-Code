#include <bits/stdc++.h>
#define ALPHABET 26
using namespace std;

struct Trie{
    struct Trie *character[ALPHABET];
    bool endOfString;
    
    Trie(){
        for(int i=0;i<ALPHABET;i++)
            character[i] = NULL;
        endOfString = false;
    }
};

struct Trie *getNode(){
    struct Trie *node = new Trie;
    return node;
}

void insert(struct Trie *node,string key){
    struct Trie *root = node;
    
    int lenKey = key.length();
    for(int i=0;i<lenKey;i++){
        int index = key[i]-'a';
        if(!root->character[index])
            root->character[index]=getNode();
        root = root->character[index];
    }
    root->endOfString=true;
}

bool search(struct Trie *root, string findStr){
    int lenStr = findStr.length();
    
    for(int i=0;i<lenStr;i++){
        int index = findStr[i]-'a';
        if(!root->character[index])
            return false;
        root=root->character[index];
    }
    return (root!=NULL&&root->endOfString);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int keys;
	    cin>>keys;
	    string str[keys],searchStr;
	    for(int i=0;i<keys;i++)
	        cin>>str[i];
	    
	    struct Trie *root = getNode();
	    for(int i=0;i<keys;i++)
	        insert(root,str[i]);
	    
	    cin>>searchStr;
	    cout<<search(root,searchStr)<<endl;
	}
	return 0;
}