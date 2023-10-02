# [2103. Rings and Rods (Easy)](https://leetcode.com/problems/rings-and-rods/)

<p>There are <code>n</code> rings and each ring is either red, green, or blue. The rings are distributed <strong>across ten rods</strong> labeled from <code>0</code> to <code>9</code>.</p>

<p>You are given a string <code>rings</code> of length <code>2n</code> that describes the <code>n</code> rings that are placed onto the rods. Every two characters in <code>rings</code> forms a <strong>color-position pair</strong> that is used to describe each ring where:</p>

<ul>
	<li>The <strong>first</strong> character of the <code>i<sup>th</sup></code> pair denotes the <code>i<sup>th</sup></code> ring's <strong>color</strong> (<code>'R'</code>, <code>'G'</code>, <code>'B'</code>).</li>
	<li>The <strong>second</strong> character of the <code>i<sup>th</sup></code> pair denotes the <strong>rod</strong> that the <code>i<sup>th</sup></code> ring is placed on (<code>'0'</code> to <code>'9'</code>).</li>
</ul>

<p>For example, <code>"R3G2B1"</code> describes <code>n == 3</code> rings: a red ring placed onto the rod labeled 3, a green ring placed onto the rod labeled 2, and a blue ring placed onto the rod labeled 1.</p>

<p>Return <em>the number of rods that have <strong>all three colors</strong> of rings on them.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/23/ex1final.png" style="width: 258px; height: 130px;">
<pre><strong>Input:</strong> rings = "B0B6G0R6R0R6G9"
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
- The rod labeled 0 holds 3 rings with all colors: red, green, and blue.
- The rod labeled 6 holds 3 rings, but it only has red and blue.
- The rod labeled 9 holds only a green ring.
Thus, the number of rods with all three colors is 1.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/23/ex2final.png" style="width: 266px; height: 130px;">
<pre><strong>Input:</strong> rings = "B0R0G0R9R0B0G0"
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
- The rod labeled 0 holds 6 rings with all colors: red, green, and blue.
- The rod labeled 9 holds only a red ring.
Thus, the number of rods with all three colors is 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> rings = "G4"
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
Only one ring is given. Thus, no rods have all three colors.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>rings.length == 2 * n</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>rings[i]</code> where <code>i</code> is <strong>even</strong> is either <code>'R'</code>, <code>'G'</code>, or <code>'B'</code> (<strong>0-indexed</strong>).</li>
	<li><code>rings[i]</code> where <code>i</code> is <strong>odd</strong> is a digit from <code>'0'</code> to <code>'9'</code> (<strong>0-indexed</strong>).</li>
</ul>


**Similar Questions**:
* [Check if All Characters Have Equal Number of Occurrences (Easy)](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/)

## Solution 1. Counting

```cpp
// OJ: https://leetcode.com/problems/rings-and-rods/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countPoints(string s) {
        bool cnt[10][3] = {};
        for (int i = 0; i < s.size(); i += 2) {
            int color = s[i] == 'R' ? 0 : (s[i] == 'G' ? 1 : 2), index = s[i + 1] - '0';
            cnt[index][color] = true;
        }
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            ans += cnt[i][0] && cnt[i][1] && cnt[i][2];
        }
        return ans;
    }
};
```

## Solution 2. Counting with Bitmask

```cpp
// OJ: https://leetcode.com/problems/rings-and-rods/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countPoints(string s) {
        char cnt[10] = {};
        for (int i = 0; i < s.size(); i += 2) {
            int color = s[i] == 'R' ? 0 : (s[i] == 'G' ? 1 : 2), index = s[i + 1] - '0';
            cnt[index] |= 1 << color;
        }
        int ans = 0;
        for (int i = 0; i < 10; ++i) ans += cnt[i] == 0b111;
        return ans;
    }
};
```