# [1004. Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)

<p>Given an array <code>A</code>&nbsp;of 0s and 1s, we may change up to <code>K</code>&nbsp;values from 0 to 1.</p>

<p>Return the length of the longest (contiguous) subarray that contains only 1s.&nbsp;</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[1,1,1,0,0,0,1,1,1,1,0]</span>, K = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">6</span>
<strong>Explanation: </strong>
[1,1,1,0,0,<u><strong>1</strong>,1,1,1,1,<strong>1</strong></u>]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">[0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]</span>, K = <span id="example-input-2-2">3</span>
<strong>Output: </strong><span id="example-output-2">10</span>
<strong>Explanation: </strong>
[0,0,<u>1,1,<b>1</b>,<strong>1</strong>,1,1,1,<strong>1</strong>,1,1</u>,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 20000</code></li>
	<li><code>0 &lt;= K &lt;= A.length</code></li>
	<li><code>A[i]</code> is <code>0</code> or <code>1</code>&nbsp;</li>
</ol>
</div>
</div>


## Solution 1. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/max-consecutive-ones-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0, ans = 0, k = 0;
        while (true) {
            for (; j < A.size() && k <= K; ++j) {
                if (A[j] == 0) ++k;
            }
            ans = max(ans, j - i - (k > K ? 1 : 0));
            if (j >= A.size()) break;
            for (; k > K; ++i) {
                if (A[i] == 0) --k;
            }
        }
        return ans;
    }
};
```