
#include <iostream>
using namespace std;

class Graph
{
    int vertices;
    int adj[20][20];
    bool visited[20];

public:
    void createGraph()
    {
        int edges, u, v;

        cout << "Enter number of vertices: ";
        cin >> vertices;

        // Initialize adjacency matrix and visited array
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;

            for (int j = 0; j < vertices; j++)
            {
                adj[i][j] = 0;
            }
        }

        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (source destination):\n";

        for (int i = 0; i < edges; i++)
        {
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }

    void displayGraph()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int v)
    {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (adj[v][i] == 1 && !visited[i])
            {
                DFS(i);
            }
        }
    }
};

int main()
{
    Graph graph;
    int start;

    graph.createGraph();
    graph.displayGraph();

    cout << "\nEnter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    graph.DFS(start);

    cout << endl;

    return 0;
}
