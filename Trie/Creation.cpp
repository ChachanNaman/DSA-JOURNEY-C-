#include <iostream>
using namespace std;

class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isterminal; 

    Trienode(char ch){
        data = ch;
        for(int i = 0 ; i <26 ; i++){
            children[i]=NULL;   //
        }
        isterminal = false;  //initially no terminal node
    }
};

class trie{
    public :
    Trienode* root;

    trie(){
        root = new Trienode('\0');
    }
    void insertutil(Trienode*root , string word){

        //base case if no word 
        if(word.length()==0){
            root-> isterminal = true;  //means root has direct terminal node , no node further so terminal
            return;
        }

        int index = word[0]-'A';
        Trienode* child;

        //alphabet present 
        if(root -> children[index] != NULL){//means root have that children of word needed "CAT" -> root have 'C'
            child = root-> children[index];
        }

        else{//alphabet not present , then create
            child = new Trienode(word[0]);
            root -> children[index] = child;
        }

        //recusrion for next alphabet of word
        insertutil(child , word.substr(1));

    }
    void insertword(string word){
        insertutil(root ,word);
    }
};

int main(){
    trie *t = new trie();

    t->insertword("abcd");
}