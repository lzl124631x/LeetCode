# [433. Minimum Genetic Mutation (Medium)](https://leetcode.com/problems/minimum-genetic-mutation/)

<p>A gene string can be represented by an 8-character long string, with choices from <code>'A'</code>, <code>'C'</code>, <code>'G'</code>, and <code>'T'</code>.</p>

<p>Suppose we need to investigate a mutation from a gene string <code>start</code> to a gene string <code>end</code> where one mutation is defined as one single character changed in the gene string.</p>

<ul>
	<li>For example, <code>"AACCGGTT" --&gt; "AACCGGTA"</code> is one mutation.</li>
</ul>

<p>There is also a gene bank <code>bank</code> that records all the valid gene mutations. A gene must be in <code>bank</code> to make it a valid gene string.</p>

<p>Given the two gene strings <code>start</code> and <code>end</code> and the gene bank <code>bank</code>, return <em>the minimum number of mutations needed to mutate from </em><code>start</code><em> to </em><code>end</code>. If there is no such a mutation, return <code>-1</code>.</p>

<p>Note that the starting point is assumed to be valid, so it might not be included in the bank.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>start.length == 8</code></li>
	<li><code>end.length == 8</code></li>
	<li><code>0 &lt;= bank.length &lt;= 10</code></li>
	<li><code>bank[i].length == 8</code></li>
	<li><code>start</code>, <code>end</code>, and <code>bank[i]</code> consist of only the characters <code>['A', 'C', 'G', 'T']</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Word Ladder (Hard)](https://leetcode.com/problems/word-ladder/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/minimum-genetic-mutation/
// Author: github.com/lzl124631x
// Time: O(NWC) where `N` is the length of `bank`, `W` is the length of `bank[i]`, and `C` is the number of genes.
// Space: O(NW)
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q{{start}};
        unordered_set<string> st(bank.begin(), bank.end()), seen{start};
        char c[4] = {'A', 'C', 'G', 'T'};
        int step = 0;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto s = q.front();
                q.pop();
                if (s == end) return step;
                for (int i = 0; i < s.size(); ++i) {
                    for (int j = 0; j < 4; ++j) {
                        if (c[j] == s[i]) continue;
                        char tmp = s[i];
                        s[i] = c[j];
                        if (st.count(s) && seen.count(s) == 0) {
                            seen.insert(s);
                            q.push(s);
                        }
                        s[i] = tmp;
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
```