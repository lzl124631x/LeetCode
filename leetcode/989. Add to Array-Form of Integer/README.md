# [989. Add to Array-Form of Integer (Easy)](https://leetcode.com/problems/add-to-array-form-of-integer/)

<p>For a non-negative integer <code>X</code>, the&nbsp;<em>array-form of <code>X</code></em>&nbsp;is an array of its digits in left to right order.&nbsp; For example, if <code>X = 1231</code>, then the array form is&nbsp;<code>[1,2,3,1]</code>.</p>

<p>Given the array-form <code>A</code> of a non-negative&nbsp;integer <code>X</code>, return the array-form of the integer <code>X+K</code>.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[1,2,0,0]</span>, K = 34
<strong>Output: </strong><span id="example-output-1">[1,2,3,4]</span>
<strong>Explanation: </strong>1200 + 34 = 1234
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">[2,7,4]</span>, K = <span id="example-input-2-2">181</span>
<strong>Output: </strong><span id="example-output-2">[4,5,5]</span>
<strong>Explanation: </strong>274 + 181 = 455
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-3-1">[2,1,5]</span>, K = <span id="example-input-3-2">806</span>
<strong>Output: </strong><span id="example-output-3">[1,0,2,1]</span>
<strong>Explanation: </strong>215 + 806 = 1021
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-4-1">[9,9,9,9,9,9,9,9,9,9]</span>, K = <span id="example-input-4-2">1</span>
<strong>Output: </strong><span id="example-output-4">[1,0,0,0,0,0,0,0,0,0,0]</span>
<strong>Explanation: </strong>9999999999 + 1 = 10000000000
</pre>

<p>&nbsp;</p>

<p><strong>Note：</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 10000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 9</code></li>
	<li><code>0 &lt;= K &lt;= 10000</code></li>
	<li>If <code>A.length &gt; 1</code>, then <code>A[0] != 0</code></li>
</ol>
</div>
</div>
</div>
</div>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)
* [Plus One (Easy)](https://leetcode.com/problems/plus-one/)
* [Add Binary (Easy)](https://leetcode.com/problems/add-binary/)
* [Add Strings (Easy)](https://leetcode.com/problems/add-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/add-to-array-form-of-integer/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int N = A.size(), carry = 0;
        vector<int> ans;
        for (int i = N - 1; i >= 0 || K || carry;) {
            if (K) {
                carry += K % 10;
                K /= 10;
            }
            if (i >= 0) carry += A[i--];
            ans.push_back(carry % 10);
            carry /= 10;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```

Or use `K` as `carry`.

```cpp
// OJ: https://leetcode.com/problems/add-to-array-form-of-integer/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int N = A.size();
        vector<int> ans;
        for (int i = N - 1; i >= 0 || K;) {
            if (i >= 0) K += A[i--];
            ans.push_back(K % 10);
            K /= 10;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```