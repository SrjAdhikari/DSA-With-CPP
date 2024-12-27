# Question : [BFS Of Graph - GFG](https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1)

Given a `directed graph`. The task is to do `Breadth First Traversal` of this graph starting from 0.

**Note**: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700217/Web/Other/e0eb5630-5d6c-493a-9b1e-d16d40f10b01_1685086421.png)

```
Input:
V = 5, E = 4
adj = {{1,2,3},{},{4},{},{}}

Output: 
0 1 2 3 4

Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2 then 3. 
After this 2 to 4, thus bfs will be
0 1 2 3 4.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700217/Web/Other/001e9e35-da68-4024-b1d3-e34944188a1e_1685086422.png)

```
Input:
V = 3, E = 2
adj = {{1,2},{},{}}

Output: 
0 1 2

Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,
thus bfs will be 0 1 2. 
```

### Your task
You dont need to read input or print anything. Your task is to complete the function bfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  a list containing the BFS traversal of the graph starting from the 0th vertex from left to right.

```
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
```

### Constraints

`1 ≤ V, E ≤ 10^4`


## Solution 

```Cpp

class Solution {
public:

    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Initialize a queue for BFS traversal
        queue<int> q;

        // Create a visited array to keep track of visited nodes
        vector<bool> visited(V, 0);

        // Start the BFS from node 0
        q.push(0);

        // Mark node 0 as visited
        visited[0] = 1;

        // Vector to store the BFS traversal order
        vector<int> ans;
        
        // Perform BFS traversal until the queue is empty
        while(!q.empty()){
            
            // Get the front node from the queue
            int frontNode = q.front();
            q.pop();                        // Remove the front node from the queue
            ans.push_back(frontNode);       // Add the front node to the answer

            // Traverse all the adjacent nodes of the front node
            for(int i = 0; i < adj[frontNode].size(); i++) {
                // Get the neighbor node
                int nbrNode = adj[frontNode][i];

                // If the neighbor node has not been visited
                if(!visited[nbrNode]) {
                    visited[nbrNode] = 1;      // Mark the neighbor node as visited
                    q.push(nbrNode);           // Push the neighbor node to the queue
                }
            }
        }
        
        // Return the BFS traversal order
        return ans;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V)
```