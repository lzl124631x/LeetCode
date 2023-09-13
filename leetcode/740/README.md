# [740. Delete and Earn (Medium)](https://leetcode.com/problems/delete-and-earn/)

<p>You are given an integer array <code>nums</code>. You want to maximize the number of points you get by performing the following operation any number of times:</p>

<ul>
	<li>Pick any <code>nums[i]</code> and delete it to earn <code>nums[i]</code> points. Afterwards, you must delete <b>every</b> element equal to <code>nums[i] - 1</code> and <strong>every</strong> element equal to <code>nums[i] + 1</code>.</li>
</ul>

<p>Return <em>the <strong>maximum number of points</strong> you can earn by applying the above operation some number of times</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,4,2]
<strong>Output:</strong> 6
<strong>Explanation:</strong> You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,3,3,3,4]
<strong>Output:</strong> 9
<strong>Explanation:</strong> You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [House Robber (Medium)](https://leetcode.com/problems/house-robber/)

## Solution 1. DP

Firstly, to avoid duplicate, store the data in a map from the number to its count.

Let `dp[i]` be the max point you can get at point `i`.

If `num != prevNum + 1`, we can freely pick `num`, then `dp[i] = dp[i-1] + num * count`.

Otherwise:
* If we skip `num`, `dp[i] = dp[i-1]`.
* If we pick `num`, `dp[i] = dp[i-2] + num * count`.

So in sum:

```
dp[i] = num == prevNum ? max(dp[i-1], dp[i-2] + num * count) : (dp[i-1] + num * count)
```

```cpp
// OJ: https://leetcode.com/problems/delete-and-earn/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int deleteAndEarn(vector<int>& A) {
        map<int, int> m;
        for (int n : A) m[n]++;
        int prev = 0, prev2 = 0, num = INT_MIN;
        for (auto &[n, cnt] : m) {
            int cur = n == num + 1 ? max(prev, prev2 + n * cnt) : (prev + n * cnt);
            prev2 = prev;
            prev = cur;
            num = n;
        }
        return prev;
    }
};
```

## Solution 2. DP

Let `use[i]` be the maximum points we can get if we use numbers in range `[1,i]` and we must use the number `i`.

Let `skip[i]` be the maximum points we can get if we use numbers in range `[1,i]` and we must skip the number `i`.

```
use[0] = skip[0] = 0
use[i] = skip[i-1] + cnt[i] * i
skip[i] = max(use[i-1], skip[i-1])
```

The answer is `max(use[10000], skip[10000])`.

```cpp
// OJ: https://leetcode.com/problems/delete-and-earn/
// Author: github.com/lzl124631x
// Time: O(N + R) where `R` is the range of numbers in `A`
// Space: O(R)
class Solution {
public:
    int deleteAndEarn(vector<int>& A) {
        int cnt[10001] = {}, use[10001] = {}, skip[10001] = {};
        for (int n : A) cnt[n]++;
        for (int i = 1; i <= 10000; ++i) {
            use[i] = skip[i - 1] + cnt[i] * i;
            skip[i] = max(skip[i - 1], use[i - 1]);
        }
        return max(use[10000], skip[10000]);
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/delete-and-earn/
// Author: github.com/lzl124631x
// Time: O(N + R)
// Space: O(R)
class Solution {
public:
    int deleteAndEarn(vector<int>& A) {
        int cnt[10001] = {}, use = 0, skip = 0, mn = INT_MAX, mx = INT_MIN;
        for (int n : A) cnt[n]++, mx = max(mx, n), mn = min(mn, n);
        for (int i = mn; i <= mx; ++i) {
            int u = skip + cnt[i] * i, s = max(skip, use);
            use = u;
            skip = s;
        }
        return max(use, skip);
    }
};
```