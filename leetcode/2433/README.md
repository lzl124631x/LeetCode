# [2433. Find The Original Array of Prefix Xor (Medium)](https://leetcode.com/problems/find-the-original-array-of-prefix-xor)

<p>You are given an <strong>integer</strong> array <code>pref</code> of size <code>n</code>. Find and return <em>the array </em><code>arr</code><em> of size </em><code>n</code><em> that satisfies</em>:</p>

<ul>
	<li><code>pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]</code>.</li>
</ul>

<p>Note that <code>^</code> denotes the <strong>bitwise-xor</strong> operation.</p>

<p>It can be proven that the answer is <strong>unique</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> pref = [5,2,0,3,1]
<strong>Output:</strong> [5,7,2,3,2]
<strong>Explanation:</strong> From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> pref = [13]
<strong>Output:</strong> [13]
<strong>Explanation:</strong> We have pref[0] = arr[0] = 13.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pref.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= pref[i] &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:
[IBM](https://leetcode.com/company/ibm), [Morgan Stanley](https://leetcode.com/company/morgan-stanley)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation)

**Similar Questions**:
* [Single Number III (Medium)](https://leetcode.com/problems/single-number-iii)
* [Count Triplets That Can Form Two Arrays of Equal XOR (Medium)](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor)
* [Decode XORed Array (Easy)](https://leetcode.com/problems/decode-xored-array)

**Hints**:
* Consider the following equation: x ^ a = b. How can you find x?
* Notice that arr[i] ^ pref[i-1] = pref[i]. This is the same as the previous equation.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-original-array-of-prefix-xor
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space
class Solution {
public:
    vector<int> findArray(vector<int>& A) {
        int N = A.size();
        vector<int> ans = A;
        for (int i = 1; i < A.size(); ++i) ans[i] ^= A[i - 1];
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/find-the-original-array-of-prefix-xor
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space
class Solution {
public:
    vector<int> findArray(vector<int>& A) {
        for (int i = 1, x = A[0]; i < A.size(); ++i) {
            A[i] ^= x;
            x ^= A[i];
        }
        return A;
    }
};
```