#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lenght(node *head)
{
    node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

void insertathead(node* &head, int d ){
    node* temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;

}

void insertattail(node* &tail, int d){
    node* temp = new node(d);
    tail->next = temp;
    temp->prev= tail;
    tail = temp;
}

int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node* tail= node1;
    print(head);
    cout << "lenght is : " << lenght(head) << endl;

    insertathead(head, 20);
    print(head);
    insertathead(head, 30);
    print(head);
    insertathead(head, 40);
    print(head);
    insertattail(tail,50);
    print(head);
}