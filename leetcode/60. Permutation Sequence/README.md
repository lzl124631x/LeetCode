# [60. Permutation Sequence (Medium)](https://leetcode.com/problems/permutation-sequence/)

<p>The set <code>[1,2,3,...,<em>n</em>]</code> contains a total of <em>n</em>! unique permutations.</p>

<p>By listing and labeling all of the permutations in order, we get the following sequence for <em>n</em> = 3:</p>

<ol>
	<li><code>"123"</code></li>
	<li><code>"132"</code></li>
	<li><code>"213"</code></li>
	<li><code>"231"</code></li>
	<li><code>"312"</code></li>
	<li><code>"321"</code></li>
</ol>

<p>Given <em>n</em> and <em>k</em>, return the <em>k</em><sup>th</sup> permutation sequence.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>Given <em>n</em> will be between 1 and 9 inclusive.</li>
	<li>Given&nbsp;<em>k</em>&nbsp;will be between 1 and <em>n</em>! inclusive.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 3, k = 3
<strong>Output:</strong> "213"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4, k = 9
<strong>Output:</strong> "2314"
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/permutation-sequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        for (int i = 1; i <= n; ++i) ans += '0' + i;
        k--;
        for (int i = n; i > 0; --i) {
            int p = 1;
            for (int j = 1; j < i; ++j) p *= j;
            int t = n - i + k / p, tmp = ans[t];
            for (; t > n - i; --t) ans[t] = ans[t - 1];
            ans[n - i] = tmp;
            k %= p;
        }
        return ans.substr(0, n);
    }
};
```