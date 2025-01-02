# Question : [Course Schedule - GFG](https://www.geeksforgeeks.org/problems/course-schedule/1)

There are a total of `n` tasks you have to pick, labelled from 0 to n-1. Some tasks may have `prerequisite` tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of `n` tasks and a list of prerequisite pairs of size `m`. Find a ordering of tasks you should pick to finish all tasks.

**Note**: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. Driver code will print `"No Ordering Possible"`, on returning an empty array. Returning any correct order will give the output as `1`, whereas any invalid order will give the output `0`. 

### Example 1

```
Input:
n = 2, m = 1
prerequisites = {{1, 0}}
Output:
1
Explanation:
The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, 
then output would be 1 for all test cases. One possible order is [0, 1].
```

### Example 2

```
Input:
n = 4, m = 4
prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}}
Output:
1
Explanation:
There are a total of 4 tasks to pick. To pick task 3 you should have finished both tasks 1 and 2. 
Both tasks 1 and 2 should be pick after you finished task 0. So one correct task order is [0, 1, 2, 3]. 
Another correct ordering is [0, 2, 1, 3]. Returning any of these order will result in an output of 1.
```

### Your task
The task is to complete the function findOrder() which takes two integers n, and m and a list of lists of size m*2 denoting the prerequisite pairs as input and returns any correct order to finish all the tasks. Return an empty array if it's impossible to finish all tasks.

```
Expected Time Complexity: O(N + P)
Expected Auxiliary Space: O(N + P)
```

### Constraints
`1 ≤ n ≤ 10^5`
`0 ≤ m ≤ min(n*(n-1),10^5)`
`0 ≤ prerequisites[i][0], prerequisites[i][1] < n`
`All prerequisite pairs are unique`
`prerequisites[i][0] ≠ prerequisites[i][1]`

## Solution Using BFS Traversal (Kahn's Algorithm)

```Cpp
class Solution {
public:
    // Function to find a valid topological order of tasks given their prerequisites using BFS.
    vector<int> findOrder(int N, int P, vector<vector<int>>& prerequisites) {
        // Initialize adjacency list of size N
        vector<vector<int>> adj(N);   
        
        // Initialize in-degree vector to track incoming edges for each task
        vector<int> inDegree(N, 0);

        // Populate the adjacency list and in-degree vector based on prerequisites
        for (int i = 0; i < P; i++) {
            int u = prerequisites[i][1];        // Prerequisite task
            int v = prerequisites[i][0];        // Dependent task

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
        
        // Vector to store the topological order
        vector<int> ans;
        
        // Perform BFS traversal, until the queue is empty
        while (!q.empty()) {
            int frontNode = q.front();              // Get the task from the front of the queue
            q.pop();                                // Remove the task from the queue
            ans.push_back(frontNode);               // Add the task to the topological order
            
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
        // If all tasks have been processed, return the topological order. 
        // Otherwise, return an empty vector indicating failure.
        return ans.size() == N ? ans : vector<int>{};
    }
};

Time Complexity = O(N + P)
Space Complexity = O(N + P)
```