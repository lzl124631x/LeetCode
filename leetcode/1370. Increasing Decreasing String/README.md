# [1370. Increasing Decreasing String (Easy)](https://leetcode.com/problems/increasing-decreasing-string)

<p>Given a string <code>s</code>. You should re-order the string using the following algorithm:</p>

<ol>
	<li>Pick the <strong>smallest</strong> character from <code>s</code> and <strong>append</strong> it to the result.</li>
	<li>Pick the <strong>smallest</strong> character from <code>s</code> which is greater than the last appended character to the result and <strong>append</strong> it.</li>
	<li>Repeat step 2 until you cannot pick more characters.</li>
	<li>Pick the <strong>largest</strong>&nbsp;character from <code>s</code> and <strong>append</strong> it to the result.</li>
	<li>Pick the <strong>largest</strong>&nbsp;character from <code>s</code> which is smaller than the last appended character to the result and <strong>append</strong> it.</li>
	<li>Repeat step 5 until you cannot pick more characters.</li>
	<li>Repeat the steps from 1 to 6 until you pick all characters from <code>s</code>.</li>
</ol>

<p>In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.</p>

<p>Return <em>the result string</em> after sorting <code>s</code>&nbsp;with this algorithm.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aaaabbbbcccc"
<strong>Output:</strong> "abccbaabccba"
<strong>Explanation:</strong> After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "rat"
<strong>Output:</strong> "art"
<strong>Explanation:</strong> The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> "cdelotee"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "ggggggg"
<strong>Output:</strong> "ggggggg"
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "spo"
<strong>Output:</strong> "ops"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> contains only lower-case English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/increasing-decreasing-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string sortString(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        int N = s.size();
        string ans(N, '\0');
        for (int i = 0; i < N; ) {
            for (int j = 0; j < 26; ++j) {
                if (!cnt[j]) continue;
                ans[i++] = 'a' + j;
                cnt[j]--;
            }
            for (int j = 25; j >= 0; --j) {
                if (!cnt[j]) continue;
                ans[i++] = 'a' + j;
                cnt[j]--;
            }
        }
        return ans;
    }
};
```