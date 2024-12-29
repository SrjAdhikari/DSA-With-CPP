# Question : [Topological Sort - GFG](https://www.geeksforgeeks.org/problems/topological-sort/1)

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

**In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.**

### Example 1

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700255/Web/Other/24aa5d54-bc1f-489c-bd2d-ad02ddccdf31_1684492511.png)

```
Output :
1

Explanation :
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700255/Web/Other/c35bb1d1-130c-49aa-a17e-118181d7bdcd_1684492512.png)

```
Output :
1

Explanation :
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
```

### Your task:
You don't need to read input or print anything. Your task is to complete the function **topoSort()**  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

```
Expected Time Complexity : O(V + E)
Expected Auxiliary Space : O(V)
```

### Constraints
`2 ≤ V ≤ 10^4`
`1 ≤ E ≤ (N*(N-1))/2`

## Solution Using DFS Traversal

```Cpp
class Solution {
public:
    // Helper function to perform DFS and push nodes to stack in topological order
    void topoSortDFS(int srcNode, vector<int> adj[], vector<bool>& visited, stack<int>& s) {
        // Mark the current node as visited
        visited[srcNode] = 1;
        
        // Traverse all the adjacent nodes of the current node
        for (auto nbrNode : adj[srcNode]) {
            // If the neighbor node has not been visited
            if (!visited[nbrNode])
                // Recursively perform DFS on the neighbor node
                topoSortDFS(nbrNode, adj, visited, s);
        }
        // After returning from the recursive calls, push the current node onto the stack
        s.push(srcNode);
    }

    // Function to return a list containing vertices in Topological order
    vector<int> topoSort(int V, vector<int> adj[]) {
        // Create a visited array to keep track of visited nodes
        vector<bool> visited(V, 0);

        // Stack to store the topological order of nodes
        stack<int> s;
        
        // Perform DFS for each node to find the topological order
        for (int node = 0; node < V; node++) {
            if (!visited[node])
                topoSortDFS(node, adj, visited, s);
        }
        
        // Vector to store the topological order
        vector<int> ans;
        
        // Pop elements from the stack and store them in the vector until the stack is empty
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        // Return the topological order
        return ans;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```

## Solution Using BFS Traversal (Kahn's Algorithm)

```Cpp
class Solution {
public:
    // Function to return a list containing vertices in Topological order
    vector<int> topoSort(int V, vector<int> adj[]) {
        // Vector to store the topological order
        vector<int> ans;

        // Vector to store the in-degree of each vertex
        vector<int> inDegree(V, 0);

        // Queue to manage vertices with in-degree 0
        queue<int> q;
        
        // Calculate the in-degree of each vertex
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                // Increment the in-degree of the adjacent vertices
                inDegree[adj[i][j]]++;
            }
        }
        
        // Add all vertices to the queue which have in-degree 0
        for (int node = 0; node < V; node++) {
            if (inDegree[node] == 0)
                q.push(node);
        }
        
        // Perform BFS traversal until the queue is empty
        while (!q.empty()) {
            int frontNode = q.front();      // Get the front node from the queue
            q.pop();                        // Remove the front node from the queue
            ans.push_back(frontNode);       // Add the front node to the topological order
            
            // Decrease the in-degree of adjacent vertices of the front node
            for (auto nbrNode : adj[frontNode]) {
                // Decrease the in-degree of the neighbor node
                inDegree[nbrNode]--;

                // After decreasing the in-degree of the neighbor node, 
                // If the in-degree becomes 0 add it to the queue
                if (inDegree[nbrNode] == 0)
                    q.push(nbrNode);
            }
        }
        // Return the topological order of the vertices
        return ans; 
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```