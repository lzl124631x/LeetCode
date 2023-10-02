# [2342. Max Sum of a Pair With Equal Sum of Digits (Medium)](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits)

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> consisting of <strong>positive</strong> integers. You can choose two indices <code>i</code> and <code>j</code>, such that <code>i != j</code>, and the sum of digits of the number <code>nums[i]</code> is equal to that of <code>nums[j]</code>.</p>
<p>Return <em>the <strong>maximum</strong> value of </em><code>nums[i] + nums[j]</code><em> that you can obtain over all possible indices </em><code>i</code><em> and </em><code>j</code><em> that satisfy the conditions.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [18,43,36,13,7]
<strong>Output:</strong> 54
<strong>Explanation:</strong> The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [10,12,19,14]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no two numbers that satisfy the conditions, so we return -1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits
// Author: github.com/lzl124631x
// Time: O(NlgD) where D is the range of numbers
// Space: O(N)
class Solution {
    int sumDigits(int n) {
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int maximumSum(vector<int>& A) {
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> m;
        for (int n : A) {
            auto &pq = m[sumDigits(n)];
            pq.push(n);
            if (pq.size() > 2) pq.pop();
        }
        int ans = -1;
        for (auto &[_, pq] : m) {
            if (pq.size() != 2) continue;
            int sum = pq.top();
            pq.pop();
            ans = max(ans, sum + pq.top());
        }
        return ans;
    }
};
```