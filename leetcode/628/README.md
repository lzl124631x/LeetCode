# [628. Maximum Product of Three Numbers (Easy)](https://leetcode.com/problems/maximum-product-of-three-numbers/)

<p>Given an integer array, find three numbers whose product is maximum and output the maximum product.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> [1,2,3]
<b>Output:</b> 6
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [1,2,3,4]
<b>Output:</b> 24
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The length of the given array will be in range [3,10<sup>4</sup>] and all elements are in the range [-1000, 1000].</li>
	<li>Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.</li>
</ol>

<p>&nbsp;</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& A) {
        sort(begin(A), end(A));
        return A.back() * max(A[A.size() - 2] * A[A.size() - 3], A[0] * A[1]);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& A) {
        vector<int> maxVals(3, INT_MIN), minVals(2, INT_MAX);
        for (int n : A) {
            for (int i = 0; i < 3; ++i) {
                if (n <= maxVals[i]) continue;
                for (int j = 2; j > i; --j) maxVals[j] = maxVals[j - 1];
                maxVals[i] = n;
                break;
            }
            for (int i = 0; i < 2; ++i) {
                if (n >= minVals[i]) continue;
                for (int j = 1; j > i; --j) minVals[j] = minVals[j - 1];
                minVals[i] = n;
                break;
            }
        }
        return maxVals[0] * max(maxVals[1] * maxVals[2], minVals[0] * minVals[1]);
    }
};
```