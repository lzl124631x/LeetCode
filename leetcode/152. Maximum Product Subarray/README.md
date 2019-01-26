# [152. Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)

<p>Given an integer array&nbsp;<code>nums</code>, find the contiguous subarray within an array (containing at least one number) which has the largest product.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [2,3,-2,4]
<strong>Output:</strong> <code>6</code>
<strong>Explanation:</strong>&nbsp;[2,3] has the largest product 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [-2,0,-1]
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;The result cannot be 2, because [-2,-1] is not a subarray.</pre>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Maximum Subarray (Easy)](https://leetcode.com/problems/maximum-subarray/)
* [House Robber (Easy)](https://leetcode.com/problems/house-robber/)
* [Product of Array Except Self (Medium)](https://leetcode.com/problems/product-of-array-except-self/)
* [Maximum Product of Three Numbers (Easy)](https://leetcode.com/problems/maximum-product-of-three-numbers/)
* [Subarray Product Less Than K (Medium)](https://leetcode.com/problems/subarray-product-less-than-k/)

## Solution 1. Two Pointers

In facrt, we don't care the number, we care the sign. The problem is the same as finding the longest subarray with even number negative numbers without 0.

We can use two pointers.
* the fast pointer keeps reading number until it reaches 0 or end of array; meanwhile, we keep updating answer with the greatest product we've seen.
* if the product is negative, we move the slow pointer until the product becomes positive or slow pointer equals fast pointer - 1 (the product at least contains one number), and update the answer if it's greater.
* we move both pointers to the next non-zero number and continue to above algorithm.

```cpp
// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, N = nums.size(), prod = 1;
        for (int i = 0, j = 0; j < N; ) {
            while (j < N && nums[j]) {
                prod *= nums[j++];
                ans = max(ans, prod);
            }
            while (prod < 0 && i < j - 1) {
                prod /= nums[i++];
                ans = max(ans, prod);
            }
            while (j < N && !nums[j]) {
                i = ++j;
                ans = max(ans, 0);
                prod = 1;
            }
        }
        return ans;
    }
};
```

## Solution 2. Greedy

Consider a similar problem with more restriction: find the maximum product subarray of `A_1...A_n` that must ends with `An`.

Assume the product of the answer is `F(A_1...A_n)`, and the product of the corresponding minimum product subarray is `G(A_1...A_n)`.

`F(A_1...A_n)` is the greatest one of:
* `F(A_1...A_(n-1)) * A_n`
* `G(A_1...A_(n-1)) * A_n`
* `A_n`

So we can keep computing `F` and `G` and the answer is the max `F` we've seen.

```cpp
// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = 1, minProd = 1, ans = INT_MIN;
        for (int n : nums) {
            int maxP = max(max(maxProd * n, minProd * n), n);
            int minP = min(min(maxProd * n, minProd * n), n);
            maxProd = maxP;
            minProd = minP;
            ans = max(ans, maxProd);
        }
        return ans;
    }
};
```