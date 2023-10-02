# [2683. Neighboring Bitwise XOR (Medium)](https://leetcode.com/problems/neighboring-bitwise-xor)

<p>A <strong>0-indexed</strong> array <code>derived</code> with length <code>n</code> is derived by computing the <strong>bitwise XOR</strong>&nbsp;(⊕) of adjacent values in a <strong>binary array</strong> <code>original</code> of length <code>n</code>.</p>
<p>Specifically, for each index <code>i</code> in the range <code>[0, n - 1]</code>:</p>
<ul>
	<li>If <code>i = n - 1</code>, then <code>derived[i] = original[i] ⊕ original[0]</code>.</li>
	<li>Otherwise, <code>derived[i] = original[i] ⊕ original[i + 1]</code>.</li>
</ul>
<p>Given an array <code>derived</code>, your task is to determine whether there exists a <strong>valid binary array</strong> <code>original</code> that could have formed <code>derived</code>.</p>
<p>Return <em><strong>true</strong> if such an array exists or <strong>false</strong> otherwise.</em></p>
<ul>
	<li>A binary array is an array containing only <strong>0's</strong> and <strong>1's</strong></li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> derived = [1,1,0]
<strong>Output:</strong> true
<strong>Explanation:</strong> A valid original array that gives derived is [0,1,0].
derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1 
derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> derived = [1,1]
<strong>Output:</strong> true
<strong>Explanation:</strong> A valid original array that gives derived is [0,1].
derived[0] = original[0] ⊕ original[1] = 1
derived[1] = original[1] ⊕ original[0] = 1
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> derived = [1,0]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no valid original array that gives derived.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == derived.length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li>The values in <code>derived</code>&nbsp;are either <strong>0's</strong> or <strong>1's</strong></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/neighboring-bitwise-xor
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& A) {
        int N = A.size(), prev = 0;
        for (int i = 0; i < N - 1; ++i) {
            prev = A[i] ^ prev;
        }
        return prev ^ 0 == A.back();
    }
};
```