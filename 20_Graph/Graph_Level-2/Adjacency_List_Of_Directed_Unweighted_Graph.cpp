#include<iostream>
#include<vector>
using namespace std;

int main() {

    // Declare variables for the number of vertices and edges
    int vertex, edges;

    cout << "Enter the no. of vertex, edges : " << endl;

    // Take input for the number of vertices and edges
    cin >> vertex >> edges;
    cout << endl;

    // Create an adjacency list using a vector of vectors
    vector<int> adjList[vertex];

    int u, v;
    cout << "Enter the edges : " << endl;

    // Take input for each edge and update the adjacency list
    for(int i = 0; i < edges; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);                // Add v to the list of u
    }
    cout << endl;

    // Print the adjacency list
    cout << "Adjacency List : " << endl;
    for(int i = 0; i < vertex; i++) {
        cout << i << " -> ";                    // Print the vertex number
        for(int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";       // Print all adjacent vertices of i
        }
        cout << endl;
    }

    return 0;
}

//* *********************************************
    //* Time Complexity = O(V + E)
    //* Space Complexity = O(V + E)
    //* V : Vertex, E : Edges
//* *********************************************