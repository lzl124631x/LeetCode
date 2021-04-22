# [60. Permutation Sequence (Hard)](https://leetcode.com/problems/permutation-sequence/)

<p>The set <code>[1, 2, 3, ...,&nbsp;n]</code> contains a total of <code>n!</code> unique permutations.</p>

<p>By listing and labeling all of the permutations in order, we get the following sequence for <code>n = 3</code>:</p>

<ol>
	<li><code>"123"</code></li>
	<li><code>"132"</code></li>
	<li><code>"213"</code></li>
	<li><code>"231"</code></li>
	<li><code>"312"</code></li>
	<li><code>"321"</code></li>
</ol>

<p>Given <code>n</code> and <code>k</code>, return the <code>k<sup>th</sup></code> permutation sequence.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 3, k = 3
<strong>Output:</strong> "213"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> n = 4, k = 9
<strong>Output:</strong> "2314"
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> n = 3, k = 1
<strong>Output:</strong> "123"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 9</code></li>
	<li><code>1 &lt;= k &lt;= n!</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/permutation-sequence/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(1)
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        for (int i = 0; i < n; ++i) ans += ('1' + i);
        while (--k) next_permutation(begin(ans), end(ans));
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/permutation-sequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        string ans;
        for (int i = 1; i <= n; ++i) {
            fact *= i;
            ans += '0' + i;
        }
        --k;
        for (int i = 0; i < n; ++i) {
            fact /= n - i;
            int j = k / fact + i, tmp = ans[j];
            for (; j > i; --j) ans[j] = ans[j - 1];
            ans[j] = tmp;
            k %= fact;
        }
        return ans;
    }
};
```