# [53. Maximum Subarray (Easy)](https://leetcode.com/problems/maximum-subarray/)

<p>Given an integer array <code>nums</code>, find the contiguous subarray (containing at least one number) which has the largest sum and return <em>its sum</em>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> [4,-1,2,1] has the largest sum = 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [5,4,-1,7,8]
<strong>Output:</strong> 23
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution using the <strong>divide and conquer</strong> approach, which is more subtle.</p>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Adobe](https://leetcode.com/company/adobe), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [Cisco](https://leetcode.com/company/cisco), [Uber](https://leetcode.com/company/uber), [eBay](https://leetcode.com/company/ebay), [Intel](https://leetcode.com/company/intel), [Oracle](https://leetcode.com/company/oracle), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Facebook](https://leetcode.com/company/facebook), [Yahoo](https://leetcode.com/company/yahoo), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [JPMorgan](https://leetcode.com/company/jpmorgan), [ServiceNow](https://leetcode.com/company/servicenow), [Shopee](https://leetcode.com/company/shopee)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Best Time to Buy and Sell Stock (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* [Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)
* [Degree of an Array (Easy)](https://leetcode.com/problems/degree-of-an-array/)
* [Longest Turbulent Subarray (Medium)](https://leetcode.com/problems/longest-turbulent-subarray/)
* [Maximum Absolute Sum of Any Subarray (Medium)](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/)
* [Maximum Subarray Sum After One Operation (Medium)](https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/)

## Solution 1. Rolling Sum + Greedy

We can first get the rolling sum so that `sum[i] = nums[0] + ... + nums[i]`. With `partial_sum` we can do that in place.

Then this problem is almost the same as [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) -- finding the maximum `sum[j] - sum[i]` where `j > i`. The only difference is that the sub array can start at index `0`, so we also need to take `sum[i]` where `0 <= i < N` into consideration. So the "minimum sum we've seen so far" should be initialized as 0. 

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        int minSum = 0, ans = INT_MIN;
        for (int n : nums) {
            ans = max(ans, n - minSum);
            minSum = min(minSum, n);
        }
        return ans;
    }
};
```

Or 

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int mn = 0, sum = 0, ans = INT_MIN;
        for (int n : A) {
            sum += n;
            ans = max(ans, sum - mn);
            mn = min(mn, sum);
        }
        return ans;
    }
};
```

## Solution 2. DP

Let `dp[i + 1]` be the sum of maximum subarray ending with `nums[i]`.

```
dp[i + 1] = max{
                dp[i] + A[i],   if dp[i] > 0
                A[i]            if dp[i] <= 0
            }
```

Or

```
dp[i + 1] = max(dp[i], 0) + A[i]
```

Where `0 <= i < N`. Note that we can set `dp[0] = 0` so that the equation stay true for `i = 0`.

The result is `max{ dp[1], ..., dp[N] }`.

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, N = nums.size();
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < N; ++i) ans = max(ans, dp[i + 1] = max(dp[i], 0) + nums[i]);
        return ans;
    }
};
```

## Solution 3. DP

We can optimize Solution 2 by storing `dp` in `nums` so that the space complexity is reduced from `O(N)` to `O(1)`.

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += max(nums[i - 1], 0);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
```

## Solution 4. DP

What if we are not allowed th change the value in `nums` array?

Since `dp[i+1]` is only dependent on `dp[i]`, we can use `O(1)` space to store `dp` array -- only store the last value.

So we put the maximum subarray sum we've seen thus far into the `cur` variable. When we need to update `cur` for the current `nums[i]`, we can simply do `cur = max(cur, 0) + n`.

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, cur = INT_MIN;
        for (int n : nums) {
            cur = max(cur, 0) + n;
            ans = max(ans, cur);
        }
        return ans;
    }
};
```

## Solution 5. Divide and Conquer

See details [here](https://leetcode.com/problems/maximum-subarray/solution/)

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(logN)
class Solution {
private:
    int crossSum(vector<int>& nums, int L, int R, int p) {
        if (L == R) return nums[L];
        int left = INT_MIN, right = INT_MIN, i, sum;
        for (i = p, sum = 0; i >= L; --i) left = max(left, sum += nums[i]);
        for (i = p + 1, sum = 0; i <= R; ++i) right = max(right, sum += nums[i]);
        return left + right;
    }
    
    int helper(vector<int>& nums, int L, int R) {
        if (L == R) return nums[L];
        int p = (L + R) / 2;
        int left = helper(nums, L, p);
        int right = helper(nums, p + 1, R);
        int cross = crossSum(nums, L, R, p);
        return max(left, max(right, cross));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
```