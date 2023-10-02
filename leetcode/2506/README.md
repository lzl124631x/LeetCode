# [2506. Count Pairs Of Similar Strings (Easy)](https://leetcode.com/problems/count-pairs-of-similar-strings)

<p>You are given a <strong>0-indexed</strong> string array <code>words</code>.</p>
<p>Two strings are <strong>similar</strong> if they consist of the same characters.</p>
<ul>
	<li>For example, <code>"abca"</code> and <code>"cba"</code> are similar since both consist of characters <code>'a'</code>, <code>'b'</code>, and <code>'c'</code>.</li>
	<li>However, <code>"abacba"</code> and <code>"bcfd"</code> are not similar since they do not consist of the same characters.</li>
</ul>
<p>Return <em>the number of pairs </em><code>(i, j)</code><em> such that </em><code>0 &lt;= i &lt; j &lt;= word.length - 1</code><em> and the two strings </em><code>words[i]</code><em> and </em><code>words[j]</code><em> are similar</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> words = ["aba","aabb","abcd","bac","aabc"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 pairs that satisfy the conditions:
- i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
- i = 3 and j = 4 : both words[3] and words[4] only consist of characters 'a', 'b', and 'c'. 
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> words = ["aabb","ab","ba"]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 pairs that satisfy the conditions:
- i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
- i = 0 and j = 2 : both words[0] and words[2] only consist of characters 'a' and 'b'.
- i = 1 and j = 2 : both words[1] and words[2] only consist of characters 'a' and 'b'.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> words = ["nba","cba","dba"]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since there does not exist any pair that satisfies the conditions, we return 0.</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> consist of only lowercase English letters.</li>
</ul>

**Companies**:
[Oracle](https://leetcode.com/company/oracle)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)
* [Count the Number of Consistent Strings (Easy)](https://leetcode.com/problems/count-the-number-of-consistent-strings/)
* [Number of Good Paths (Hard)](https://leetcode.com/problems/number-of-good-paths/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-pairs-of-similar-strings
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(N)
class Solution {
public:
    int similarPairs(vector<string>& A) {
        unordered_map<int, int> m;
        int ans = 0;
        for (auto &s : A) {
            int bits = 0;
            for (char c : s) bits |= (1 << (c - 'a'));
            ans += m[bits];
            m[bits]++;
        }
        return ans;
    }
};
```