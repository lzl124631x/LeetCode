# [1442. Count Triplets That Can Form Two Arrays of Equal XOR (Medium)](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/)

<p>Given an array of&nbsp;integers <code>arr</code>.</p>

<p>We want to select three indices <code>i</code>, <code>j</code> and <code>k</code> where <code>(0 &lt;= i &lt; j &lt;= k &lt; arr.length)</code>.</p>

<p>Let's define <code>a</code> and <code>b</code> as follows:</p>

<ul>
	<li><code>a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]</code></li>
	<li><code>b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]</code></li>
</ul>

<p>Note that <strong>^</strong> denotes the <strong>bitwise-xor</strong> operation.</p>

<p>Return <em>the number of triplets</em> (<code>i</code>, <code>j</code> and <code>k</code>) Where <code>a == b</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [2,3,1,6,7]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,1,1,1,1]
<strong>Output:</strong> 10
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [2,3]
<strong>Output:</strong> 0
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> arr = [1,3,5,7,9]
<strong>Output:</strong> 3
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> arr = [7,11,12,9,5,2,7,17,22]
<strong>Output:</strong> 8
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 300</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^8</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, vector<int>> m;
        m[0] = {-1};
        int x = 0, ans = 0;
        for (int k = 0; k < A.size(); ++k) {
            x ^= A[k];
            if (m.count(x)) {
                for (int i : m[x]) ans += k - i - 1;
            }
            m[x].push_back(k);
        }
        return ans;
    }
};
```