# [1520. Maximum Number of Non-Overlapping Substrings (Medium)](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)

<p>Given a string <code>s</code>&nbsp;of lowercase letters, you need to find the maximum number of <strong>non-empty</strong> substrings of&nbsp;<code>s</code>&nbsp;that meet the following conditions:</p>

<ol>
	<li>The substrings do not overlap, that is for any two substrings <code>s[i..j]</code> and <code>s[k..l]</code>, either <code>j &lt; k</code> or <code>i &gt; l</code>&nbsp;is true.</li>
	<li>A substring that contains a certain character&nbsp;<code>c</code>&nbsp;must also contain all occurrences of <code>c</code>.</li>
</ol>

<p>Find <em>the maximum number of substrings that meet the above conditions</em>. If there are multiple solutions with the same number of substrings, <em>return the one with minimum total length.&nbsp;</em>It can be shown that there exists a unique solution of minimum total length.</p>

<p>Notice that you can return the substrings in <strong>any</strong> order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "adefaddaccc"
<strong>Output:</strong> ["e","f","ccc"]
<b>Explanation:</b>&nbsp;The following are all the possible substrings that meet the conditions:
[
&nbsp; "adefaddaccc"
&nbsp; "adefadda",
&nbsp; "ef",
&nbsp; "e",
  "f",
&nbsp; "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abbaccd"
<strong>Output:</strong> ["d","bb","cc"]
<b>Explanation: </b>Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code>&nbsp;contains only lowercase English letters.</li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/743223/C%2B%2BJava-Greedy-O(n)
class Solution {
    int checkSubstr(string &s, int i, vector<int> &left, vector<int> &right) { // get the corresponding right edge of `s[i]`
        int R = right[s[i] - 'a'];
        for (int j = i; j <= R; ++j) {
            if (left[s[j] - 'a'] < i) return -1;
            R = max(R, right[s[j] - 'a']);
        }
        return R;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> left(26, INT_MAX), right(26, INT_MIN); // character `'a' + c` is in range `[ left[c], right[c] ]`
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            int c = s[i] - 'a';
            left[c] = min(left[c], i);
            right[c] = max(right[c], i);
        }
        int R = INT_MAX;
        vector<string> ans;
        for (int i = 0; i < N; ++i) {
            if (i != left[s[i] - 'a']) continue; // Skip if this is not a left edge of range.
            int nextR = checkSubstr(s, i, left, right);
            if (nextR == -1) continue;
            if (i > R || ans.empty()) ans.push_back(""); // If this new substring doesn't overlap with the previous substring or it's the first substring, push new item into the answer instead of updating the previous one.
            R = nextR;
            ans.back() = s.substr(i, R - i + 1);
        }
        return ans;
    }
};
```