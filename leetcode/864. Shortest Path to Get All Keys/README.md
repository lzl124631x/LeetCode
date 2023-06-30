# [864. Shortest Path to Get All Keys (Hard)](https://leetcode.com/problems/shortest-path-to-get-all-keys/)

<p>You are given an <code>m x n</code> grid <code>grid</code> where:</p>

<ul>
	<li><code>'.'</code> is an empty cell.</li>
	<li><code>'#'</code> is a wall.</li>
	<li><code>'@'</code> is the starting point.</li>
	<li>Lowercase letters represent keys.</li>
	<li>Uppercase letters represent locks.</li>
</ul>

<p>You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.</p>

<p>If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.</p>

<p>For some <code><font face="monospace">1 &lt;= k &lt;= 6</font></code>, there is exactly one lowercase and one uppercase letter of the first <code>k</code> letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.</p>

<p>Return <em>the lowest number of moves to acquire all keys</em>. If it is impossible, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-keys2.jpg" style="width: 404px; height: 245px;">
<pre><strong>Input:</strong> grid = ["@.a.#","###.#","b.A.B"]
<strong>Output:</strong> 8
<strong>Explanation:</strong> Note that the goal is to obtain all the keys not to open all the locks.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-key2.jpg" style="width: 404px; height: 245px;">
<pre><strong>Input:</strong> grid = ["@..aA","..B#.","....b"]
<strong>Output:</strong> 6
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/23/lc-keys3.jpg" style="width: 244px; height: 85px;">
<pre><strong>Input:</strong> grid = ["@Aa"]
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 30</code></li>
	<li><code>grid[i][j]</code> is either an English letter, <code>'.'</code>, <code>'#'</code>, or <code>'@'</code>.</li>
	<li>The number of keys in the grid is in the range <code>[1, 6]</code>.</li>
	<li>Each key in the grid is <strong>unique</strong>.</li>
	<li>Each key in the grid has a matching lock.</li>
</ul>


**Companies**:  
[Airbnb](https://leetcode.com/company/airbnb), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/shortest-path-to-get-all-keys/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    int getState(int x, int y, int keys) {
        return x * 10000 + y * 100 + keys;
    }
public:
    int shortestPathAllKeys(vector<string>& A) {
        int M = A.size(), N = A[0].size(), startX, startY, allLocks = 0, dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}}, step = 0;
        queue<int> q;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '@') startX = i, startY = j;
                else if (A[i][j] >= 'A' && A[i][j] <= 'F') allLocks |= (1 << (A[i][j] - 'A'));
            }
        }
        int initState = getState(startX, startY, 0);
        q.emplace(initState);
        unordered_set<int> seen{initState};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int state = q.front();
                q.pop();
                int x = state / 10000, y = state % 10000 / 100, keys = state % 100;
                if (keys == allLocks) return step;
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == '#' || (isupper(A[a][b]) && (keys & (1 << (A[a][b] - 'A'))) == 0)) continue;
                    int newKeys = keys;
                    if (islower(A[a][b])) newKeys |= (1 << (A[a][b] - 'a'));
                    int newState = getState(a, b, newKeys);
                    if (seen.count(newState)) continue;
                    seen.insert(newState);
                    q.emplace(newState);
                }
            }
            ++step;
        }
        return -1;
    }
};
```