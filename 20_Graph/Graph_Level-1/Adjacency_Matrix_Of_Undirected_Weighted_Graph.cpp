#include<iostream>
#include<vector>
using namespace std;

int main() {

    // Declare variables for the number of vertices and edges
    int vertex, edges;

    cout << "Enter the no. of vertex and edges : " << endl;

    // Take input for the number of vertices and edges
    cin >> vertex >> edges;
    cout << endl;

    // Create an adjacency matrix initialized with zeros
    vector<vector<int> > adjMat(vertex, vector<int>(vertex, 0));

    int u, v, weight;
    cout << "Enter the edges and weight : " << endl;

    // Take input for each edge and its weight, and update the adjacency matrix
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> weight;
        adjMat[u][v] = weight;      // Set the weight for the edge from u to v
        adjMat[v][u] = weight;      // Set the weight for the edge from v to u (since the graph is undirected)
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