# [773. Sliding Puzzle (Hard)](https://leetcode.com/problems/sliding-puzzle/)

<p>On a 2x3 <code>board</code>, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.</p>

<p>A move consists of choosing <code>0</code>&nbsp;and a 4-directionally adjacent number and swapping it.</p>

<p>The state of the board is <em>solved</em> if and only if the <code>board</code> is <code>[[1,2,3],[4,5,0]].</code></p>

<p>Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.</p>

<p><strong>Examples:</strong></p>

<pre><strong>Input:</strong> board = [[1,2,3],[4,0,5]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Swap the 0 and the 5 in one move.
</pre>

<pre><strong>Input:</strong> board = [[1,2,3],[5,4,0]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> No number of moves will make the board solved.
</pre>

<pre><strong>Input:</strong> board = [[4,1,2],[5,0,3]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
</pre>

<pre><strong>Input:</strong> board = [[3,2,4],[1,5,0]]
<strong>Output:</strong> 14
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>board</code> will be a 2 x 3 array as described above.</li>
	<li><code>board[i][j]</code> will be a permutation of <code>[0, 1, 2, 3, 4, 5]</code>.</li>
</ul>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. BFS

We can regard a board as a node in a graph. If we can change a board `A` to board `B` in one move, there is an edge between their corresponding nodes. This problem is asking for the shortest path. We can use BFS to find it.

```cpp
// OJ: https://leetcode.com/problems/sliding-puzzle/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& A) {
        string target = "123450", start;
        int ans = 0;
        vector<vector<int>> neighbors = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) start += '0' + A[i][j];
        }
        if (target == start) return 0;
        unordered_set<string> seen;
        seen.insert(start);
        queue<string> q;
        q.push(start);
        while (q.size()) {
            int cnt = q.size();
            ++ans;
            while (cnt--) {
                auto B = q.front();
                q.pop();
                int from = 0;
                for (int i = 0; i < 6; ++i) {
                    if (B[i] == '0') {
                        from = i;
                        break;
                    }
                }
                for (auto &to : neighbors[from]) {
                    swap(B[from], B[to]);
                    if (B == target) return ans;
                    if (seen.count(B) == 0) {
                        seen.insert(B);
                        q.push(B);
                    }
                    swap(B[from], B[to]);
                }
            }
        }
        return -1;
    }
};
```