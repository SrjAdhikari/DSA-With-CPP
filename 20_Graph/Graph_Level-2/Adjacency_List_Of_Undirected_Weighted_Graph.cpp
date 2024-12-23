#include <iostream>
#include <vector>
#include <utility> // Include utility for pair
using namespace std;

int main() {

    // Declare variables for the number of vertices and edges
    int vertex, edges;

    cout << "Enter the no. of vertex and edges : " << endl;

    // Take input for the number of vertices and edges
    cin >> vertex >> edges;
    cout << endl;

    // Create an adjacency list using a vector of pairs
    vector<pair<int, int> > adjList[vertex];

    int u, v, weight;
    cout << "Enter the edges and weight : " << endl;

    // Take input for each edge and its weight, and update the adjacency list
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> weight;
        adjList[u].push_back({v, weight});          // Add pair (v, weight) to the list of u
        adjList[v].push_back({u, weight});          // Add pair (u, weight) to the list of v (since the graph is undirected)
    }
    cout << endl;

    // Print the adjacency list
    cout << "Adjacency List : " << endl;
    for(int i = 0; i < vertex; i++) {
        cout << i << " -> ";                        // Print the vertex number
        for(int j = 0; j < adjList[i].size(); j++) {
            // Print each adjacent vertex and its weight
            cout << "(" << adjList[i][j].first << ", " << adjList[i][j].second << ")" << " ";
        }
        cout << endl;
    }

    return 0; // Indicate that the program ended successfully
}

//* *********************************************
    //* Time Complexity = O(V + E)
    //* Space Complexity = O(V + E)
    //* V : Vertex, E : Edges
//* *********************************************