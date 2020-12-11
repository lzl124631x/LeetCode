# [1307. Verbal Arithmetic Puzzle (Hard)](https://leetcode.com/problems/verbal-arithmetic-puzzle/)

<p>Given an equation, represented by <code>words</code> on left side and the <code>result</code> on right side.</p>

<p>You need to check if the equation is solvable&nbsp;under the following rules:</p>

<ul>
	<li>Each character is decoded as one digit (0 - 9).</li>
	<li>Every pair of different characters they must map to different digits.</li>
	<li>Each <code>words[i]</code> and <code>result</code>&nbsp;are decoded as one number <strong>without</strong> leading zeros.</li>
	<li>Sum of numbers on left side (<code>words</code>) will equal to the number on right side (<code>result</code>).&nbsp;</li>
</ul>

<p>Return <code>True</code>&nbsp;if the equation is solvable otherwise&nbsp;return&nbsp;<code>False</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["SEND","MORE"], result = "MONEY"
<strong>Output:</strong> true
<strong>Explanation:</strong> Map 'S'-&gt; 9, 'E'-&gt;5, 'N'-&gt;6, 'D'-&gt;7, 'M'-&gt;1, 'O'-&gt;0, 'R'-&gt;8, 'Y'-&gt;'2'
Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
<strong>Output:</strong> true
<strong>Explanation:</strong> Map 'S'-&gt; 6, 'I'-&gt;5, 'X'-&gt;0, 'E'-&gt;8, 'V'-&gt;7, 'N'-&gt;2, 'T'-&gt;1, 'W'-&gt;'3', 'Y'-&gt;4
Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["THIS","IS","TOO"], result = "FUNNY"
<strong>Output:</strong> true
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> words = ["LEET","CODE"], result = "POINT"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= words.length &lt;= 5</code></li>
	<li><code>1 &lt;= words[i].length,&nbsp;result.length&nbsp;&lt;= 7</code></li>
	<li><code>words[i], result</code>&nbsp;contains only upper case English letters.</li>
	<li>Number of different characters used on the expression is at most&nbsp;10.</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1. Backtracking

Try to map the characters from right to left so that we can check the validity along the way.

### Time complexity

Assume the maximum length of `result` or `words[i]` is `L`, and `words` is of length `W`.

There are `L!` permutations. For each permutation, we need to check validity. Checking validity takes `O(LW)`. We check validity when each new character is mapped, so we check `L` times for a permutation.

So overall the time complexity is `O(L! * L^2 * W)`.

```cpp
// OJ: https://leetcode.com/problems/verbal-arithmetic-puzzle/
// Author: github.com/lzl124631x
// Time: O(L! * L^2 * W)
// Space: O(L)
class Solution {
    unordered_map<char, int> m; // map from char to the corresponding integer
    vector<char> chs; // chars to consider, right most chars are first considered.
    unordered_set<char> leading; // leading chars can't be zero
    int used[10] = {}; // digit `i` is used if `used[i] == 1`
    bool valid(vector<string>& words, string result) { // check if the current map `m` is valid
        int sum = 0;
        for (int i = 0; i < result.size(); ++i) {
            for (auto &w : words) {
                if (i >= w.size()) continue;
                char c = w[w.size() - i - 1];
                if (m.count(c) == 0) return true;
                sum += m[c];
            }
            char c = result[result.size() - i - 1];
            if (m.count(c) == 0) return true;
            sum -= m[c];
            if (sum % 10) return false;
            sum /= 10;
        }
        return true;
    }
    bool dfs(vector<string>& words, string result, int index) {
        if (index == chs.size()) return true;
        for (int i = 0; i < 10; ++i) {
            if (used[i] || (i == 0 && leading.count(chs[index]))) continue;
            used[i] = 1;
            m[chs[index]] = i;
            if (valid(words, result) && dfs(words, result, index + 1)) return true;
            m.erase(chs[index]);
            used[i] = 0;
        }
        return false;
    }
    void addChar(char ch) {
        for (char c : chs) {
            if (c == ch) return;
        }
        chs.push_back(ch);
    }
public:
    bool isSolvable(vector<string>& words, string result) {
        for (auto &w : words) {
            if (w.size() > result.size()) return false;
            if (w.size() > 1) leading.insert(w[0]);
        }
        if (result.size() > 1) leading.insert(result[0]);
        for (int i = 0; i < result.size(); ++i) {
            for (auto &w : words) {
                if (i < w.size()) addChar(w[w.size() - i - 1]);
            }
            addChar(result[result.size() - i - 1]);
        }
        return dfs(words, result, 0);
    }
};
```