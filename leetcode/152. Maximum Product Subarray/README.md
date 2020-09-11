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

## Solution 1.

For each segments surrounded by `0`, we calculate the product of the segment. 

If the product is positive, we update the answer using the product of the entire segment.

If the product is negative, we can update the answer using:
* the product from the first element to the last element before the last negative number.
* the product from the first element after the first negative element to the last element.

```cpp
// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& A) {
        int N = A.size(), i = 0, ans = A[0];
        while (i < N) {
            if (A[i] == 0) {
                ans = max(ans, 0);
                ++i;
                continue;
            }
            int j = i, first = -1, last = -1, prod = 1;
            for (; i < N && A[i] != 0; ++i) {
                if (A[i] < 0) {
                    if (first == -1) first = i;
                    last = i;
                }
                prod *= A[i];
                ans = max(ans, prod);
            }
            if (prod < 0) {
                if (j < last) {
                    prod = 1;
                    for (int k = j; k < last; ++k) prod *= A[k];
                    ans = max(ans, prod);
                }
                if (first + 1 < i) {
                    prod = 1;   
                    for (int k = first + 1; k < i; ++k) prod *= A[k];
                    ans = max(ans, prod);
                }
            }
        }
        return ans;
    }
};
```

## Solution 1. Two Pointers

In fact, we don't care the number, we care the sign. The problem is the same as finding the longest subarray with even number negative numbers without 0.

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
    int maxProduct(vector<int>& A) {
        int ans = A[0], N = A.size(), j = 0;
        while (j < N) {
            int i = j, prod = 1;
            while (j < N && A[j] != 0) {
                prod *= A[j++];
                ans = max(ans, prod);
            }
            if (j < N) ans = max(ans, 0);
            while (i < N && prod < 0) {
                prod /= A[i++];
                if (i != j) ans = max(ans, prod);
            }
            while (j < N && A[j] == 0) ++j;
        }
        return ans;
    }
};
```

## Solution 2. DP

Let `max[i]` be the maximum product of subarrays ending at `A[i]`, `min[i]` be the minimum product of subarrays ending at `A[i]`.

```
max[i] = max(A[i], A[i] * max[i - 1], A[i] * min[i - 1])
min[i] = min(A[i], A[i] * max[i - 1], A[i] * min[i - 1])
```

```cpp
// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& A) {
        int maxProd = 1, minProd = 1, ans = INT_MIN;
        for (int n : A) {
            int a = n * maxProd, b = n * minProd;
            maxProd = max({n, a, b});
            minProd = min({n, a, b});
            ans = max(ans, maxProd);
        }
        return ans;
    }
};
```