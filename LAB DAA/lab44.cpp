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
            cout << "Enter the word and meaning: ";
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

        return balance(root);
    }

    void inorder_rec(node *root)
    {
        if (root != NULL)
        {
            inorder_rec(root->left);
            cout << root->word << " : " << root->mean << endl;
            inorder_rec(root->right);
        }
    }

    void display()
    {
        cout << "Inorder view of my data: " << endl;
        inorder_rec(root);
    }

    node *balance(node *temp)
    {
        int bf = BF(temp);

        if (bf == 2)
        {
            if (BF(temp->left) < 0)
            {
                cout << "\nLR Rotation at: " << temp->word << endl;
                return LR_rotation(temp);
            }
            else
            {
                cout << "\nLL Rotation at: " << temp->word << endl;
                return LL_rotation(temp);
            }
        }

        if (bf == -2)
        {
            if (BF(temp->right) > 0)
            {
                cout << "\nRL Rotation at: " << temp->word << endl;
                return RL_rotation(temp);
            }
            else
            {
                cout << "\nRR Rotation at: " << temp->word << endl;
                return RR_rotation(temp);
            }
        }

        return temp;
    }

    int BF(node *temp)
    {
        return height(temp->left) - height(temp->right);
    }

    int height(node *temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        else
        {
            return max(height(temp->left), height(temp->right)) + 1;
        }
    }

    node *LL_rotation(node *temp)
    {
        node *x = temp->left;
        node *y = x->right;
        x->right = temp;
        temp->left = y;
        return x;
    }

    node *RR_rotation(node *temp)
    {
        node *x = temp->right;
        node *y = x->left;
        x->left = temp;
        temp->right = y;
        return x;
    }

    node *LR_rotation(node *temp)
    {
        temp->left = RR_rotation(temp->left);
        return LL_rotation(temp);
    }

    node *RL_rotation(node *temp)
    {
        temp->right = LL_rotation(temp->right);
        return RR_rotation(temp);
    }
};

int main()
{
    avl a;
    a.create();
    a.display();
    return 0;
}
