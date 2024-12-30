# Question : [Bipartite Graph - GFG](https://www.geeksforgeeks.org/problems/bipartite-graph/1)

Given an adjacency list of a graph `adj` of `V` no. of vertices having `0 based index`. Check whether the graph is bipartite or not.

### Example 1

![](https://media.geeksforgeeks.org/wp-content/uploads/20240926114602/Bipartite-Graph.webp)

```
Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700410/Web/Other/blobid0_1735020917.webp)

```
Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
```

### Your task:
You don't need to read or print anything. Your task is to complete the function `isBipartite()` which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.


```
Expected Time Complexity : O(V + E)
Expected Auxiliary Space : O(V)
```

### Constraints
`1 ≤ V, E ≤ 10^5`

## Solution Using BFS Traversal

```Cpp
class Solution {
public:
    // Function to check if a graph is bipartite
    bool isBipartite(int V, vector<int> adj[]) {
        // Vector to store the color of each vertex and initialize it with -1
        vector<int> color(V, -1);

        // Initialize a queue for BFS traversal
        queue<int> q;
        
        // Iterate through all vertices to ensure all components are checked
        for (int node = 0; node < V; node++) {
            // Check if the current node is not colored yet, 
            // Then color it with color 0 and push it to the queue
            if (color[node] == -1) {
                color[node] = 0;    // Color the starting node with color 0
                q.push(node);       // Push the starting node to the queue
                
                // Perform BFS traversal until the queue is empty
                while (!q.empty()) {
                    int frontNode = q.front();      // Get the front node from the queue
                    q.pop();                        // Remove the front node from the queue
                    
                    // Traverse all adjacent nodes of the front node
                    for (auto nbrNode : adj[frontNode]) {
                        // Check if the neighbor node is colored or not, 
                        // If not colored, color it with alternate color
                        if (color[nbrNode] == -1) {
                            // Assign an alternate color to the neighbor node (0 or 1)
                            color[nbrNode] = (color[frontNode] + 1) % 2;
                            q.push(nbrNode);
                        }
                        // If the neighbor node is colored with the same color as the current node, 
                        // Then the graph is not a bipartite graph
                        else {
                            if (color[frontNode] == color[nbrNode])
                                return 0;       // The graph is not a bipartite graph
                        }
                    }
                }
            }
        }
        // If no conflicts in coloring are found, the graph is a bipartite graph
        return 1;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```

## Solution Using DFS Traversal

```Cpp
class Solution {
public:
    // Helper function to check if a graph is bipartite
    bool checkBipartite(int srcNode, vector<int> adj[], vector<int>& color) {
        // Iterate through all adjacent nodes of srcNode
        for (auto nbrNode : adj[srcNode]) {
            // Check if the neighbor node is colored or not, 
            // If not colored, color it with alternate color
            if (color[nbrNode] == -1) {
                // Assign the neighbor node the opposite color (0 or 1)
                color[nbrNode] = (color[srcNode] + 1) % 2;
    
                // Recursively call checkBipartite for the neighbor node
                if (checkBipartite(nbrNode, adj, color) == 0)
                    // If not bipartite, return false
                    return 0;
            }
            // If the neighbor node is already colored and has the same color as srcNode
            // Then the graph is not bipartite
            else {
                if (color[srcNode] == color[nbrNode])
                    return 0;
            }
        }
        // If no conflicts in coloring are found, the graph is a bipartite graph
        return 1;
    }

    // Function to check if a graph is bipartite
    bool isBipartite(int V, vector<int> adj[]) {
        // Vector to store the color of each vertex, initialized to -1
        vector<int> color(V, -1);

        // Iterate through all the nodes in the graph
        // Handle Disconnected Components Of Graph
        for (int node = 0; node < V; node++) {
            // If the node is not colored
            if (color[node] == -1) {
                // Color the first node with color 0
                color[node] = 0;

                // Check if the subgraph is bipartite or not starting from this node
                if (checkBipartite(node, adj, color) == 0)
                    // If not bipartite, return false
                    return 0;
            }
        }
        // If bipartite, return true
        return 1;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```