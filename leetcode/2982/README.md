# [2982. Find Longest Special Substring That Occurs Thrice II (Medium)](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii)

<p>You are given a string <code>s</code> that consists of lowercase English letters.</p>

<p>A string is called <strong>special</strong> if it is made up of only a single character. For example, the string <code>&quot;abc&quot;</code> is not special, whereas the strings <code>&quot;ddd&quot;</code>, <code>&quot;zz&quot;</code>, and <code>&quot;f&quot;</code> are special.</p>

<p>Return <em>the length of the <strong>longest special substring</strong> of </em><code>s</code> <em>which occurs <strong>at least thrice</strong></em>, <em>or </em><code>-1</code><em> if no special substring occurs at least thrice</em>.</p>

<p>A <strong>substring</strong> is a contiguous <strong>non-empty</strong> sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aaaa&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest special substring which occurs thrice is &quot;aa&quot;: substrings &quot;<u><strong>aa</strong></u>aa&quot;, &quot;a<u><strong>aa</strong></u>a&quot;, and &quot;aa<u><strong>aa</strong></u>&quot;.
It can be shown that the maximum length achievable is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcdef&quot;
<strong>Output:</strong> -1
<strong>Explanation:</strong> There exists no special substring which occurs at least thrice. Hence return -1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcaba&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> The longest special substring which occurs thrice is &quot;a&quot;: substrings &quot;<u><strong>a</strong></u>bcaba&quot;, &quot;abc<u><strong>a</strong></u>ba&quot;, and &quot;abcab<u><strong>a</strong></u>&quot;.
It can be shown that the maximum length achievable is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table), [String](https://leetcode.com/tag/string), [Binary Search](https://leetcode.com/tag/binary-search), [Sliding Window](https://leetcode.com/tag/sliding-window), [Counting](https://leetcode.com/tag/counting)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters)
* [Longest Substring with At Least K Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters)

**Hints**:
* Let <code>len[i]</code> be the length of the longest special string ending with <code>s[i]</code>.
* If <code>i > 0</code> and <code>s[i] == s[i - 1]</code>, <code>len[i] = len[i - 1] + 1</code>. Otherwise <code>len[i] == 1</code>.
* Group all the <code>len[i]</code> by <code>s[i]</code>. We have at most <code>26</code> groups.
* The maximum value of the third largest <code>len[i]</code> in each group is the answer.
* We only need to maintain the top three values for each group. You can use sorting, heap, or brute-force comparison to find the third largest value in each group.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumLength(string s) {
        int N = s.size(), ans = -1;
        unordered_map<int, int> m[26] = {};
        for (int i = 0; i < N; ++i) {
            int len = 1, ch = s[i] - 'a';
            while (i + 1 < N && s[i + 1] == s[i]) ++i, ++len;
            if (len > 0) m[ch][len]++;
            if (len - 1 > 0) m[ch][len - 1] += 2;
            if (len - 2 > 0) m[ch][len - 2] += 3;
        }
        for (int ch = 0; ch < 26; ++ch) {
            for (auto &[len, cnt] : m[ch]) {
                if (cnt >= 3) ans = max(ans, len);
            }
        }
        return ans;
    }
};
```