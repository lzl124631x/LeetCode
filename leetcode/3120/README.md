# [3120. Count the Number of Special Characters I (Easy)](https://leetcode.com/problems/count-the-number-of-special-characters-i)

<p>You are given a string <code>word</code>. A letter is called <strong>special</strong> if it appears <strong>both</strong> in lowercase and uppercase in <code>word</code>.</p>

<p>Return the number of<em> </em><strong>special</strong> letters in<em> </em><code>word</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;aaAbcBC&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The special characters in <code>word</code> are <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;abc&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>No character in <code>word</code> appears in uppercase.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;abBCab&quot;</span></p>

<p><strong>Output:</strong> 1</p>

<p><strong>Explanation:</strong></p>

<p>The only special character in <code>word</code> is <code>&#39;b&#39;</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 50</code></li>
	<li><code>word</code> consists of only lowercase and uppercase English letters.</li>
</ul>

**Similar Questions**:

- [Detect Capital (Easy)](https://leetcode.com/problems/detect-capital)

**Hints**:

- The constraints are small. For all the 56 characters, check if they are present in <code>word</code>.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-the-number-of-special-characters-i
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfSpecialChars(string s) {
        int cnt[26] = {}, ans = 0;
        for (char c : s) {
            if (islower(c)) cnt[c - 'a'] |= 1;
            else cnt[c - 'A'] |= 2;
        }
        for (int i = 0; i < 26; ++i) {
            ans += cnt[i] == 3;
        }
        return ans;
    }
};
```
