# [2031. Count Subarrays With More Ones Than Zeros (Medium)](https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/)

<p>You are given a binary array <code>nums</code> containing only the integers <code>0</code> and <code>1</code>. Return<em> the number of <strong>subarrays</strong> in nums that have <strong>more</strong> </em><code>1</code>'<em>s than </em><code>0</code><em>'s. Since the answer may be very large, return it <strong>modulo</strong> </em><code>10<sup>9</sup> + 7</code>.</p>

<p>A <strong>subarray</strong> is a contiguous sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,1,0,1]
<strong>Output:</strong> 9
<strong>Explanation:</strong>
The subarrays of size 1 that have more ones than zeros are: [1], [1], [1]
The subarrays of size 2 that have more ones than zeros are: [1,1]
The subarrays of size 3 that have more ones than zeros are: [0,1,1], [1,1,0], [1,0,1]
The subarrays of size 4 that have more ones than zeros are: [1,1,0,1]
The subarrays of size 5 that have more ones than zeros are: [0,1,1,0,1]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No subarrays have more ones than zeros.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The subarrays of size 1 that have more ones than zeros are: [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/), [Merge Sort](https://leetcode.com/tag/merge-sort/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

**Similar Questions**:
* [Ones and Zeroes (Medium)](https://leetcode.com/problems/ones-and-zeroes/)
* [Longer Contiguous Segments of Ones than Zeros (Easy)](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/)

## Solution 1.

```
index:     0  1  2  3  4
A:         0  1  1  0  1
Diff:   0 -1  0  1  0  1 // Count(1) - Count(0)
Count:     0 +1 +3 +1 +4 // Sum of number of diffs less than the current diff.
```

Let `diff[i]` be the count of `1`s minus count of `0`s before `A[i]` inclusive.

For each `A[i]`, it will add "sum of number of diffs less than the current diff" to the answer.

So we need a data structure with which we can query a range sum. Segment tree and Binary Indexed Tree are good for this purpose.

This implementation uses BIT.

```cpp
// OJ: https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/discuss/1512961/BIT-vs.-O(n)
const int N = 200000, mod = 1e9 + 7;
int bt[N + 1] = {};
class Solution {
    int sum(int i) {
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans += bt[i];
        return ans;
    }
    void update(int i, int val) {
        for (++i; i <= N; i += i & -i) bt[i] += val;
    }
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& A) {
        int ans = 0, diff = 0;
        memset(bt, 0, sizeof(bt));
        update(N / 2, 1);
        for (int n : A) {
            diff += n ? 1 : -1;
            update(N / 2 + diff, 1);
            ans = (ans + sum(N / 2 + diff - 1)) % mod;
        }
        return ans;
    }
};
```

## Solution 2. Divide and Conquer (Merge Sort)

```cpp
// OJ: https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& A) {
        vector<int> diff(A.size() + 1), tmp(A.size() + 1);
        for (int i = 0, d = 0; i < A.size(); ++i) {
            d += A[i] == 1 ? 1 : -1;
            diff[i + 1] = d;
        }
        function<int(int, int)> mergeSort = [&](int begin, int end) -> int {
            if (begin + 1 >= end) return 0;
            long mid = (begin + end) / 2, mod = 1e9 + 7, ans = (mergeSort(begin, mid) + mergeSort(mid, end)) % mod;
            for (int i = begin, j = mid, k = begin; i < mid || j < end; ++k) {
                if (j == end || (i < mid && diff[i] < diff[j])) tmp[k] = diff[i++];
                else {
                    ans = (ans + i - begin) % mod;
                    tmp[k] = diff[j++];
                }
            }
            for (int i = begin; i < end; ++i) diff[i] = tmp[i];
            return ans;
        };
        return mergeSort(0, diff.size());
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/discuss/1512961/BIT-vs.-O(n)
const int N = 200000, mod = 1e9 + 7;
int bt[N + 1] = {};
class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& A) {
        int ans = 0, diff = 0, cnt = 0;
        memset(bt, 0, sizeof(bt));
        bt[N / 2] = 1;
        for (int n : A) {
            diff += n ? 1 : -1;
            cnt += n ? bt[N / 2 + diff - 1] : -bt[N / 2 + diff];
            ans = (ans + cnt) % mod;
            ++bt[N / 2 + diff];
        }
        return ans;
    }
};
```

## TODO

Add notes to Solution 1 and 3.