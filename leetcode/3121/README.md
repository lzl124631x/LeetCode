# [3121. Count the Number of Special Characters II (Medium)](https://leetcode.com/problems/count-the-number-of-special-characters-ii)

<p>You are given a string <code>word</code>. A letter&nbsp;<code>c</code> is called <strong>special</strong> if it appears <strong>both</strong> in lowercase and uppercase in <code>word</code>, and <strong>every</strong> lowercase occurrence of <code>c</code> appears before the <strong>first</strong> uppercase occurrence of <code>c</code>.</p>

<p>Return the number of<em> </em><strong>special</strong> letters<em> </em>in<em> </em><code>word</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;aaAbcBC&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The special characters are <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;abc&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>There are no special characters in <code>word</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;AbBCab&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>There are no special characters in <code>word</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>word</code> consists of only lowercase and uppercase English letters.</li>
</ul>

**Similar Questions**:

- [Detect Capital (Easy)](https://leetcode.com/problems/detect-capital)

**Hints**:

- For each character <code>c</code>, store the first occurrence of its uppercase and the last occurrence of its lowercase.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-the-number-of-special-characters-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfSpecialChars(string s) {
        int N = s.size(), ans = 0;
        vector<int> lastLower(26, N);
        for (int i = 0; i < N; ++i) {
            if (islower(s[i])) lastLower[s[i] - 'a'] = i;
        }
        for (int i = 0; i < N; ++i) {
            if (islower(s[i])) continue;
            int j = s[i] - 'A';
            ans += lastLower[j] < i;
            lastLower[j] = N;
        }
        return ans;
    }
};
```
