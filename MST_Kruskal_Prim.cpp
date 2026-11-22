
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Graph
{
    int vertices;
    int adj[100][100];

public:

    // Constructor
    Graph(int v)
    {
        vertices = v;

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    // Add weighted connection
    void addEdge(int u, int v, int w)
    {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    // Display adjacency matrix
    void display()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adj[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Find parent for Kruskal's algorithm
    int findParent(int parent[], int i)
    {
        if (parent[i] == i)
            return i;

        return findParent(parent, parent[i]);
    }

    // Kruskal's Algorithm
    void kruskal()
    {
        vector<pair<int, pair<int, int>>> edges;

        // Store all edges
        for (int i = 0; i < vertices; i++)
        {
            for (int j = i + 1; j < vertices; j++)
            {
                if (adj[i][j] != 0)
                {
                    edges.push_back({adj[i][j], {i, j}});
                }
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end());

        int parent[100];

        for (int i = 0; i < vertices; i++)
        {
            parent[i] = i;
        }

        int cost = 0;
        int count = 0;

        cout << "\nKruskal's MST:\n";

        for (auto edge : edges)
        {
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            int pu = findParent(parent, u);
            int pv = findParent(parent, v);

            // Check cycle
            if (pu != pv)
            {
                cout << u << " - " << v
                     << " : " << w << endl;

                parent[pu] = pv;

                cost = cost + w;
                count++;

                if (count == vertices - 1)
                    break;
            }
        }

        if (count != vertices - 1)
        {
            cout << "MST is not possible. Graph is disconnected.\n";
            return;
        }

        cout << "Total Minimum Cost = " << cost << endl;
    }

    // Prim's Algorithm
    void prim()
    {
        int key[100];
        int parent[100];
        bool visited[100] = {false};

        for (int i = 0; i < vertices; i++)
        {
            key[i] = INT_MAX;
            parent[i] = -1;
        }

        key[0] = 0;

        int cost = 0;
        int count = 0;

        cout << "\nPrim's MST:\n";

        for (int i = 0; i < vertices; i++)
        {
            int min = INT_MAX;
            int u = -1;

            // Find minimum key vertex
            for (int j = 0; j < vertices; j++)
            {
                if (!visited[j] && key[j] < min)
                {
                    min = key[j];
                    u = j;
                }
            }

            if (u == -1)
                break;

            visited[u] = true;

            if (parent[u] != -1)
            {
                cout << parent[u] << " - " << u
                     << " : " << key[u] << endl;

                cost = cost + key[u];
                count++;
            }

            // Update adjacent vertices
            for (int v = 0; v < vertices; v++)
            {
                if (adj[u][v] != 0 &&
                    !visited[v] &&
                    adj[u][v] < key[v])
                {
                    key[v] = adj[u][v];
                    parent[v] = u;
                }
            }
        }

        if (count != vertices - 1)
        {
            cout << "MST is not possible. Graph is disconnected.\n";
            return;
        }

        cout << "Total Minimum Cost = " << cost << endl;
    }
};

int main()
{
    int vertices, edges;

    cout << "POWER DISTRIBUTION NETWORK\n";

    cout << "Enter number of substations: ";
    cin >> vertices;

    if (vertices <= 0 || vertices > 100)
    {
        cout << "Invalid number of substations!";
        return 0;
    }

    Graph g(vertices);

    cout << "Enter number of connections: ";
    cin >> edges;

    if (edges < 0 || edges > vertices * (vertices - 1) / 2)
    {
        cout << "Invalid number of connections!";
        return 0;
    }

    cout << "Enter connections (u v cost):\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 0 || v < 0 ||
            u >= vertices || v >= vertices ||
            u == v || w <= 0)
        {
            cout << "Invalid connection!";
            return 0;
        }

        g.addEdge(u, v, w);
    }

    g.display();

    g.kruskal();

    g.prim();

    return 0;
}

