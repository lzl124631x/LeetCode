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


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [LinkedIn](https://leetcode.com/company/linkedin)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Minimum Number of Swaps to Make the String Balanced (Medium)](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/)


## Solution 1.

`left` and `right` represents the counts of currently unmatched left and right parenthesis respectively.

The following implementation simply discuss different cases we can meet.

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
                if (right) { // when we see ( and there is still a ) left
                    if (left) { // If we have ( balance, use it and add a )
                        --left;
                        ++ans; // add )
                    } else ans += 2; // otherwise, add a ( and a )
                    right = 0; // clear the )
                }
                ++left;
            } else {
                ++right;
                if (left) {
                    if (right == 2) { // if we have ( balance and 2 )s, clear this pair
                        right = 0;
                        --left;
                    }
                } else { // if there is no ( balance, we add a (
                    ++ans;
                    ++left;
                }
            }
        }
        if (left) { // in the end, if we still have ( balance
            ans += 2 * left - right; // add )s
        } else {
            ans += 2 * right; // add one ( if there is ) balance (must be 1)
        }
        return ans;
    }
};
```

Or

* Whenever we see a `)` and we don't have `(` available, we add a `(` at this moment. This simplify the cases to consider because it makes sure we always have enough `(` to cover `)`.
* Always reset `)` whenever we have two `)`s.

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
                if (right) { // Must be a single unmatched `)`. Clear it with a `(`.
                    right = 0;
                    --left;
                    ++ans; // add a `)`
                }
                ++left;
            } else {
                ++right;
                if (left == 0) { // We must add a `(` to match this `)`. This makes sure that if we have an unmatched `)`, there must be at least one `(`, simplifying the cases to consider.
                    left = 1;
                    ++ans; // add one `(`
                }
                if (right == 2) { // We always reset `)` whenever we have two `)`s.
                    right = 0;
                    --left;
                }
            }
        }
        return ans + left * 2 - right;
    }
};
```

Or

* Always reset `)` whenever we have two `)`s.
* Since we don't add `(` early (when we see a `)` without any available `(`), we need more `if (left)` checks later.

```cpp
// OJ: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minInsertions(string s) {
        int left = 0, right = 0, ans = 0, N = s.size();
        for (int i = 0; i <= N; ++i) {
            if (i == N || s[i] == '(') {
                if (right) { // Need to clear this single unmatched `)`.
                    if (left) { // If we have `(` available, use it
                        --left;
                        ++ans; // need to add a single `)`
                    } else ans += 2; // need to add a `(` and a `)`.
                    right = 0;
                }
                if (i < N) ++left;
            } else if (++right == 2) { // We always reset `)` whenever we have two `)`s.
                if (left) --left;
                else ++ans; // add a `(`
                right = 0;
            }
        }
        return ans + 2 * left;
    }
};
```

Or

* We don't even clear `)` when we have two `)`s. We clear `)` when we see `(` or reached end of string.

```cpp
// OJ: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minInsertions(string s) {
        int left = 0, right = 0, ans = 0, N = s.size();
        for (int i = 0; i <= N; ++i) {
            if (i == N || s[i] == '(') {
                if (right % 2) ++ans, ++right; // if we have odd `)` balance, add one `)` to make it even
                left -= right / 2;
                right = 0;
                if (left < 0) {
                    ans -= left;
                    left = 0;
                }
                if (i < N) ++left;
            } else ++right;
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
        int right = 0, ans = 0;
        for (char c : s) {
            if (c == '(') {
                if (right % 2) { // if we have odd `)` needed, we must clear  right now
                    --right;
                    ++ans; // add one `)`
                }
                right += 2;
            } else {
                if (right) --right;
                else {
                    right = 1;
                    ++ans; // add a `(`
                }
            }
        }
        return ans + right;
    }
};
```