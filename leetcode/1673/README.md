# [1673. Find the Most Competitive Subsequence (Medium)](https://leetcode.com/problems/find-the-most-competitive-subsequence/)

<p>Given an integer array <code>nums</code> and a positive integer <code>k</code>, return <em>the most<strong> competitive</strong> subsequence of </em><code>nums</code> <em>of size </em><code>k</code>.</p>

<p>An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.</p>

<p>We define that a subsequence <code>a</code> is more <strong>competitive</strong> than a subsequence <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, subsequence <code>a</code> has a number <strong>less</strong> than the corresponding number in <code>b</code>. For example, <code>[1,3,4]</code> is more competitive than <code>[1,3,5]</code> because the first position they differ is at the final number, and <code>4</code> is less than <code>5</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,5,2,6], k = 2
<strong>Output:</strong> [2,6]
<strong>Explanation:</strong> Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,4,3,3,5,4,9,6], k = 4
<strong>Output:</strong> [2,3,3,4]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


**Companies**:  
[Dunzo](https://leetcode.com/company/dunzo)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

**Similar Questions**:
* [Remove K Digits (Medium)](https://leetcode.com/problems/remove-k-digits/)
* [Smallest Subsequence of Distinct Characters (Medium)](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)

## Solution 1. Mono-stack + Greedy

This problem is very similar to [402. Remove K Digits (Medium)](https://leetcode.com/problems/remove-k-digits/).

Since we are looking for the lexicographically **smallest** subsequence, we use mono-**increasing** stack.

For each `A[i]`, we pop back of `ans` if:
* There is delete allowance, i.e. `i - ans.size() < N - k`: `i - ans.size()` is the number of elements that we've already popped, and `N - k` is the number of elements that we need to remove. So if `i - ans < N - k`, we can continue popping.
* `ans.back()` is strictly greater than `A[i]`, i.e. `ans.size() && ans.back() > A[i]`.

We only push `A[i]` into `ans` when `ans.size() < k` i.e. there are not yet `k` elements selected.

```cpp
// OJ: https://leetcode.com/problems/find-the-most-competitive-subsequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& A, int k) {
        vector<int> ans;
        for (int i = 0, N = A.size(); i < N; ++i) {
            while (i - ans.size() < N - k && ans.size() && A[i] < ans.back()) ans.pop_back();
            if (ans.size() < k) ans.push_back(A[i]);
        }
        return ans;
    }
};
```