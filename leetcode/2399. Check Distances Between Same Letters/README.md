# [2399. Check Distances Between Same Letters (Easy)](https://leetcode.com/problems/check-distances-between-same-letters)

<p>You are given a <strong>0-indexed</strong> string <code>s</code> consisting of only lowercase English letters, where each letter in <code>s</code> appears <strong>exactly</strong> <strong>twice</strong>. You are also given a <strong>0-indexed</strong> integer array <code>distance</code> of length <code>26</code>.</p>

<p>Each letter in the alphabet is numbered from <code>0</code> to <code>25</code> (i.e. <code>'a' -&gt; 0</code>, <code>'b' -&gt; 1</code>, <code>'c' -&gt; 2</code>, ... , <code>'z' -&gt; 25</code>).</p>

<p>In a <strong>well-spaced</strong> string, the number of letters between the two occurrences of the <code>i<sup>th</sup></code> letter is <code>distance[i]</code>. If the <code>i<sup>th</sup></code> letter does not appear in <code>s</code>, then <code>distance[i]</code> can be <strong>ignored</strong>.</p>

<p>Return <code>true</code><em> if </em><code>s</code><em> is a <strong>well-spaced</strong> string, otherwise return </em><code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abaccb", distance = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
<strong>Output:</strong> true
<strong>Explanation:</strong>
- 'a' appears at indices 0 and 2 so it satisfies distance[0] = 1.
- 'b' appears at indices 1 and 5 so it satisfies distance[1] = 3.
- 'c' appears at indices 3 and 4 so it satisfies distance[2] = 0.
Note that distance[3] = 5, but since 'd' does not appear in s, it can be ignored.
Return true because s is a well-spaced string.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aa", distance = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
<strong>Output:</strong> false
<strong>Explanation:</strong>
- 'a' appears at indices 0 and 1 so there are zero letters between them.
Because distance[0] = 1, s is not a well-spaced string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 52</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
	<li>Each letter appears in <code>s</code> exactly twice.</li>
	<li><code>distance.length == 26</code></li>
	<li><code>0 &lt;= distance[i] &lt;= 50</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Shortest Distance to a Character (Easy)](https://leetcode.com/problems/shortest-distance-to-a-character/)

## Solution 1. Prefix State Map

```cpp
// OJ: https://leetcode.com/problems/check-distances-between-same-letters
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(26)
class Solution {
public:
    bool checkDistances(string s, vector<int>& A) {
        int index[26] = {[0 ... 25] = -1};
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            if (index[c] == -1) index[c] = i;
            else if (A[c] != i - index[c] - 1) return false;
        }
        return true;
    }
};
```