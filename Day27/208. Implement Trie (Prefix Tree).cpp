//https://leetcode.com/problems/implement-trie-prefix-tree/



class TrieNode{
public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char data){
        this->data=data;
        isTerminal=false;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};
class Trie {
public:
    TrieNode*root;
    Trie() {
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
    bool startsWith(TrieNode*root,string prefix) {
        if(root==NULL) return false;
        if(prefix.size()==0){
            return true;
        }
        int index=prefix[0]-'a';
        return startsWith(root->children[index],prefix.substr(1));           
    }
    bool startsWith(string prefix) {
        return startsWith(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
