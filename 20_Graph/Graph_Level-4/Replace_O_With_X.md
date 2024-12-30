# Question : [Replace O's with X's - GFG](https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1)

Given a matrix **mat** of size N x M where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

### Example 1

```
Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix. 
```

### Example 2

```
Input: 
n = 5, m = 4
mat = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix.
```

### Your task
You do not need to read input or print anything. Your task is to complete the function **fill()** which takes N, M and mat as input parameters ad returns a 2D array representing the resultant matrix.

```
Expected Time Complexity: O(n * m)
Expected Auxiliary Space: O(n * m)
```

### Constraints
`11 ≤ n, m ≤ 500`

## Solution Using BFS Traversal

```Cpp
class Solution {
public:
    // Function to fill character 'O' with 'X'
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        // Get the number of rows and columns in the matrix
        int row = n;
        int col = m;
    
        // Array of directions for moving to 4 adjacent cells (up, down, left, right)
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Queue to store the positions of boundary 'O's
        queue<pair<int, int>> q;
    
        // Perform BFS to check all boundary 'O's. Replace all boundary 'O's with 'V'.
        // 1. Check the first row for 'O' and mark them as visited ('V'), then push into queue
        for (int firstRow = 0; firstRow < col; firstRow++) {
            if (mat[0][firstRow] == 'O') {
                q.push({0, firstRow});
                mat[0][firstRow] = 'V';  // Mark as visited
            }
        }
    
        // 2. Check the first column for 'O' and mark them as visited ('V'), then push into queue
        for (int firstCol = 1; firstCol < row; firstCol++) {
            if (mat[firstCol][0] == 'O') {
                q.push({firstCol, 0});
                mat[firstCol][0] = 'V';  // Mark as visited
            }
        }
    
        // 3. Check the last row for 'O' and mark them as visited ('V'), then push into queue
        for (int lastRow = 1; lastRow < col; lastRow++) {
            if (mat[row - 1][lastRow] == 'O') {
                q.push({row - 1, lastRow});
                mat[row - 1][lastRow] = 'V';  // Mark as visited
            }
        }
    
        // 4. Check the last column for 'O' and mark them as visited ('V'), then push into queue
        for (int lastCol = 1; lastCol < row - 1; lastCol++) {
            if (mat[lastCol][col - 1] == 'O') {
                q.push({lastCol, col - 1});
                mat[lastCol][col - 1] = 'V';  // Mark as visited
            }
        }

        // Perform BFS traversal until the queue is empty
        while (!q.empty()) {
            // Get the current cell's row and column index, and remove it from the queue
            int rowIndex = q.front().first;
            int colIndex = q.front().second;
            q.pop();
    
            // Check all 4 adjacent cells (up, down, left, right) for unvisited cells
            for (auto dir : directions) {
                int newRow = rowIndex + dir[0];
                int newCol = colIndex + dir[1];
    
                // Check if the new cell is within bounds and contains 'O', 
                // If so, mark it as visited and add it to the queue
                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && mat[newRow][newCol] == 'O') {
                    mat[newRow][newCol] = 'V';  // Mark as visited
                    q.push({newRow, newCol});
                }
            }
        }
    
        // Change all remaining 'O's to 'X' (since they are not connected to boundary 'O's)
        // And revert visited 'V's back to 'O'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // Check if the current cell contains 'O', if so, convert it to 'X'
                if (mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
                // Check if the current cell contains 'V', if so, convert it back to 'O'
                else if (mat[i][j] == 'V') {
                    mat[i][j] = 'O';
                }
            }
        }
        // Return the modified matrix
        return mat;
    }
};

Time Complexity = O(n * m)
Space Complexity = O(n * m)
```