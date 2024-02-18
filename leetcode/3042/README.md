# [3042. Count Prefix and Suffix Pairs I (Easy)](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i)

<p>You are given a <strong>0-indexed</strong> string array <code>words</code>.</p>

<p>Let&#39;s define a <strong>boolean</strong> function <code>isPrefixAndSuffix</code> that takes two strings, <code>str1</code> and <code>str2</code>:</p>

<ul>
	<li><code>isPrefixAndSuffix(str1, str2)</code> returns <code>true</code> if <code>str1</code> is <strong>both</strong> a <span data-keyword="string-prefix">prefix</span> and a <span data-keyword="string-suffix">suffix</span> of <code>str2</code>, and <code>false</code> otherwise.</li>
</ul>

<p>For example, <code>isPrefixAndSuffix(&quot;aba&quot;, &quot;ababa&quot;)</code> is <code>true</code> because <code>&quot;aba&quot;</code> is a prefix of <code>&quot;ababa&quot;</code> and also a suffix, but <code>isPrefixAndSuffix(&quot;abc&quot;, &quot;abcd&quot;)</code> is <code>false</code>.</p>

<p>Return <em>an integer denoting the <strong>number</strong> of index pairs </em><code>(i, j)</code><em> such that </em><code>i &lt; j</code><em>, and </em><code>isPrefixAndSuffix(words[i], words[j])</code><em> is </em><code>true</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;a&quot;,&quot;aba&quot;,&quot;ababa&quot;,&quot;aa&quot;]
<strong>Output:</strong> 4
<strong>Explanation:</strong> In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix(&quot;a&quot;, &quot;aba&quot;) is true.
i = 0 and j = 2 because isPrefixAndSuffix(&quot;a&quot;, &quot;ababa&quot;) is true.
i = 0 and j = 3 because isPrefixAndSuffix(&quot;a&quot;, &quot;aa&quot;) is true.
i = 1 and j = 2 because isPrefixAndSuffix(&quot;aba&quot;, &quot;ababa&quot;) is true.
Therefore, the answer is 4.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;pa&quot;,&quot;papa&quot;,&quot;ma&quot;,&quot;mama&quot;]
<strong>Output:</strong> 2
<strong>Explanation:</strong> In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix(&quot;pa&quot;, &quot;papa&quot;) is true.
i = 2 and j = 3 because isPrefixAndSuffix(&quot;ma&quot;, &quot;mama&quot;) is true.
Therefore, the answer is 2.  </pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abab&quot;,&quot;ab&quot;]
<strong>Output:</strong> 0
<strong>Explanation: </strong>In this example, the only valid index pair is i = 0 and j = 1, and isPrefixAndSuffix(&quot;abab&quot;, &quot;ab&quot;) is false.
Therefore, the answer is 0.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>

**Similar Questions**:

- [Implement Trie (Prefix Tree) (Medium)](https://leetcode.com/problems/implement-trie-prefix-tree)
- [Design Add and Search Words Data Structure (Medium)](https://leetcode.com/problems/design-add-and-search-words-data-structure)

**Hints**:

- Iterate through all index pairs <code>(i, j)</code>, such that <code>i < j</code>, and check <code>isPrefixAndSuffix(words[i], words[j])</code>.
- The answer is the total number of pairs where <code>isPrefixAndSuffix(words[i], words[j]) == true</code>.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i
// Author: github.com/lzl124631x
// Time: O(N^2 * W)
// Space: O(W)
class Solution {
    bool isPrefixAndSuffix(string &a, string &b) {
        return a.size() <= b.size() && b.substr(0, a.size()) == a && b.substr(b.size() - a.size()) == a;
    }
public:
    int countPrefixSuffixPairs(vector<string>& A) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (isPrefixAndSuffix(A[i], A[j])) ++ ans;
            }
        }
        return ans;
    }
};
```
