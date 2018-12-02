# [828. Unique Letter String (Hard)](https://leetcode.com/problems/unique-letter-string/)

<p>A character is unique in string <code>S</code> if it occurs exactly once in it.</p>

<p>For example, in string <code>S = "LETTER"</code>, the only unique characters are <code>"L"</code> and <code>"R"</code>.</p>

<p>Let's define <code>UNIQ(S)</code> as the number of unique characters in string <code>S</code>.</p>

<p>For example, <code>UNIQ("LETTER") =&nbsp; 2</code>.</p>

<p>Given a string <code>S</code> with only uppercases, calculate the sum of <code>UNIQ(substring)</code> over all non-empty substrings of <code>S</code>.</p>

<p>If there are two or more equal substrings at different positions in <code>S</code>, we consider them different.</p>

<p>Since the answer can be very large, return&nbsp;the answer&nbsp;modulo&nbsp;<code>10 ^ 9 + 7</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>"ABC"
<strong>Output: </strong>10
<strong>Explanation: </strong>All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>"ABA"
<strong>Output: </strong>8
<strong>Explanation: </strong>The same as example 1, except uni("ABA") = 1.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong> <code>0 &lt;= S.length &lt;= 10000</code>.</p>


**Companies**:  
[ForUsAll](https://leetcode.com/company/forusall)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1. Brute Force

Keep track of counts of letters. When the count reachs 1, increment unique count. When the count reachs 2, decrement unique count.

```cpp
// OJ: https://leetcode.com/problems/unique-letter-string
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int uniqueLetterString(string S) {
        int mod = 1e9 + 7, N = S.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            int cnts[26] = {0}, prev = 0, two = 0;
            for (int j = i; j < N && two != 26; ++j) {
                cnts[S[j] - 'A']++;
                int cur = prev;
                if (cnts[S[j] - 'A'] == 1) ++cur;
                else if (cnts[S[j] - 'A'] == 2) {
                    --cur;
                    two++;
                }
                ans = (ans + cur) % mod;
                prev = cur;
            }
        }
        return ans;
    }
};
```

## Solution 2. Split by Letter

Look at each letter one by one. Consider a sequence `A B A CD A`, assume the indexes of `A` are `[0,2,5]`. For the middle `A`, how many times does it show up in the substrings?

```
BA
BAC
BACD
A
AC
ACD
```

6 times. Because the start position can be 1 or 2 (from `B` or from middle `A`), and the end position can be 3, 4, or 5 (ends before `C`, `D`, or `A`). They are simply the difference between the indexes of `A`s. `6 = (2 - 0) * (5 - 2) = 2 * 3`.

So in general, keep track of positions of letters. `(pos[i - 1] - pos[i]) * (pos[i + 1] - pos[i])` is the unique count of letter `S[i]` in all substrings.

```cpp
// OJ: https://leetcode.com/problems/unique-letter-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int uniqueLetterString(string S) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < S.size(); ++i) {
            m[S[i]].push_back(i);
        }
        int ans = 0, mod = 1e9 + 7;
        for (auto it = m.begin(); it != m.end(); ++it) {
            char c = it->first;
            auto &v = it->second;
            for (int i = 0; i < v.size(); ++i) {
                int prev = i == 0 ? -1 : v[i - 1];
                int next = i < v.size() - 1 ? v[i + 1] : S.size();
                ans = (ans + (v[i] - prev) * (next - v[i]) % mod) % mod;
            }
        }
        return ans;
    }
};
```