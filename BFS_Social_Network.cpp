
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int vertices;
    vector<int> adj[100];

public:

    // Constructor
    Graph(int v)
    {
        vertices = v;
    }

    // Add friendship
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Display adjacency list
    void display()
    {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < vertices; i++)
        {
            cout << "User " << i << " -> ";

            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }

    // Breadth First Search
    void BFS(int start)
    {
        bool visited[100] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        int level = 0;

        cout << "\nBFS Traversal:\n";

        while (!q.empty())
        {
            int size = q.size();

            cout << "Level " << level << ": ";

            for (int i = 0; i < size; i++)
            {
                int current = q.front();
                q.pop();

                cout << "User " << current << " ";

                for (int j = 0; j < adj[current].size(); j++)
                {
                    int next = adj[current][j];

                    if (!visited[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            cout << endl;
            level++;
        }
    }
};

int main()
{
    int v, e, u, w, start;

    cout << "Enter number of users: ";
    cin >> v;

    if (v <= 0 || v > 100)
    {
        cout << "Invalid number of users!";
        return 0;
    }

    Graph g(v);

    cout << "Enter number of friendships: ";
    cin >> e;

    if (e < 0 || e > v * (v - 1) / 2)
    {
        cout << "Invalid number of friendships!";
        return 0;
    }

    cout << "Enter friendships:\n";

    for (int i = 0; i < e; i++)
    {
        cin >> u >> w;

        if (u < 0 || w < 0 || u >= v || w >= v || u == w)
        {
            cout << "Invalid friendship!";
            return 0;
        }

        g.addEdge(u, w);
    }

    g.display();

    cout << "\nEnter starting user for BFS: ";
    cin >> start;

    if (start < 0 || start >= v)
    {
        cout << "Invalid starting user!";
        return 0;
    }

    g.BFS(start);

    return 0;
}


