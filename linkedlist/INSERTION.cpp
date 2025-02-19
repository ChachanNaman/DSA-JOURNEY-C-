#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertattail(node* &tail , int d){
    node* temp = new node(d);
    tail->next= temp;
    tail = temp;
}
void insertathead(node* &head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertbetween(node* &tail , node* &head, int pos , int d){

    if(pos == 1){
        insertathead(head, d);
        return ;
    }

    node* temp = head;
    int i = 1;

    if(temp ->next == NULL){
        insertattail(tail,d);
        return ;
    }
    while(i<pos-1){
        temp= temp->next;
        i++;
    }
    node *newnode = new node(d);
   newnode->next = temp->next;
   temp->next = newnode;
}



void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *node1 = new node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    node *head = node1;
    node *tail = node1;
    print(head);

    insertattail(tail, 30);
    print(head);
    insertattail(tail, 60);
    print(head);
    insertbetween(tail , head, 4, 22);
    print(head);
    return 0;
}