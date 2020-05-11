# [1425. Constrained Subsequence Sum (Hard)](https://leetcode.com/problems/constrained-subsequence-sum/)

<p>Given an integer array&nbsp;<code>nums</code>&nbsp;and an integer <code>k</code>, return the maximum sum of a <strong>non-empty</strong> subsequence&nbsp;of that array such that for every&nbsp;two <strong>consecutive</strong> integers in the subsequence,&nbsp;<code>nums[i]</code>&nbsp;and&nbsp;<code>nums[j]</code>, where&nbsp;<code>i &lt; j</code>, the condition&nbsp;<code>j - i &lt;= k</code>&nbsp;is satisfied.</p>

<p>A&nbsp;<em>subsequence</em>&nbsp;of an array is&nbsp;obtained by deleting some number of elements (can be&nbsp;zero) from the array, leaving the remaining elements in their original order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [10,2,-10,5,20], k = 2
<strong>Output:</strong> 37
<b>Explanation:</b> The subsequence is [10, 2, 5, 20].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-1,-2,-3], k = 1
<strong>Output:</strong> -1
<b>Explanation:</b> The subsequence must be non-empty, so we choose the largest number.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [10,-2,-10,-5,20], k = 2
<strong>Output:</strong> 23
<b>Explanation:</b> The subsequence is [10, -2, -5, 20].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>-10^4&nbsp;&lt;= nums[i] &lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

If all the elements in `A` are zero or negative, the result is just the maximum value.

Otherwise, let `dp[i]` be the maximum result I can get on the subarray `A[0..i]` if I pick `A[i]`.

The result is `max(dp[i] | 0 <= i < N)`.

For `dp[i]`, since we picked `A[i]`, the previous pick must be one of `A[i-k]`, `A[i-k+1]`, ..., `A[i-1]`.

So `dp[i] = A[i] + max( dp[j] | i-k <= j < i )`.

Here is a TLE version.

```cpp
// OJ: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
// NOTE: this will get TLE
class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        int maxVal = *max_element(begin(A), end(A));
        if (maxVal <= 0) return maxVal;
        int N = A.size(), ans = 0;
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int mx = 0;
            for (int j = 1; j <= k; ++j) {
                if (i - j < 0) break;
                mx = max(mx, dp[i - j]);
            }
            dp[i] = mx + A[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

One optimization is that we can break the `j` loop once `A[i - j] > 0`, because further extending `j` won't give us better result.

```cpp
// OJ: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        int maxVal = *max_element(begin(A), end(A));
        if (maxVal <= 0) return maxVal;
        int N = A.size(), ans = 0;
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int mx = 0;
            for (int j = 1; j <= k; ++j) {
                if (i - j < 0) break;
                mx = max(mx, dp[i - j]);
                if (A[i - j] > 0) break;
            }
            dp[i] = mx + A[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

## Solution 2. DP + multiset

Same idea as Solution 1, here we use a `multiset` to prevent linear search of the maximum `dp` value.

```cpp
// OJ: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(N)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        int maxVal = *max_element(begin(A), end(A));
        if (maxVal <= 0) return maxVal;
        int N = A.size(), ans = 0;
        multiset<int> s{0};
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int sum = *s.rbegin() + A[i];
            if (i >= k) s.erase(s.find(dp[i - k]));
            s.insert(sum);
            dp[i] = sum;
            ans = max(ans, sum);
        }
        return ans;
    }
};
```

## Solution 3. DP + Monotonous Deque

Assume the `dp` values are `3, 1, 2`. Popping `3` will change the max value, but popping `1` won't. This tells us that we can just keep the `3, 2` `dp` sequence which forms a monotonically decreasing sequence.

We can store the indexes of these sequence in a `deque<int> mx`. `dp[mx.front()]` stores the maximum `dp` value within the `dp[i-k]` and `dp[i-1]` range.

`dp[i] = max(0, dp[mx.front()]) + A[i]`

Given `dp[i]`, we can pop those indexes in `mx` which are pointing to `dp` values that are smaller or equal to`dp[i]`.

Then we can push `i` into the `mx` deque.

Don't forget popping the out-of-range index, i.e. when `mx.front() === i - k - 1`, we should pop front.

```cpp
// OJ: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        int maxVal = *max_element(begin(A), end(A));
        if (maxVal <= 0) return maxVal;
        int N = A.size(), ans = 0;
        deque<int> mx;
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            if (mx.size() && mx.front() == i - k - 1) mx.pop_front();
            dp[i] = max(0, mx.size() ? dp[mx.front()] : 0) + A[i];
            while (mx.size() && dp[mx.back()] <= dp[i]) mx.pop_back();
            mx.push_back(i);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

## Solution 4. DP + Monotonous Deque
 
```cpp
// OJ: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
// Ref: https://leetcode.com/problems/constrained-subsequence-sum/discuss/597751/JavaC%2B%2BPython-O(N)-Decreasing-Deque
class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        deque<int> q;
        int ans = A[0];
        for (int i = 0; i < A.size(); ++i) {
            A[i] += q.size() ? q.front() : 0;
            ans = max(ans, A[i]);
            while (q.size() && A[i] > q.back()) q.pop_back();
            if (A[i] > 0) q.push_back(A[i]);
            if (i >= k && q.size() && q.front() == A[i - k]) q.pop_front();
        }
        return ans;
    }
};
```