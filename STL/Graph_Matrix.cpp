#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> Matrix;

public:
    Graph(int V)
    {
        this->V = V;
        Matrix = vector<vector<int>>{V, vector<int>(V, 0)};
    }
    void AddEdge(int u, int v)
    {
        Matrix[u][v] = 1;
        Matrix[v][u] = 1;
    }
    void PrintGraph()
    {
        for (int i = 0; i < V; i++)
        {
            for (auto &x : Matrix[i])
                cout << x << ' ';
            cout << endl;
        }
    }
    ~Graph()
    {
        Matrix = vector<vector<int>>{V, vector<int>(V, 0)};
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
