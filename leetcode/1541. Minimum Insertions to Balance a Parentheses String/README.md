# [1541. Minimum Insertions to Balance a Parentheses String (Medium)](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)

<p>Given a parentheses string <code>s</code> containing only the characters <code>'('</code> and <code>')'</code>. A parentheses string is <strong>balanced</strong> if:</p>

<ul>
	<li>Any left parenthesis&nbsp;<code>'('</code>&nbsp;must have a corresponding two consecutive right parenthesis&nbsp;<code>'))'</code>.</li>
	<li>Left parenthesis&nbsp;<code>'('</code>&nbsp;must go before the corresponding two&nbsp;consecutive right parenthesis&nbsp;<code>'))'</code>.</li>
</ul>

<p>In other words, we treat <code>'('</code> as openning parenthesis and <code>'))'</code> as closing parenthesis.</p>

<p>For example, <code>"())"</code>, <code>"())(())))"</code> and <code>"(())())))"</code> are&nbsp;balanced, <code>")()"</code>, <code>"()))"</code> and <code>"(()))"</code> are not balanced.</p>

<p>You can insert the characters <code>'('</code> and <code>')'</code> at any position of the string to balance it if needed.</p>

<p>Return <em>the minimum number of insertions</em> needed to make <code>s</code> balanced.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "(()))"
<strong>Output:</strong> 1
<strong>Explanation:</strong> The second '(' has two matching '))', but the first '(' has only ')' matching. We need to to add one more ')' at the end of the string to be "(())))" which is balanced.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "())"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The string is already balanced.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "))())("
<strong>Output:</strong> 3
<strong>Explanation:</strong> Add '(' to match the first '))', Add '))' to match the last '('.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "(((((("
<strong>Output:</strong> 12
<strong>Explanation:</strong> Add 12 ')' to balance the string.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = ")))))))"
<strong>Output:</strong> 5
<strong>Explanation:</strong> Add 4 '(' at the beginning of the string and one ')' at the end. The string becomes "(((())))))))".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code> consists of <code>'('</code> and <code>')'</code> only.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

## Solution 1.

`left` and `right` represents the counts of currently unmatched left and right parenthesis respectively.

```cpp
// OJ: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minInsertions(string s) {
        int left = 0, right = 0, ans = 0;
        for (char c : s) {
            if (c == '(') {
                ++left;
                if (right) { // Unmatched right, reset it with a matching left parenthesis.
                    right = 0;
                    --left;
                    ++ans;
                }
            } else {
                ++right;
                if (left == 0) { // Make sure we always have a left parenthesis to match right parenthesis.
                    left = 1;
                    ++ans;
                }
                if (right == 2) { // When `right` equals `2`, reset it to `0` with a matching left parenthesis, if any.
                    right = 0;
                    if (left) --left;
                    else ++ans;
                }
            }
        }
        return ans + left * 2 - right;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minInsertions(string s) {
        int left = 0, right = 0, ans = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == '(') {
                if (right) {
                    if (left) {
                        --left;
                        ++ans;
                    } else ans += 2;
                    right = 0;
                }
                if (i < s.size()) ++left;
            } else if (++right == 2) {
                if (left) --left;
                else ++ans;
                right = 0;
            }
        }
        return ans + 2 * left;
    }
};
```

## Solution 2.

`right` represents the number of right parenthesis we need.

```cpp
// OJ: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/discuss/780199/JavaC%2B%2BPython-Straight-Forward-One-Pass
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, right = 0;
        for (char c : s) {
            if (c == '(') {
                if (right % 2) { // we need odd number right parenthesis, provide one right parenthesis to make `right` even.
                    --right;
                    ++ans;
                }
                right += 2; // Need to right parenthesis to match this left parenthesis
            } else {
                --right;
                if (right < 0) { // need to add a left parenthesis
                    right += 2;
                    ++ans;
                }
            }
        }
        return ans + right;
    }
};
```