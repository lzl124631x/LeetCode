# [522. Longest Uncommon Subsequence II (Medium)](https://leetcode.com/problems/longest-uncommon-subsequence-ii/)

<p>Given an array of strings <code>strs</code>, return <em>the length of the <strong>longest uncommon subsequence</strong> between them</em>. If the longest uncommon subsequence does not exist, return <code>-1</code>.</p>

<p>An <strong>uncommon subsequence</strong> between an array of strings is a string that is a <strong>subsequence of one string but not the others</strong>.</p>

<p>A <strong>subsequence</strong> of a string <code>s</code> is a string that can be obtained after deleting any number of characters from <code>s</code>.</p>

<ul>
	<li>For example, <code>"abc"</code> is a subsequence of <code>"aebdc"</code> because you can delete the underlined characters in <code>"a<u>e</u>b<u>d</u>c"</code> to get <code>"abc"</code>. Other subsequences of <code>"aebdc"</code> include <code>"aebdc"</code>, <code>"aeb"</code>, and <code>""</code> (empty string).</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> strs = ["aba","cdc","eae"]
<strong>Output:</strong> 3
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> strs = ["aaa","aaa","aa"]
<strong>Output:</strong> -1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 50</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 10</code></li>
	<li><code>strs[i]</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Longest Uncommon Subsequence I (Easy)](https://leetcode.com/problems/longest-uncommon-subsequence-i/)

## Solution 1.

The answer must be one of the strings in `A`. We can prove by contradiction. Assume the longest LUS is a subsequence of `A[i]` but not `A[i]` itself, we can always add the rest characters in `A[i]` to get a longer LUS which contradicts with the assumption.

So, we can iterate through the strings in `A` and check if it's a subsequence of another string of longer or equal length. If it's not, then it's the LUS.

```cpp
// OJ: https://leetcode.com/problems/longest-uncommon-subsequence-ii/
// Author: github.com/lzl124631x
// Time: O(N^2 * W) where `N` is the number of elements in `A` and `W` is the maximum length of a string in `A`.
// Space: O(1)
class Solution {
    bool isSubsequence(string &a, string &b) {
        int i = 0, j = 0, M = a.size(), N = b.size();
        for (; i < M && j < N; ) {
            while (j < N && a[i] != b[j]) ++j;
            if (j < N && a[i] == b[j]) ++i, ++j;
        }
        return i == M;
    }
public:
    int findLUSlength(vector<string>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a.size() > b.size(); });
        for (int i = 0; i < A.size(); ++i) {
            bool good = true;
            for (int j = 0; j < A.size() && A[i].size() <= A[j].size() && good; ++j) {
                if (i != j && isSubsequence(A[i], A[j])) good = false;
            }
            if (good) return A[i].size();
        }
        return -1;
    }
};
```