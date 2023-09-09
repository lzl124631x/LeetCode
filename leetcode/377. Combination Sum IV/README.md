# [377. Combination Sum IV (Medium)](https://leetcode.com/problems/combination-sum-iv)

<p>Given an array of <strong>distinct</strong> integers <code>nums</code> and a target integer <code>target</code>, return <em>the number of possible combinations that add up to</em>&nbsp;<code>target</code>.</p>
<p>The test cases are generated so that the answer can fit in a <strong>32-bit</strong> integer.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3], target = 4
<strong>Output:</strong> 7
<strong>Explanation:</strong>
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [9], target = 3
<strong>Output:</strong> 0
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li>All the elements of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>
<p>&nbsp;</p>
<p><strong>Follow up:</strong> What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?</p>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)
* [Ways to Express an Integer as Sum of Powers (Medium)](https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/)

## Solution 1. DP Top-down

```cpp
// OJ: https://leetcode.com/problems/combination-sum-iv/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(T)
class Solution {
public:
    int combinationSum4(vector<int>& A, int target) {
        sort(begin(A), end(A));
        int N = A.size();
        unordered_map<int, int> m{{0, 1}};
        function<int(int)> dp = [&](int target) {
            if (m.count(target)) return m[target];
            int ans = 0;
            for (int i = 0; i < N && A[i] <= target; ++i) {
                ans += dp(target - A[i]);
            }
            return m[target] = ans;
        };
        return dp(target);
    }
};
```

## Solution 2. DP bottom-up

```cpp
// OJ: https://leetcode.com/problems/combination-sum-iv/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(T)
class Solution {
public:
    int combinationSum4(vector<int>& A, int target) {
        sort(begin(A), end(A));
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int n : A) {
                if (n > i) break;
                dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};
```