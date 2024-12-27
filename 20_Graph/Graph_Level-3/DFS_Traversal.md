# Question : [DFS Of Graph - GFG](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

You are given a `connected undirected graph`. Perform a `Depth First Traversal` of the graph.

**Note**: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/graph-1659528381.png)

```
Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]

Output: 0 2 4 3 1

Explanation: 
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4, and then 3 and 1.
Thus dfs will be 0 2 4 3 1
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/graph(1)-1659528893.png)

```
Input: V = 4, adj = [[1,3], [2,0], [1], [0]]

Output: 0 1 2 3

Explanation:
0 is connected to 1 , 3.
1 is connected to 0, 2. 
2 is connected to 1.
3 is connected to 0. 
so starting from 0, it will go to 1 then 2
then back to 0 then 0 to 3 thus dfs will be 0 1 2 3. 
```

### Your task
You don't need to read input or print anything. Your task is to complete the function `dfsOfGraph()` which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a list containing the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

```
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
```

### Constraints

`1 ≤ V, E ≤ 10^4`

## Solution 1

```Cpp
Using Recursive Method :

class Solution {
public:

    // Depth-First Search (DFS) function
    void dfs(int node, vector<int> adj[], vector<int>& ans, vector<bool>& visited) {

        // Mark the current node as visited
        visited[node] = 1;

        // Add the current node to the answer
        ans.push_back(node);
    
        // Traverse all adjacent nodes of the current node
        for (int i = 0; i < adj[node].size(); i++) {
            // Get the neighbor node
            int nbrNode = adj[node][i];
            
            // If the neighbor node has not been visited
            if (!visited[nbrNode]) {
                // Recursively perform DFS on the neighbor node
                dfs(nbrNode, adj, ans, visited);
            }
        }
    }

    // Function to perform DFS traversal of the graph
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Create a visited array to keep track of visited nodes
        vector<bool> visited(V, 0);

        // Vector to store the DFS traversal order
        vector<int> ans;

        // Start the DFS from node 0
        dfs(0, adj, ans, visited);

        // Return the DFS traversal order
        return ans;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```

## Solution 2

```Cpp
Using Stack :

class Solution {
public:

    // Function to perform DFS traversal of the graph using a stack
    vector<int> dfsUsingStack(int V, vector<int> adj[]) {

        // Create a visited array to keep track of visited nodes
        vector<bool> visited(V, 0);

        // Vector to store the DFS traversal order
        vector<int> ans;

        // Stack to hold the nodes for DFS
        stack<int> s;

        // Start the DFS from node 0
        s.push(0);

        while (!s.empty()) {
            // Get the current node from the top of the stack and pop it
            int node = s.top();
            s.pop();

            // If the node hasn't been visited yet
            if (!visited[node]) {
                // Mark the node as visited
                visited[node] = 1;

                // Add the node to the answer
                ans.push_back(node);

                // Push all adjacent nodes of the current node to the stack
                // We iterate from the end to maintain the order of traversal
                for (int i = adj[node].size() - 1; i >= 0; i--) {
                    // Get the neighbor node
                    int nbrNode = adj[node][i];

                    // If the neighbor node has not been visited yet, push it to the stack
                    if (!visited[nbrNode]) {
                        s.push(nbrNode);
                    }
                }
            }
        }

        // Return the DFS traversal order
        return ans;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```