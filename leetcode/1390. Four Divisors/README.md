# [1390. Four Divisors (Medium)](https://leetcode.com/problems/four-divisors/)

<p>Given an integer array <code>nums</code>, return the sum of divisors of the integers in that array that have exactly four divisors.</p>

<p>If there is no such integer in the array, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [21,4,7]
<strong>Output:</strong> 32
<b>Explanation:</b>
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^4</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/four-divisors/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            int cnt = 0, sum = 0;
            for (int i = 1; i * i <= n && cnt <= 4; ++i) {
                if (n % i) continue;
                int j = n / i;
                ++cnt;
                sum += i;
                if (i != j) {
                    ++cnt;
                    sum += j;
                }
            }
            if (cnt != 4) continue;
            ans += sum;
        }
        return ans;
    }
};
```