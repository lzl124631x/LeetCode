# [1496. Path Crossing (Easy)](https://leetcode.com/problems/path-crossing/)

<p>Given a string&nbsp;<code>path</code>, where <code>path[i] =&nbsp;'N'</code>, <code>'S'</code>, <code>'E'</code>&nbsp;or&nbsp;<code>'W'</code>, each representing moving one unit north, south, east, or west, respectively. You start at the origin <code>(0, 0)</code> on a 2D plane and walk on the path specified by <code>path</code>.</p>

<p>Return <code>True</code> if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return <code>False</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/06/10/screen-shot-2020-06-10-at-123929-pm.png" style="width: 250px; height: 224px;"></p>

<pre><strong>Input:</strong> path = "NES"
<strong>Output:</strong> false 
<strong>Explanation:</strong> Notice that the path doesn't cross any point more than once.
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/06/10/screen-shot-2020-06-10-at-123843-pm.png" style="width: 250px; height: 212px;"></p>

<pre><strong>Input:</strong> path = "NESWW"
<strong>Output:</strong> true
<strong>Explanation:</strong> Notice that the path visits the origin twice.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= path.length &lt;= 10^4</code></li>
	<li><code>path</code> will only consist of characters in&nbsp;<code>{'N', 'S', 'E', 'W}</code></li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/path-crossing/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    long hash(int x, int y) { return (long)x * 10000 + y; }
public:
    bool isPathCrossing(string path) {
        unordered_set<long> s;
        int x = 0, y = 0;
        s.insert(hash(x, y));
        for (char c : path) {
            if (c == 'N') ++y;
            else if (c == 'E') ++x;
            else if (c == 'S') --y;
            else --x;
            long key = hash(x, y);
            if (s.count(key)) return true;
            s.insert(key);
        }
        return false;
    }
};
```