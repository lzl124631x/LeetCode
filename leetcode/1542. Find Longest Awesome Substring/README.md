# [1542. Find Longest Awesome Substring (Hard)](https://leetcode.com/problems/find-longest-awesome-substring/)

<p>Given a string <code>s</code>. An <em>awesome</em> substring is a non-empty substring of <code>s</code> such that we can make any number of swaps in order to make it palindrome.</p>

<p>Return the length of the maximum length <strong>awesome substring</strong> of <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "3242415"
<strong>Output:</strong> 5
<strong>Explanation:</strong> "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "12345678"
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "213123"
<strong>Output:</strong> 6
<strong>Explanation:</strong> "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "00"
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code> consists only of digits.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-longest-awesome-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) since there are at most 2^10=1024 states.
class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> m{{0, -1}};
        int state = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            state ^= 1 << (s[i] - '0');
            if (m.count(state)) ans = max(ans, i - m[state]);
            for (int j = 0; j < 10; ++j) {
                int prev = state ^ (1 << j);
                if (m.count(prev)) ans = max(ans, i - m[prev]);
            }
            if (!m.count(state)) m[state] = i;
        }
        return ans;
    }
};
```

Since there are only 1024 states, we can also use `vector<int>` for the map.

```cpp
// OJ: https://leetcode.com/problems/find-longest-awesome-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestAwesome(string s) {
        int state = 0, ans = 0, N = s.size();
        vector<int> m(1024, N);
        m[0] = -1;
        for (int i = 0; i < s.size(); ++i) {
            state ^= 1 << (s[i] - '0');
            ans = max(ans, i - m[state]);
            for (int j = 0; j < 10; ++j) {
                ans = max(ans, i - m[state ^ (1 << j)]);
            }
            m[state] = min(m[state], i);
        }
        return ans;
    }
};
```