#include <iostream>
#include <queue>
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
void levelordertraversal(node *root)
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
    // created a tree
    root = buildtree(root);
    // now doing level order traversal
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << endl;
    cout << "Level order traversal is : " << endl;
    levelordertraversal(root);

    return 0;
}