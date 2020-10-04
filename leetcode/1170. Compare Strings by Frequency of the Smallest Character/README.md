# [1170. Compare Strings by Frequency of the Smallest Character (Easy)](https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/)

<p>Let's define a function <code>f(s)</code> over a non-empty string <code>s</code>, which calculates the frequency of the smallest character in <code>s</code>. For example,&nbsp;if <code>s = "dcce"</code> then <code>f(s) = 2</code> because the smallest character is <code>"c"</code> and its frequency is 2.</p>

<p>Now, given string arrays <code>queries</code>&nbsp;and <code>words</code>, return an integer array <code>answer</code>, where each <code>answer[i]</code>&nbsp;is the number of words such that <code>f(queries[i])</code>&nbsp;&lt; <code>f(W)</code>, where <code>W</code>&nbsp;is a word in <code>words</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> queries = ["cbd"], words = ["zaaaz"]
<strong>Output:</strong> [1]
<strong>Explanation:</strong> On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") &lt; f("zaaaz").
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> On the first query only f("bbb") &lt; f("aaaa"). On the second query both f("aaa") and f("aaaa") are both &gt; f("cc").
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 2000</code></li>
	<li><code>1 &lt;= words.length &lt;= 2000</code></li>
	<li><code>1 &lt;= queries[i].length, words[i].length &lt;= 10</code></li>
	<li><code>queries[i][j]</code>, <code>words[i][j]</code> are English lowercase letters.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// Author: github.com/lzl124631x
// Time: O(W*Q)
// Space: O(W)
class Solution {
    int frequency(string &s) {
        int ch = 'z', cnt = 0;
        for (char c : s) {
            if (c < ch) {
                cnt = 1;
                ch = c;
            } else if (c == ch) ++cnt;
        }
        return cnt;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& Q, vector<string>& W) {
        vector<int> F(W.size()), ans;
        for (int i = 0; i < W.size(); ++i) F[i] = frequency(W[i]);
        for (auto &s : Q) {
            int cnt = 0, f = frequency(s);
            for (int i = 0; i < W.size(); ++i) cnt += F[i] > f;
            ans.push_back(cnt);
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// Author: github.com/lzl124631x
// Time: O(W + Q)
// Space: O(1)
class Solution {
    int frequency(string &s) {
        int ch = 'z', cnt = 0;
        for (char c : s) {
            if (c < ch) {
                cnt = 1;
                ch = c;
            } else if (c == ch) ++cnt;
        }
        return cnt;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& Q, vector<string>& W) {
        vector<int> F(11), ans;
        for (int i = 0; i < W.size(); ++i) F[frequency(W[i])]++;
        for (int i = 1; i < 11; ++i) F[i] += F[i - 1];
        for (auto &s : Q) ans.push_back(W.size() - F[frequency(s)]);
        return ans;
    }
};
```