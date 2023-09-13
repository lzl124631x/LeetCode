# [2138. Divide a String Into Groups of Size k (Easy)](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/)

<p>A string <code>s</code> can be partitioned into groups of size <code>k</code> using the following procedure:</p>

<ul>
	<li>The first group consists of the first <code>k</code> characters of the string, the second group consists of the next <code>k</code> characters of the string, and so on. Each character can be a part of <strong>exactly one</strong> group.</li>
	<li>For the last group, if the string <strong>does not</strong> have <code>k</code> characters remaining, a character <code>fill</code> is used to complete the group.</li>
</ul>

<p>Note that the partition is done so that after removing the <code>fill</code> character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be <code>s</code>.</p>

<p>Given the string <code>s</code>, the size of each group <code>k</code> and the character <code>fill</code>, return <em>a string array denoting the <strong>composition of every group</strong> </em><code>s</code><em> has been divided into, using the above procedure</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcdefghi", k = 3, fill = "x"
<strong>Output:</strong> ["abc","def","ghi"]
<strong>Explanation:</strong>
The first 3 characters "abc" form the first group.
The next 3 characters "def" form the second group.
The last 3 characters "ghi" form the third group.
Since all groups can be completely filled by characters from the string, we do not need to use fill.
Thus, the groups formed are "abc", "def", and "ghi".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcdefghij", k = 3, fill = "x"
<strong>Output:</strong> ["abc","def","ghi","jxx"]
<strong>Explanation:</strong>
Similar to the previous example, we are forming the first three groups "abc", "def", and "ghi".
For the last group, we can only use the character 'j' from the string. To complete this group, we add 'x' twice.
Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of lowercase English letters only.</li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
	<li><code>fill</code> is a lowercase English letter.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Text Justification (Hard)](https://leetcode.com/problems/text-justification/)
* [Positions of Large Groups (Easy)](https://leetcode.com/problems/positions-of-large-groups/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for (int i = 0; i < s.size(); ) {
            string tmp;
            for (int j = 0; j < k; ++j) {
                if (i < s.size()) tmp += s[i++];
                else tmp += fill;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
```