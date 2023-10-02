# [1849. Splitting a String Into Descending Consecutive Values (Medium)](https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/)

<p>You are given a string <code>s</code> that consists of only digits.</p>

<p>Check if we can split <code>s</code> into <strong>two or more non-empty substrings</strong> such that the <strong>numerical values</strong> of the substrings are in <strong>descending order</strong> and the <strong>difference</strong> between numerical values of every two <strong>adjacent</strong> <strong>substrings</strong> is equal to <code>1</code>.</p>

<ul>
	<li>For example, the string <code>s = "0090089"</code> can be split into <code>["0090", "089"]</code> with numerical values <code>[90,89]</code>. The values are in descending order and adjacent values differ by <code>1</code>, so this way is valid.</li>
	<li>Another example, the string <code>s = "001"</code> can be split into <code>["0", "01"]</code>, <code>["00", "1"]</code>, or <code>["0", "0", "1"]</code>. However all the ways are invalid because they have numerical values <code>[0,1]</code>, <code>[0,1]</code>, and <code>[0,0,1]</code> respectively, all of which are not in descending order.</li>
</ul>

<p>Return <code>true</code> <em>if it is possible to split</em> <code>s</code>​​​​​​ <em>as described above</em><em>, or </em><code>false</code><em> otherwise.</em></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1234"
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no valid way to split s.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "050043"
<strong>Output:</strong> true
<strong>Explanation:</strong> s can be split into ["05", "004", "3"] with numerical values [5,4,3].
The values are in descending order with adjacent values differing by 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "9080701"
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no valid way to split s.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "10009998"
<strong>Output:</strong> true
<strong>Explanation:</strong> s can be split into ["100", "099", "98"] with numerical values [100,99,98].
The values are in descending order with adjacent values differing by 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>s</code> only consists of digits.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Recursion](https://leetcode.com/tag/recursion/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N)
class Solution {
    bool valid(string &prev, string cur) {
        if (prev == "") return true;
        reverse(begin(cur), end(cur));
        int carry = 1;
        for (char &c : cur) {
            carry += c - '0';
            c = '0' + carry % 10;
            carry /= 10;
        }
        if (carry) cur.push_back('1');
        reverse(begin(cur), end(cur));
        return prev == cur;
    }
    bool dfs(string &s, int start, string prev = "") {
        if (start == s.size()) {
            return true;
        }
        while (start + 1 < s.size() && s[start] == '0') ++start;
        for (int i = start + 1; i <= s.size() - (prev == ""); ++i) {
            auto sub = s.substr(start, i - start);
            if (valid(prev, sub) && dfs(s, i, sub)) return true;
        }
        return false;
    }
public:
    bool splitString(string s) {
        return dfs(s, 0);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N)
class Solution {
    bool dfs(string &s, int start, long long prev = -1) {
        if (start == s.size()) {
            return true;
        }
        while (start + 1 < s.size() && s[start] == '0') ++start; // it's important to skip leading zeros. Otherwise the substring could be too long for `stoll`
        for (int i = start + 1; i <= s.size() - (prev == -1); ++i) {
            if (i - start > 10) break; // the original string is at most 20 characters long, so skip if the length of the substring is more than 10.
            auto sub = s.substr(start, i - start);
            long long n = stoll(sub);
            if (prev == -1 || n == prev - 1) {
                if (dfs(s, i, n)) return true;
            }
        }
        return false;
    }
public:
    bool splitString(string s) {
        return dfs(s, 0);
    }
};
```