# [526. Beautiful Arrangement (Medium)](https://leetcode.com/problems/beautiful-arrangement/)

<p>Suppose you have <code>n</code> integers labeled <code>1</code> through <code>n</code>. A permutation of those <code>n</code> integers <code>perm</code> (<strong>1-indexed</strong>) is considered a <strong>beautiful arrangement</strong> if for every <code>i</code> (<code>1 &lt;= i &lt;= n</code>), <strong>either</strong> of the following is true:</p>

<ul>
	<li><code>perm[i]</code> is divisible by <code>i</code>.</li>
	<li><code>i</code> is divisible by <code>perm[i]</code>.</li>
</ul>

<p>Given an integer <code>n</code>, return <em>the <strong>number</strong> of the <strong>beautiful arrangements</strong> that you can construct</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<b>Explanation:</b> 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Beautiful Arrangement II (Medium)](https://leetcode.com/problems/beautiful-arrangement-ii/)

## Solution 1. Next Permutation + Backtracking

The brute force way is to generate all the permutations and check each permutation's validity. This will take `O(N!)` time and get TLE.

We can improve it by backtracking once we see invalid prefix.

```cpp
// OJ: https://leetcode.com/problems/beautiful-arrangement/
// Author: github.com/lzl124631x
// Time: O(K) where K is the number of valid permuataions
// Space: O(N)
class Solution {
    int dfs(vector<int> &v, int start) {
        if (start == v.size()) return 1;
        int ans = 0;
        for (int i = start; i < v.size(); ++i) {
            if (v[i] % (start + 1) && (start + 1) % v[i]) continue;
            swap(v[i], v[start]);
            ans += dfs(v, start + 1);
            swap(v[i], v[start]);
        }
        return ans;
    }
public:
    int countArrangement(int n) {
        vector<int> v(n);
        iota(begin(v), end(v), 1);
        return dfs(v, 0);
    }
};
```
