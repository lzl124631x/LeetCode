# [1177. Can Make Palindrome from Substring (Medium)](https://leetcode.com/problems/can-make-palindrome-from-substring/)

<p>Given a string <code>s</code>, we make queries on substrings of <code>s</code>.</p>

<p>For each query <code>queries[i] = [left, right, k]</code>, we may <strong>rearrange</strong>&nbsp;the substring <code>s[left], ..., s[right]</code>, and then choose <strong>up to</strong> <code>k</code> of them to replace with any lowercase English letter.&nbsp;</p>

<p>If the substring&nbsp;is possible to be a&nbsp;palindrome string after the operations above, the result of the query is <code>true</code>.&nbsp;Otherwise, the result&nbsp;is <code>false</code>.</p>

<p>Return an array <code>answer[]</code>, where <code>answer[i]</code> is the result of the <code>i</code>-th query <code>queries[i]</code>.</p>

<p>Note that: Each letter is counted <strong>individually</strong> for replacement so&nbsp;if for example&nbsp;<code>s[left..right] = "aaa"</code>, and <code>k = 2</code>, we can only replace two of the letters.&nbsp; (Also, note that the initial string <code>s</code>&nbsp;is never modified by any query.)</p>

<p>&nbsp;</p>
<p><strong>Example :</strong></p>

<pre><strong>Input:</strong> s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
<strong>Output:</strong> [true,false,false,true,true]
<strong>Explanation:</strong>
queries[0] : substring = "d", is palidrome.
queries[1] :&nbsp;substring = "bc", is not palidrome.
queries[2] :&nbsp;substring = "abcd", is not palidrome after replacing only 1 character.
queries[3] :&nbsp;substring = "abcd", could be changed to "abba" which is palidrome. Also this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
queries[4] :&nbsp;substring = "abcda",&nbsp;could be changed to "abcba" which is palidrome.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length,&nbsp;queries.length&nbsp;&lt;= 10^5</code></li>
	<li><code>0 &lt;= queries[i][0] &lt;= queries[i][1] &lt;&nbsp;s.length</code></li>
	<li><code>0 &lt;= queries[i][2] &lt;= s.length</code></li>
	<li><code>s</code> only contains lowercase English letters.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/can-make-palindrome-from-substring/
// Author: github.com/lzl124631x
// Time: O(N + Q)
// Space: O(N)
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& Q) {
        int N = s.size();
        vector<array<int, 26>> cnts(N);
        for (int i = 0; i < N; ++i) {
            if (i > 0) cnts[i] = cnts[i - 1];
            cnts[i][s[i] - 'a']++;
        }
        vector<bool> ans;
        for (auto &q : Q) {
            int from = q[0], to = q[1], k = q[2], odd = 0;
            auto cnt = cnts[to];
            if (from != 0) {
                for (int i = 0; i < 26; ++i) {
                    cnt[i] -= cnts[from - 1][i];
                }
            }
            for (int i = 0; i < 26; ++i) {
                odd += cnt[i] % 2;
            }
            ans.push_back(odd - 2 * k <= 1);
        }
        return ans;
    }
};
```

Or use bit mask

```cpp
// OJ: https://leetcode.com/problems/can-make-palindrome-from-substring/
// Author: github.com/lzl124631x
// Time: O(N + Q)
// Space: O(N)
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& Q) {
        int N = s.size(), mask = 0;
        vector<int> odds(1);
        for (char c : s) {
            odds.push_back(mask ^= (1 << (c - 'a')));
        }
        vector<bool> ans;
        for (auto &q : Q) {
            int from = q[0], to = q[1], k = q[2], odd = odds[to + 1] ^ odds[from], cnt = __builtin_popcount(odd);
            ans.push_back(cnt - 2 * k <= 1);
        }
        return ans;
    }
};
```