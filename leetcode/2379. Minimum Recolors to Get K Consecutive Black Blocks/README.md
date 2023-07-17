# [2379. Minimum Recolors to Get K Consecutive Black Blocks (Easy)](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks)

<p>You are given a <strong>0-indexed</strong> string <code>blocks</code> of length <code>n</code>, where <code>blocks[i]</code> is either <code>'W'</code> or <code>'B'</code>, representing the color of the <code>i<sup>th</sup></code> block. The characters <code>'W'</code> and <code>'B'</code> denote the colors white and black, respectively.</p>
<p>You are also given an integer <code>k</code>, which is the desired number of <strong>consecutive</strong> black blocks.</p>
<p>In one operation, you can <strong>recolor</strong> a white block such that it becomes a black block.</p>
<p>Return<em> the <strong>minimum</strong> number of operations needed such that there is at least <strong>one</strong> occurrence of </em><code>k</code><em> consecutive black blocks.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> blocks = "WBBWWBBWBW", k = 7
<strong>Output:</strong> 3
<strong>Explanation:</strong>
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW". 
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> blocks = "WBWBBBW", k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == blocks.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>blocks[i]</code> is either <code>'W'</code> or <code>'B'</code>.</li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

**Companies**:
[DailyHunt](https://leetcode.com/company/dailyhunt)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)
* [Maximum Points You Can Obtain from Cards (Medium)](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)
* [Maximum Number of Vowels in a Substring of Given Length (Medium)](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)

## Solution 1. Fixed-length Sliding Window

```cpp
// OJ: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumRecolors(string s, int k) {
        int cnt = 0, ans = INT_MAX;
        for (int i = 0, N = s.size(); i < N; ++i) {
            cnt += s[i] == 'W';
            if (i - k >= 0) cnt -= s[i - k] == 'W';
            if (i >= k - 1) ans = min(ans, cnt);
        }
        return ans;
    }
};
```