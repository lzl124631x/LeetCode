# [2060. Check if an Original String Exists Given Two Encoded Strings (Hard)](https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/)

<p>An original string, consisting of lowercase English letters, can be encoded by the following steps:</p>

<ul>
	<li>Arbitrarily <strong>split</strong> it into a <strong>sequence</strong> of some number of <strong>non-empty</strong> substrings.</li>
	<li>Arbitrarily choose some elements (possibly none) of the sequence, and <strong>replace</strong> each with <strong>its length</strong> (as a numeric string).</li>
	<li><strong>Concatenate</strong> the sequence as the encoded string.</li>
</ul>

<p>For example, <strong>one way</strong> to encode an original string <code>"abcdefghijklmnop"</code> might be:</p>

<ul>
	<li>Split it as a sequence: <code>["ab", "cdefghijklmn", "o", "p"]</code>.</li>
	<li>Choose the second and third elements to be replaced by their lengths, respectively. The sequence becomes <code>["ab", "12", "1", "p"]</code>.</li>
	<li>Concatenate the elements of the sequence to get the encoded string: <code>"ab121p"</code>.</li>
</ul>

<p>Given two encoded strings <code>s1</code> and <code>s2</code>, consisting of lowercase English letters and digits <code>1-9</code> (inclusive), return <code>true</code><em> if there exists an original string that could be encoded as <strong>both</strong> </em><code>s1</code><em> and </em><code>s2</code><em>. Otherwise, return </em><code>false</code>.</p>

<p><strong>Note</strong>: The test cases are generated such that the number of consecutive digits in <code>s1</code> and <code>s2</code> does not exceed <code>3</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "internationalization", s2 = "i18n"
<strong>Output:</strong> true
<strong>Explanation:</strong> It is possible that "internationalization" was the original string.
- "internationalization" 
  -&gt; Split:       ["internationalization"]
  -&gt; Do not replace any element
  -&gt; Concatenate:  "internationalization", which is s1.
- "internationalization"
  -&gt; Split:       ["i", "nternationalizatio", "n"]
  -&gt; Replace:     ["i", "18",                 "n"]
  -&gt; Concatenate:  "i18n", which is s2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "l123e", s2 = "44"
<strong>Output:</strong> true
<strong>Explanation:</strong> It is possible that "leetcode" was the original string.
- "leetcode" 
  -&gt; Split:      ["l", "e", "et", "cod", "e"]
  -&gt; Replace:    ["l", "1", "2",  "3",   "e"]
  -&gt; Concatenate: "l123e", which is s1.
- "leetcode" 
  -&gt; Split:      ["leet", "code"]
  -&gt; Replace:    ["4",    "4"]
  -&gt; Concatenate: "44", which is s2.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s1 = "a5b", s2 = "c5b"
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible.
- The original string encoded as s1 must start with the letter 'a'.
- The original string encoded as s2 must start with the letter 'c'.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s1 = "112s", s2 = "g841"
<strong>Output:</strong> true
<strong>Explanation:</strong> It is possible that "gaaaaaaaaaaaas" was the original string
- "gaaaaaaaaaaaas"
  -&gt; Split:      ["g", "aaaaaaaaaaaa", "s"]
  -&gt; Replace:    ["1", "12",           "s"]
  -&gt; Concatenate: "112s", which is s1.
- "gaaaaaaaaaaaas"
  -&gt; Split:      ["g", "aaaaaaaa", "aaaa", "s"]
  -&gt; Replace:    ["g", "8",        "4",    "1"]
  -&gt; Concatenate: "g841", which is s2.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s1 = "ab", s2 = "a2"
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible.
- The original string encoded as s1 has two letters.
- The original string encoded as s2 has three letters.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 40</code></li>
	<li><code>s1</code> and <code>s2</code> consist of digits <code>1-9</code> (inclusive), and lowercase English letters only.</li>
	<li>The number of consecutive digits in <code>s1</code> and <code>s2</code> does not exceed <code>3</code>.</li>
</ul>


**Similar Questions**:
* [Valid Word Abbreviation (Easy)](https://leetcode.com/problems/valid-word-abbreviation/)
* [Check If Two String Arrays are Equivalent (Easy)](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/
// Author: github.com/lzl124631x
// Time: O(C * MN) where `C` is the range of the possible length differences. It's [-10,000, 10,000] in this problem
// Space: O(C * MN)
// Ref: https://leetcode-cn.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/solution/dong-tai-gui-hua-ji-lu-ke-neng-de-chang-o87gp/
class Solution {
public:
    bool possiblyEquals(string s, string t) {
        int M = s.size(), N = t.size();
        unordered_set<int> dp[41][41] = {};
        dp[0][0].insert(0);
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                for (int delta : dp[i][j]) {
                    int num = 0;
                    for (int p = i; p < M && isdigit(s[p]); ++p) {
                        num = num * 10 + (s[p] - '0');
                        dp[p + 1][j].insert(delta + num);
                    }
                    num = 0;
                    for (int p = j; p < N && isdigit(t[p]); ++p) {
                        num = num * 10 + (t[p] - '0');
                        dp[i][p + 1].insert(delta - num);
                    }
                    if (i < M && delta < 0 && isalpha(s[i])) dp[i + 1][j].insert(delta + 1);
                    if (j < N && delta > 0 && isalpha(t[j])) dp[i][j + 1].insert(delta - 1);
                    if (i < M && j < N && delta == 0 && s[i] == t[j]) dp[i + 1][j + 1].insert(0);
                }
            }
        }
        return dp[M][N].count(0);
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/
// Author: github.com/lzl124631x
// Time: O(MNC)
// Space: O(MNC) where C is the maximum possible difference of digits. Since there are at most 3 consecutive digits, the difference is at most 1000 (then it must try to match a letter)
// Ref: https://leetcode-cn.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/solution/ji-yi-hua-sou-suo-by-endlesscheng-ll3r/
class Solution {
public:
    bool possiblyEquals(string s, string t) {
        int M = s.size(), N = t.size();
        const int mx = 2001, bias = 1000;
        bool seen[41][41][mx] = {};
        function <bool(int, int, int)> dfs = [&](int i, int j, int d) {
            if (i == M && j == N) return d == 0;
            if (i > M || j > N) return false;
            if (seen[i][j][d + bias]) return false;
            seen[i][j][d + bias] = true;
            if (d == 0 && s[i] == t[j] && dfs(i + 1, j + 1, 0)) return true;
            if (d <= 0) {
                if (isdigit(s[i])) {
                    for (int p = i, num = 0; p < M && isdigit(s[p]); ++p) {
                        num = num * 10 + (s[p] - '0');
                        if (dfs(p + 1, j, d + num)) return true;
                    }
                } else if (d < 0 && dfs(i + 1, j, d + 1)) return true;
            }
            if (d >= 0) {
                if (isdigit(t[j])) {
                    for (int p = j, num = 0; p < N && isdigit(t[p]); ++p) {
                        num = num * 10 + (t[p] - '0');
                        if (dfs(i, p + 1, d - num)) return true;
                    }
                } else if (d > 0 && dfs(i, j + 1, d - 1)) return true;
            }
            return false;  
        };
        return dfs(0, 0, 0);
    }
};
```