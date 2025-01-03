# Question : [Parallel Courses III - (LeetCode : 2050)](https://leetcode.com/problems/parallel-courses-iii/description/)

You are given an integer `n`, which indicates that there are `n` courses labeled from `1` to `n`. You are also given a 2D integer array `relations` where `relations[j] = [prevCoursej, nextCoursej]` denotes that course `prevCoursej` has to be completed **before** course `nextCoursej` (prerequisite relationship). Furthermore, you are given a **0-indexed** integer array `time` where `time[i]` denotes how many **months** it takes to complete the `(i+1)th` course.

You must find the **minimum** number of months needed to complete all the courses following these rules:

* You may start taking a course at **any time** if the prerequisites are met.
* **Any number of courses** can be taken at the **same time.**

Return the ***minimum*** *number of months needed to complete all the courses.*

**Note:** The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).

### Example 1
![](https://assets.leetcode.com/uploads/2021/10/07/ex1.png)

```
Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
Output: 8
Explanation: The figure above represents the given graph and the time required to complete each course. 
We start course 1 and course 2 simultaneously at month 0.
Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
Thus, the earliest time we can start course 3 is at month 3, and the total time required is 3 + 5 = 8 months.
```

### Example 2
![](https://assets.leetcode.com/uploads/2021/10/07/ex2.png)

```
Input: n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
Output: 12
Explanation: The figure above represents the given graph and the time required to complete each course.
You can start courses 1, 2, and 3 at month 0.
You can complete them after 1, 2, and 3 months respectively.
Course 4 can be taken only after course 3 is completed, i.e., after 3 months. It is completed after 3 + 4 = 7 months.
Course 5 can be taken only after courses 1, 2, 3, and 4 have been completed, i.e., after max(1,2,3,7) = 7 months.
Thus, the minimum time needed to complete all the courses is 7 + 5 = 12 months.
```

### Constraints
* `1 <= n <= 5 * 10^4`
* `0 <= relations.length <= min(n * (n - 1) / 2, 5 * 10^4)`
* `relations[j].length == 2`
* `1 <= prevCoursej, nextCoursej <= n`
* `prevCoursej != nextCoursej`
* All the pairs `[prevCoursej, nextCoursej]` **are unique.**
* `time.length == n`
* `1 <= time[i] <= 10^4`
* The given graph is a directed acyclic graph.


## Solution Using BFS Traversal

```Cpp
class Solution {
public:
    // Function to find the minimum time required to complete all courses
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // Initialize adjacency list and in-degree vector
        vector<int> adj[n];
        vector<int> inDegree(n, 0);

        // Populate the adjacency list and in-degree vector based on prerequisites
        for (int i = 0; i < relations.size(); i++) {
            int u = relations[i][0];        // Prerequisite course ( Given as 1-based index)
            int v = relations[i][1];        // Dependent course ( Given as 1-based index)

            // Convert to 0-based indexing and add the edge from prerequisite to dependent course (add edge u -> v)
            adj[u - 1].push_back(v - 1);

            // Increment in-degree of the dependent course (course v)   
            inDegree[v - 1]++;
        }

        // Initialize a queue to process courses with no prerequisites (courses with in-degree 0)
        queue<int> q;

        // Add courses with no prerequisites (courses with in-degree 0) to the queue
        for (int i = 0; i < n; i++) {
            // If a course has no prerequisites (in-degree 0), add it to the queue
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Array to store the maximum time to complete each course
        vector<int> courseTime(n, 0);

        // Perform BFS traversal, until the queue is empty
        while (!q.empty()) {
            int frontNode = q.front();              // Get the course with no prerequisites
            q.pop();                                // Remove the course from the queue

            // Process all the dependent courses (courses with in-degree greater than 0)
            for (auto nbrNode : adj[frontNode]) {
                // Decrement the in-degree of the dependent course
                inDegree[nbrNode]--;

                // If the dependent course has no more prerequisites (in-degree 0), add it to the queue
                if (inDegree[nbrNode] == 0)
                    q.push(nbrNode);

                // Update the time to complete the neighbor course
                // It is the maximum of its current time, addition of the time to complete the prerequisite course, and its own completion time.
                courseTime[nbrNode] = max(courseTime[nbrNode], courseTime[frontNode] + time[frontNode]);
            }
        }

        // Initialize a variable to store the answer
        int ans = 0;

        // Calculate the maximum time required to complete all courses
        for (int i = 0; i < n; i++) {
            ans = max(ans, courseTime[i] + time[i]);
        }
        // Return the minimum time required to complete all courses
        return ans;
    }
};

Time Complexity = O(N + P)
Space Complexity = O(N + P)
=> P is the total number of prerequisites.
```