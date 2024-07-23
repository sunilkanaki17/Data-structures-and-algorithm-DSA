#include<bits/stdc++.h>
using namespace std;

class graph
{
    public:
     map<int,list<int>>adj;

    void addedge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printadj()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
};

void dfs(int node,map<int,bool> &visited,vector<int> &res, map<int,list<int>> &adj)
{
    //res.push_back(node);
    cout<<node<<" ";
    visited[node] = true;

    for(int i:adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,res,adj);
        }
    }

}

int main()
{
    int m,n;
    int u,v;
    graph g;
    cout<<"Enter number of edges"<<endl;
    cin>>m;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;

    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g.addedge(u,v);
    }

    g.printadj();
    map<int,bool>visited;
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
        dfs(i,visited,res,g.adj);
        }
    }
    
}