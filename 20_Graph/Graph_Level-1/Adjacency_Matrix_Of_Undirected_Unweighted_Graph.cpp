#include<iostream>
#include<vector>
using namespace std;

int main() {

    // Declare variables for number of vertices and edges
    int vertex, edges;

    cout << "Enter the no. of vertex and edges : " << endl;

    // Take input for number of vertices and edges
    cin >> vertex >> edges;
    cout << endl;

    // Create an adjacency matrix initialized with false (0)
    vector<vector<bool> > adjMat(vertex, vector<bool>(vertex, 0));

    int u, v;
    cout << "Enter the edges : " << endl;

    // Take input for each edge and update the adjacency matrix
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        adjMat[u][v] = 1;       // Mark the edge from u to v as true (1)
        adjMat[v][u] = 1;       // Mark the edge from v to u as true (1) since the graph is undirected
    }
    cout << endl;

    // Print the adjacency matrix
    cout << "Adjacency Matrix : " << endl;
    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//* *********************************************
    //* Time Complexity = O(V^2)
    //* Space Complexity = O(V^2)
    //* V : Vertex
//* *********************************************