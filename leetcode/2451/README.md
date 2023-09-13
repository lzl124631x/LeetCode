# [2451. Odd String Difference (Easy)](https://leetcode.com/problems/odd-string-difference)

<p>You are given an array of equal-length strings <code>words</code>. Assume that the length of each string is <code>n</code>.</p>
<p>Each string <code>words[i]</code> can be converted into a <strong>difference integer array</strong> <code>difference[i]</code> of length <code>n - 1</code> where <code>difference[i][j] = words[i][j+1] - words[i][j]</code> where <code>0 &lt;= j &lt;= n - 2</code>. Note that the difference between two letters is the difference between their <strong>positions</strong> in the alphabet i.e.&nbsp;the position of <code>'a'</code> is <code>0</code>, <code>'b'</code> is <code>1</code>, and <code>'z'</code> is <code>25</code>.</p>
<ul>
	<li>For example, for the string <code>"acb"</code>, the difference integer array is <code>[2 - 0, 1 - 2] = [2, -1]</code>.</li>
</ul>
<p>All the strings in words have the same difference integer array, <strong>except one</strong>. You should find that string.</p>
<p>Return<em> the string in </em><code>words</code><em> that has different <strong>difference integer array</strong>.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> words = ["adc","wzy","abc"]
<strong>Output:</strong> "abc"
<strong>Explanation:</strong> 
- The difference integer array of "adc" is [3 - 0, 2 - 3] = [3, -1].
- The difference integer array of "wzy" is [25 - 22, 24 - 25]= [3, -1].
- The difference integer array of "abc" is [1 - 0, 2 - 1] = [1, 1]. 
The odd array out is [1, 1], so we return the corresponding string, "abc".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> words = ["aaa","bob","ccc","ddd"]
<strong>Output:</strong> "bob"
<strong>Explanation:</strong> All the integer arrays are [0, 0] except for "bob", which corresponds to [13, -13].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>3 &lt;= words.length &lt;= 100</code></li>
	<li><code>n == words[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 20</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
</ul>

**Companies**:
[Visa](https://leetcode.com/company/visa)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Minimum Rounds to Complete All Tasks (Medium)](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/odd-string-difference
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(W)
class Solution {
public:
    string oddString(vector<string>& A) {
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < A.size(); ++i) {
            auto s = A[i];
            int d = s[0] - 'a';
            for (char &c : s) c = 'a' + (c - 'a' - d + 26) % 26;
            if (m[s].size() < 2) m[s].push_back(i);
        }
        for (auto &[s, v] : m) {
            if (v.size() == 1) return A[v[0]];
        }
        return "";
    }
};
```