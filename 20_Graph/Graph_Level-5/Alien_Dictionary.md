# Question : [Alien Dictionary - GFG](https://www.geeksforgeeks.org/problems/alien-dictionary/1)

Given a `sorted` dictionary of an alien language having `N` words and `k` starting alphabets of standard dictionary. Find the order of characters in the alien language.

**Note:** Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

### Example 1

```
Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
```

### Example 2

```
Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
```

### Your task
You don't need to read or print anything. Your task is to complete the function **findOrder**() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.

```
Expected Time Complexity : O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity : O(K)
```

### Constraints
`1 ≤ N, M ≤ 300`
`1 ≤ K ≤ 26`
`1 ≤ Length of words ≤ 50`

## Solution Using BFS Traversal (Kahn's Algorithm)

```Cpp
class Solution {
public:
    // Function to find the order of characters in the alien language.
    string findOrder(string dict[], int N, int K) {
        // Create adjacency list for the graph and in-degree vector
        vector<int> adj[K];             // To store edges from one character to another
        vector<int> inDegree(K, 0);     // To store the in-degree of each character
        
        for (int i = 0; i < N - 1; i++) {
            // Extract two consecutive words from the dictionary
            string word1 = dict[i];
            string word2 = dict[i + 1];
            
            // Initialize indices to compare characters of word1 and word2
            int index1 = 0;
            int index2 = 0;
            
            // Compare characters of word1 and word2 until we find a mismatch or reach the end of one of the words
            while (index1 < word1.size() && index2 < word2.size() && word1[index1] == word2[index2]) {
                index1++;
                index2++;
            }

            // If word1 has the less characters than word2 or both words have the same number of characters, 
            // continue to the next word, Eg. word1 = "ab", word2 = "abc"
            if (index1 == word1.size()) {
                continue;
            }

            // When we find a mismatch between word1 and word2, 
            // Create a directed edge from word1's character to word2's character
            // 'a' is subtracted to convert character to index (e.g., 'a' -> 0, 'b' -> 1, ..., 'z' -> 25)
            char charFromWord1 = word1[index1];
            char charFromWord2 = word2[index2];
            adj[charFromWord1 - 'a'].push_back(charFromWord2 - 'a');
            
            // Increment the in-degree of word2[index2] (since word2 depends on word1 in the dictionary order)
            inDegree[charFromWord2 - 'a']++;
        }
        
        // Initialize a queue to process characters with 0 in-degree (no prerequisites)
        queue<int> q;

        // Add characters with 0 in-degree to the queue
        for (int i = 0; i < K; i++) {
            // If a character has no prerequisites (in-degree 0), add it to the queue
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Initialize an empty string to store the result (order of characters)
        string ans;
    
        // Process characters in topological order using BFS
        while (!q.empty()) {
            int frontNode = q.front();      // Get the front character from the queue
            q.pop();                        // Remove the front character from the queue
            
            // Convert the integer index back to character ('a' + frontNode)
            char ch = 'a' + frontNode;

            // Append the character to the result
            ans += ch;

            // Process all the adjacent characters whose in-degree is greater than 0
            for (auto nbrNode : adj[frontNode]) {
                // Decrement the in-degree of the dependent character
                inDegree[nbrNode]--;
                
                // If the in-degree of the dependent character becomes 0, add it to the queue
                if (inDegree[nbrNode] == 0) {
                    q.push(nbrNode);
                }
            }
        }
        // Return the result string containing the topological order of characters
        return ans;
    }
};

Time Complexity : O(N * L + K + P)
Space Complexity = O(K + P)

=> L is the average length of the words.
=> K is the total number of characters.
=> P is the total number of dependencies.
```