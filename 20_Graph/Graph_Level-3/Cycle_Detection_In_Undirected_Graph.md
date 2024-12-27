# Question : [Detect Cycle In An Undirected Graph - GFG](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700219/Web/Other/891791f9-1abb-45b1-80f2-7af46d73dcd2_1685086491.png)

```
Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 

Output: 1

Explanation: 
1->2->3->4->1 is a cycle.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700219/Web/Other/d8cbd97e-406e-4f50-a38c-6a58747df876_1685086491.png)

```
Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}

Output: 0

Explanation: 
No cycle in the graph.
```

### Your task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

**NOTE**: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

```
Expected Time Complexity : O(V + E)
Expected Auxiliary Space : O(V)
```

### Constraints
`1 ≤ V, E ≤ 10^5`

## Solution Using DFS Traversal

```Cpp
class Solution {
public:
    // Helper function to detect a cycle in the graph using DFS
    bool cycleDetect(int srcNode, int parent, vector<int> adj[], vector<bool>& visited) {
        // Mark the source node as visited
        visited[srcNode] = 1;
        
        // Iterate through all the adjacent nodes of the source node
        for(auto nbrNode : adj[srcNode]) {
            // Check if the neighbor node is the parent node, 
            // If so, skip it to avoid false cycle detection
            if(parent == nbrNode)
                continue;
            
            // Check if the neighbor node is already visited
            // If the neighbor node is already visited, a cycle is detected
            if(visited[nbrNode])
                return 1;
                
            // Recursively call cycleDetect for the neighbor node
            if(cycleDetect(nbrNode, srcNode, adj, visited))
                // If a cycle is detected in the recursive call, return true
                return 1;
        }
        // If no cycle is detected, return false
        return 0;
    }

    // Function to check if there is a cycle in the graph
    bool isCycle(int V, vector<int> adj[]) {
        // Create a visited array to keep track of visited nodes
        vector<bool> visited(V, 0);

        // Initialize the parent node of the source node as -1.
        int parent = -1;
        
        // Iterate through all the nodes in the graph
        // Handle Disconnected Components Of Graph
        for(int node = 0; node < V; node++) {
            // If the node is not visited and a cycle is detected from that node
            if(!visited[node] && cycleDetect(node, parent, adj, visited)) {
                // Return true if a cycle is detected
                return 1;
            }
        }
        // Return false if no cycle is detected
        return 0;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```

## Solution Using BFS Traversal

```Cpp
class Solution {
public:
    // Helper function to detect a cycle in the graph using BFS
    bool cycleDetect(int srcNode, vector<int> adj[], vector<int>& visited) {
        // Initialize a queue to perform BFS, storing node and its parent
        queue<pair<int, int>> q;

        // Initialize the parent node of the source node as -1.
        int parent = -1;
        
        // Mark the source node as visited
        visited[srcNode] = 1;

        // Push the source node and its parent into the queue
        q.push({srcNode, parent});
        
        // Perform BFS traversal until the queue is empty
        while (!q.empty()) {
            // Get the front node from the queue
            int frontNode = q.front().first;

            // Get the parent of the front node
            int parentNode = q.front().second;
            q.pop();
            
            // Traverse all the adjacent nodes of the front node
            for (auto nbrNode : adj[frontNode]) {
                // Check if the neighbor node is the parent node, 
                // If so, skip it to avoid false cycle detection
                if (parentNode == nbrNode)
                    continue;
                
                // Check if the neighbor node is already visited
                // If the neighbor node is already visited, a cycle is detected
                if (visited[nbrNode])
                    return 1;
                
                // Mark the neighbor node as visited
                visited[nbrNode] = 1;

                // Push the neighbor node and its parent node into the queue
                q.push({nbrNode, frontNode});
            }
        }
        // If no cycle is detected, return false
        return 0;
    }

    // Function to check if there is a cycle in the graph
    bool isCycle(int V, vector<int> adj[]) {
        // Create a visited array to keep track of visited nodes
        vector<int> visited(V, 0);
        
        // Iterate through all the nodes in the graph
        // Handle Disconnected Components Of Graph
        for (int node = 0; node < V; node++) {
            // If the node is not visited and a cycle is detected from that node
            if (!visited[node] && cycleDetect(node, adj, visited))
                // Return true if a cycle is detected
                return 1;
        }
        // Return false if no cycle is detected
        return 0;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```