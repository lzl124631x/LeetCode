# [2769. Find the Maximum Achievable Number (Easy)](https://leetcode.com/problems/find-the-maximum-achievable-number)

<p>You are given two integers, <code>num</code> and <code>t</code>.</p>
<p>An integer <code>x</code> is called <b>achievable</b> if it can become equal to <code>num</code> after applying the following operation no more than <code>t</code> times:</p>
<ul>
	<li>Increase or decrease <code>x</code> by <code>1</code>, and simultaneously increase or decrease <code>num</code> by <code>1</code>.</li>
</ul>
<p>Return <em>the maximum possible achievable number</em>. It can be proven that there exists at least one achievable number.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> num = 4, t = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> The maximum achievable number is x = 6; it can become equal to num after performing this operation:
1- Decrease x by 1, and increase num by 1. Now, x = 5 and num = 5. 
It can be proven that there is no achievable number larger than 6.

</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> num = 3, t = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> The maximum achievable number is x = 7; after performing these operations, x will equal num: 
1- Decrease x by 1, and increase num by 1. Now, x = 6 and num = 4.
2- Decrease x by 1, and increase num by 1. Now, x = 5 and num = 5.
It can be proven that there is no achievable number larger than 7.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= num, t&nbsp;&lt;= 50</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-maximum-achievable-number
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int theMaximumAchievableX(int n, int t) {
        return n + t * 2;
    }
};
```