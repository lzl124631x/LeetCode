# [2025. Maximum Number of Ways to Partition an Array (Hard)](https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code>. The number of ways to <strong>partition</strong> <code>nums</code> is the number of <code>pivot</code> indices that satisfy both conditions:</p>

<ul>
	<li><code>1 &lt;= pivot &lt; n</code></li>
	<li><code>nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]</code></li>
</ul>

<p>You are also given an integer <code>k</code>. You can choose to change the value of <strong>one</strong> element of <code>nums</code> to <code>k</code>, or to leave the array <strong>unchanged</strong>.</p>

<p>Return <em>the <strong>maximum</strong> possible number of ways to <strong>partition</strong> </em><code>nums</code><em> to satisfy both conditions after changing <strong>at most</strong> one element</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,-1,2], k = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> One optimal approach is to change nums[0] to k. The array becomes [<strong><u>3</u></strong>,-1,2].
There is one way to partition the array:
- For pivot = 2, we have the partition [3,-1 | 2]: 3 + -1 == 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,0], k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> The optimal approach is to leave the array unchanged.
There are two ways to partition the array:
- For pivot = 1, we have the partition [0 | 0,0]: 0 == 0 + 0.
- For pivot = 2, we have the partition [0,0 | 0]: 0 + 0 == 0.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14], k = -33
<strong>Output:</strong> 4
<strong>Explanation:</strong> One optimal approach is to change nums[2] to k. The array becomes [22,4,<u><strong>-33</strong></u>,-20,-15,15,-16,7,19,-10,0,-13,-14].
There are four ways to partition the array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= k, nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Partition Equal Subset Sum (Medium)](https://leetcode.com/problems/partition-equal-subset-sum/)
* [Partition to K Equal Sum Subsets (Medium)](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)

## Solution 1. Frequency Map

Given array `A`, we can compute an array `diff` where `diff[i] = (A[0] + .. + A[i-1]) - (A[i] + .. + A[N-1])` (`1 <= i < N`), i.e. sum of left part minus sum of right part.

If we don't do any replacement, the answer is the number of `0`s in the `diff` array.

If we replace `A[i]` with `k`, then `diff[1]` to `diff[i]` decrease by `d`, and `diff[i+1]` to `diff[N-1]` increase by `d`, where `d = k - A[i]`. Again, the answer is the number of `0`s in this new `diff` array.

Instead of changing the `diff` array (taking `O(N)` time), we can simply count the number of `d` in `diff[1..i]` and number of `-d` in `diff[(i+1)..(N-1)]` (taking `O(1)` time).

So, we can use two frequency maps `L` and `R` which are the frequency maps of `diff[1..i]` and `diff[(i+1)..(N-1)]` respectively.

We scan from left to right. For each `A[i]`, we try to update `ans` with `L[d] + R[-d]` where `d = k - A[i]`, and update the frequency maps.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int waysToPartition(vector<int>& A, int k) {
        long sum = accumulate(begin(A), end(A), 0L), N = A.size();
        unordered_map<long, int> L, R;
        for (long i = 0, left = 0; i < N - 1; ++i) {
            left += A[i];
            long right = sum - left;
            R[left - right]++;
        }
        int ans = R[0]; // If we don't do any replacement, answer is the number of `0`s in the frequency map
        for (long i = 0, left = 0; i < N; ++i) {
            left += A[i];
            long right = sum - left, d = k - A[i];
            ans = max(ans, L[d] + R[-d]); // If we replace `A[i]` with `k`, we will get `L[d] + R[-d]` pivots
            R[left - right]--; // transfer the frequency from `R` to `L`.
            L[left - right]++;
        }
        return ans;
    }
};
```

Example: 

```plaintext
A =            [2, -1,  2]
diff =         [_,  1, -1]
```

If we change the `diff` array.

```plaintext
// replace A[0] with 3
A =            [3, -1,  2]
diff change        +1  +1
diff =         [_,  2,  0]

// replace A[1] with 3
A =            [2,  3,  2]
diff change        -4  +4
diff =         [_, -3,  3]

// replace A[2] with 3
A =            [2, -1,  3]
diff change        -1  -1 
diff =         [_,  0, -2]
```

If we use frequency maps:
```plaintext
diff =         [_,  1, -1]

// If we don't do any replacement
               [_ | 1,  -1]
answer = R[0] = 0

// replace A[0] with 3, d = 1
               [_ | 1,  -1]
answer = L[1] + R[-1] = 0 + 1 = 1

// replace A[1] with 3, d = 4
               [_  1 | -1]
answer = L[4] + R[-4] = 0 + 0 = 0

// replace A[2] with 3, d = 1
               [_  1  -1 |]
answer = L[1] + R[-1] = 1 + 0 = 1
```

## Discuss

https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/discuss/1499365/C%2B%2B-Frequency-Map-O(N)