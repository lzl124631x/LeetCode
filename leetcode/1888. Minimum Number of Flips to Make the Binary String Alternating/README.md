# [1888. Minimum Number of Flips to Make the Binary String Alternating (Medium)](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)

<p>You are given a binary string <code>s</code>. You are allowed to perform two types of operations on the string in any sequence:</p>

<ul>
	<li><strong>Type-1: Remove</strong> the character at the start of the string <code>s</code> and <strong>append</strong> it to the end of the string.</li>
	<li><strong>Type-2: Pick</strong> any character in <code>s</code> and <strong>flip</strong> its value, i.e., if its value is <code>'0'</code> it becomes <code>'1'</code> and vice-versa.</li>
</ul>

<p>Return <em>the <strong>minimum</strong> number of <strong>type-2</strong> operations you need to perform</em> <em>such that </em><code>s</code> <em>becomes <strong>alternating</strong>.</em></p>

<p>The string is called <strong>alternating</strong> if no two adjacent characters are equal.</p>

<ul>
	<li>For example, the strings <code>"010"</code> and <code>"1010"</code> are alternating, while the string <code>"0100"</code> is not.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "111000"
<strong>Output:</strong> 2
<strong>Explanation</strong>: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "10<u>1</u>01<u>0</u>".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "010"
<strong>Output:</strong> 0
<strong>Explanation</strong>: The string is already alternating.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "1110"
<strong>Output:</strong> 1
<strong>Explanation</strong>: Use the second operation on the second element to make s = "1<u>0</u>10".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    int even(string &s, int c) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans += i % 2 ? (s[i] != c + '0') : (s[i] != '0' + (1 - c));
        }
        return ans;
    }
    int odd(string &s, int c) {
        int N = s.size();
        vector<vector<int>> dp(N + 1, vector<int>(2));
        for (int i = 0; i < s.size(); ++i) {
            dp[i + 1][1] = dp[i][1] + (i % 2 ? (s[i] != c + '0') : (s[i] != '0' + (1 - c)));
            dp[i + 1][0] = min(dp[i][1], dp[i][0]) + (i % 2 == 0? (s[i] != c + '0') : (s[i] != '0' + (1 - c)));
        }
        return min(dp[N][0], dp[N][1]);
    }
public:
    int minFlips(string s) {
        if (s.size() % 2 == 0) {
            return min(even(s, 0), even(s, 1));
        }
        return min(odd(s, 0), odd(s, 1));
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/discuss/1253874/C%2B%2B-Solution-sliding-window.-O(N)
class Solution {
public:
    int minFlips(string s) {
        int N = s.size(), c1 = 0, c2 = 0, ans = INT_MAX;
        s += s;
        string x, y;
        for (int i = 0; i < 2 * N; ++i) {
            x += i % 2 ? '1' : '0';
            y += i % 2 ? '0' : '1';
        }
        for (int i = 0; i < 2 * N; ++i) {
            if (i - N >= 0) {
                c1 -= x[i - N] != s[i - N];
                c2 -= y[i - N] != s[i - N];
            }
            c1 += x[i] != s[i];
            c2 += y[i] != s[i];
            if (i >= N - 1) ans = min({ ans, c1, c2 });
        }
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minFlips(string s) {
        int N = s.size(), t = 0;
        for (int i = 0; i < N; ++i) t += (s[i] == '0') ^ (i % 2 == 0);
        int ans = min(t, N - t);
        if (N % 2 == 0) return ans;
        for (int i = 0; i < N - 1; ++i) {
            t = N - t + (s[i] == '0' ? -1 : 1);
            ans = min(ans, min(t, N - t));
        }
        return ans;
    }
};
```