# Question : [Shortest Path In Weighted Undirected graph - GFG](https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1)

You are given a weighted undirected graph having ***n*** vertices numbered from 1 to n and ***m*** edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

**Note** : 
1. If there exists a path, then return a list whose first element is the weight of the path.
2. If no path exists then return a list containing a single element -1.

### Example 1

```
Example:
Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output:
5 1 4 3 5
Explaination:
Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
```

### Your task :
You don't need to read input or print anything. Your task is to complete the function ***shortestPath()*** which takes n vertex and m edges and vector of edges having weight as inputs and returns the shortest path between vertex 1 to n.

```
Expected Time Complexity : O(m * log(n))
Expected Space Complexity : O(n + m)
```

### Constraints
`2 <= n <= 10^5`
`0 <= m <= 10^5`
`0 <= a, b <= n`
`1 <= w <= 10^5`

## Solution Using Dijkstra's Algorithm

```Cpp
class Solution {
public:
    // Function to find the shortest path between two nodes in a weighted undirected graph.
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Create an adjacency list to store the graph
        // Vector stores the pairs of (node, weight)
        vector<pair<int,int>> adj[n + 1];
        
        // Create the adjacency list with the edges and their weights
        for(int i = 0; i < m; i++){
            int u = edges[i][0];                // Starting vertex of the edge
            int v = edges[i][1];                // Ending vertex of the edge
            int weight = edges[i][2];           // Weight of the edge between u and v
            
            // Since the graph is undirected, add edges in both directions
            adj[u].push_back({v, weight});      // Edge from u to v with weight
            adj[v].push_back({u, weight});      // Edge from v to u with weight
        }
        
        // Initialize visited array to keep track of visited nodes
        vector<bool> visited(n + 1, 0);
        
        // Initialize distance array to store the shortest distance from the source
        vector<int> dist(n + 1, INT_MAX);
        
        // Initialize the parent vector to reconstruct the path, initially all nodes have no parent
        vector<int> parent(n + 1, -1);
        
        // Priority queue to select the node with the smallest distance
        // The priority queue stores pairs of (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Initially, push the source node (node 1) with a distance of 0 into the priority queue
        pq.push({0, 1});

        // Set the distance of the source node to itself as 0
        dist[1] = 0;
        
        // Loop to find the shortest path for all nodes in the graph
        while(!pq.empty()){
            int node = pq.top().second;         // Get the node with the smallest distance
            pq.pop();                           // Remove the node from the priority queue
            
            // If the node has already been visited, skip it
            if(visited[node] == 1)
                continue;
            
            // Mark the current node as visited
            visited[node] = 1;
            
            // Iterate through all neighbors of the current node and update their distances
            for (auto nbrPair : adj[node]) {
                int nbrNode = nbrPair.first;        // Neighbor node
                int edgeWeight = nbrPair.second;    // Weight of the edge to the neighbor node
                
                // If the neighbor node is not visited and a shorter path is found
                if (!visited[nbrNode] && dist[node] + edgeWeight < dist[nbrNode]) {
                    // Update the distance to the neighbor node
                    dist[nbrNode] = dist[node] + edgeWeight;

                    // Push the updated distance and neighbor node to the priority queue
                    pq.push({dist[nbrNode], nbrNode});

                    // Update the parent of the neighbor node
                    parent[nbrNode] = node;
                }
            }
        }
        
        // Vector to store the final path
        vector<int> path;
        
        // If there is no path to the destination node, return -1
        if(parent[n] == -1){
            path.push_back(-1);
            return path;
        }

        // Destination node is the final node (node n)
        int dest = n;

        // Start from the destination node and move back to the source node
        while(dest != -1){
            path.push_back(dest);
            dest = parent[dest];
        }

        // Add the shortest distance from the source node to the destination node at the end of the path
        path.push_back(dist[n]);
        
        // Reverse the path to get the correct order from source to destination
        reverse(path.begin(), path.end());
        
        // Return the shortest path from source to destination
        return path;
    }
};

Time Complexity = O(mlogn + n) => O(ElogV + V)
Space Complexity = O(n + m) => O(V + E)
```