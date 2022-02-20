# [2182. Construct String With Repeat Limit (Medium)](https://leetcode.com/problems/construct-string-with-repeat-limit/)

<p>You are given a string <code>s</code> and an integer <code>repeatLimit</code>. Construct a new string <code>repeatLimitedString</code> using the characters of <code>s</code> such that no letter appears <strong>more than</strong> <code>repeatLimit</code> times <strong>in a row</strong>. You do <strong>not</strong> have to use all characters from <code>s</code>.</p>

<p>Return <em>the <strong>lexicographically largest</strong> </em><code>repeatLimitedString</code> <em>possible</em>.</p>

<p>A string <code>a</code> is <strong>lexicographically larger</strong> than a string <code>b</code> if in the first position where <code>a</code> and <code>b</code> differ, string <code>a</code> has a letter that appears later in the alphabet than the corresponding letter in <code>b</code>. If the first <code>min(a.length, b.length)</code> characters do not differ, then the longer string is the lexicographically larger one.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "cczazcc", repeatLimit = 3
<strong>Output:</strong> "zzcccac"
<strong>Explanation:</strong> We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aababab", repeatLimit = 2
<strong>Output:</strong> "bbabaa"
<strong>Explanation:</strong> We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= repeatLimit &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Rearrange String k Distance Apart (Hard)](https://leetcode.com/problems/rearrange-string-k-distance-apart/)

## Solution 1. Greedy + Counting

Store frequency of characters in `int cnt[26]`.

We pick characters in batches. In each batch, we pick the first character from `z` to `a` whose `cnt` is positive with the following caveats:
1. If the current character is the same as the one used in the previous batch, we need to skip it.
2. On top of case 1, if the `cnt` of the character used in the previous batch is positive, then we can only fill a single character in this batch.

```cpp
// OJ: https://leetcode.com/problems/construct-string-with-repeat-limit/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        int cnt[26] = {};
        string ans;
        for (char c : s) cnt[c - 'a']++;
        while (true) {
            int i = 25;
            bool onlyOne = false;
            for (; i >= 0; --i) {
                if (ans.size() && i == ans.back() - 'a' && cnt[i]) { // the character of our last batch still has some count left, so we only insert a single character in this batch
                    onlyOne = true;
                    continue;
                }
                if (cnt[i]) break; // found a character with positive count, fill with this character
            }
            if (i == -1) break; // no more characters to fill, break;
            int fill = onlyOne ? 1 : min(cnt[i], limit);
            cnt[i] -= fill;
            while (fill--) ans += 'a' + i;
        }
        return ans;
    }
};
```
## Discuss

https://leetcode.com/problems/construct-string-with-repeat-limit/discuss/1784718

## Note

I saw some code with the following loops

```cpp
for (int i = 1; i <= 100000; ++i) {
    for (int j = i; j <= 100000; j += i) {
        // Some O(1) operation
    }
}
```

The time complexity of these loops is roughly `O(NlogN)`. Because `1/1+1/2+...+1/N` is roughly `logN`. See https://math.stackexchange.com/questions/3367037/sum-of-1-1-2-1-3-1-n