# [1835. Find XOR Sum of All Pairs Bitwise AND (Hard)](https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/)

<p>The <strong>XOR sum</strong> of a list is the bitwise <code>XOR</code> of all its elements. If the list only contains one element, then its <strong>XOR sum</strong> will be equal to this element.</p>

<ul>
	<li>For example, the <strong>XOR sum</strong> of <code>[1,2,3,4]</code> is equal to <code>1 XOR 2 XOR 3 XOR 4 = 4</code>, and the <strong>XOR sum</strong> of <code>[3]</code> is equal to <code>3</code>.</li>
</ul>

<p>You are given two <strong>0-indexed</strong> arrays <code>arr1</code> and <code>arr2</code> that consist only of non-negative integers.</p>

<p>Consider the list containing the result of <code>arr1[i] AND arr2[j]</code> (bitwise <code>AND</code>) for every <code>(i, j)</code> pair where <code>0 &lt;= i &lt; arr1.length</code> and <code>0 &lt;= j &lt; arr2.length</code>.</p>

<p>Return <em>the <strong>XOR sum</strong> of the aforementioned list</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,2,3], arr2 = [6,5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The list = [1 AND 6, 1 AND 5, 2 AND 6, 2 AND 5, 3 AND 6, 3 AND 5] = [0,1,2,0,2,1].
The XOR sum = 0 XOR 1 XOR 2 XOR 0 XOR 2 XOR 1 = 0.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr1 = [12], arr2 = [4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The list = [12 AND 4] = [4]. The XOR sum = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= arr1[i], arr2[j] &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

**Intuition**:

Consider case `A = [1, 2, 3], B = [6, 5]`.

We can first handle the subcase of `A = [1], B = [6, 5]`.

The result is `(001 AND 110) XOR (001 AND 101)`.

We can consider bit by bit. For the `0`-th (rightmost) bit, `A[0]` has `1` there, so we need to look at the `0`-th bits of `B[i]`.

Since there are odd number of `1`s (one `1` in this case), the result must have `1` in the `0`-th bit. If there are even number of `1`s, the result must have `0` in the `0`-th bit.

For the `1`st bit, `A[0]` has `0` there, so the result must have `0` in the `1`st bit.

And so on.

**Algorithm**: 

* Scan array `B`, compute a `cnt` array where `cnt[i]` is the number of bit `1`s at the `i`-th bit of all numbers in `B`.
* For each `a` in  array `A`, let `x` be the result of `(a AND B[0]) XOR (a AND B[1]) ...`:
  * If `a`'s `i`th bit is `0`, or `cnt[i] % 2 == 0`, then `x`'s `i`th bit must be `0`.
  * Otherwise `x`'s `i`-th bit must be `1`.
* The answer is the XOR result of all the `x` values.

```cpp
// OJ: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
class Solution {
public:
    int getXORSum(vector<int>& A, vector<int>& B) {
        int cnt[31] = {};
        for (int b : B) {
            for (int i = 0; i < 31; ++i) {
                cnt[i] += (b >> i & 1);
            }
        }
        int ans = 0;
        for (int a : A) {
            int x = 0;
            for (int i = 0; i < 31; ++i) {
                if ((a >> i & 1) == 0 || cnt[i] % 2 == 0) continue;
                x |= 1 << i;
            }
            ans ^= x;
        }
        return ans;
    }
};
```

## Solution 2.

Let `AND(i, j) = A[i] AND B[j]`. The answer is `XOR( AND(i, j) | 0 <= i < M, 0 <= j < N )`.

`AND(i, j)`'s `k`th bit is `1` if and only if `A[i]` and `B[j]` must be both `1` at the `k`th bit. Otherwise, `AND(i, j) = 0`.

Consider the `k`th bit of the answer, it's the XOR result of the `k`th bits of all `AND(i, j)`. So the `k`th bit of the answer is `1` if and only if there are odd number of `1`s of all `AND(i, j)` at `k`th bit.

Let `cnt1[k]` and `cnt2[k]` be the number of bit `1`s at `k`th bit in `A` and `B` respectively. Then `cnt1[k] * cnt2[k]` is the number of `1`s of all `AND(i, j)` at `k`th bit.

So, the `k`th bit of the answer is `1` if and only if `cnt1[k] * cnt2[k]` is an odd number, or in other words, `cnt1[k]` and `cnt2[k]` are both odd numbers.

```cpp
// OJ: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
class Solution {
public:
    int getXORSum(vector<int>& A, vector<int>& B) {
        int ans = 0;
        for  (int i = 0; i < 31; ++i) {
            int ca = 0, cb = 0;
            for (int n : A) ca += (n >> i & 1);
            for (int n : B) cb += (n >> i & 1);
            if (ca % 2 && cb % 2) ans |= 1 << i;
        }
        return ans;
    }
};
```

## Solution 3.

Similar to `(a + b) * (c + d) == a * c + a * d + b * c + b * d`, the following is also true:

`(a1 ^ a2) & (b1 ^ b2) == (a1 & b1) ^ (a1 & b2) ^ (a2 & b1) ^ (a2 & b2)`

We can prove this by the following reasoning:

* The answer's `k`th bit is `1`

If and only if

* `cnt1[k]` and `cnt2[k]` are both odd numbers

If and only if

* The XOR of all the `k`th bits in `A` is `1`. The same for `B`.

If and only if

* "The XOR of all the `k`th bits in `A`" AND "the XOR of all the `k`th bits in `B`" is `1`.

Hence, the proof is done.

Let `a` and `b` be the XOR of all the numbers in `A` and `B` respectively, the answer is `a & b`.



```cpp
// OJ: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
// Ref: https://leetcode-cn.com/problems/find-xor-sum-of-all-pairs-bitwise-and/solution/find-xor-sum-of-all-pairs-bitwise-and-by-sok6/
class Solution {
public:
    int getXORSum(vector<int>& A, vector<int>& B) {
        int a = 0, b = 0;
        for (int n : A) a ^= n;
        for (int n : B) b ^= n;
        return a & b;
    }
};
```