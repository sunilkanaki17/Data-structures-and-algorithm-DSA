#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    map<int,list<int>>adj;

    void addedge(int u,int v, bool direction)
    {
        //undirection = 0;
        //direction = 1
        adj[u].push_back(v);
        if(!direction)
        {
            adj[v].push_back(u);
        }
    }
    void printgraph()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int m;
    int u,v;
    graph g;
    cout<<"Enter number of edges"<<endl;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g.addedge(u,v,0);
    }

    g.printgraph();


}