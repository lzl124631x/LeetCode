# [844. Backspace String Compare (Easy)](https://leetcode.com/problems/backspace-string-compare/)

<p>Given two&nbsp;strings&nbsp;<code>S</code>&nbsp;and <code>T</code>,&nbsp;return if they are equal when both are typed into empty text editors. <code>#</code> means a backspace character.</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-1-1">"ab#c"</span>, T = <span id="example-input-1-2">"ad#c"</span>
<strong>Output: </strong><span id="example-output-1">true
</span><span><strong>Explanation</strong>: Both S and T become "ac".</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-2-1">"ab##"</span>, T = <span id="example-input-2-2">"c#d#"</span>
<strong>Output: </strong><span id="example-output-2">true
</span><span><strong>Explanation</strong>: Both S and T become "".</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-3-1">"a##c"</span>, T = <span id="example-input-3-2">"#a#c"</span>
<strong>Output: </strong><span id="example-output-3">true
</span><span><strong>Explanation</strong>: Both S and T become "c".</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-4-1">"a#c"</span>, T = <span id="example-input-4-2">"b"</span>
<strong>Output: </strong><span id="example-output-4">false
</span><span><strong>Explanation</strong>: S becomes "c" while T becomes "b".</span>
</pre>

<p><span><strong>Note</strong>:</span></p>

<ol>
	<li><code><span>1 &lt;= S.length &lt;= 200</span></code></li>
	<li><code><span>1 &lt;= T.length &lt;= 200</span></code></li>
	<li><span><code>S</code>&nbsp;and <code>T</code> only contain&nbsp;lowercase letters and <code>'#'</code> characters.</span></li>
</ol>

<p><strong>Follow up:</strong></p>

<ul>
	<li>Can you solve it in <code>O(N)</code> time and <code>O(1)</code> space?</li>
</ul>
</div>
</div>
</div>
</div>


## Solution 1.

Update the `S` and `T` to the results of applying backspaces, then compare the strings.

```cpp
// OJ: https://leetcode.com/problems/backspace-string-compare/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    string normalize(string &s) {
        int len = 0;
        for (char c : s) {
            if (c == '#') len = max(len - 1, 0);
            else s[len++] = c;
        }
        s.resize(len);
        return s;
    }
public:
    bool backspaceCompare(string S, string T) {
        return normalize(S) == normalize(T);
    }
};
```

## Solution 2.

If it's not allowed to change the input string, we scan backward. `back` function is used to skip all characters that are deleted using backspaces. After `back`, the indexes are pointing to characters that we need to compare.

```cpp
// OJ: https://leetcode.com/problems/backspace-string-compare/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    void back(string &s, int &i) {
        if (i < 0 || s[i] != '#') return;
        int cnt = 0;
        for (; i >= 0 && (cnt || s[i] == '#'); --i) {
            if (s[i] == '#') ++cnt;
            else --cnt;
        }
    }
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        while (i >= 0 || j >= 0) {
            back(S, i);
            back(T, j);
            if ((i >= 0 && j < 0) || (i < 0 && j >= 0)) return false;
            for (; i >= 0 && j >= 0 && S[i] != '#' && T[j] != '#'; --i, --j) {
                if (S[i] != T[j]) return false;
            } 
        }
        return true;
    }
};
```