# [2147. Number of Ways to Divide a Long Corridor (Hard)](https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor)

<p>Along a long library corridor, there is a line of seats and decorative plants. You are given a <strong>0-indexed</strong> string <code>corridor</code> of length <code>n</code> consisting of letters <code>&#39;S&#39;</code> and <code>&#39;P&#39;</code> where each <code>&#39;S&#39;</code> represents a seat and each <code>&#39;P&#39;</code> represents a plant.</p>

<p>One room divider has <strong>already</strong> been installed to the left of index <code>0</code>, and <strong>another</strong> to the right of index <code>n - 1</code>. Additional room dividers can be installed. For each position between indices <code>i - 1</code> and <code>i</code> (<code>1 &lt;= i &lt;= n - 1</code>), at most one divider can be installed.</p>

<p>Divide the corridor into non-overlapping sections, where each section has <strong>exactly two seats</strong> with any number of plants. There may be multiple ways to perform the division. Two ways are <strong>different</strong> if there is a position with a room divider installed in the first way but not in the second way.</p>

<p>Return <em>the number of ways to divide the corridor</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>. If there is no way, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/04/1.png" style="width: 410px; height: 199px;" />
<pre>
<strong>Input:</strong> corridor = &quot;SSPPSPS&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 different ways to divide the corridor.
The black bars in the above image indicate the two room dividers already installed.
Note that in each of the ways, <strong>each</strong> section has exactly <strong>two</strong> seats.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/04/2.png" style="width: 357px; height: 68px;" />
<pre>
<strong>Input:</strong> corridor = &quot;PPSPSP&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only 1 way to divide the corridor, by not installing any additional dividers.
Installing any would create some section that does not have exactly two seats.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/12/3.png" style="width: 115px; height: 68px;" />
<pre>
<strong>Input:</strong> corridor = &quot;S&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no way to divide the corridor because there will always be a section that does not have exactly two seats.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == corridor.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>corridor[i]</code> is either <code>&#39;S&#39;</code> or <code>&#39;P&#39;</code>.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google), [Zomato](https://leetcode.com/company/zomato)

**Related Topics**:  
[Math](https://leetcode.com/tag/math), [String](https://leetcode.com/tag/string), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Similar Questions**:
* [Decode Ways II (Hard)](https://leetcode.com/problems/decode-ways-ii)
* [Minimum Cost to Cut a Stick (Hard)](https://leetcode.com/problems/minimum-cost-to-cut-a-stick)
* [Ways to Split Array Into Three Subarrays (Medium)](https://leetcode.com/problems/ways-to-split-array-into-three-subarrays)

**Hints**:
* Divide the corridor into segments. Each segment has two seats, starts precisely with one seat, and ends precisely with the other seat.
* How many dividers can you install between two adjacent segments? You must install precisely one. Otherwise, you would have created a section with not exactly two seats.
* If there are k plants between two adjacent segments, there are k + 1 positions (ways) you could install the divider you must install.
* The problem now becomes: Find the product of all possible positions between every two adjacent segments.

## Solution 1.

**Intuition**: If there are `p` plants between two sections, we multiply the answer by `p + 1`.

**Algorithm**:

If the total number of seats is not a positive even number, return 0

Scan `corridor` section by section, count the number of plants between sections, and multiply the answer by `plant + 1`.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfWays(string s) {
        long ans = 1, mod = 1e9 + 7, N = s.size(), total = 0, section = 0;
        for (int i = 0; i < N; ) {
            int seat = 0, plant = 0;
            for (; i < N && seat < 2; ++i) {
                seat += s[i] == 'S';
                if (seat == 0) plant += s[i] == 'P'; // Only count the plants in the front of the first seat of this section
            }
            if (seat && section++ > 0) ans = ans * (plant + 1) % mod;
            total += seat;
        }
        return total % 2 == 0 && total ? ans : 0; // if the total number of seats is not a positive even number, return 0
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfWays(string s) {
        long N = s.size(), mod = 1e9 + 7, prev = 0, cnt = 0, plant = 0, ans = 1;
        for (int i = 0; i < N; ++i) {
            if (prev == cnt) plant += s[i] == 'P'; // count leading plants in each section.
            cnt += s[i] == 'S';
            if (cnt == prev + 2) {
                if (prev) ans = ans * (plant + 1) % mod;
                prev = cnt;
                plant = 0;
            }
        }
        return prev == cnt && cnt ? ans : 0;
    }
};
```

## Discuss

https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/discuss/1709665/C%2B%2B-Scan-section-by-section-O(N)-Time-O(1)-space