# [2425. Bitwise XOR of All Pairings (Medium)](https://leetcode.com/problems/bitwise-xor-of-all-pairings)

<p>You are given two <strong>0-indexed</strong> arrays, <code>nums1</code> and <code>nums2</code>, consisting of non-negative integers. There exists another array, <code>nums3</code>, which contains the bitwise XOR of <strong>all pairings</strong> of integers between <code>nums1</code> and <code>nums2</code> (every integer in <code>nums1</code> is paired with every integer in <code>nums2</code> <strong>exactly once</strong>).</p>
<p>Return<em> the <strong>bitwise XOR</strong> of all integers in </em><code>nums3</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums1 = [2,1,3], nums2 = [10,2,5,0]
<strong>Output:</strong> 13
<strong>Explanation:</strong>
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums1 = [1,2], nums2 = [3,4]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[j] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Trilogy](https://leetcode.com/company/trilogy)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Brainteaser](https://leetcode.com/tag/brainteaser/)

## Solution 1.

$$(a_0 \oplus b_0) \oplus (a_0 \oplus b_1) \cdots (a_0 \oplus b_{n-1})\newline
\oplus (a_1 \oplus b_0) \oplus (a_1 \oplus b_1) \cdots (a_1 \oplus b_{n-1})\newline
\cdots\newline
\oplus (a_{m-1} \oplus b_0) \oplus (a_{m-1} \oplus b_1) \cdots (a_{m-1} \oplus b_{n-1})$$
We regroup them as the following
$$ (a_0\oplus a_1 \cdots \oplus a_{m_1})^\oplus_{N} \oplus (b_0\oplus b_1 \cdots \oplus b_{n-1})^\oplus_{M}$$
where $x^\oplus_k$ means XORing `x` itself `k` times.

$(a_0\oplus a_1 \cdots \oplus a_{m_1})^\oplus_{N}$ equals $a_0\oplus a_1 \cdots \oplus a_{m_1}$ if $N$ is odd, or $0$ if $N$ is even.


```cpp
// OJ: https://leetcode.com/problems/bitwise-xor-of-all-pairings
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    int xorAllNums(vector<int>& A, vector<int>& B) {
        int ans = 0;
        if (B.size() % 2) {
            for (int n : A) ans ^= n;
        }
        if (A.size() % 2) {
            for (int n : B) ans ^= n;
        }
        return ans;
    }
};
```