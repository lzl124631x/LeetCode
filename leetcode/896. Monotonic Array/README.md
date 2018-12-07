# [896. Monotonic Array (Easy)](https://leetcode.com/problems/monotonic-array/)

<p>An array is <em>monotonic</em> if it is either monotone increasing or monotone decreasing.</p>

<p>An array <code>A</code> is monotone increasing if for all <code>i &lt;= j</code>, <code>A[i] &lt;= A[j]</code>.&nbsp; An array <code>A</code> is monotone decreasing if for all <code>i &lt;= j</code>, <code>A[i] &gt;= A[j]</code>.</p>

<p>Return <code>true</code> if and only if the given array <code>A</code> is monotonic.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,2,2,3]</span>
<strong>Output: </strong><span id="example-output-1">true</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[6,5,4,4]</span>
<strong>Output: </strong><span id="example-output-2">true</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[1,3,2]</span>
<strong>Output: </strong><span id="example-output-3">false</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">[1,2,4,5]</span>
<strong>Output: </strong><span id="example-output-4">true</span>
</pre>

<div>
<p><strong>Example 5:</strong></p>

<pre><strong>Input: </strong><span id="example-input-5-1">[1,1,1]</span>
<strong>Output: </strong><span id="example-output-5">true</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 50000</code></li>
	<li><code>-100000 &lt;= A[i] &lt;= 100000</code></li>
</ol>
</div>
</div>
</div>
</div>
</div>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/monotonic-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 2) return true;
        int type = 0;
        for (int i = 1; i < A.size(); ++i) {
            int d = A[i] - A[i - 1];
            if (!d) continue;
            if (d > 0) {
                if (type == -1) return false;
                type = 1;
            } else {
                if (type == 1) return false;
                type = -1;
            }
        }
        return true;
    }
};
```