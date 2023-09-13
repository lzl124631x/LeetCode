# [880. Decoded String at Index (Medium)](https://leetcode.com/problems/decoded-string-at-index/)

<p>An encoded string <code>S</code> is given.&nbsp; To find and write the <em>decoded</em> string to a tape, the encoded string is read <strong>one character at a time</strong>&nbsp;and the following steps are taken:</p>

<ul>
	<li>If the character read is a letter, that letter is written onto the tape.</li>
	<li>If the character read is a digit (say <code>d</code>), the entire current tape is repeatedly written&nbsp;<code>d-1</code>&nbsp;more times in total.</li>
</ul>

<p>Now for some encoded string <code>S</code>, and an index <code>K</code>, find and return the <code>K</code>-th letter (1 indexed) in the decoded string.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-1-1">"leet2code3"</span>, K = <span id="example-input-1-2">10</span>
<strong>Output: </strong><span id="example-output-1">"o"</span>
<strong>Explanation: </strong>
The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-2-1">"ha22"</span>, K = <span id="example-input-2-2">5</span>
<strong>Output: </strong><span id="example-output-2">"h"</span>
<strong>Explanation: </strong>
The decoded string is "hahahaha".  The 5th letter is "h".
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-3-1">"a2345678999999999999999"</span>, K = <span id="example-input-3-2">1</span>
<strong>Output: </strong><span id="example-output-3">"a"</span>
<strong>Explanation: </strong>
The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".
</pre>
</div>
</div>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= S.length &lt;= 100</code></li>
	<li><code>S</code>&nbsp;will only contain lowercase letters and digits <code>2</code> through <code>9</code>.</li>
	<li><code>S</code>&nbsp;starts with a letter.</li>
	<li><code>1 &lt;= K &lt;= 10^9</code></li>
	<li>It's guaranteed that <code>K</code>&nbsp;is less than or equal to the length of the decoded string.</li>
	<li>The decoded string is guaranteed to have less than <code>2^63</code> letters.</li>
</ul>


**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/decoded-string-at-index/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        vector<tuple<string, int, long>> v;
        long N = S.size(), len = 0;
        --K;
        for (int i = 0; i < N; ) {
            string s;
            while (i < N && isalpha(S[i])) s += S[i++];
            int n = S[i++] - '0';
            len += s.size();
            v.emplace_back(s, n, len);
            len *= n;
            if (len > K) break;
        }
        for (int i = v.size() - 1; i >= 0; --i) {
            auto [s, n, len] = v[i];
            K %= len;
            if (i == 0) return string(1, s[K % s.size()]);
            else if (K >= len - s.size()) return string(1, s[K - (len - s.size())]);
        }
        return "";
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/decoded-string-at-index/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(1)
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long N = S.size(), len = 0;
        for (int i = 0; i < N; ++i) {
            if (isdigit(S[i])) len *= S[i] - '0';
            else len++;
        }
        for (int i = N - 1; i >= 0; --i) {
            K %= len;
            if (K == 0 && isalpha(S[i])) return string(1, S[i]);
            if (isdigit(S[i])) len /= S[i] - '0';
            else len--;
        }
        return "";
    }
};
```