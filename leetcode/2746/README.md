# [2746. Decremental String Concatenation (Medium)](https://leetcode.com/problems/decremental-string-concatenation)

<p>You are given a <strong>0-indexed</strong> array <code>words</code> containing <code>n</code> strings.</p>

<p>Let&#39;s define a <strong>join</strong> operation <code>join(x, y)</code> between two strings <code>x</code> and <code>y</code> as concatenating them into <code>xy</code>. However, if the last character of <code>x</code> is equal to the first character of <code>y</code>, one of them is <strong>deleted</strong>.</p>

<p>For example <code>join(&quot;ab&quot;, &quot;ba&quot;) = &quot;aba&quot;</code> and <code>join(&quot;ab&quot;, &quot;cde&quot;) = &quot;abcde&quot;</code>.</p>

<p>You are to perform <code>n - 1</code> <strong>join</strong> operations. Let <code>str<sub>0</sub> = words[0]</code>. Starting from <code>i = 1</code> up to <code>i = n - 1</code>, for the <code>i<sup>th</sup></code> operation, you can do one of the following:</p>

<ul>
	<li>Make <code>str<sub>i</sub> = join(str<sub>i - 1</sub>, words[i])</code></li>
	<li>Make <code>str<sub>i</sub> = join(words[i], str<sub>i - 1</sub>)</code></li>
</ul>

<p>Your task is to <strong>minimize</strong> the length of <code>str<sub>n - 1</sub></code>.</p>

<p>Return <em>an integer denoting the minimum possible length of</em> <code>str<sub>n - 1</sub></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;aa&quot;,&quot;ab&quot;,&quot;bc&quot;]
<strong>Output:</strong> 4
<strong>Explanation: </strong>In this example, we can perform join operations in the following order to minimize the length of str<sub>2</sub>: 
str<sub>0</sub> = &quot;aa&quot;
str<sub>1</sub> = join(str<sub>0</sub>, &quot;ab&quot;) = &quot;aab&quot;
str<sub>2</sub> = join(str<sub>1</sub>, &quot;bc&quot;) = &quot;aabc&quot; 
It can be shown that the minimum possible length of str<sub>2</sub> is 4.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;ab&quot;,&quot;b&quot;]
<strong>Output:</strong> 2
<strong>Explanation:</strong> In this example, str<sub>0</sub> = &quot;ab&quot;, there are two ways to get str<sub>1</sub>: 
join(str<sub>0</sub>, &quot;b&quot;) = &quot;ab&quot; or join(&quot;b&quot;, str<sub>0</sub>) = &quot;bab&quot;. 
The first string, &quot;ab&quot;, has the minimum length. Hence, the answer is 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;aaa&quot;,&quot;c&quot;,&quot;aba&quot;]
<strong>Output:</strong> 6
<strong>Explanation:</strong> In this example, we can perform join operations in the following order to minimize the length of str<sub>2</sub>: 
str<sub>0</sub> = &quot;aaa&quot;
str<sub>1</sub> = join(str<sub>0</sub>, &quot;c&quot;) = &quot;aaac&quot;
str<sub>2</sub> = join(&quot;aba&quot;, str<sub>1</sub>) = &quot;abaaac&quot;
It can be shown that the minimum possible length of str<sub>2</sub> is 6.
</pre>

<div class="notranslate" style="all: initial;">&nbsp;</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li>Each character in <code>words[i]</code> is an English lowercase letter</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [String](https://leetcode.com/tag/string), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Similar Questions**:
* [Largest Merge Of Two Strings (Medium)](https://leetcode.com/problems/largest-merge-of-two-strings)

**Hints**:
* Use dynamic programming with memoization.
* Notice that the first and last characters of a string are sufficient to determine the length of its concatenation with any other string.
* Define dp[i][first][last] as the shortest concatenation length of the first i words starting with a character first and ending with a character last. Convert characters to their ASCII codes if your programming language cannot implicitly convert them to array indices.

## Solution 1. DP

Let `dp[i][first][last]` be the shortest length of concatenated words using `A[0..i]`. The answer is `dp[N-1][i][j]` (`'a' <= i,j <= 'z'`).

```
dp[0][s[0]][s.back()] = s.size() where s = A[0]
```

```cpp
// Denote the first and last letters in `A[i]` as `first` and `last`
// We iterate all possible values of dp[i-1][a][b]
// If append A[i]
dp[i][a][last] = min( dp[i-1][a][b] + A[i].size() - (first == b))
// If prepend A[i]
dp[i][first][b] = min( dp[i-1][a][b] + A[i].size() - (last == a))
``````

```cpp
// OJ: https://leetcode.com/problems/decremental-string-concatenation
// Author: github.com/lzl124631x
// Time: O(N * C^2) where C is the size of character set
// Space: O(C^2)
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& A) {
        unordered_map<int, int> m{{(A[0][0] - 'a') * 100 + (A[0].back() - 'a'), A[0].size()}};
        for (int i = 1; i < A.size(); ++i) {
            unordered_map<int, int> next;
            int first = A[i][0] - 'a', last = A[i].back() - 'a', newLen = A[i].size();
            for (auto &[prev, len] : m) {
                int a = prev / 100, b = prev - a * 100;
                int code1 = a * 100 + last, len1 = len + newLen - (b == first);
                if (next.count(code1) == 0 || next[code1] > len1) next[code1] = len1;
                int code2 = first * 100 + b, len2 = len + newLen - (last == a);
                if (next.count(code2) == 0 || next[code2] > len2) next[code2] = len2;
            }
            swap(next, m);
        }
        int ans = INT_MAX;
        for (auto &[_, len] : m) ans = min(ans, len);
        return ans;
    }
};
```

Or 

```cpp
// OJ: https://leetcode.com/problems/decremental-string-concatenation
// Author: github.com/lzl124631x
// Time: O(N * C^2)
// Space: O(C^2)
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& A) {
        if (A.size() == 1) return A[0].size();
        int dp[26][26] = {}, ans = INT_MAX;
        dp[A[0][0] - 'a'][A[0].back() - 'a'] = A[0].size();
        for (int i = 1; i < A.size(); ++i) {
            int next[26][26] = {}, first = A[i][0] - 'a', last = A[i].back() - 'a', newLen = A[i].size();
            for (int a = 0; a < 26; ++a) {
                for (int b = 0; b < 26; ++b) {
                    if (dp[a][b] == 0) continue;
                    int len1 = dp[a][b] + newLen - (b == first);
                    if (next[a][last] == 0 || next[a][last] > len1) next[a][last] = len1;
                    int len2 = dp[a][b] + newLen - (last == a);
                    if (next[first][b] == 0 || next[first][b] > len2) next[first][b] = len2;
                    if (i == A.size() - 1) ans = min({ans, next[a][last], next[first][b]});
                }
            }
            swap(dp, next);
        }
        return ans;
    }
};
```