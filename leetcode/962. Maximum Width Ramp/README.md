# [962. Maximum Width Ramp (Medium)](https://leetcode.com/problems/maximum-width-ramp/)

<p>Given an array <code>A</code> of integers, a <em>ramp</em>&nbsp;is a tuple <code>(i, j)</code> for which <code>i &lt; j</code>&nbsp;and&nbsp;<code>A[i] &lt;= A[j]</code>.&nbsp; The width of such a&nbsp;ramp is <code>j - i</code>.</p>

<p>Find the maximum width of a ramp in <code>A</code>.&nbsp; If one doesn't exist, return 0.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[6,0,8,2,1,5]</span>
<strong>Output: </strong><span id="example-output-1">4</span>
<strong>Explanation: </strong>
The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[9,8,1,0,1,9,4,0,4,1]</span>
<strong>Output: </strong><span id="example-output-2">7</span>
<strong>Explanation: </strong>
The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.
</pre>
</div>

<div>
<div>
<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>2 &lt;= A.length &lt;= 50000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 50000</code></li>
</ol>
</div>
</div>

<div>
<div>&nbsp;</div>
</div>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

Consider the array ends with `4, 1, 2`. For the a number `n` in front:
* If `n <= 2`, we use the last `2` to form the ramp. The last `1` won't be used.
* If `2 < n <= 4`, we use the last `4` to form the ramp.

So we can traverse from rear to front, and save the numbers in ascending order:

```
numbers: [2, 4]
indexes: [N - 1, N - 3]
```

Then we traverse from front to rear, use `lower_bound` to find the smallest number greater than the current `A[i]`. The corresponding `index` can be used form a ramp.

```cpp
// OJ: https://leetcode.com/problems/maximum-width-ramp/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> v, index;
        for (int i = N - 1; i >= 0; --i) {
            if (v.empty() || v.back() < A[i]) {
                v.push_back(A[i]);
                index.push_back(i);
            }
        }
        for (int i = 0; i < N; ++i) {
            int ind = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
            ans = max(ans, index[ind] - i);
        }
        return ans;
    }
};
```