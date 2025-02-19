#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;
class friends
{
    int id;
    char name[20];
    friends *next;
    friend class graph;
};

class graph
{
    friends *head[20];
    int n;

public:
    graph(int n1)
    {
        n = n1;
        for (int i = 0; i < n; i++)
        {
            head[i] = nullptr; // Initialize all head pointers to nullptr
        }
    }
    void create();
    void display();
    void non_dft(int vertex);
    void rec_dft(int vertex);
    void non_bft(int vertex);
};

class mystack
{
public:
    int stack[MAX];
    int top;
    mystack(){
top = -1;
    }
   
    friend class graph;
    int isfull()
    {
        if (top == MAX - 1)
            return 1;
        else
            return 0;
    }
    int isempty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    void push(int x)
    {
        if (isfull() == 0)
        {
            top++;
            stack[top] = x;
        }
        else
            cout << "stack is full so element cannot be added." << endl;
    }
    int pop()
    {
        if (isempty() == 1)
        {
            cout << "Stack is empty hence element cannot be deleted." << endl;
            return -1;
        }
        else
        {
            int x = stack[top];
            top--;
            return x;
        }
    }
};

class myqueue
{
public:
    int queue[MAX];
    int front;
    int rear;
    myqueue(){
     front = -1;
     rear = -1;
    }
   
    int isfull()
    {
        if (rear == MAX - 1)
        {
            return 1;
        }
        else
            return 0;
    }

    int isempty()
    {
        return (front == -1 && rear == -1); 
    }

    void insert(int x)
    {
        if (isfull() == 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            { 
                front = 0;
            }
            rear++;
            queue[rear] = x;
        }
    }

    int Delete()
    {
        if (isempty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            int element = queue[front];
            front++;
            if (front > rear) 
            {
                front = -1;
                rear = -1;
            }
            return element;
        }
    }
};

void graph::create()
{
    char ch;

    for (int i = 0; i < n; i++)
    {
        head[i] = new friends();
        cout << "Enter the user name of user : " << i << endl;
        cin >> head[i]->name;
        head[i]->id = i;
        head[i]->next = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        friends *temp = head[i];
        cout << "Does user " << i << " have any friends ? Enter y(yes)/n(no ) : " << endl;
        cin >> ch;
        while (ch == 'y')
        {
            friends *curr = new friends();
            cout << "Accept friend ID" << endl;
            cin >> curr->id;
            if (curr->id < 0 || curr->id >= n)
            {
                cout << "Invalid friend ID!" << endl;
                delete curr;
                continue;
            }

            strcpy(curr->name, head[curr->id]->name);
            curr->next = NULL;
            temp->next = curr;
            temp = curr;
            cout << "If more friends enter y(yes)/n(no) : " << endl;
            cin >> ch;
        }
    }
}

void graph::display()
{
    friends *temp;
    for (int i = 0; i < n; i++)
    {
        temp = head[i];
        while (temp != NULL)
        {
            if (temp->next == NULL)
                cout << temp->id << " " << temp->name << endl;
            else
                cout << temp->id << " " << temp->name << "->";
            temp = temp->next;
        }
    }
}

void graph::rec_dft(int vertex)
{
    static int visit[100] = {0};
    visit[vertex] = 1;
    cout << " " << head[vertex]->id << " " << head[vertex]->name;
    friends *temp = head[vertex]->next;
    while (temp != NULL)
    {
        if (visit[temp->id] == 0)
        {
            
            rec_dft(temp->id);
        }
        temp = temp->next;
    }
}

void graph::non_dft(int vertex)
{
    int visited[100] = {0};
    friends *temp;
    mystack s;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    s.push(vertex);
    while (s.isempty() == 0)
    {
        int v = s.pop();
        if (visited[v] == 0)
        {
            cout << head[v]->id << " -> " << head[v]->name << endl;
            visited[v] = 1;
        }
        temp = head[v]->next;
        while (temp != NULL)
        {
            if (visited[temp->id] == 0)
            {
                s.push(temp->id);
            }
            temp = temp->next;
        }
    }
}

void graph::non_bft(int vertex)
{
    int visited[100] = {0};
    friends *temp;
    myqueue q;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    q.insert(vertex);
    while (q.isempty() == 0)
    {
        int v = q.Delete();
        if (visited[v] == 0)
        {
            cout << head[v]->id << " -> " << head[v]->name << endl;
            visited[v] = 1;
        }
        temp = head[v]->next;
        while (temp != NULL)
        {
            if (visited[temp->id] == 0)
            {
                q.insert(temp->id);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of users" << endl;
    cin >> n;

    graph g(n);
    g.create();
    g.display();
    int vertex1;
    cout << ":Enter the starting address of rec dft traversal" << endl;
    cin >> vertex1;
    g.rec_dft(vertex1);
    // int vertex2;
    // cout << ":Enter the starting address of non bft traversal" << endl;
    // cin >> vertex2;
    // g.non_bft(vertex2);
    // int vertex3;
    // cout << ":Enter the starting address of non dft traversal" << endl;
    // cin >> vertex3;
    // g.non_dft(vertex3);
    return 0;
}