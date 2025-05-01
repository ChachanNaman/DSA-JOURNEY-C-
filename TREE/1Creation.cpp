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

node *buildtree(node *root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new node(data); // calling constructor here where d=data and left right set to null automatcially

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    return 0;
}