#include <iostream>
#include <string>
using namespace std;

class node
{
    string word;
    string mean;
    node *left;
    node *right;
    friend class avl;
};

class avl
{
    node *root;

public:
    avl()
    {
        root = NULL;
    }
    void create(){
        char ch;
        node *curr;
        string word, mean;
        do{
        cout<<"enter the word and mean : ";
        cin>>word>>mean;
        curr = new node();
        curr->word = word;
        curr->mean = mean;
        curr->left = curr -> right = NULL;
        root = avl_rec(root , curr);
        cout<<"Do you want to add another word ? (y/n) : ";
        cin>>ch;
        }while(ch =='y');
    }
    node *avl_rec(node *root , node *curr){
        if(root == NULL){
            return curr;
        }
        else if(curr->word < root->word){
            root->left = avl_rec(root , curr->left);
        }
        else{
            root->right = avl_rec(root , curr->right);
        }
        return balance(root);
    }
    node *balance(node *temp){
        int bf;
        bf = BF(temp);
        if(bf == 2){
            if(BF(temp->left)<0){
                cout<<"\nLR rotation at "<<temp->word<<endl;
                return LR_rotation(temp);
            }
            else{
                cout<<"\nLL rotation at "<<temp->word<<endl;
                return LL_rotation(temp);
            }
        }
        if(bf == -2){
            if(BF(temp->left)<0){
                cout<<"\nRR rotation at "<<temp->word<<endl;
                return RR_rotation(temp);
            }
            else{
                cout<<"\nLL rotation at "<<temp->word<<endl;
                return RL_rotation(temp);
            }
        }
        return temp;
    }
    int BF(node *temp){
        int bf = height(temp->left)-height(temp->right);
        return bf;
    }
    int height(node*temp){
        if(temp == NULL){
            return 0;
        }
        else{
            return max(height(temp->left) , height(temp->right)) +1;
        }
    }

};

