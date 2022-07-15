
struct node{
    int endCnt=0;
    node* links[26]={NULL};

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void putNode(char ch,node* newNode){
        links[ch-'a']=newNode;
    }

    node* getNode(char ch){
        return links[ch-'a'];
    }
 
    void setEnd(int i){
        endCnt=i;
    }
};


class Trie{
    node* root;
   public:
    Trie(){
        root=new node();
    }
    void insert(string &word){
        int l=word.length();
        node* curr=root;
        for(int i=0;i<l;i++){
            if(!curr->containsKey(word[i])){
                curr->putNode(word[i],new node());
            }
            curr=curr->getNode(word[i]);
        }
        curr->setEnd(1);
     }
    int isComplete(string &word ){
        int l=word.length();
        node* curr=root;
        for(int i=0;i<l;i++){
            curr=curr->getNode(word[i]);
            if(curr->endCnt==0) return 0;
        }
        return word.length();
 }
};
 

string completeString(int n, vector<string> &a){
     sort(a.begin(),a.end());
    Trie* obj =new Trie();
     for(auto i:a) obj->insert(i);
    
       string ans="";
       int maxLen=0;
      for(int i=0;i<n;i++){
          int currLen=0;
          if(a[i].length()>maxLen) currLen=obj->isComplete(a[i]);
          if(currLen>maxLen){
              maxLen=currLen;
              ans=a[i];
          }
      }
    return ans==""?"None":ans;
}
