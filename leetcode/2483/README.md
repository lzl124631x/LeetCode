# [2483. Minimum Penalty for a Shop (Medium)](https://leetcode.com/problems/minimum-penalty-for-a-shop)

<p>You are given the customer visit log of a shop represented by a <strong>0-indexed</strong> string <code>customers</code> consisting only of characters <code>'N'</code> and <code>'Y'</code>:</p>
<ul>
	<li>if the <code>i<sup>th</sup></code> character is <code>'Y'</code>, it means that customers come at the <code>i<sup>th</sup></code> hour</li>
	<li>whereas <code>'N'</code> indicates that no customers come at the <code>i<sup>th</sup></code> hour.</li>
</ul>
<p>If the shop closes at the <code>j<sup>th</sup></code> hour (<code>0 &lt;= j &lt;= n</code>), the <strong>penalty</strong> is calculated as follows:</p>
<ul>
	<li>For every hour when the shop is open and no customers come, the penalty increases by <code>1</code>.</li>
	<li>For every hour when the shop is closed and customers come, the penalty increases by <code>1</code>.</li>
</ul>
<p>Return<em> the <strong>earliest</strong> hour at which the shop must be closed to incur a <strong>minimum</strong> penalty.</em></p>
<p><strong>Note</strong> that if a shop closes at the <code>j<sup>th</sup></code> hour, it means the shop is closed at the hour <code>j</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> customers = "YYNY"
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
- Closing the shop at the 0<sup>th</sup> hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1<sup>st</sup> hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2<sup>nd</sup> hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3<sup>rd</sup> hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4<sup>th</sup> hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2<sup>nd</sup> or 4<sup>th</sup> hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> customers = "NNNNN"
<strong>Output:</strong> 0
<strong>Explanation:</strong> It is best to close the shop at the 0<sup>th</sup> hour as no customers arrive.</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> customers = "YYYY"
<strong>Output:</strong> 4
<strong>Explanation:</strong> It is best to close the shop at the 4<sup>th</sup> hour as customers arrive at each hour.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= customers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>customers</code> consists only of characters <code>'Y'</code> and <code>'N'</code>.</li>
</ul>

**Companies**:
[Stripe](https://leetcode.com/company/stripe)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Grid Game (Medium)](https://leetcode.com/problems/grid-game/)

## Solution 1. Left-to-right state transition

The penalty at `s[i]` is the count of Y's to the right (excluding `s[i]`) plus the count of N's to the left (including `s[i]`).

```cpp
// OJ: https://leetcode.com/problems/minimum-penalty-for-a-shop
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int bestClosingTime(string s) {
        int N = s.size(), y = 0, n = 0;
        for (char c : s) y += c == 'Y';
        int minPenalty = y, ans = 0;
        for (int i = 0; i < N; ++i) {
            y -= s[i] == 'Y';
            n += s[i] == 'N';
            if (y + n < minPenalty) {
                minPenalty = y + n;
                ans = i + 1;
            }
        }
        return ans;
    }
};
```