# [2928. Distribute Candies Among Children I (Easy)](https://leetcode.com/problems/distribute-candies-among-children-i)

<p>You are given two positive integers <code>n</code> and <code>limit</code>.</p>

<p>Return <em>the <strong>total number</strong> of ways to distribute </em><code>n</code> <em>candies among </em><code>3</code><em> children such that no child gets more than </em><code>limit</code><em> candies.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 5, limit = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3, limit = 3
<strong>Output:</strong> 10
<strong>Explanation:</strong> There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= limit &lt;= 50</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Rubrik](https://leetcode.com/company/rubrik)

**Related Topics**:  
[Math](https://leetcode.com/tag/math), [Combinatorics](https://leetcode.com/tag/combinatorics), [Enumeration](https://leetcode.com/tag/enumeration)

**Similar Questions**:
* [Count Ways to Distribute Candies (Hard)](https://leetcode.com/problems/count-ways-to-distribute-candies)

**Hints**:
* Use three nested for loops to check all the triplets.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/distribute-candies-among-children-i
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for (int i = 0; i <= limit; ++i) {
            ans += max(0, min(n - i, limit) - max(0, n - i - limit) + 1);
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/distribute-candies-among-children-i/solutions/4301078/c-o-n-time-one-pass/