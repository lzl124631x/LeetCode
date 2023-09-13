# [678. Valid Parenthesis String (Medium)](https://leetcode.com/problems/valid-parenthesis-string/)

<p>Given a string <code>s</code> containing only three types of characters: <code>'('</code>, <code>')'</code> and <code>'*'</code>, return <code>true</code> <em>if</em> <code>s</code> <em>is <strong>valid</strong></em>.</p>

<p>The following rules define a <strong>valid</strong> string:</p>

<ul>
	<li>Any left parenthesis <code>'('</code> must have a corresponding right parenthesis <code>')'</code>.</li>
	<li>Any right parenthesis <code>')'</code> must have a corresponding left parenthesis <code>'('</code>.</li>
	<li>Left parenthesis <code>'('</code> must go before the corresponding right parenthesis <code>')'</code>.</li>
	<li><code>'*'</code> could be treated as a single right parenthesis <code>')'</code> or a single left parenthesis <code>'('</code> or an empty string <code>""</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "()"
<strong>Output:</strong> true
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "(*)"
<strong>Output:</strong> true
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> s = "(*))"
<strong>Output:</strong> true
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code> is <code>'('</code>, <code>')'</code> or <code>'*'</code>.</li>
</ul>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Rubrik](https://leetcode.com/company/rubrik), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Oracle](https://leetcode.com/company/oracle)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Special Binary String (Hard)](https://leetcode.com/problems/special-binary-string/)
* [Check if a Parentheses String Can Be Valid (Medium)](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/)

## TLE Version

This solution is not performant if `s` contains lots of `"*"`.

```cpp
// OJ: https://leetcode.com/problems/valid-parenthesis-string/
// Author: github.com/lzl124631x
// Time: O(3^S) where S is the length of string s. In the worst case every character
//       is "*", so every step has 3 choices.
// Space: O(S)
class Solution {
private:
    bool dfs(string &s, int start, int leftParenCnt) {
        if (start == s.size()) return !leftParenCnt;
        if (s[start] == '(') {
            return dfs(s, start + 1, leftParenCnt + 1);
        } else if (s[start] == ')') {
            if (--leftParenCnt < 0) return false;
            return dfs(s, start + 1, leftParenCnt);
        } else {
            if (dfs(s, start + 1, leftParenCnt + 1)) return true;
            if (leftParenCnt >= 1 && dfs(s, start + 1, leftParenCnt - 1)) return true;
            return dfs(s, start + 1, leftParenCnt);
        }
    }
public:
    bool checkValidString(string s) {
        return dfs(s, 0, 0);
    }
};
```

## Solution 1.

Let `diff` be count of left parenthesis minus count of right parenthesis.

When we meet:

* `(`, we increment `diff`.
* `)`, we decrement `diff`.
* `*`, we have three choices which makes the `diff` become a range -- `[diff - 1, diff + 1]`.

So we use `maxDiff`/`minDiff` to record the maximum/minimum `diff` we can get.

When we meet:

* `(`, `++maxDiff` and `++minDiff`.
* `)`, `--maxDiff` and `--minDiff`.
* `*`, `++maxDiff` and `--minDiff`.

If `maxDiff` become negative, it means it's already invalid, we should return `false`.

Whenever `minDiff` falls below `0`, we should force it to be `0` because we never accept negative `diff` during the process.

After scanning through string `s`, as long as `minDiff` is `0`, this string can be a valid one.

> Whenever `minDiff` falls below `0`, we should force it to be `0` because we never accept negative `diff` during the process.

`minDiff` means the `diff` we got if we always try to replace `*` with `)`. If `minDiff` become `-1`, it means that this replacement results in more `)` than `(`, so it should be avoided. To avoid it, we simply reset `minDiff` from `-1` to `0` which implies we only replace `*` with `(` or empty string.

Example: `(**)`

* Seeing `(`, the range becomes `[1, 1]`.
* Seeing `*`, the range becomes `[0, 2]`. `0` correponds to `()`, `1` to `(_`, `2` to `((`.
* Seeing `*`, the range becomes `[-1,3]`. But `-1` is invalid because it means `())` and should be avoided. So we correct the range to `[0, 3]`.
* Seeing `)`, the range becomes `[-1, 2]`. Again, we correct the range to `[0, 2]` (because `-1` means `()_)` or `(_))`)

The final `[0, 2]` range means that we can either get a perfect string, or has `1` or `2` more `(` available (which are created by `*`).

```cpp
// OJ: https://leetcode.com/problems/valid-parenthesis-string/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int maxDiff = 0, minDiff = 0;
        for (char c : s) {
            maxDiff += (c == '(' || c == '*') ? 1 : -1;
            minDiff += (c == ')' || c == '*') ? -1 : 1;
            if (maxDiff < 0) return false;
            if (minDiff < 0) minDiff = 0;
        }
        return minDiff == 0;
    }
};
```

## NOTE:

My post: https://leetcode.com/problems/valid-parenthesis-string/discuss/302732/C%2B%2B-O(S)-Time-O(1)-Space-One-Pass-with-Explanation