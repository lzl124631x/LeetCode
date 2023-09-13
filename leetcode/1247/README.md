# [1247. Minimum Swaps to Make Strings Equal (Medium)](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/)

<p>You are given two strings&nbsp;<code>s1</code>&nbsp;and&nbsp;<code>s2</code>&nbsp;of equal length&nbsp;consisting of letters <code>"x"</code> and <code>"y"</code> <strong>only</strong>. Your task is to&nbsp;make these two strings equal to each other. You can swap any two characters that belong to <strong>different</strong> strings,&nbsp;which means: swap <code>s1[i]</code> and <code>s2[j]</code>.</p>

<p>Return&nbsp;the minimum number of swaps required&nbsp;to make&nbsp;<code>s1</code>&nbsp;and <code>s2</code> equal, or return&nbsp;<code>-1</code>&nbsp;if it is&nbsp;impossible to do so.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "xx", s2 = "yy"
<strong>Output:</strong> 1
<strong>Explanation: 
</strong>Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".</pre>

<p><strong>Example 2:&nbsp;</strong></p>

<pre><strong>Input:</strong> s1 = "xy", s2 = "yx"
<strong>Output:</strong> 2
<strong>Explanation: 
</strong>Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s1 = "xx", s2 = "xy"
<strong>Output:</strong> -1
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 1000</code></li>
	<li><code>s1, s2</code>&nbsp;only contain <code>'x'</code> or <code>'y'</code>.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Determine if Two Strings Are Close (Medium)](https://leetcode.com/problems/determine-if-two-strings-are-close/)

## Solution 1.

```
a = "xxyyxyxyxx"
b = "xyyxyxxxyx"
```

First remove the places where `a[i] == b[i]`

```
a = "xyxyyx"
b = "yxyxxy"
```

We can first swap `a[2]` and `b[0]`.

```
a = "xyyyyx"
b = "xxyxxy"
// Remove same characters
a = "yyyx"
b = "xxxy"
```

So we can see that for a pattern like the following, we just need one swap
```
a = "xx"
b = "yy"
// Or
a = "yy"
b = "xx"
```

So we whenever we see such pattern, we can increment the answer.

Let `x` and `y` be the count of `x` and `y` we see in `a` respectively, ignoring the places where `a[i] == b[i]`.

When we see `'x'` we increment `x`, otherwise, increment `y`.

When `x == 2`, we increment the answer and reset `x` to `0`. The same for `y`.

In the end there are two cases:

* both `x == 0` and `y == 0`, we return `ans`
* both `x == 1` and `y == 1`, we return `ans + 2`
* `x != y`, we return `-1`

```cpp
// OJ: https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumSwap(string a, string b) {
        int x = 0, y = 0, ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) continue;
            if (a[i] == 'x') ++x;
            else ++y;
            if (x == 2) ++ans, x = 0;
            if (y == 2) ++ans, y = 0;
        }
        if (x != y) return -1;
        return x ? ans + 2 : ans;
    }
};
```