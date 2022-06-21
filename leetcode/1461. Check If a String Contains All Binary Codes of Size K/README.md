# [1461. Check If a String Contains All Binary Codes of Size K (Medium)](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)

<p>Given a binary string <code>s</code> and an integer <code>k</code>, return <code>true</code> <em>if every binary code of length</em> <code>k</code> <em>is a substring of</em> <code>s</code>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "00110110", k = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "0110", k = 1
<strong>Output:</strong> true
<strong>Explanation:</strong> The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "0110", k = 2
<strong>Output:</strong> false
<strong>Explanation:</strong> The binary code "00" is of length 2 and does not exist in the array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>1 &lt;= k &lt;= 20</code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Hash Function](https://leetcode.com/tag/hash-function/)

## NOTE

Bitwise AND has higher priority than bitwise OR according to https://en.cppreference.com/w/cpp/language/operator_precedence. So 


```cpp
cout << bitset<3>(0b110 | 1 & 0b11) << " " << bitset<3>(0b110 & 0b11 | 1) << endl;
// 111 011
```

For `k = 20`, there are at most `2^k ~= 1e6` binary codes.

We can use a sliding window of length `k` to scan all the binary codes that can be generated from `s`.

For `s.length = 5e5`, there are at most `5e5 - 19` codes. We can save them in a set. If the size of set becomes `2^k`, we've seen all the binary codes. 

## Solution 1. Sliding window

We can use a sliding window to keep track of the substring of length `k`, and mark the corresponding binary representation `n` as visited. Then we check if all the numbers in range `[0, 2^k)` are visited.

```cpp
// OJ: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Author: github.com/lzl124631x
// Time: O(N + min(N, 2^K))
// Space: O(2^K)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> v(1 << k);
        int n = 0, mask = (1 << k) - 1;
        for (int i = 0; i < s.size(); ++i) {
            n = (n << 1) & mask | (s[i] - '0');
            if (i >= k - 1) v[n] = true;
        }
        for (int i = 0; i < (1 << k); ++i) {
            if (!v[i]) return false;
        }
        return true;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Author: github.com/lzl124631x
// Time: O(min(N, 2^K))
// Space: O(2^K)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> v(1 << k);
        int mask = (1 << k) - 1, cnt = 1 << k, n = 0;
        for (int i = 0; i < s.size() && cnt; ++i) {
            n = n << 1 & mask | (s[i] - '0');
            if (i >= k - 1) {
                if (!v[n]) --cnt;
                v[n] = true;
            }
        }
        return cnt == 0;
    }
};
```

## Solution 2. Sliding window

Same idea as Solution 1, but using `unordered_set` to store the visited info and we just need to check the size of the set in the end.

```cpp
// OJ: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(2^K)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> st;
        int n = 0, mask = (1 << k) - 1;
        for (int i = 0; i < s.size(); ++i) {
            n = (n << 1) & mask | (s[i] - '0');
            if (i >= k - 1) st.insert(n);
            if (st.size() == (1 << k)) return true;
        }
        return false;
    }
};
```