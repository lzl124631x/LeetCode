# [1755. Closest Subsequence Sum (Hard)](https://leetcode.com/problems/closest-subsequence-sum/)

<p>You are given an integer array <code>nums</code> and an integer <code>goal</code>.</p>

<p>You want to choose a subsequence of <code>nums</code> such that the sum of its elements is the closest possible to <code>goal</code>. That is, if the sum of the subsequence's elements is <code>sum</code>, then you want to <strong>minimize the absolute difference</strong> <code>abs(sum - goal)</code>.</p>

<p>Return <em>the <strong>minimum</strong> possible value of</em> <code>abs(sum - goal)</code>.</p>

<p>Note that a subsequence of an array is an array formed by removing some elements <strong>(possibly all or none)</strong> of the original array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [5,-7,3,5], goal = 6
<strong>Output:</strong> 0
<strong>Explanation:</strong> Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [7,-9,15,-2], goal = -5
<strong>Output:</strong> 1
<strong>Explanation:</strong> Choose the subsequence [7,-9,-2], with a sum of -4.
The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3], goal = -7
<strong>Output:</strong> 7
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 40</code></li>
	<li><code>-10<sup>7</sup> &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= goal &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Sprinklr](https://leetcode.com/company/sprinklr)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Bitmask](https://leetcode.com/tag/bitmask/)

**Similar Questions**:
* [Minimize the Difference Between Target and Chosen Elements (Medium)](https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/)
* [Partition Array Into Two Arrays to Minimize Sum Difference (Hard)](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/closest-subsequence-sum
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    int minAbsDifference(vector<int>& ns, int goal) {
        int res = abs(goal), pos = 0, neg = 0;
        for (auto n : ns)
            pos += max(0, n), neg += min(0, n);
        if (goal < neg || goal > pos)
            return min(abs(neg - goal), abs(goal - pos));
        set<int> h1{0}, h2{0};
        for (auto i = 0; i < ns.size() / 2; ++i)
            for (auto n : vector<int>(begin(h1), end(h1)))
                if (h1.insert(n + ns[i]).second)
                    res = min(res, abs(goal - n - ns[i]));
        for (auto i = ns.size() / 2; i < ns.size(); ++i)
            for (auto n : vector<int>(begin(h2), end(h2)))
                if (h2.insert(n + ns[i]).second) {
                    auto it = h1.lower_bound(goal - n - ns[i]);
                    if (it != end(h1))
                        res = min(res, abs(goal - n - ns[i] - *it));
                    if (it != begin(h1))
                        res = min(res, abs(goal - n - ns[i] - *prev(it)));
                    if (res == 0)
                        return res;
                }
        return res;
    }
};
```