# [856. Score of Parentheses (Medium)](https://leetcode.com/problems/score-of-parentheses/)

<p>Given a balanced parentheses string <code>S</code>, compute the score of the string based on the following rule:</p>

<ul>
	<li><code>()</code> has score 1</li>
	<li><code>AB</code> has score <code>A + B</code>, where A and B are balanced parentheses strings.</li>
	<li><code>(A)</code> has score <code>2 * A</code>, where A is a balanced parentheses string.</li>
</ul>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"()"</span>
<strong>Output: </strong><span id="example-output-1">1</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"(())"</span>
<strong>Output: </strong><span id="example-output-2">2</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">"()()"</span>
<strong>Output: </strong><span id="example-output-3">2</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">"(()(()))"</span>
<strong>Output: </strong><span id="example-output-4">6</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>S</code> is a balanced parentheses string, containing only <code>(</code> and <code>)</code>.</li>
	<li><code>2 &lt;= S.length &lt;= 50</code></li>
</ol>
</div>
</div>
</div>
</div>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/score-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int scoreOfParentheses(string S) {
        if (S == "()") return 1;
        int i = 0, left = 0;
        do {
            left += S[i++] == '(' ? 1 : -1;
        } while (left);
        if (i == S.size()) return 2 * scoreOfParentheses(S.substr(1, S.size() - 2));
        return scoreOfParentheses(S.substr(0, i)) + scoreOfParentheses(S.substr(i));
    }
};
```

## Solution 2.

Same idea as Solution 1, but more space efficient.

```cpp
// OJ: https://leetcode.com/problems/score-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    int score(string &S, int begin, int end) {
        if (begin + 2 == end) return 1;
        int i = begin, left = 0;
        do {
            left += S[i++] == '(' ? 1 : -1;
        } while (left);
        if (i == end) return 2 * score(S, begin + 1, end - 1);
        return score(S, begin, i) + score(S, i, end);
    }
public:
    int scoreOfParentheses(string S) {
        return score(S, 0, S.size());
    }
};
```