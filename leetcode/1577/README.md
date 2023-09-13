# [1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers (Medium)](https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/)

<p>Given two arrays of integers&nbsp;<code>nums1</code> and <code>nums2</code>, return the number of triplets formed (type 1 and type 2) under the following rules:</p>

<ul>
	<li>Type 1: Triplet (i, j, k)&nbsp;if <code>nums1[i]<sup>2</sup>&nbsp;== nums2[j] * nums2[k]</code> where <code>0 &lt;= i &lt; nums1.length</code> and <code>0 &lt;= j &lt; k &lt; nums2.length</code>.</li>
	<li>Type 2:&nbsp;Triplet (i, j, k) if <code>nums2[i]<sup>2</sup>&nbsp;== nums1[j] * nums1[k]</code> where <code>0 &lt;= i &lt; nums2.length</code> and <code>0 &lt;= j &lt; k &lt; nums1.length</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [7,4], nums2 = [5,2,8,9]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Type 1: (1,1,2), nums1[1]^2 = nums2[1] * nums2[2]. (4^2 = 2 * 8). 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,1], nums2 = [1,1,1]
<strong>Output:</strong> 9
<strong>Explanation:</strong> All Triplets are valid, because 1^2 = 1 * 1.
Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2).  nums1[i]^2 = nums2[j] * nums2[k].
Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]^2 = nums1[j] * nums1[k].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums1 = [7,7,8,3], nums2 = [1,2,9,7]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 valid triplets.
Type 1: (3,0,2).  nums1[3]^2 = nums2[0] * nums2[2].
Type 2: (3,0,1).  nums2[3]^2 = nums1[0] * nums1[1].
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no valid triplets.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

Type 1 and Type 2 are symmetrical so we can define a function `count(A, B)` which returns the count of the Type 1 triples. The answer is `count(A, B) + count(B, A)`.

For `count(A, B)`, we can use a `unordered_map<int, int> m` to store the frequency of the numbers in `B`. Then for each number `a` in `A`, the `target` value is `a * a`. We traverse the map `m` to count the triplets.

For each entry `(b, cnt)` in `m`:
* If `target` is not divisible by `b` or `target / b` is not in `m`, there is no triplets, skip.
* If `target / b == b`, we need to pick 2 out of `cnt` numbers so we can add `cnt * (cnt - 1)` triplets to the answer.
* Otherwise, we can add `cnt * m[target / b]` triplets to the answer.

Since we count the the pairs in `B` twice, we need to divide the answer by 2 before returning.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    int count(vector<int> &A, vector<int> &B) {
        int ans = 0;
        unordered_map<int, int> m;
        for (int n : B) m[n]++;
        for (int a : A) {
            long target = (long)a * a;
            for (auto &[b, cnt] : m) {
                if (target % b || m.count(target / b) == 0) continue;
                if (target / b == b) ans += cnt * (cnt - 1);
                else ans += cnt * m[target / b];
            }
        }
        return ans / 2;
    }
public:
    int numTriplets(vector<int>& A, vector<int>& B) {
        return count(A, B) + count(B, A);
    }
};
```