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
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the left data of " << data << endl;
    root->left = create(root->left);
    cout << "enter the right data of " << data << endl;
    root->right = create(root->right);
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);

    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    root = create(root);

    cout << "Inorder Traversla " << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder Traversla " << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder Traversla " << endl;
    postorder(root);
    cout << endl;
}