# [694. Number of Distinct Islands (Medium)](https://leetcode.com/problems/number-of-distinct-islands/)

<p>Given a non-empty 2D array <code>grid</code> of 0's and 1's, an <b>island</b> is a group of <code>1</code>'s (representing land) connected 4-directionally (horizontal or vertical.)  You may assume all four edges of the grid are surrounded by water.</p>

<p>Count the number of <b>distinct</b> islands.  An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.</p>

<p><b>Example 1:</b><br>
</p><pre>11000
11000
00011
00011
</pre>
Given the above grid map, return <code>1</code>.
<p></p>

<p><b>Example 2:</b><br>
</p><pre>11011
10000
00001
11011</pre>
Given the above grid map, return <code>3</code>.<br><br>
Notice that:
<pre>11
1
</pre>
and
<pre> 1
11
</pre>
are considered different island shapes, because we do not consider reflection / rotation.
<p></p>

<p><b>Note:</b>
The length of each dimension in the given <code>grid</code> does not exceed 50.
</p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Lyft](https://leetcode.com/company/lyft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)
* [Number of Distinct Islands II (Hard)](https://leetcode.com/problems/number-of-distinct-islands-ii/)

## Solution 1. Encode Shape

```cpp
// OJ: https://leetcode.com/problems/number-of-distinct-islands/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/number-of-distinct-islands/discuss/194673/C%2B%2B-easy-to-understand
class Solution {
private:
    unordered_set<string> s;
    int M, N;
    void explore(vector<vector<int>>& grid, int x, int y, string &path, char dir) {
        if (x < 0 || x >= M || y < 0 || y >= N || !grid[x][y]) return;
        grid[x][y] = 0;
        path.push_back(dir);
        explore(grid, x + 1, y, path, 'd');
        explore(grid, x, y + 1, path, 'r');
        explore(grid, x - 1, y, path, 'u');
        explore(grid, x, y - 1, path, 'l');
        path.push_back('x');
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                string path;
                explore(grid, i, j, path, 'o');
                if (path.size()) s.insert(path);
            }
        }
        return s.size();
    }
};
```