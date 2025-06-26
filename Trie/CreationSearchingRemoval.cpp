#include <iostream>
using namespace std;
#include <string>
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

    bool searchutil(Trienode* root, string word){

        //if got terminal node 
        if(word.length()==0){
            return root->isterminal;
        }

        int index = word[0]-'A';
        Trienode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{//not there in tree
            return false; 
        }

        //now recurssion
        return searchutil(child , word.substr(1));
    }

    bool search(string word){
       return searchutil(root , word);
    }

    void removeutil(Trienode* root , string word){
        if(word.length()==0){
            root->isterminal=0;
            return;
        }
        int index = word[0]-'A';
        Trienode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return;
        }
        removeutil(child, word.substr(1));
    }

    void remove(string word){
        removeutil(root , word);
    }
};

int main(){
    trie *t = new trie();
    //creation
    t->insertword("NAMAN");
    t->insertword("IS");
    t->insertword("GOD");
    //searching
    cout<<"present(1) or not(0) : "<< t->search("IS")<<endl;
    cout<<"present(1) or not(0) : "<< t->search("NAMAN")<<endl;
    cout<<"present(1) or not(0) : "<< t->search("GOOD")<<endl;

    //removing
    t->remove("NAMAN");
    cout<<"present(1) or not(0) : "<< t->search("NAMAN")<<endl; 
}