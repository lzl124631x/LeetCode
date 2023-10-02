# [2405. Optimal Partition of String (Medium)](https://leetcode.com/problems/optimal-partition-of-string)

<p>Given a string <code>s</code>, partition the string into one or more <strong>substrings</strong> such that the characters in each substring are <strong>unique</strong>. That is, no letter appears in a single substring more than <strong>once</strong>.</p>
<p>Return <em>the <strong>minimum</strong> number of substrings in such a partition.</em></p>
<p>Note that each character should belong to exactly one substring in a partition.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "abacaba"
<strong>Output:</strong> 4
<strong>Explanation:</strong>
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "ssssss"
<strong>Output:</strong> 6
<strong>Explanation:
</strong>The only valid partition is ("s","s","s","s","s","s").
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only English lowercase letters.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [Longest Substring with At Least K Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)
* [Partition Labels (Medium)](https://leetcode.com/problems/partition-labels/)
* [Partition Array into Disjoint Intervals (Medium)](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)
* [Maximum Sum of Distinct Subarrays With Length K (Medium)](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/optimal-partition-of-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int partitionString(string s) {
        int N = s.size(), ans = 0;
        for (int i = 0; i < N; ) {
            bool seen[26] = {};
            while (i < N && !seen[s[i] - 'a']) {
                seen[s[i] - 'a'] = true;
                ++i;
            }
            ++ans;
        }
        return ans;
    }
};
```