# [198. House Robber (Medium)](https://leetcode.com/problems/house-robber/)

<p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and <b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p>

<p>Given an integer array <code>nums</code> representing the amount of money of each house, return <em>the maximum amount of money you can rob tonight <b>without alerting the police</b></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,7,9,3,1]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 400</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Cisco](https://leetcode.com/company/cisco), [Apple](https://leetcode.com/company/apple), [Adobe](https://leetcode.com/company/adobe), [Qualtrics](https://leetcode.com/company/qualtrics), [Arcesium](https://leetcode.com/company/arcesium), [Bloomberg](https://leetcode.com/company/bloomberg), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [ByteDance](https://leetcode.com/company/bytedance), [eBay](https://leetcode.com/company/ebay), [Flipkart](https://leetcode.com/company/flipkart), [PayTM](https://leetcode.com/company/paytm)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)
* [House Robber II (Medium)](https://leetcode.com/problems/house-robber-ii/)
* [Paint House (Medium)](https://leetcode.com/problems/paint-house/)
* [Paint Fence (Medium)](https://leetcode.com/problems/paint-fence/)
* [House Robber III (Medium)](https://leetcode.com/problems/house-robber-iii/)
* [Non-negative Integers without Consecutive Ones (Hard)](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)
* [Coin Path (Hard)](https://leetcode.com/problems/coin-path/)
* [Delete and Earn (Medium)](https://leetcode.com/problems/delete-and-earn/)

## Solution 1. DP

For `nums[i]`, we have two options, rob or skip.

Let `rob[i+1]` and `skip[i+1]` be the best outcome we can get with `house[0..i]` if we rob or skip the `house[i]` respectively.

```cpp
rob[i + 1] = nums[i] + skip[i] // If we rob at house[i], we must skip house[i-1]
skip[i + 1] = max(rob[i - 1], skip[i - 1]) // If we skip house[i], we can pick the maximum from robbing or skipping house[i-1]
```

```cpp
// OJ: https://leetcode.com/problems/house-robber/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int rob(vector<int>& A) {
        int N = A.size();
        vector<int> rob(N + 1), skip(N + 1);
        for (int i = 0; i < N; ++i) {
            rob[i + 1] = skip[i] + A[i];
            skip[i + 1] = max(skip[i], rob[i]);
        }
        return max(rob[N], skip[N]);
    }
};
```

**Space Optimization**:

Since `rob[i+1]` and `skip[i+1]` are only dependent on `rob[i]`  and `skip[i]`, we can reduce the space complexity to `O(1)` by only storing the current `rob` and `skip`.

So initially we have `rob = 0`, `skip = 0`, and for each `nums[i]`, we have 

```
rob2 = nums[i] + skip
skip2 = max(rob, skip)
```

Then we can assign `rob2` back to `rob`, and `skip2` back to `skip`.

```cpp
// OJ: https://leetcode.com/problems/house-robber/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int rob(vector<int>& A) {
        int rob = 0, skip = 0;
        for (int n : A) {
            int r = n + skip, s = max(rob, skip);
            rob = r, skip = s;
        }
        return max(rob, skip);
    }
};
```

Further more, since `skip` is the only one required by both `rob2` and `skip2`, we can do the following:

```
tmp = skip
skip = max(rob, skip)
rob = tmp + nums[i]
```

```cpp
// OJ: https://leetcode.com/problems/house-robber/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0, skip = 0;
        for (int n : nums) {
            int tmp = skip;
            skip = max(rob, skip);
            rob = tmp + n;
        }
        return max(rob, skip);
    }
};
```

## Solution 2. DP

Let `dp[i]` be the best outcome we can get at `nums[i]`.

```
dp[i] = max(
            dp[i - 1],             // skip the current house
            dp[i - 2] + nums[i]    // rob the current house
)
```

So `dp[i]` is only dependent on the previous 2 values. We can reduce the space complexity to `O(1)` by storing the previous two values:

```
cur = max(
            prev,
            prev2 + nums[i]
)
```

```cpp
// OJ: https://leetcode.com/problems/house-robber/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, prev2 = 0;
        for (int n : nums) {
            int cur = max(prev, prev2 + n);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};
```

```py
# OJ: https://leetcode.com/problems/house-robber/
# Author: github.com/lzl124631x
# Time: O(N)
# Space: O(1)
class Solution:
    def rob(self, nums: List[int]) -> int:
        prev, cur = 0, 0
        for n in nums: prev, cur = cur, max(cur, prev + n)
        return cur
```