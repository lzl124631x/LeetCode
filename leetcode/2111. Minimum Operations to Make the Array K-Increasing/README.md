# [2111. Minimum Operations to Make the Array K-Increasing (Hard)](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/)

<p>You are given a <strong>0-indexed</strong> array <code>arr</code> consisting of <code>n</code> positive integers, and a positive integer <code>k</code>.</p>

<p>The array <code>arr</code> is called <strong>K-increasing</strong> if <code>arr[i-k] &lt;= arr[i]</code> holds for every index <code>i</code>, where <code>k &lt;= i &lt;= n-1</code>.</p>

<ul>
	<li>For example, <code>arr = [4, 1, 5, 2, 6, 2]</code> is K-increasing for <code>k = 2</code> because:

	<ul>
		<li><code>arr[0] &lt;= arr[2] (4 &lt;= 5)</code></li>
		<li><code>arr[1] &lt;= arr[3] (1 &lt;= 2)</code></li>
		<li><code>arr[2] &lt;= arr[4] (5 &lt;= 6)</code></li>
		<li><code>arr[3] &lt;= arr[5] (2 &lt;= 2)</code></li>
	</ul>
	</li>
	<li>However, the same <code>arr</code> is not K-increasing for <code>k = 1</code> (because <code>arr[0] &gt; arr[1]</code>) or <code>k = 3</code> (because <code>arr[0] &gt; arr[3]</code>).</li>
</ul>

<p>In one <strong>operation</strong>, you can choose an index <code>i</code> and <strong>change</strong> <code>arr[i]</code> into <strong>any</strong> positive integer.</p>

<p>Return <em>the <strong>minimum number of operations</strong> required to make the array K-increasing for the given </em><code>k</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [5,4,3,2,1], k = 1
<strong>Output:</strong> 4
<strong>Explanation:
</strong>For k = 1, the resultant array has to be non-decreasing.
Some of the K-increasing arrays that can be formed are [5,<u><strong>6</strong></u>,<u><strong>7</strong></u>,<u><strong>8</strong></u>,<u><strong>9</strong></u>], [<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>1</strong></u>,1], [<u><strong>2</strong></u>,<u><strong>2</strong></u>,3,<u><strong>4</strong></u>,<u><strong>4</strong></u>]. All of them require 4 operations.
It is suboptimal to change the array to, for example, [<u><strong>6</strong></u>,<u><strong>7</strong></u>,<u><strong>8</strong></u>,<u><strong>9</strong></u>,<u><strong>10</strong></u>] because it would take 5 operations.
It can be shown that we cannot make the array K-increasing in less than 4 operations.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [4,1,5,2,6,2], k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong>
This is the same example as the one in the problem description.
Here, for every index i where 2 &lt;= i &lt;= 5, arr[i-2] &lt;=<b> </b>arr[i].
Since the given array is already K-increasing, we do not need to perform any operations.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [4,1,5,2,6,2], k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong>
Indices 3 and 5 are the only ones not satisfying arr[i-3] &lt;= arr[i] for 3 &lt;= i &lt;= 5.
One of the ways we can make the array K-increasing is by changing arr[3] to 4 and arr[5] to 5.
The array will now be [4,1,5,<u><strong>4</strong></u>,6,<u><strong>5</strong></u>].
Note that there can be other ways to make the array K-increasing, but none of them require less than 2 operations.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], k &lt;= arr.length</code></li>
</ul>


**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [Minimum Swaps To Make Sequences Increasing (Hard)](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/)

## Solution 1. Longest Increasing Subsequence (LIS)

Split the numbers in `A` into `k` groups: `[0, k, 2k, 3k, ...]`, `[1, 1+k, 1+2k, 1+3k, ...]`, ...

Compute the minimum operations needed to make a group non-decreasing. Assume the Longest Increasing Subsequence (LIS) of this group is of length `t`, and the group is of length `len`, then the minimum operations needed is `len - t`.

Computing the length of LIS is a classic problem that can be solved using binary search. See [300. Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)

The answer is the sum of minimum operations for all the groups.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/
// Author: github.com/lzl124631x
// Time: O(Nlog(N/k))
// Space: O(N/k)
class Solution {
public:
    int kIncreasing(vector<int>& A, int k) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < k; ++i) { // handle each group separately
            vector<int> lis{A[i]}; // the longest non-decreasing subsequence of this group
            int len = 1; // the length of this group
            for (int j = i + k; j < N; j += k, ++len) {
                auto i = upper_bound(begin(lis), end(lis), A[j]);
                if (i == end(lis)) lis.push_back(A[j]);
                else *i = A[j];
            }
            ans += len - lis.size();
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/discuss/1634980/C%2B%2B-Longest-Increasing-Subsequence