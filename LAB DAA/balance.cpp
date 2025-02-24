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
    avl() { root = NULL; }

    void create()
    {
        char ch;
        node *curr;
        string word, mean;
        do
        {

            cout << "enter the word and mean : ";
            cin >> word >> mean;
            curr = new node();
            curr->word = word;
            curr->mean = mean;
            curr->left = curr->right = NULL;
            root = avl_rec(root, curr);
            cout << "Do you want to add another word? (y/n): ";
            cin >> ch;
        } while (ch == 'y');
    }
    node *avl_rec(node *root, node *curr)
    {
        if (root == NULL)
        {
            return curr;
        }
        else if (curr->word < root->word)
        {
            root->left = avl_rec(root->left, curr);
        }
        else
        {
            root->right = avl_rec(root->right, curr);
        }
        return root;
    }
    void inorder_rec(node *root)
    {
        if (root != NULL)
        {
            inorder_rec(root->left);
            cout << root->word << " : " << root->mean << endl;
            cout << "  BF: " << BF(root) << endl;
            inorder_rec(root->right);
        }
    }
    void display()
    {
        cout << "Inorder view of my data : " << endl;
        inorder_rec(root);
    }

    int BF(node *temp)
    {
        int bf;
        bf = height(temp->left) - height(temp->right);
        return bf;
    }
    int height(node *temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        else
        {
            return std::max(height(temp->left), height(temp->right)) + 1;
        }
    }
};

int main()
{
    avl a;
    a.create();
    a.display();
    return 0;
}