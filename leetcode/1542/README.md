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


**Companies**:  
[Directi](https://leetcode.com/company/directi)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. Bitmask + Prefix State Map

Encode the parity of each digit using bit mask. For example, if we've seen `001233444`, we encode it as `10110` because there are odd numbers of `1, 2, 4` and even numbers of `0, 3`.

We use a map `m` to store the mapping from the bitmask to the index of the first occurrence of that bitmask.

For the current `mask`, we have two options:
* all the digits in the window appeared even number times. The maximum length of such window is `i - m[mask]`.
* Only a single digit in the window appeared odd number times. Assume it's digit `0 <= j < 9`, the maximum length of such window is `i - m[mask ^ (1 << j)]`

```cpp
// OJ: https://leetcode.com/problems/find-longest-awesome-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) since there are at most 2^10=1024 states.
class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> m{{0,-1}}; // mask -> index of first occurrence
        int ans = 0;
        for (int i = 0, mask = 0; i < s.size(); ++i) {
            mask ^= 1 << (s[i] - '0');
            if (m.count(mask)) ans = max(ans, i - m[mask]);
            else m[mask] = i;
            for (int j = 0; j < 10; ++j) {
                int prev = mask ^ (1 << j);
                if (m.count(prev)) ans = max(ans, i - m[prev]);
            }
        }
        return ans;
    }
};
```

Since there are only 1024 states, we can also use `vector<int>` or `array` for the map.

```cpp
// OJ: https://leetcode.com/problems/find-longest-awesome-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestAwesome(string s) {
        int ans = 0, N = s.size(), m[1024] = { [0] = -1, [1 ... 1023] = N };
        for (int i = 0, mask = 0; i < s.size(); ++i) {
            mask ^= 1 << (s[i] - '0');
            ans = max(ans, i - m[mask]);
            for (int j = 0; j < 10; ++j) {
                int prev = mask ^ (1 << j);
                ans = max(ans, i - m[prev]);
            }
            m[mask] = min(m[mask], i);
        }
        return ans;
    }
};
```