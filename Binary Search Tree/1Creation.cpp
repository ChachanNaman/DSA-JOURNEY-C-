#include <iostream>
#include <queue>
using namespace std;
//level order traversal for printing tree
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

node *insertintoBST(node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertintoBST(root->right, d);
    }
    else
    {
        root->left = insertintoBST(root->left, d);
    }
    return root;
}
void takeinput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
       root =  insertintoBST(root, data);
         cin >> data;
    }
}
void levelordertraversal(node * root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        { // enter condition
            cout << endl;
            if (!q.empty())
            { // means there are some element in queue then push NULL for next enter
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = NULL;
    cout << "enter datas to create BST : " << endl;
    takeinput(root);

    cout << "Printing BST : " << endl;
    levelordertraversal(root);

    return 0;
}