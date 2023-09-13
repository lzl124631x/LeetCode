# [327. Count of Range Sum (Hard)](https://leetcode.com/problems/count-of-range-sum)

<p>Given an integer array <code>nums</code> and two integers <code>lower</code> and <code>upper</code>, return <em>the number of range sums that lie in</em> <code>[lower, upper]</code> <em>inclusive</em>.</p>
<p>Range sum <code>S(i, j)</code> is defined as the sum of the elements in <code>nums</code> between indices <code>i</code> and <code>j</code> inclusive, where <code>i &lt;= j</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [-2,5,-1], lower = -2, upper = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0], lower = 0, upper = 0
<strong>Output:</strong> 1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>-10<sup>5</sup> &lt;= lower &lt;= upper &lt;= 10<sup>5</sup></code></li>
	<li>The answer is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> integer.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/), [Merge Sort](https://leetcode.com/tag/merge-sort/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

**Similar Questions**:
* [Count of Smaller Numbers After Self (Hard)](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
* [Reverse Pairs (Hard)](https://leetcode.com/problems/reverse-pairs/)
* [Count the Number of Fair Pairs (Medium)](https://leetcode.com/problems/count-the-number-of-fair-pairs/)

## Solution 1. Divide and Conquer (Merge Sort)

Since we are discussing about range sum, we can start with prefix sum. We store the corresponding prefix sums into vector `sums`.

```
sums[j] - sums[i] = sum( nums[k] | i < k <= j )
```

Our goal now becomes finding the number of pairs `0 <= i < j <= N` that `lower <= sums[j] - sums[i] <= upper`.

For a given `i`, what's the time complexity to count all the `j`s that satisfy `i < j <= N` and `lower + sums[i] <= sums[j] <= upper + sums[i]`?

If the array is not sorted, we have to scan all the `j > i` which will take `O(N)` time.

But if the array is sorted, it will just take `O(logN)` time to count the `j`s. This implies that we can have an algorithm of time complexity `O(NlogN)`.

Now abstractly think `i` and `j` are in the left and right part of the `sum` array, respectively.

If both parts are sorted, then we just need `O(N)` time to count the valid pairs, because as `i` increments, `sums[i]` increases, and the valid range of `j` must increases as well. So we can use two pointers to find the valid range in the right part and these pointers always only increase.

Now this is very similar to a merge sort algorithm where we split the array into two parts, sort each part and merge them together in `O(N)` time.

```cpp
// OJ: https://leetcode.com/problems/count-of-range-sum/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    long sums[10001] = {}, tmp[10001] = {};
private:
    int countMergeSort(int start, int end, int lower, int upper) {
        if (start + 1 >= end) return 0; // we at least need two prefix sums to calculate the range sum.
        int mid = (start + end) / 2;
        int cnt = countMergeSort(start, mid, lower, upper)
                    + countMergeSort(mid, end, lower, upper);
        int s = mid, e = mid, j = mid, k = 0; // `s` points to the first good number in the right part
                                              // `e` points to the first number after the last good number in the right part
                                              // `j` points to the read position in the right part
                                              // `k` points to the write position in `tmp` array
        for (int i = start; i < mid; ++i, ++k) {
            while (s < end && sums[s] - sums[i] < lower) ++s; // the first good number
            while (e < end && sums[e] - sums[i] <= upper) ++e; // the next number after the last good number
            cnt += e - s;
            while (j < end && sums[j] < sums[i]) tmp[k++] = sums[j++]; // 
            tmp[k] = sums[i];
        }
        for (int i = 0; i < k; ++i) sums[start + i] = tmp[i]; // write back into `sums`
        return cnt;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int N = nums.size();
        for (int i = 0; i < N; ++i) sums[i + 1] = sums[i] + nums[i];
        return countMergeSort(0, N + 1, lower, upper);
    }
};
```

## Solution 2. Binary Indexed Tree

```cpp
// OJ: https://leetcode.com/problems/count-of-range-sum
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/count-of-range-sum/solutions/1462057
class BIT {
    vector<int> node;
    static inline int lb(int x) { return x & -x; }
public:
    BIT(int N) : node(N + 1) {}
    int query(int i) { // query(i) returns the count of numbers <= i
        int ans = 0;
        for (++i; i; i -= lb(i)) ans += node[i];
        return ans;
    }
    void update(int i, int delta) {
        for (++i; i < node.size(); i += lb(i)) node[i] += delta;
    }
};
class Solution {
public:
    int countRangeSum(vector<int>& A, int lower, int upper) {
        int N = A.size();
        vector<long long> sum(N + 1);
        map<long long, int> rank; // compress the range of numbers using rank.
        rank[0] = 0;
        for (int i = 0; i < N; ++i) {
            sum[i + 1] = sum[i] + A[i];
            rank[sum[i + 1]] = 0;
        }
        int k = 0;
        for (auto &[_, r] : rank) r = k++;
        BIT bit(k);
        bit.update(rank[0], 1);
        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            long long R = sum[i + 1] - lower;
            long long L = sum[i + 1] - upper;
            auto rit = rank.upper_bound(R);
            int ri = rit == rank.end() ? k : rit->second;
            auto lit = rank.lower_bound(L);
            int li = lit == rank.end() ? k : lit->second;
            ans += bit.query(ri - 1) - bit.query(li - 1); // count the numbers in range [li, ri - 1]
            bit.update(rank[sum[i + 1]], 1);
        }
        return ans;
    }
};
```