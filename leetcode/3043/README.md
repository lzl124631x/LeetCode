# [3043. Find the Length of the Longest Common Prefix (Medium)](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix)

<p>You are given two arrays with <strong>positive</strong> integers <code>arr1</code> and <code>arr2</code>.</p>

<p>A <strong>prefix</strong> of a positive integer is an integer formed by one or more of its digits, starting from its <strong>leftmost</strong> digit. For example, <code>123</code> is a prefix of the integer <code>12345</code>, while <code>234</code> is <strong>not</strong>.</p>

<p>A <strong>common prefix</strong> of two integers <code>a</code> and <code>b</code> is an integer <code>c</code>, such that <code>c</code> is a prefix of both <code>a</code> and <code>b</code>. For example, <code>5655359</code> and <code>56554</code> have a common prefix <code>565</code> while <code>1223</code> and <code>43456</code> <strong>do not</strong> have a common prefix.</p>

<p>You need to find the length of the <strong>longest common prefix</strong> between all pairs of integers <code>(x, y)</code> such that <code>x</code> belongs to <code>arr1</code> and <code>y</code> belongs to <code>arr2</code>.</p>

<p>Return <em>the length of the <strong>longest</strong> common prefix among all pairs</em>.<em> If no common prefix exists among them</em>, <em>return</em> <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr1 = [1,10,100], arr2 = [1000]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 pairs (arr1[i], arr2[j]):
- The longest common prefix of (1, 1000) is 1.
- The longest common prefix of (10, 1000) is 10.
- The longest common prefix of (100, 1000) is 100.
The longest common prefix is 100 with a length of 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr1 = [1,2,3], arr2 = [4,4,4]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There exists no common prefix for any pair (arr1[i], arr2[j]), hence we return 0.
Note that common prefixes between elements of the same array do not count.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= arr1[i], arr2[i] &lt;= 10<sup>8</sup></code></li>
</ul>

**Similar Questions**:

- [Longest Common Prefix (Easy)](https://leetcode.com/problems/longest-common-prefix)

**Hints**:

- Put all the possible prefixes of each element in <code>arr1</code> into a HashSet.
- For all the possible prefixes of each element in <code>arr2</code>, check if it exists in the HashSet.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(NW)
class Solution {
public:
    int longestCommonPrefix(vector<int>& A, vector<int>& B) {
        unordered_set<string> st;
        int len = 0;
        for (int n : A) {
            auto s = to_string(n);
            for (int len = s.size(); len >= 1; --len) {
                st.insert(s.substr(0, len));
            }
            len = max(len, (int)s.size());
        }
        vector<string> sb;
        for (int n : B) sb.push_back(to_string(n));
        for (; len > 0; --len) {
            for (auto &s : sb) {
                s = s.substr(0, len);
                if (s.size() == len && st.count(s)) return len;
            }
        }
        return 0;
    }
};
```
