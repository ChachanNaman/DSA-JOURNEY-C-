#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *create(node *root)
{
    cout << "enter the data " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"enter the left data of "<<data<<endl;
    root->left = create(root->left);
    cout<<"enter the right data of "<<data<<endl;
    root->right = create(root->right);
    return root;
}

int main()
{
    node *root = NULL;
    root = create(root);
}