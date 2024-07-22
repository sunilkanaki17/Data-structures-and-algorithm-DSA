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

void bfs(map<int,list<int>> &adj,vector<bool> &visited,int startnode)
{
    
    queue<int> q;
    q.push(startnode);
    visited[startnode] = true;

    while(!q.empty())
    {
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();

        for(int key:adj[curr])
        {
            if(!visited[key])
            {
                visited[key] = true;
                q.push(key);
            }
        }
    }
   
}

int main()
{
    int m,n;
    int u,v;
    graph g;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    cout<<"Enter number of edges"<<endl;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g.addedge(u,v,0);
    }

    g.printgraph();
    vector<bool> visited(n,false);
    bfs(g.adj,visited,0);

}