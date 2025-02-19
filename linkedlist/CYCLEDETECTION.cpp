#include <iostream>
#include <map>
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

void insertattail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void insertathead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertbetween(node *&tail, node *&head, int pos, int d)
{

    if (pos == 1)
    {
        insertathead(head, d);
        return;
    }

    node *temp = head;
    int i = 1;

    if (temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    node *newnode = new node(d);
    newnode->next = temp->next;
    temp->next = newnode;
}

bool detectcycle(node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "presented element is : " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

node *floyddetect(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head;
    node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

node *startingpoint(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *intersection = floyddetect(head);
    node *slow = head;

    while (slow != intersection)
    {
        intersection = intersection->next;
        slow = slow->next;
    }
    return slow;
}

int removeloop(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    node *startofloop = startingpoint(head);
    node *temp = startofloop;
    while (temp->next != startofloop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    if (temp->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
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
    insertbetween(tail, head, 4, 22);
    print(head);

    tail->next = head->next;
    if (floyddetect(head))
    {
        cout << " cycle is there ! " << endl;
    }
    else
    {
        cout << " cycle is not there ! " << endl;
    }

    cout << " starting cycle at : " << startingpoint(head)->data << endl;

    cout<<" calling remove loop function "<<endl;
    if(removeloop(head)){
        cout<< " loop is removed ! "<<endl;
    }
    else{
        cout<<" loop wasn't there ! "<<endl;
    }
    return 0;
}