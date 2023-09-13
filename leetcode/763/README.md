# [763. Partition Labels (Medium)](https://leetcode.com/problems/partition-labels/)

<p>You are given a string <code>s</code>. We want to partition the string into as many parts as possible so that each letter appears in at most one part.</p>

<p>Note that the partition is done so that after concatenating all the parts in order, the resultant string should be <code>s</code>.</p>

<p>Return <em>a list of integers representing the size of these parts</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ababcbacadefegdehijhklij"
<strong>Output:</strong> [9,7,8]
<strong>Explanation:</strong>
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "eccbbbbdec"
<strong>Output:</strong> [10]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Oracle](https://leetcode.com/company/oracle)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)

## Solution 1. Counting + Bitmask

For every character that appears in the current range, we must exhaust all its occurrences.

```cpp
// OJ: https://leetcode.com/problems/partition-labels/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(1)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int cnt[26] = {};
        for (char c : S) cnt[c - 'a']++;
        vector<int> ans;
        for (int i = 0, prev = 0; i < S.size();) {
            int mask = 0; // `mask` is a bitmask representing all the characters that we've seen in the current range and haven't exhausted all their occurrences.
            do {
                int key = S[i++] - 'a';
                cnt[key]--;
                mask |= 1 << key; 
                if (cnt[key] == 0) mask ^= 1 << key; // If we've exhausted this character, remove it from the mask
            } while (mask); // When `mask != 0`, there are still some characters that have remaining occurrences -- we keep looping
            ans.push_back(i - prev);
            prev = i;
        }
        return ans;
    }
};
```

## Solution 2. Extending Boundary

```cpp
// OJ: https://leetcode.com/problems/partition-labels/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int N = s.size(), last[26] = {};
        memset(last, -1, sizeof(last));
        for (int i = 0; i < N; ++i) last[s[i] - 'a'] = i;
        vector<int> ans;
        for (int i = 0; i < N;) {
            int start = i;
            for (int end = i + 1; i < end; ++i) end = max(end, last[s[i] - 'a'] + 1);
            ans.push_back(i - start);
        }
        return ans;
    }
};
```