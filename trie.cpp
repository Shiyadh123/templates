struct node{
    int passCnt=0;
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

    void setPass(int i){
        passCnt+=i;
    }
    void setEnd(int i){
        endCnt+=i;
    }
    void eraseNode(char ch){
        links[ch-'a']=NULL;
    }
};

class Trie{
    private:
        node* root;
    public:

    Trie(){
        // Write your code here.
        root= new node();
    }

    void insert(string &word){
        // Write your code here.
        int l=word.length();
        node* curr=root;
        for(int i=0;i<l;i++){
            if(!curr->containsKey(word[i])){
                curr->putNode(word[i],new node());
            }
            curr=curr->getNode(word[i]);
            curr->setPass(1);
        }
        curr->setEnd(1);
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        int l=word.length();
        node* curr=root;
        for(int i=0;i<l;i++){
            if(!curr->containsKey(word[i])){
                return 0;
            }
            curr=curr->getNode(word[i]);
        }
        return curr->endCnt;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        int l=word.length();
        node* curr=root;
        for(int i=0;i<l;i++){
            if(!curr->containsKey(word[i])){
                return 0;
            }
            curr=curr->getNode(word[i]);
        }
        return curr->passCnt;
    }

    void erase(string &word){
        int l=word.length();
        node* curr=root;
        for(int i=0;i<l;i++){
            curr=curr->getNode(word[i]);
            curr->setPass(-1);
        }
        curr->setEnd(-1);
        return;
    }
};
