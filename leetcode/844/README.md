# [844. Backspace String Compare (Easy)](https://leetcode.com/problems/backspace-string-compare)

<p>Given two strings <code>s</code> and <code>t</code>, return <code>true</code> <em>if they are equal when both are typed into empty text editors</em>. <code>&#39;#&#39;</code> means a backspace character.</p>

<p>Note that after backspacing an empty text, the text will continue empty.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ab#c&quot;, t = &quot;ad#c&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> Both s and t become &quot;ac&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ab##&quot;, t = &quot;c#d#&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> Both s and t become &quot;&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a#c&quot;, t = &quot;b&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> s becomes &quot;c&quot; while t becomes &quot;b&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code><span>1 &lt;= s.length, t.length &lt;= 200</span></code></li>
	<li><span><code>s</code> and <code>t</code> only contain lowercase letters and <code>&#39;#&#39;</code> characters.</span></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Can you solve it in <code>O(n)</code> time and <code>O(1)</code> space?</p>


**Companies**:
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Google](https://leetcode.com/company/google), [Oracle](https://leetcode.com/company/oracle), [Grammarly](https://leetcode.com/company/grammarly), [Microsoft](https://leetcode.com/company/microsoft), [IBM](https://leetcode.com/company/ibm), [Amazon](https://leetcode.com/company/amazon), [Booking.com](https://leetcode.com/company/bookingcom), [Apple](https://leetcode.com/company/apple), [Visa](https://leetcode.com/company/visa), [Bloomberg](https://leetcode.com/company/bloomberg), [VMware](https://leetcode.com/company/vmware), [Twilio](https://leetcode.com/company/twilio), [TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers), [String](https://leetcode.com/tag/string), [Stack](https://leetcode.com/tag/stack), [Simulation](https://leetcode.com/tag/simulation)

**Similar Questions**:
* [Crawler Log Folder (Easy)](https://leetcode.com/problems/crawler-log-folder)
* [Removing Stars From a String (Medium)](https://leetcode.com/problems/removing-stars-from-a-string)


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
        int cnt = 0;
        while (i >= 0 && (s[i] == '#' || cnt)) {
            cnt += s[i--] == '#' ? 1 : -1;
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