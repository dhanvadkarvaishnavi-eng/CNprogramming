#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define V 6

void dijkstra(int graph[V][V], int src, int dest)
{
    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int minDist = INT_MAX;
        int u = -1;

        // Find the unvisited vertex with minimum distance
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Display shortest path and distance
    cout << "\nSource: " << char('A' + src) << endl;
    cout << "Destination: " << char('A' + dest) << endl;

    if (dist[dest] == INT_MAX)
    {
        cout << "No path exists!\n";
        return;
    }

    int path[V];
    int count = 0;

    for (int v = dest; v != -1; v = parent[v])
        path[count++] = v;

    reverse(path, path + count);

    cout << "Shortest path: ";

    for (int i = 0; i < count; i++)
    {
        cout << char('A' + path[i]);

        if (i < count - 1)
            cout << " to ";
    }

    cout << "\nShortest distance: " << dist[dest] << endl;
}

int main()
{
    int graph[V][V] = {0};
    char u, v;
    int cost, edges;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges and costs (example: A B 4):\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> cost;

        u = toupper(u);
        v = toupper(v);

        if (u < 'A' || u > 'F' ||
            v < 'A' || v > 'F' ||
            cost <= 0 || u == v)
        {
            cout << "Invalid input!\n";
            return 1;
        }

        int a = u - 'A';
        int b = v - 'A';

        // Undirected graph
        graph[a][b] = cost;
        graph[b][a] = cost;
    }

    char source, destination;

    cout << "Enter source vertex (A-F): ";
    cin >> source;

    cout << "Enter destination vertex (A-F): ";
    cin >> destination;

    source = toupper(source);
    destination = toupper(destination);

    if (source < 'A' || source > 'F' ||
        destination < 'A' || destination > 'F')
    {
        cout << "Invalid source or destination!\n";
        return 1;
    }

    dijkstra(graph, source - 'A', destination - 'A');

    return 0;
}





/*Enter number of edges: 7
1)Enter edges and costs (example: A B 4):
A B 2
A C 4
B C 7
B D 3
B E 5
C D 1                                   
D E 9
Enter source vertex (A-F): A
Enter destination vertex (A-F): F

Source: A
Destination: F
No path exists!


2)Enter number of edges: 7
Enter edges and costs (example: A B 4):
A B 2
A C 4
B C 7
B D 3
B E 5
C D 1
D E 9
Enter source vertex (A-F): A
Enter destination vertex (A-F): D

Source: A
Destination: D
Shortest path: A to B to D
Shortest distance: 5*/