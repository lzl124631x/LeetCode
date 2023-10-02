# [2381. Shifting Letters II (Medium)](https://leetcode.com/problems/shifting-letters-ii)

<p>You are given a string <code>s</code> of lowercase English letters and a 2D integer array <code>shifts</code> where <code>shifts[i] = [start<sub>i</sub>, end<sub>i</sub>, direction<sub>i</sub>]</code>. For every <code>i</code>, <strong>shift</strong> the characters in <code>s</code> from the index <code>start<sub>i</sub></code> to the index <code>end<sub>i</sub></code> (<strong>inclusive</strong>) forward if <code>direction<sub>i</sub> = 1</code>, or shift the characters backward if <code>direction<sub>i</sub> = 0</code>.</p>
<p>Shifting a character <strong>forward</strong> means replacing it with the <strong>next</strong> letter in the alphabet (wrapping around so that <code>'z'</code> becomes <code>'a'</code>). Similarly, shifting a character <strong>backward</strong> means replacing it with the <strong>previous</strong> letter in the alphabet (wrapping around so that <code>'a'</code> becomes <code>'z'</code>).</p>
<p>Return <em>the final string after all such shifts to </em><code>s</code><em> are applied</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
<strong>Output:</strong> "ace"
<strong>Explanation:</strong> Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "dztz", shifts = [[0,0,0],[1,1,1]]
<strong>Output:</strong> "catz"
<strong>Explanation:</strong> Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length, shifts.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>shifts[i].length == 3</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt; s.length</code></li>
	<li><code>0 &lt;= direction<sub>i</sub> &lt;= 1</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

**Companies**:
[Veritas](https://leetcode.com/company/veritas)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [The Skyline Problem (Hard)](https://leetcode.com/problems/the-skyline-problem/)
* [Range Sum Query - Mutable (Medium)](https://leetcode.com/problems/range-sum-query-mutable/)
* [Range Addition (Medium)](https://leetcode.com/problems/range-addition/)
* [Shifting Letters (Medium)](https://leetcode.com/problems/shifting-letters/)
* [Maximum Population Year (Easy)](https://leetcode.com/problems/maximum-population-year/)
* [Describe the Painting (Medium)](https://leetcode.com/problems/describe-the-painting/)

## Solution 1. Difference Array

```cpp
// OJ: https://leetcode.com/problems/shifting-letters-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& A) {
        int N = s.size();
        vector<int> d(N);
        for (auto &shift : A) {
            int start = shift[0], end = shift[1], direction = shift[2], diff = direction == 0 ? -1 : 1;
            d[start] = (d[start] + diff + 26) % 26;
            if (end + 1 < N) d[end + 1] = (d[end + 1] - diff + 26) % 26;
        }
        for (int i = 0, diff = 0; i < N; ++i) {
            diff = (diff + d[i] + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + diff) % 26;
        }
        return s;
    }
};
```