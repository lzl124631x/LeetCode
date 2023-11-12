# [1215. Stepping Numbers (Medium)](https://leetcode.com/problems/stepping-numbers)

<p>A <strong>stepping number</strong> is an integer such that all of its adjacent digits have an absolute difference of exactly <code>1</code>.</p>

<ul>
	<li>For example, <code>321</code> is a <strong>stepping number</strong> while <code>421</code> is not.</li>
</ul>

<p>Given two integers <code>low</code> and <code>high</code>, return <em>a sorted list of all the <strong>stepping numbers</strong> in the inclusive range</em> <code>[low, high]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> low = 0, high = 21
<strong>Output:</strong> [0,1,2,3,4,5,6,7,8,9,10,12,21]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> low = 10, high = 15
<strong>Output:</strong> [10,12]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= low &lt;= high &lt;= 2 * 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Epic Systems](https://leetcode.com/company/epic-systems)

**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search)

**Similar Questions**:
* [Count Stepping Numbers in Range (Hard)](https://leetcode.com/problems/count-stepping-numbers-in-range)

**Hints**:
* Try to generate the numbers using recursion.
* In one step in the recursion, add a valid digit to the right of the current number.
* Save the number if it's in the range between low and high.

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/stepping-numbers
// Author: github.com/lzl124631x
// Time: O(lg(R) * 2^lg(R))
// Space: O(lg(R))
class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        if (low == 0) ans.push_back(0), ++low;
        int L = log(low) / log(10) + 1, R = log(high) / log(10) + 1;
        function<void(long, int, int)> dfs = [&](long n, int i, int len) {
            if (i == len) {
                if (n >= low && n <= high) ans.push_back(n);
                return;
            }
            int d = n % 10;
            if (d - 1 >= 0) dfs(n * 10 + d - 1, i + 1, len);
            if (d + 1 <= 9) dfs(n * 10 + d + 1, i + 1, len);
        };
        for (int len = L; len <= R; ++len) {
            for (int d = 1; d <= 9; ++d) dfs(d, 1, len);
        }
        return ans;
    }
};
```

## Solution 2. BFS

```cpp
// OJ: https://leetcode.com/problems/stepping-numbers
// Author: github.com/lzl124631x
// Time: O(lg(R) * 2^lg(R))
// Space: O(2^lg(R))
class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        queue<long> q;
        for (int i = 1; i <= 9; ++i) q.push(i);
        if (low == 0) ans.push_back(0);
        while (q.size()) {
            long n = q.front(), d = n % 10;
            q.pop();
            if (n >= low && n <= high) ans.push_back(n);
            if (n < high) {
                if (d - 1 >= 0) q.push(n * 10 + d - 1);
                if (d + 1 <= 9) q.push(n * 10 + d + 1);
            }
        }
        return ans;
    }
};
```