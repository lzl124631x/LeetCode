# [1664. Ways to Make a Fair Array (Medium)](https://leetcode.com/problems/ways-to-make-a-fair-array/)

<p>You are given an integer array&nbsp;<code>nums</code>. You can choose <strong>exactly one</strong> index (<strong>0-indexed</strong>) and remove the element. Notice that the index of the elements may change after the removal.</p>

<p>For example, if <code>nums = [6,1,7,4,1]</code>:</p>

<ul>
	<li>Choosing to remove index <code>1</code> results in <code>nums = [6,7,4,1]</code>.</li>
	<li>Choosing to remove index <code>2</code> results in <code>nums = [6,1,4,1]</code>.</li>
	<li>Choosing to remove index <code>4</code> results in <code>nums = [6,1,7,4]</code>.</li>
</ul>

<p>An array is <strong>fair</strong> if the sum of the odd-indexed values equals the sum of the even-indexed values.</p>

<p>Return the <em><strong>number</strong> of indices that you could choose such that after the removal, </em><code>nums</code><em> </em><em>is <strong>fair</strong>. </em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,6,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
Remove index 0: [1,6,4] -&gt; Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -&gt; Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -&gt; Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -&gt; Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong>&nbsp;You can remove any index and the remaining array is fair.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;You cannot make a fair array after removing any index.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Dunzo](https://leetcode.com/company/dunzo)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Left-to-Right State Transition (Prefix + Suffix)

**Intuition**: 

If we remove `A[i]`, then the parity of the indexes greater than `i` are all changed (even becomes odd and vice versa). 

```
[ left part ] A[i] [ right part ]
```

We can get the sum of even/odd numbers in the **right part** using the precomputed suffix sum, and get the sum of even/odd numbers in the **left part** by calculating prefix sum.

**Algorithm**:

Let `e[i]`/`o[i]` be the (suffix) sum of all even/odd numbers with index greater than and equal to `i`.

We precompute `e[i]` and `o[i]` first.

Then we can scan from left to right and compute the prefix sum of all even/odd numbers with indexes smaller than `i` on the fly, and save them in `even` and `odd`.

If we remove `A[i]`, then the sum of all the even numbers is `even + o[i + 1]`, and the sum of all odd numbers is `odd + e[i + 1]`.

```cpp
// OJ: https://leetcode.com/problems/ways-to-make-a-fair-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int waysToMakeFair(vector<int>& A) {
        int N = A.size(), even = 0, odd = 0, ans = 0;
        vector<int> e(N + 1), o(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            if (i % 2 == 0) e[i] += A[i];
            else o[i] += A[i];
            e[i] += e[i + 1];
            o[i] += o[i + 1];
        }
        for (int i = 0; i < N; ++i) {
            ans += (even + o[i + 1]) == (odd + e[i + 1]);
            if (i % 2 == 0) even += A[i];
            else odd += A[i];
        }
        return ans;
    }
};
```

## Solution 2. Left-to-right State Transition (Prefix + Suffix)

We can compute the suffix sums on the fly as well to save the extra space

```cpp
// OJ: https://leetcode.com/problems/ways-to-make-a-fair-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int waysToMakeFair(vector<int>& A) {
        int N = A.size(), evenPrefix = 0, oddPrefix = 0, evenSuffix = 0, oddSuffix = 0, ans = 0;
        for (int i = 0; i < N; ++i) {
            if (i % 2 == 0) evenSuffix += A[i];
            else oddSuffix += A[i];
        }
        for (int i = 0; i < N; ++i) {
            if (i % 2 == 0) evenSuffix -= A[i];
            else oddSuffix -= A[i];
            ans += (evenPrefix + oddSuffix) == (oddPrefix + evenSuffix);
            if (i % 2 == 0) evenPrefix += A[i];
            else oddPrefix += A[i];
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/ways-to-make-a-fair-array/discuss/944355/