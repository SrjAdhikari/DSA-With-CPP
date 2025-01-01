# Question : [Number Of Islands - (LeetCode : 200)](https://leetcode.com/problems/number-of-islands/description/)

Given an `m x n` 2D binary grid `grid` which represents a map of `'1's` (land) and `'0's` (water), return *the number of islands.*

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

### Example 1

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

### Example 2

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

### Constraints

`m == grid.length`
`n == grid[i].length`
`1 <= m, n <= 300`
`grid[i][j] is '0' or '1'.`


## Solution Using BFS Traversal

```Cpp
class Solution {
public:
    // Function to count the number of islands in a 2D grid
    int numIslands(vector<vector<char>>& grid) {
        // Get the number of rows and columns in the grid
        int row = grid.size();
        int col = grid[0].size();

        // Queue to store the positions of unvisited cells
        queue<pair<int, int>> q;

        // Variable to count the number of islands found
        int count = 0;

        // Array of directions for moving to 4 adjacent cells (up, down, left, right)
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Array to represent the 8 possible directions (up, down, left, right, and diagonals)
        // int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, // up, down, left, right
        //                         {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; // diagonals

        // Traverse the entire grid
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If the cell contains '1', it means it's part of an island
                if (grid[i][j] == '1') {
                    // Increment the island count
                    count++;
                    
                    // Add the current cell to the queue
                    q.push({i, j});

                    // Mark the current cell as visited by setting it to '0'
                    grid[i][j] = '0';

                    // Process all cells in the current island, one by one
                    while (!q.empty()) {
                        // Get the current cell's row and column index, and remove it from the queue
                        int rowIndex = q.front().first;
                        int colIndex = q.front().second;
                        q.pop();

                        // Check all 4 adjacent cells (up, down, left, right) for unvisited cells
                        for (auto dir : directions) {
                            // Get the new row and column index of the adjacent cell
                            int newRow = rowIndex + dir[0]; 
                            int newCol = colIndex + dir[1];

                            // Check if the new cell is within bounds and contains '1'
                            // If so, mark it as visited and add it to the queue
                            if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == '1') {
                                // Mark the new cell as visited
                                grid[newRow][newCol] = '0';

                                // Add the new cell to the queue for further processing
                                q.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }
        // Return the total number of islands found
        return count;
    }
};

Time Complexity = O(row * col)
Space Complexity = O(row * col)
```