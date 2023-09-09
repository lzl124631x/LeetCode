# [216. Combination Sum III (Medium)](https://leetcode.com/problems/combination-sum-iii/)

<p>Find all valid combinations of <code>k</code> numbers that sum up to <code>n</code> such that the following conditions are true:</p>

<ul>
	<li>Only numbers <code>1</code> through <code>9</code> are used.</li>
	<li>Each number is used <strong>at most once</strong>.</li>
</ul>

<p>Return <em>a list of all possible valid combinations</em>. The list must not contain the same combination twice, and the combinations may be returned in any order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> k = 3, n = 7
<strong>Output:</strong> [[1,2,4]]
<strong>Explanation:</strong>
1 + 2 + 4 = 7
There are no other valid combinations.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> k = 3, n = 9
<strong>Output:</strong> [[1,2,6],[1,3,5],[2,3,4]]
<strong>Explanation:</strong>
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> k = 4, n = 1
<strong>Output:</strong> []
<strong>Explanation:</strong> There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 &gt; 1, there are no valid combination.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= 9</code></li>
	<li><code>1 &lt;= n &lt;= 60</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/combination-sum-iii
// Author: github.com/lzl124631x
// Time: O(2^9 * 9)
// Space: O(9)
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        function<void(int, int)> dfs = [&](int i, int n) {
            if (tmp.size() == k) {
                if (n == 0) ans.push_back(tmp);
                return;
            }
            if (i > 9) return;
            dfs(i + 1, n); // skip i
            tmp.push_back(i);
            dfs(i + 1, n - i); // use i
            tmp.pop_back();
        };
        dfs(1, n);
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/combination-sum-iii/
// Author: github.com/lzl124631x
// Time: O(2^9 * 9)
// Space: O(9)
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        function<void(int, int)> dfs = [&](int start, int n) {
            if (tmp.size() == k) {
                if (n == 0) ans.push_back(tmp);
                return;
            }
            for (int i = start; i <= min(9, n); ++i) {
                tmp.push_back(i);
                dfs(i + 1, n - i);
                tmp.pop_back();
            }
        };
        dfs(1, n);
        return ans;
    }
};
```

## Solution 2. Bitmask Subset Traversal

```cpp
// OJ: https://leetcode.com/problems/combination-sum-iii/
// Author: github.com/lzl124631x
// Time: O(2^9 * 9)
// Space: O(9)
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for (unsigned m = 1; m < 1 << 9; ++m) {
            if (__builtin_popcount(m) != k) continue;
            vector<int> tmp;
            int sum = 0;
            for (int i = 1; i <= 9; ++i) {
                if (m >> (i - 1) & 1) {
                    sum += i;
                    tmp.push_back(i);
                }
            }
            if (sum == n) ans.push_back(tmp);
        }
        return ans;
    }
};
```

We can use Gosper's Hack to generate bitmasks with `k` bit 1's. 

```cpp
// OJ: https://leetcode.com/problems/combination-sum-iii/
// Author: github.com/lzl124631x
// Time: O(C(9, k) * 9)
// Space: O(9)
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int m = (1 << k) - 1;
        while (m < (1 << 9)) {
            vector<int> tmp;
            int sum = 0;
            for (int i = 1; i <= 9; ++i) {
                if (m >> (i - 1) & 1) {
                    sum += i;
                    tmp.push_back(i);
                }
            }
            if (sum == n) ans.push_back(tmp);
            int c = m & -m, r = m + c;
            m = (((r ^ m) >> 2) / c) | r;
        }
        return ans;
    }
};
```