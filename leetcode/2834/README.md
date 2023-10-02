# [2834. Find the Minimum Possible Sum of a Beautiful Array (Medium)](https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array)

<p>You are given positive integers <code>n</code> and <code>target</code>.</p>
<p>An array <code>nums</code> is <strong>beautiful</strong> if it meets the following conditions:</p>
<ul>
	<li><code>nums.length == n</code>.</li>
	<li><code>nums</code> consists of pairwise <strong>distinct</strong> <strong>positive</strong> integers.</li>
	<li>There doesn't exist two <strong>distinct</strong> indices, <code>i</code> and <code>j</code>, in the range <code>[0, n - 1]</code>, such that <code>nums[i] + nums[j] == target</code>.</li>
</ul>
<p>Return <em>the <strong>minimum</strong> possible sum that a beautiful array could have</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 2, target = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can see that nums = [1,3] is beautiful.
- The array nums has length n = 2.
- The array nums consists of pairwise distinct positive integers.
- There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
It can be proven that 4 is the minimum possible sum that a beautiful array could have.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 3, target = 3
<strong>Output:</strong> 8
<strong>Explanation:</strong> We can see that nums = [1,3,4] is beautiful.
- The array nums has length n = 3.
- The array nums consists of pairwise distinct positive integers.
- There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
It can be proven that 8 is the minimum possible sum that a beautiful array could have.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> n = 1, target = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can see, that nums = [1] is beautiful.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= target &lt;= 10<sup>5</sup></code></li>
</ul>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans = 0, x = 1;
        unordered_set<int> ban;
        for (int i = 0; i < n; ++x) {
            if (ban.count(x)) continue;
            ans += x;
            ++i;
            if (target - x > x) ban.insert(target - x);
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans = 0;
        unordered_set<int> s;
        for (int x = 1; s.size() < n; ++x) {
            if (s.count(target - x)) continue;
            s.insert(x);
            ans += x;
        }
        return ans;
    }
};
```