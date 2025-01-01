# Question : [Prerequisite Tasks - GFG](https://www.geeksforgeeks.org/problems/prerequisite-tasks/1)

There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks `N` and a list of `prerequisite pairs P`, find if it is possible to finish all tasks.

### Example 1

```
Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible. 
```

### Example 2

```
Input:
N = 2, P = 2
prerequisites = {{1,0},{0,1}}
Output:
No
Explanation:
To do task 1 you should have completed
task 0, and to do task 0 you should
have finished task 1. So it is impossible.
```

### Your task
You don’t need to read input or print anything. Your task is to complete the function **isPossible()** which takes the integer N denoting the number of tasks, P denoting the number of prerequisite pairs and prerequisite as input parameters and returns true if it is possible to finish all tasks otherwise returns false. 

```
Expected Time Complexity: O(N + P)
Expected Auxiliary Space: O(N + P)
```

### Constraints
`1 ≤ N ≤ 10^4`
`1 ≤ P ≤ 10^5`

## Solution Using BFS Traversal (Kahn's Algorithm)

```Cpp
class Solution {
public:
    // Function to check if it is possible to finish all tasks or not
    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        // Initialize adjacency list and in-degree vector
        vector<int> adj[N];
        vector<int> inDegree(N, 0);
        
        // Populate the adjacency list and in-degree vector based on prerequisites
        for (int i = 0; i < P; i++) {
            int u = prerequisites[i].second;        // Prerequisite task
            int v = prerequisites[i].first;         // Dependent task

            // Add edge from prerequisite to dependent task (add edge u -> v)
            adj[u].push_back(v);

            // Increment in-degree of the dependent task (task v)       
            inDegree[v]++;
        }
        
        // Initialize a queue to process tasks with no prerequisites (tasks with in-degree 0)
        queue<int> q;

        // Add tasks with no prerequisites (tasks with in-degree 0) to the queue
        for (int task = 0; task < N; task++) {
            // If a task has no prerequisites (in-degree 0), add it to the queue
            if (inDegree[task] == 0) {
                q.push(task);
            }
        }
        
        // Variable to track the number of tasks processed
        int count = 0;
        
        // Perform BFS traversal, until the queue is empty
        while (!q.empty()) {
            int frontNode = q.front();  // Get the task from the front of the queue
            q.pop();                    // Remove the task from the queue
            count++;                    // Increment the processed task count
            
            // Process all the dependent tasks (tasks with in-degree greater than 0)
            for (auto nbrNode : adj[frontNode]) {
                // Decrement the in-degree of the dependent task
                inDegree[nbrNode]--;

                // If the dependent task has no more prerequisites (in-degree 0), add it to the queue
                if (inDegree[nbrNode] == 0) {
                    q.push(nbrNode);
                }
            }
        }
        // Return true if all tasks have been processed (count == N), otherwise return false
        return count == N;
    }
};

Time Complexity = O(N + P)
Space Complexity = O(N + P)
```