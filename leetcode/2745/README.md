# [2745. Construct the Longest New String (Medium)](https://leetcode.com/problems/construct-the-longest-new-string)

<p>You are given three integers <code>x</code>, <code>y</code>, and <code>z</code>.</p>
<p>You have <code>x</code> strings equal to <code>"AA"</code>, <code>y</code> strings equal to <code>"BB"</code>, and <code>z</code> strings equal to <code>"AB"</code>. You want to choose some (possibly all or none) of these strings and concactenate them in some order to form a new string. This new string must not contain <code>"AAA"</code> or <code>"BBB"</code> as a substring.</p>
<p>Return <em>the maximum possible length of the new string</em>.</p>
<p>A <b>substring</b> is a contiguous <strong>non-empty</strong> sequence of characters within a string.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> x = 2, y = 5, z = 1
<strong>Output:</strong> 12
<strong>Explanation: </strong>We can concactenate the strings "BB", "AA", "BB", "AA", "BB", and "AB" in that order. Then, our new string is "BBAABBAABBAB". 
That string has length 12, and we can show that it is impossible to construct a string of longer length.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> x = 3, y = 2, z = 2
<strong>Output:</strong> 14
<strong>Explanation:</strong> We can concactenate the strings "AB", "AB", "AA", "BB", "AA", "BB", and "AA" in that order. Then, our new string is "ABABAABBAABBAA". 
That string has length 14, and we can show that it is impossible to construct a string of longer length.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= x, y, z &lt;= 50</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/), [Brainteaser](https://leetcode.com/tag/brainteaser/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/construct-the-longest-new-string
// Author: github.com/lzl124631x
// Time: O(XYZ)
// Space: O(XYZ)
class Solution {
public:
    int longestString(int x, int y, int z) {
        int m[51][51][51][4] = {};
        memset(m, -1, sizeof(m));
        function<int(int, int, int, int)> dp = [&](int x, int y, int z, int last) {
            if (m[x][y][z][last] != -1) return m[x][y][z][last];
            int ans = 0;
            if (x && last != 1) ans = max(ans, 2 + dp(x - 1, y, z, 1)); // pick AA
            if (y && last <= 1) ans = max(ans, 2 + dp(x, y - 1, z, 2)); // pick BB
            if (z && last != 1) ans = max(ans, 2 + dp(x, y, z - 1, 3)); // pick BB
            return m[x][y][z][last] = ans;
        };
        return dp(x, y, z, 0);
    }
};
```

## Solution 2.

* There is no requirement to match strings of the "AB" type with any specific string. These strings can be placed anywhere within the overall string as "ABABABAB..". Hence we take all "AB"'s.
* Combine "AA" and "BB" strings as "AABB" pairs. Thus, for the total length, we choose the minimum number of occurrences between the two patterns and multiply it by 4. The resulting string will have the pattern "AABB".
* If there are remaining "AA" or "BB" strings, append a single occurrence at the end of the string. For example, with x=2, y=1, and z=0, the resulting string would be "AABBAA".

```cpp
// OJ: https://leetcode.com/problems/construct-the-longest-new-string
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/construct-the-longest-new-string/solutions/3677601
class Solution {
public:
    int longestString(int x, int y, int z) {
        int mn = min(x, y);
        return (x == y ? 4 * x : 2 * mn + 2 * (mn + 1)) + z * 2;
    }
};
```