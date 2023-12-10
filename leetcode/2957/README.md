# [2957. Remove Adjacent Almost-Equal Characters (Medium)](https://leetcode.com/problems/remove-adjacent-almost-equal-characters)

<p>You are given a <strong>0-indexed</strong> string <code>word</code>.</p>

<p>In one operation, you can pick any index <code>i</code> of <code>word</code> and change <code>word[i]</code> to any lowercase English letter.</p>

<p>Return <em>the <strong>minimum</strong> number of operations needed to remove all adjacent <strong>almost-equal</strong> characters from</em> <code>word</code>.</p>

<p>Two characters <code>a</code> and <code>b</code> are <strong>almost-equal</strong> if <code>a == b</code> or <code>a</code> and <code>b</code> are adjacent in the alphabet.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;aaaaa&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can change word into &quot;a<strong><u>c</u></strong>a<u><strong>c</strong></u>a&quot; which does not have any adjacent almost-equal characters.
It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;abddez&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can change word into &quot;<strong><u>y</u></strong>bd<u><strong>o</strong></u>ez&quot; which does not have any adjacent almost-equal characters.
It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 2.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;zyxyxyz&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can change word into &quot;z<u><strong>a</strong></u>x<u><strong>a</strong></u>x<strong><u>a</u></strong>z&quot; which does not have any adjacent almost-equal characters. 
It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Minimum Changes To Make Alternating Binary String (Easy)](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string)

**Hints**:
* For <code>i > 0</code>, if <code>word[i]</code> and <code>word[i - 1]</code> are adjacent, we will change <code>word[i]</code> to another character. Which character should we change it to?
* We will change <code>word[i]</code> to some character that is not adjacent to <code>word[i - 1]</code> nor <code>word[i + 1]</code> (if it exists). Such a character always exists. However, since the problem does not ask for the final state of the string, It is enough to prove that the character exists and we do not need to find it.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-adjacent-almost-equal-characters
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int N = s.size(), ans = 0;
        for (int i = 1; i < N; ++i) {
            if (s[i] == s[i - 1] || abs(s[i] - s[i - 1]) == 1) {
                ++ans;
                ++i;
            }
        }
        return ans;
    }
};
```