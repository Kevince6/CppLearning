#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adj; // 邻接表储存方式
public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V); // 给vector分配空间
    }
    void AddEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void PrintGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            for (auto &x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }
    ~Graph()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
                adj[i].pop_back();
        }
    }
};

int main()
{
    Graph g(6);
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(1, 5);
    g.AddEdge(3, 5);
    g.AddEdge(4, 5);
    g.PrintGraph();
    return 0;
}
