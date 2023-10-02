# [2104. Sum of Subarray Ranges (Medium)](https://leetcode.com/problems/sum-of-subarray-ranges/)

<p>You are given an integer array <code>nums</code>. The <strong>range</strong> of a subarray of <code>nums</code> is the difference between the largest and smallest element in the subarray.</p>

<p>Return <em>the <strong>sum of all</strong> subarray ranges of </em><code>nums</code><em>.</em></p>

<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [4,-2,-3,4,1]
<strong>Output:</strong> 59
<strong>Explanation:</strong> The sum of all subarray ranges of nums is 59.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Similar Questions**:
* [Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/)
* [Sum of Subarray Minimums (Medium)](https://leetcode.com/problems/sum-of-subarray-minimums/)
* [Number of Visible People in a Queue (Hard)](https://leetcode.com/problems/number-of-visible-people-in-a-queue/)
* [Count Number of Homogenous Substrings (Medium)](https://leetcode.com/problems/count-number-of-homogenous-substrings/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/sum-of-subarray-ranges/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    long long subArrayRanges(vector<int>& A) {
        long long ans = 0, N = A.size();
        for (int i = 0; i < N; ++i) {
            int mn = A[i], mx = A[i];
            for (int j = i; j < N; ++j) {
                mn = min(mn, A[j]);
                mx = max(mx, A[j]);
                ans += mx - mn;
            }
        }
        return ans;
    }
};
```

## Solution 2. Monotonic Stack

```cpp
// OJ: https://leetcode.com/problems/sum-of-subarray-ranges/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long subArrayRanges(vector<int>& A) {
        long long ans = 0, N = A.size();
        vector<int> prevLE(N, -1), nextLT(N, N), prevGE(N, -1), nextGT(N, N);
        stack<int> ins, des;
        for (int i = 0; i < N; ++i) {
            while (ins.size() && A[ins.top()] > A[i]) {
                nextLT[ins.top()] = i;
                ins.pop();
            }
            if (ins.size()) prevLE[i] = ins.top();
            ins.push(i);
            while (des.size() && A[des.top()] < A[i]) {
                nextGT[des.top()] = i;
                des.pop();
            }
            if (des.size()) prevGE[i] = des.top();
            des.push(i);
        }
        for (long i = 0; i < N; ++i) ans += A[i] * ((i - prevGE[i]) * (nextGT[i] - i) - (i - prevLE[i]) * (nextLT[i] - i));
        return ans;
    }
};
```

## TODO

https://leetcode.com/problems/sum-of-subarray-ranges/discuss/1624222/JavaC%2B%2BPython-O(n)-solution-detailed-explanation