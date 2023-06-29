# [2597. The Number of Beautiful Subsets (Medium)](https://leetcode.com/problems/the-number-of-beautiful-subsets)

<p>You are given an array <code>nums</code> of positive integers and a <strong>positive</strong> integer <code>k</code>.</p>

<p>A subset of <code>nums</code> is <strong>beautiful</strong> if it does not contain two integers with an absolute difference equal to <code>k</code>.</p>

<p>Return <em>the number of <strong>non-empty beautiful </strong>subsets of the array</em> <code>nums</code>.</p>

<p>A <strong>subset</strong> of <code>nums</code> is an array that can be obtained by deleting some (possibly none) elements from <code>nums</code>. Two subsets are different if and only if the chosen indices to delete are different.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,4,6], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1], k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 20</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Construct the Lexicographically Largest Valid Sequence (Medium)](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/)

## Solution 1. Backtracking

The brute force way is to generate `2^N-1` non-empty subsets using DFS, and check each one of them are valid, taking `O(2^N * N)` time.

There are lots of unnecessary checks. For example, if the subset already contains conflicts, all the subsequently generated subsets won't be valid.

So, we can use backtracking to skip those cases.

```cpp
// OJ: https://leetcode.com/problems/the-number-of-beautiful-subsets
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    int beautifulSubsets(vector<int>& A, int k) {
        int ans = 0, cnt[1001] = {}, used[1001] = {}, i = 0;
        for (int i : A) cnt[i]++;
        sort(begin(A), end(A));
        auto last = unique(begin(A), end(A));
        A.erase(last, end(A));
        function<void(int,int)> dfs = [&](int i, int c) {
            if (i == A.size()) {
                ans += c; 
                return;
            }
            if (A[i] - k <= 0 || !used[A[i] - k]) { // use A[i]
                used[A[i]] = 1;
                dfs(i + 1, c * ((1 << cnt[A[i]]) - 1));
                used[A[i]] = 0;
            }
            dfs(i + 1, c); // don't use A[i]
        };
        dfs(0, 1);
        return ans - 1;
    }
};
```