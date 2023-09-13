# [1283. Find the Smallest Divisor Given a Threshold (Medium)](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)

<p>Given an array of integers <code>nums</code> and an integer <code>threshold</code>, we will choose a positive integer divisor and&nbsp;divide&nbsp;all the array by it and sum the result of the division. Find the <strong>smallest</strong> divisor such that the result mentioned above is less than&nbsp;or equal to <code>threshold</code>.</p>

<p>Each&nbsp;result of&nbsp;division is rounded&nbsp;to the nearest integer greater than or equal to that element.&nbsp;(For example: 7/3 = 3 and 10/2 = 5).</p>

<p>It is guaranteed that there will be an answer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,5,9], threshold = 6
<strong>Output:</strong> 5
<strong>Explanation:</strong> We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,5,7,11], threshold = 11
<strong>Output:</strong> 3
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [19], threshold = 5
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^6</code></li>
	<li><code>nums.length &lt;=&nbsp;threshold &lt;= 10^6</code></li>
</ul>

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Author: github.com/lzl124631x
// Time: O(Nlog(max(A)))
// Space: O(1)
class Solution {
    bool valid(vector<int> &A, int d, int threshold) {
        for (int n : A) {
            if ((threshold -= (n + d - 1) / d) < 0) return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& A, int threshold) {
        int L = 1, R = 1e6;
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(A, M, threshold)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```