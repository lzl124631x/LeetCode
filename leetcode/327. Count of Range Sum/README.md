# [327. Count of Range Sum (Hard)](https://leetcode.com/problems/count-of-range-sum/)

<p>Given an integer array <code>nums</code>, return the number of range sums that lie in <code>[lower, upper]</code> inclusive.<br>
Range sum <code>S(i, j)</code> is defined as the sum of the elements in <code>nums</code> between indices <code>i</code> and <code>j</code> (<code>i</code> ≤ <code>j</code>), inclusive.</p>

<p><b>Note:</b><br>
A naive algorithm of <i>O</i>(<i>n</i><sup>2</sup>) is trivial. You MUST do better than that.</p>

<p><b>Example:</b></p>

<pre><strong>Input: </strong><i>nums</i> = <code>[-2,5,-1]</code>, <i>lower</i> = <code>-2</code>, <i>upper</i> = <code>2</code>,
<strong>Output: </strong>3 
<strong>Explanation: </strong>The three ranges are : <code>[0,0]</code>, <code>[2,2]</code>, <code>[0,2]</code> and their respective sums are: <code>-2, -1, 2</code>.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Sort](https://leetcode.com/tag/sort/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/)

**Similar Questions**:
* [Count of Smaller Numbers After Self (Hard)](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
* [Reverse Pairs (Hard)](https://leetcode.com/problems/reverse-pairs/)

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