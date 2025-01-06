# Question : [Shortest Path In An Unweighted Graph - CodingNinja](https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297)

***Problem statement***
The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively and are connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’. It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.

A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where starting house is ‘S’ and the ending house is ‘T’ and there is a road connecting two consecutive houses. Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.

***For example***
In the below map of Ninjaland let say you want to go from S=1 to T=8, the shortest path is (1, 3, 8). You can also go from S=1 to T=8  via (1, 2, 5, 8)  or (1, 4, 6, 7, 8) but these paths are not shortest.

![](https://files.codingninjas.in/pic1-6747.png)

### Your task
You don't need to print or input anything.

### Constraints
`1 <= T <= 100`
`2 <= N <= 10^3`
`1 <= M <= min( N *(N - 1) / 2 , 1000 )`
`1 <= S, T <= N`

## Solution Using BFS Traversal

```Cpp
class Solution {
public:
    vector<int> shortestPath(vector<pair<int, int>> edges, int N, int M, int src, int dest) {
        // Create an adjacency list to represent the graph
        vector<int> adj[N];

        // Iterate over all edges to populate the adjacency list, 
        // And converting the vertices to 0-based indexing
        for(int i = 0; i < M; i++) {
            int u = edges[i].first;         // Starting vertex of the edge
            int v = edges[i].second;        // Ending vertex of the edge
            adj[u - 1].push_back(v - 1);    // Add v to the list of adjacent vertices of u
            adj[v - 1].push_back(u - 1);    // Since the graph is undirected, add u to the list of adjacent vertices of v
        }
        
        // Convert source and destination to 0-based indexing
        src--;
        dest--;

        // Initialize the visited vector to keep track of visited nodes, initially all nodes are unvisited
        vector<bool> visited(N, false);
        
        // Initialize the parent vector to reconstruct the path, initially all nodes have no parent
        vector<int> parent(N, -1);

        // Create a queue for BFS (Breadth-First Search)
        queue<int> q;

        // Start BFS from the source node
        q.push(src);                        // Add the source node to the queue
        visited[src] = true;                // Mark the source node as visited

        // Perform BFS
        while(!q.empty()) {
            int frontNode = q.front();      // Get the front node from the queue
            q.pop();                        // Dequeue the front node

            // Iterate over all the neighbors of the current node
            for(auto nbrNode : adj[frontNode]) {
                // If the neighbor has already been visited, skip it
                if(visited[nbrNode])
                    continue;

                // If the neighbor hasn't been visited:
                else {
                    visited[nbrNode] = true;         // Mark it as visited
                    q.push(nbrNode);                 // Add the neighbor node to the queue
                    parent[nbrNode] = frontNode;     // Store the parent of the neighbor node
                }
            }
        }

        // Vector to store the final path
        vector<int> path;

        // Start from the destination node, and move back to the source node
        while(dest != -1) {
            path.push_back(dest + 1);       // Convert back to 1-based indexing
            dest = parent[dest];            // Move to the parent node
        }

        // Reverse the path to get it from source to destination
        reverse(path.begin(), path.end());

        // Return the shortest path from source to destination
        return path;
    }
};

Time Complexity = O(V + E)
Space Complexity = O(V + E)
```