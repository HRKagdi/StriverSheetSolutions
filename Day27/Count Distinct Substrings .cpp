//https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos



#include<bits/stdc++.h>
using namespace std;
class TrieNode{
   public:
    char data;
    bool isTerminal;
    TrieNode**children;
    TrieNode(char data){
        this->data=data;
        isTerminal=false;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie{
  public:
    TrieNode*root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insert(TrieNode*root,string word){
        if(word.size()==0){
            root->isTerminal=true;
            return ;
        }
        int index=word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insert(child,word.substr(1));
    }
    void insert(string word) {
        insert(root,word);
    }
    bool search(TrieNode*root,string word) {
        if(root==NULL) return false;
        if(word.size()==0){
            if(root->isTerminal) return true;
            return false;
        }
        int index=word[0]-'a';
        return search(root->children[index],word.substr(1));
    }
    
    bool search(string word) {
        return search(root,word);
    }
};
int countDistinctSubstrings(string &s)
{
    Trie*prefix=new Trie();
    int ans=0;
    for(int i=0;i<s.size();i++){
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(!prefix->search(temp)) {
                ans++;
                prefix->insert(temp);
            }
        }
    }
    return ans+1;
}
