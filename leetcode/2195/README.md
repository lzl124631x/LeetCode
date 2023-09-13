# [2195. Append K Integers With Minimal Sum (Medium)](https://leetcode.com/problems/append-k-integers-with-minimal-sum/)

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. Append <code>k</code> <strong>unique positive</strong> integers that do <strong>not</strong> appear in <code>nums</code> to <code>nums</code> such that the resulting total sum is <strong>minimum</strong>.</p>

<p>Return<em> the sum of the</em> <code>k</code> <em>integers appended to</em> <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,4,25,10,25], k = 2
<strong>Output:</strong> 5
<strong>Explanation:</strong> The two unique positive integers that do not appear in nums which we append are 2 and 3.
The resulting sum of nums is 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70, which is the minimum.
The sum of the two integers appended is 2 + 3 = 5, so we return 5.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,6], k = 6
<strong>Output:</strong> 25
<strong>Explanation:</strong> The six unique positive integers that do not appear in nums which we append are 1, 2, 3, 4, 7, and 8.
The resulting sum of nums is 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36, which is the minimum. 
The sum of the six integers appended is 1 + 2 + 3 + 4 + 7 + 8 = 25, so we return 25.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
</ul>


**Similar Questions**:
* [Remove K Digits (Medium)](https://leetcode.com/problems/remove-k-digits/)
* [Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
* [Kth Missing Positive Number (Easy)](https://leetcode.com/problems/kth-missing-positive-number/)


## Solution 1. Sorting

**Intuition**: Sort the array. Traverse from left to right, sum up the missing numbers between `A[i-1]` and `A[i]` until we've used `k` missing numbers.

**Algorithm**:

For a given `A[i]`, the previous number `prev` is `A[i-1]` or `0` if `A[i-1]` doesn't exist.

There are `cnt = min(k, max(0, A[i] - prev - 1))` missing numbers inbetween, i.e. from `prev+1` to `prev+cnt`. The sum of these numbers is `(prev+1 + prev+cnt) * cnt / 2`.

If there are still `k` missing numbers after traversing the array, the rest of the missing numbers are `A[N-1]+1` to `A[N-1]+k`. The sum of them is `(A[N-1]+1 + A[N-1]+k) * k / 2`.

```cpp
// OJ: https://leetcode.com/problems/append-k-integers-with-minimal-sum/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    long long minimalKSum(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long ans = 0, N = A.size();
        for (int i = 0; i < N && k; ++i) {
            long prev = i == 0 ? 0 : A[i - 1]; // the previous number
            long cnt = min((long)k, max((long)0, A[i] - prev - 1)); // the count of missing numbers between `prev` and `A[i]`
            k -= cnt; // use these `cnt` missing numbers
            ans += (long)(prev + 1 + prev + cnt) * cnt / 2; // sum of these `cnt` missing numbers `[prev+1, prev+cnt]`.
        }
        if (k > 0) ans += ((long)A.back() + 1 + A.back() + k) * k / 2; // If there are still missing numbers, add the sum of numbers`[A.back()+1, A.back()+k]` to answer
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/append-k-integers-with-minimal-sum/discuss/1823619/