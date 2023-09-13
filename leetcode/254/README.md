# [254. Factor Combinations (Medium)](https://leetcode.com/problems/factor-combinations)

<p>Numbers can be regarded as the product of their factors.</p>
<ul>
	<li>For example, <code>8 = 2 x 2 x 2 = 2 x 4</code>.</li>
</ul>
<p>Given an integer <code>n</code>, return <em>all possible combinations of its factors</em>. You may return the answer in <strong>any order</strong>.</p>
<p><strong>Note</strong> that the factors should be in the range <code>[2, n - 1]</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> []
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 12
<strong>Output:</strong> [[2,6],[3,4],[2,2,3]]
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> n = 37
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>7</sup></code></li>
</ul>

**Companies**:
[LinkedIn](https://leetcode.com/company/linkedin), [TikTok](https://leetcode.com/company/tiktok), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/factor-combinations
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(?)
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        function<void(int, int)> dfs = [&](int n, int d) {
            for (int i = d; i * i <= n; ++i) {
                if (n % i) continue;
                tmp.push_back(i);
                dfs(n / i, i);
                tmp.push_back(n / i);
                ans.push_back(tmp);
                tmp.pop_back();
                tmp.pop_back();
            }
        };
        dfs(n, 2);
        return ans;
    }
};
```