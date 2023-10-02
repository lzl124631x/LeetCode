# [2027. Minimum Moves to Convert String (Easy)](https://leetcode.com/problems/minimum-moves-to-convert-string/)

<p>You are given a string <code>s</code> consisting of <code>n</code> characters which are either <code>'X'</code> or <code>'O'</code>.</p>

<p>A <strong>move</strong> is defined as selecting <strong>three</strong> <strong>consecutive characters</strong> of <code>s</code> and converting them to <code>'O'</code>. Note that if a move is applied to the character <code>'O'</code>, it will stay the <strong>same</strong>.</p>

<p>Return <em>the <strong>minimum</strong> number of moves required so that all the characters of </em><code>s</code><em> are converted to </em><code>'O'</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "XXX"
<strong>Output:</strong> 1
<strong>Explanation:</strong> <u>XXX</u> -&gt; OOO
We select all the 3 characters and convert them in one move.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "XXOX"
<strong>Output:</strong> 2
<strong>Explanation:</strong> <u>XXO</u>X -&gt; O<u>OOX</u> -&gt; OOOO
We select the first 3 characters in the first move, and convert them to <code>'O'</code>.
Then we select the last 3 characters and convert them so that the final string contains all <code>'O'</code>s.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "OOOO"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no <code>'X's</code> in <code>s</code> to convert.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'X'</code> or <code>'O'</code>.</li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-moves-to-convert-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumMoves(string s) {
        int N = s.size(), ans = 0;
        for (int i = 0; i < N;) {
            if (s[i] == 'O') ++i;
            else ++ans, i += 3;
        }
        return ans;
    }
};
```