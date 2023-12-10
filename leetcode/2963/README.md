# [2963. Count the Number of Good Partitions (Hard)](https://leetcode.com/problems/count-the-number-of-good-partitions)

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> consisting of <strong>positive</strong> integers.</p>

<p>A partition of an array into one or more <strong>contiguous</strong> subarrays is called <strong>good</strong> if no two subarrays contain the same number.</p>

<p>Return <em>the <strong>total number</strong> of good partitions of </em><code>nums</code>.</p>

<p>Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 8
<strong>Explanation:</strong> The 8 possible good partitions are: ([1], [2], [3], [4]), ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only possible good partition is: ([1,1,1,1]).
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The 2 possible good partitions are: ([1,2,1], [3]) and ([1,2,1,3]).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Similar Questions**:
* [Check if There is a Valid Partition For The Array (Medium)](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array)

**Hints**:
* If a segment contains a value, it must contain all occurrences of the same value.
* Partition the array into segments making each one as short as possible. This can be achieved by two-pointers or using a Set.
* If we have <code>m</code> segments, we can arbitrarily group the neighboring segments. How many ways are there to group these <code>m</code> segments?

# Solution 1. Count non-overlapping intervals

* Elements with the same value have to be included in the same subarray.
* For each element value, find their indices of their first and last occurrences. Each `{first, last}` forms an interval.
* Merge intervals if they are overlapping.
* If there are `n` non-overlapping intervals, there are $2^{n-1}$ ways to split the interval

```cpp
// OJ: https://leetcode.com/problems/count-the-number-of-good-partitions
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    long pow(long base, long exp, long mod) {
        long ans = 1;
        while (exp > 0) {
            if (exp & 1) ans = ans * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return ans;
    }
public:
    int numberOfGoodPartitions(vector<int>& A) {
        long mod = 1e9 + 7, N = A.size(), ans = 0, cnt = 0;
        typedef array<int, 2> PII; // index intervals {first, last}
        vector<PII> v; // array of intervals
        unordered_map<int, int> F, L; // mapping from A[i] to the index of its first/last occurrence
        for (int i = 0; i < N; ++i) {
            if (F.count(A[i]) == 0) F[A[i]] = i;
            L[A[i]] = i;
        }
        for (auto &[n, f] : F) v.push_back({f, L[n]});
        sort(begin(v), end(v)); // Sort intervals in ascending order
        int E = -1;
        for (auto &[begin, end] : v) { // Count of number of non-overlapping intervals
            if (begin > E) ++cnt;
            E = max(E, end);
        }
        return pow(2, cnt - 1, mod); // If there are `cnt` non-overlapping intervals, there are `2^{cnt-1}` ways to split the array.
    }
};
```