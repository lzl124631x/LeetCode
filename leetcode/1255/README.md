# [1255. Maximum Score Words Formed by Letters (Hard)](https://leetcode.com/problems/maximum-score-words-formed-by-letters/)

<p>Given a list of <code>words</code>, list of&nbsp; single&nbsp;<code>letters</code> (might be repeating)&nbsp;and <code>score</code>&nbsp;of every character.</p>

<p>Return the maximum score of <strong>any</strong> valid set of words formed by using the given letters (<code>words[i]</code> cannot be used two&nbsp;or more times).</p>

<p>It is not necessary to use all characters in <code>letters</code> and each letter can only be used once. Score of letters&nbsp;<code>'a'</code>, <code>'b'</code>, <code>'c'</code>, ... ,<code>'z'</code> is given by&nbsp;<code>score[0]</code>, <code>score[1]</code>, ... , <code>score[25]</code> respectively.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
<strong>Output:</strong> 23
<strong>Explanation:</strong>
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
<strong>Output:</strong> 27
<strong>Explanation:</strong>
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
Letter "e" can only be used once.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 14</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 15</code></li>
	<li><code>1 &lt;= letters.length &lt;= 100</code></li>
	<li><code>letters[i].length == 1</code></li>
	<li><code>score.length ==&nbsp;26</code></li>
	<li><code>0 &lt;= score[i] &lt;= 10</code></li>
	<li><code>words[i]</code>, <code>letters[i]</code>&nbsp;contains only lower case English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Bitmask](https://leetcode.com/tag/bitmask/)

## Solution 1. Bitmask

```cpp
// OJ: https://leetcode.com/problems/maximum-score-words-formed-by-letters/
// Author: github.com/lzl124631x
// Time: O(2^N * NC + NW) where `N` is the length of `A`, `C` is the range of characters, and `W` is the maximum length of `A[i]`.
// Space: O(NC)
class Solution {
public:
    int maxScoreWords(vector<string>& A, vector<char>& letters, vector<int>& score) {
        int avail[26] = {}, ans = 0, cnt[14][26] = {}, N = A.size();
        for (char c : letters) avail[c - 'a']++;
        for (int i = 0; i < N; ++i) {
            for (char c : A[i]) cnt[i][c - 'a']++;
        }
        for (int m = 1; m < 1 << N; ++m) {
            int total[26] = {};
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) {
                    for (int j = 0; j < 26; ++j) total[j] += cnt[i][j];
                }
            }
            int i = 0;
            for (; i < 26 && total[i] <= avail[i]; ++i);
            if (i < 26) continue;
            int val = 0;
            for (int i = 0; i < 26; ++i) val += total[i] * score[i];
            ans = max(ans, val);
        }
        return ans;
    }
};
```

## Solution 2. Bitmask DP

We can also use DP but for this problem it's slower and takes more space.

```cpp
// OJ: https://leetcode.com/problems/maximum-score-words-formed-by-letters/
// Author: github.com/lzl124631x
// Time: O(2^N * C)
// Space: O(2^N * C)
class Solution {
public:
    int maxScoreWords(vector<string>& A, vector<char>& letters, vector<int>& score) {
        int avail[26] = {}, ans = 0, cnt[14][26] = {}, wordScore[14] = {}, N = A.size();
        vector<array<int, 26>> used(1 << N);
        vector<int> scoreSum(1 << N);
        for (char c : letters) avail[c - 'a']++;
        for (int i = 0; i < N; ++i) {
            for (char c : A[i]) {
                cnt[i][c - 'a']++;
                wordScore[i] += score[c - 'a'];
            }
        }
        for (int m = 1; m < 1 << N; ++m) {
            int lb = m & -m, i = __builtin_ctz(lb);
            used[m] = used[m - lb];
            for (int j = 0; j < 26; ++j) used[m][j] += cnt[i][j];
            int j = 0;
            for (; j < 26 && used[m][j] <= avail[j]; ++j);
            if (j < 26) continue;
            scoreSum[m] = scoreSum[m - lb] + wordScore[i];
            ans = max(ans, scoreSum[m]);
        }
        return ans;
    }
};
```