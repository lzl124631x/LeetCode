# [932. Beautiful Array (Medium)](https://leetcode.com/problems/beautiful-array/)

<p>For some fixed <code>N</code>, an array <code>A</code> is <em>beautiful</em> if it is a permutation of the integers <code>1, 2, ..., N</code>, such that:</p>

<p>For every <code>i &lt; j</code>, there is <strong>no</strong>&nbsp;<code>k</code> with <code>i &lt; k &lt; j</code>&nbsp;such that <code>A[k] * 2 = A[i] + A[j]</code>.</p>

<p>Given <code>N</code>, return <strong>any</strong> beautiful array <code>A</code>.&nbsp; (It is guaranteed that one exists.)</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">4</span>
<strong>Output: </strong><span id="example-output-1">[2,1,4,3]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">5</span>
<strong>Output: </strong><span>[3,1,2,5,4]</span></pre>

<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ul>
	<li><code>1 &lt;= N &lt;= 1000</code></li>
</ul>

<div>
<div>&nbsp;</div>
</div>

**Related Topics**:  
[Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/)

## Solution 1. Divide and Conquer

Observations:

* Given `2 * A[k] != A[i] + A[j]`, since `2 * A[k]` is even, we can make `A[i]` an odd number and `A[j]` an even number. So we can split the array into two parts, all the `odd` numbers into `left` and all the even `numbers` into `right`.
* We can reuse the solution to `1 2 3 4 5` to construct the solution for `1 3 5 7 9`.

```cpp
// OJ: https://leetcode.com/problems/beautiful-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(NlogN)
class Solution {
    unordered_map<int, vector<int>> m;
    vector<int> dfs(int N) {
        if (m.count(N)) return m[N];
        vector<int> ans(N);
        if (N == 1) ans[0] = 1;
        else {
            int t = 0;
            for (int x : dfs((N + 1) / 2)) ans[t++] = 2 * x - 1; // odd
            for (int x : dfs(N / 2)) ans[t++] = 2 * x; // even
        }
        return m[N] = ans;
    }
public:
    vector<int> beautifulArray(int N) {
        return dfs(N);
    }
};
```