#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void AddEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int Get_V()
    {
        return V;
    }
    void BFS(int v)
    {
        queue<int> q;
        q.push(v);
        vector<int> vis(V, 0);
        while (q.size())
        {
            int cur = q.front();
            q.pop();
            cout << cur << "->";
            vis[cur] = 1;
            for (auto &x : adj[cur])
            {
                if (!vis[x])
                {
                    q.push(x);
                }
            }
        };
    }
    void DFS(int v, vector<int> &vis)
    {
        vis[v] = 1;
        cout << v << "->";
        for (auto &x : adj[v])
            if (!vis[x])
                DFS(x, vis);
    }
    ~Graph()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
                adj[i].pop_back();
        }
        cout << "Graph Destroyed." << endl;
    }
};

int main()
{
    Graph G(7);
    G.AddEdge(0, 1);
    G.AddEdge(0, 2);
    G.AddEdge(1, 3);
    G.AddEdge(3, 4);
    G.AddEdge(2, 5);
    G.AddEdge(4, 6);
    vector<int> vis(G.Get_V(), 0);
    G.DFS(0, vis);
    cout << endl;
    G.BFS(0);
    cout << endl;
    return 0;
}