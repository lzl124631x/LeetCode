# [954. Array of Doubled Pairs (Medium)](https://leetcode.com/problems/array-of-doubled-pairs/)

<p>Given an array of integers <code>A</code>&nbsp;with even length, return <code>true</code> if and only if it is possible to reorder it such that <code>A[2 * i + 1] = 2 * A[2 * i]</code> for every <code>0 &lt;=&nbsp;i &lt; len(A) / 2</code>.</p>

<p>&nbsp;</p>

<div>
<div>
<div>
<ol>
</ol>
</div>
</div>
</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[3,1,3,6]</span>
<strong>Output: </strong><span id="example-output-1">false</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[2,1,2,6]</span>
<strong>Output: </strong><span id="example-output-2">false</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[4,-2,2,-4]</span>
<strong>Output: </strong><span id="example-output-3">true</span>
<strong>Explanation: </strong><span id="example-output-3">We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">[1,2,4,16,8,4]</span>
<strong>Output: </strong><span id="example-output-4">false</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= A.length &lt;= 30000</code></li>
	<li><code>A.length</code> is even</li>
	<li><code>-100000 &lt;= A[i] &lt;= 100000</code></li>
</ol>
</div>
</div>
</div>
</div>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/array-of-doubled-pairs/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        multiset<int> s(A.begin(), A.end());
        while (s.size()) {
            int val = *s.begin();
            if (val < 0 && val % 2) return false;
            int next = val >= 0 ? val * 2 : val / 2;
            s.erase(s.begin());
            auto it = s.find(next);
            if (it == s.end()) return false;
            s.erase(it);
        }
        return true;
    }
};
```