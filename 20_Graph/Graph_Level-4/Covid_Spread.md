# Question : [Covid Spread - GFG](https://www.geeksforgeeks.org/problems/covid-spread--141631/1)

Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
Given a matrix of dimension **R * C** where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
**0**: Empty ward
**1**: Cells have uninfected patients
**2**: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (**up, down, left and right**) in unit time. Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.

### Example 1
```
Input:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1 
Output:
2
Explanation:
Patients at positions {0,0}, {0, 3}, {1, 3}
and {2, 3} will infect patient at {0, 1}, 
{1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st 
unit time. And, during 2nd unit time, patient at 
{1, 0} will get infected and will infect patient 
at {2, 0}. Hence, total 2 unit of time is
required to infect all patients.
```

### Example 2
```
Input:
3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1
Output:
-1
Explanation:
All patients will not be infected.
```

### Your task
You don't need to read input or print anything. Your task is to complete the function **helpaterp()** which takes a 2-D Matrix **hospital** as input parameter and returns the minimum units of time in which all patients will be infected or -1 if it is impossible.

### Constraints
`1 ≤ R,C ≤ 1000`
`0 ≤ mat[i][j] ≤ 2`

## Solution Using BFS Traversal

```Cpp
class Solution {
public:
    // Function to find the minimum time required to infect all patients
    int helpaterp(vector<vector<int>> hospital) {
        // Get the row and column sizes of the hospital grid
        int row = hospital.size();
        int col = hospital[0].size();

        // Queue to store the positions of infected patients
        queue<pair<int, int>> q;
        
        // Push all initially infected patients (cells with value 2) into the queue
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (hospital[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        // Timer variable to track the time to infect all patients
        int timer = 0;

        // Array of directions for moving to 4 adjacent cells (up, down, left, right)
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Perform BFS traversal to infect all uninfected patients, one level at a time
        while (!q.empty()) {
            // Increment the timer for each level of infection
            timer++;

            // Get the number of infected patients at the current level
            int currPatientCount = q.size();
            
            // Process all infected patients at the current level, one by one
            while (currPatientCount--) {
                // Get the current patient's row and column index, and remove it from the queue
                int rowIndex = q.front().first;
                int colIndex = q.front().second;
                q.pop();
                
                // Check all 4 adjacent cells (up, down, left, right) for infected patients
                for (auto dir : directions) {
                    // Get the new row and column index of the adjacent cell
                    int newRow = rowIndex + dir[0];
                    int newCol = colIndex + dir[1];
                    
                    // Check if the new cell is within bounds and is a healthy patient (value 1)
                    // If so, infect it and add it to the queue
                    if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && hospital[newRow][newCol] == 1) {
                        // Infect the healthy patient
                        hospital[newRow][newCol] = 2;

                        // Add the newly infected patient to the queue
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        
        // Check if any healthy patient remains after the infection
        // If any healthy patient is found, return -1 to indicate an impossible scenario
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (hospital[i][j] == 1) {
                    return -1;
                }
            }
        }
        // If all patients are infected, return the total time taken
        return timer - 1;
    }
};

Time Complexity = O(row * col)
Space Complexity = O(row * col)
```