# [471. Encode String with Shortest Length (Hard)](https://leetcode.com/problems/encode-string-with-shortest-length/)

<p>Given a <b>non-empty</b> string, encode the string such that its encoded length is the shortest.</p>

<p>The encoding rule is: <code>k[encoded_string]</code>, where the <i>encoded_string</i> inside the square brackets is being repeated exactly <i>k</i> times.</p>

<p><b>Note:</b></p>

<ol>
	<li><i>k</i> will be a positive integer and encoded string will not be empty or have extra space.</li>
	<li>You may assume that the input string contains only lowercase English letters. The string's length is at most 160.</li>
	<li>If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them is fine.</li>
</ol>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre>Input: "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre>Input: "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
</pre>

<p>&nbsp;</p>

<p><b>Example 3:</b></p>

<pre>Input: "aaaaaaaaaa"
Output: "10[a]"
Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".
</pre>

<p>&nbsp;</p>

<p><b>Example 4:</b></p>

<pre>Input: "aabcaabcd"
Output: "2[aabc]d"
Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".
</pre>

<p>&nbsp;</p>

<p><b>Example 5:</b></p>

<pre>Input: "abbbabbbcabbbabbbc"
Output: "2[2[abbb]c]"
Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2[abbb]c", so one answer can be "2[2[abbb]c]".
</pre>

<p>&nbsp;</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Decode String (Medium)](https://leetcode.com/problems/decode-string/)
* [Number of Atoms (Hard)](https://leetcode.com/problems/number-of-atoms/)

## TLE Solution

The TLE case `"slkjdfbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"`.

Why not simply traverse the string and merge substring of the same letters? Because for this case `"aaabaaaaaabaaa"`, the result should be `"2[aaabaaa]"`. If we merge it to `"aaab6[a]baaa"`, we can't get the right answer.

```cpp
// OJ: https://leetcode.com/problems/encode-string-with-shortest-length/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N)
class Solution {
private:
    bool compare(string &s, int s1, int s2, int len) {
        if (s1 + len > s.size() || s2 + len > s.size()) return false;
        int i = 0;
        for (; i < len && s[s1 + i] == s[s2 + i]; ++i);
        return i == len;
    }
public:
    string encode(string s) {
        if (s.size() <= 4) return s;
        string ans = s;
        for (int len = s.size() / 2; len >= 1; --len) {
            for (int i = 0; i + len <= s.size(); ++i) {
                int cnt = 1;
                while (compare(s, i, i + cnt * len, len)) ++cnt;
                if (cnt == 1) continue;
                string prefix = i > 0 ? encode(s.substr(0, i)) : "";
                string suffix = i + cnt * len < s.size() ? encode(s.substr(i + cnt * len)) : "";
                string middle = to_string(cnt) + "[" + encode(s.substr(i, len)) + "]";
                string encoded = prefix + middle + suffix;
                if (ans == "" || encoded.size() < ans.size()) ans = encoded;
            }
        }
        return ans;
    }
};
```