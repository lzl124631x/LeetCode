# [792. Number of Matching Subsequences (Medium)](https://leetcode.com/problems/number-of-matching-subsequences/)

<p>Given a string <code>s</code> and an array of strings <code>words</code>, return <em>the number of</em> <code>words[i]</code> <em>that is a subsequence of</em> <code>s</code>.</p>

<p>A <strong>subsequence</strong> of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.</p>

<ul>
	<li>For example, <code>"ace"</code> is a subsequence of <code>"abcde"</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcde", words = ["a","bb","acd","ace"]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three strings in words that are a subsequence of s: "a", "acd", "ace".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>s</code> and <code>words[i]</code> consist of only lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Coupang](https://leetcode.com/company/coupang)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Is Subsequence (Easy)](https://leetcode.com/problems/is-subsequence/)
* [Shortest Way to Form String (Medium)](https://leetcode.com/problems/shortest-way-to-form-string/)

## Solution 1. Next Pointers

Given the constraints, we can't compare each `A[i]` with `s` to check if `A[i]` is a subsequence of `s` because each of these comparison takes `O(W + S)` time so the overall time complexity is `O(N * (W + S))` which will get TLE.

We can first preprocess `s` in a way such that checking if `A[i]` is a subsequence of `s` only takes `O(W)` time, then the time complexity becomes `O(NW)` for the subsequence checking part.

```cpp
// OJ: https://leetcode.com/problems/number-of-matching-subsequences/
// Author: github.com/lzl124631x
// Time: O(SC + NW) where S is the length of `s`, C is the range of characters, N is the length of `A` and W is the maximum length of strings in `A`
// Space: O(SC)
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& A) {
        int next[50002][26] = {}, N = s.size(), ans = 0;
        memset(next, -1, sizeof(next));
        for (int i = N - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) next[i][j] = next[i + 1][j];
            next[i][s[i] - 'a'] = i + 1;
        }
        for (auto &w : A) {
            int i = 0, j = 0;
            for (; i < w.size() && next[j][w[i] - 'a'] != -1; ++i) {
                j = next[j][w[i] - 'a'];
            }
            if (i == w.size()) ++ans;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/number-of-matching-subsequences/
// Author: github.com/lzl124631x
// Time: O(S + NWlogS)
// Space: O(S)
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& A) {
        vector<int> index[26];
        for (int i = 0; i < s.size(); ++i) index[s[i] - 'a'].push_back(i);
        int ans = 0;
        for (auto &w : A) {
            int i = 0, j = 0;
            for (; i < w.size(); ++i) {
                auto &v = index[w[i] - 'a'];
                auto it = lower_bound(begin(v), end(v), j);
                if (it == end(v)) break;
                j = *it + 1;
            }
            ans += i == w.size();
        }
        return ans;
    }
};
```

## Solution 3. Separate Task Queues

1. Split the words into different queues each of which corresponds to one of the 26 English letters.
2. A queue is activated when we see the corresponding letter in `s`. We move all the pointers in the queue forward, and distribute the pointers into the new queues based on the next letter.
3. In the end, the words left in the queue are those that are not subsequence of `s`.

```cpp
// OJ: https://leetcode.com/problems/number-of-matching-subsequences/
// Author: github.com/lzl124631x
// Time: O(S + NW)
// Space: O(N)
// Ref: https://leetcode.com/problems/number-of-matching-subsequences/discuss/117634/Efficient-and-simple-go-through-words-in-parallel-with-explanation
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& A) {
        int N = A.size(), sum = 0;
        queue<pair<int, int>> q[26];
        for (int i = 0; i < N; ++i) q[A[i][0] - 'a'].emplace(i, 0);
        for (char c : s) {
            int cnt = q[c - 'a'].size();
            while (cnt--) {
                auto [i, j] = q[c - 'a'].front();
                q[c - 'a'].pop();
                if (A[i][j] == c) ++j;
                if (j == A[i].size()) continue;
                q[A[i][j] - 'a'].emplace(i, j);
            }
        }
        for (int i = 0; i < 26; ++i) sum += q[i].size();
        return A.size() - sum;
    }
};
```
