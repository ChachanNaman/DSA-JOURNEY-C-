#include <iostream>
#include <stdlib.h>
#include <list>
#include <unordered_map>

using namespace std;

class graph
{
public:
    unordered_map<int, list<int> >  adj;
    void add(int u, int v, bool direction)
    //direction = 0 -> undirected graph 
    //direction = 1 -> directed graph
    { // u->first node , v->second node ,diectiorn -> ordered or unordered
        adj[u].push_back(v);
        if (direction == 0)  //if undirected graph then there can be both side edges like 1->0 and 0->1 so pushing u in v also
        {
            adj[v].push_back(u);
        }
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ,";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    int m;
    cout<<"enter the no. of nodes : ";
    cin>>n;
    cout<<endl;
    
    cout<<"enter the no. of edges : ";
    cin>>m;
    cout<<endl;

    graph g;
    for (int i = 0; i < m; i++)
    {
        int n,m;
        cin >> n >> m;
        g.add(n,m,0);
    }
    g.print();
    


    
    return 0;
}