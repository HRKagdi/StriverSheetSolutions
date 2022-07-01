//https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos



class TrieNode{
   public:
    char data;
    TrieNode**children;
    bool isTerminal;
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
    bool isComplete(TrieNode*root,string word){
        if(root==NULL) return false;
        if(word.size()==0){
            if(root->isTerminal) return true;
            return false;
        }
        int index=word[0]-'a';
        TrieNode*child=root->children[index];
        return child->isTerminal && isComplete(child,word.substr(1));
    }
    bool isComplete(string word){
        return isComplete(root,word);
    }
};
bool comparator(string a,string b){
    return (a.size()>b.size());
}
string completeString(int n, vector<string> &a){
    sort(a.begin(),a.end(),comparator);
    Trie*prefix=new Trie();
    for(int i=0;i<n;i++){
       prefix->insert(a[i]);
    }
    string ans="None";
    for(int i=0;i<a.size();i++){
        if(prefix->isComplete(a[i])){
            ans=a[i]; break;
        }
    }
    return ans;
}
