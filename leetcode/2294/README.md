# [2294. Partition Array Such That Maximum Difference Is K (Medium)](https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k)

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. You may partition <code>nums</code> into one or more <strong>subsequences</strong> such that each element in <code>nums</code> appears in <strong>exactly</strong> one of the subsequences.</p>

<p>Return <em>the <strong>minimum </strong>number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is <strong>at most</strong> </em><code>k</code><em>.</em></p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,6,1,2,5], k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong>
We can partition nums into the two subsequences [3,1,2] and [6,5].
The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3], k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong>
We can partition nums into the two subsequences [1,2] and [3].
The difference between the maximum and minimum value in the first subsequence is 2 - 1 = 1.
The difference between the maximum and minimum value in the second subsequence is 3 - 3 = 0.
Since two subsequences were created, we return 2. Note that another optimal solution is to partition nums into the two subsequences [1] and [2,3].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,4,5], k = 0
<strong>Output:</strong> 3
<strong>Explanation:</strong>
We can partition nums into the three subsequences [2,2], [4], and [5].
The difference between the maximum and minimum value in the first subsequences is 2 - 2 = 0.
The difference between the maximum and minimum value in the second subsequences is 4 - 4 = 0.
The difference between the maximum and minimum value in the third subsequences is 5 - 5 = 0.
Since three subsequences were created, we return 3. It can be shown that 3 is the minimum number of subsequences needed.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Greedy](https://leetcode.com/tag/greedy), [Sorting](https://leetcode.com/tag/sorting)

**Similar Questions**:
* [Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit (Medium)](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit)
* [Maximum Beauty of an Array After Applying Operation (Medium)](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation)

**Hints**:
* Which values in each subsequence matter? The only values that matter are the maximum and minimum values.
* Let the maximum and minimum values of a subsequence be Max and Min. It is optimal to place all values in between Max and Min in the original array in the same subsequence as Max and Min.
* Sort the array.

## Solution 1. Sorting + Greedy

At first I thought about greedy. Use the first number to absort any numbers within range. For the rest numbers, repeat this process until no numbers are left.

But I can find a counter example: `A=[5,1,3,6], k=2`. `5` and `1` are not in range so they has to be in two subsequences, then where should `3` go? If `3` go with `5`, then `6` can't go with `5 3` subsequence. The best option is `(1,3), (5,6)`

This made me realize that I don't need to care about the order. Just sort the numbers, and from the smallest number, keep forming group of numbers within `k` range.

```cpp
// OJ: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int partitionArray(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int ans = 1;
        for (int i = 0, N = A.size(), start = A[0]; i < N; ++i) {
            if (A[i] - start > k) {
                ++ans;
                start = A[i];
            }
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int partitionArray(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int ans = 0;
        for (int i = 0, N = A.size(); i < N; ++ans) {
            i = upper_bound(begin(A), end(A), A[i] + k) - begin(A);
        }
        return ans;
    }
};
```