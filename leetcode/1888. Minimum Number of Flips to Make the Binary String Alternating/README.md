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
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Minimum Operations to Make the Array Alternating (Medium)](https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/)


## Note

Hint 1: Only consider the case where the first character in the result string is `0`. The `1` case is symmetrical.

Hint 2: Type-1 operation basically allows us to regard `s` as a cyclic string. We can pick any index as the starting index and use its next `N` characters (including the starting index) to get the result. 

## Solution 1. Fixed-length Sliding Window

This is a fixed-length sliding window problem on a cyclic string.

We can loop `i` in range `[0, 2N)`. Push `s[i % N]` into window and `s[i - N] (i - N >= 0)` out of the window. We keep track of the count of flips needed within the window as `cnt` and return the global minimal `cnt` as the answer.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minFlips(string s) {
        int N = s.size();
        auto solve = [&](char c) {
            int ans = INT_MAX, cnt = 0;
            for (int i = 0; i < 2 * N; ++i) {
                cnt += s[i % N] == c ^ (i % 2);
                if (i - N >= 0) cnt -= s[i - N] == c ^ ((i - N) % 2) ;
                if (i >= N - 1) ans = min(ans, cnt);
            }
            return ans;
        };
        return min(solve('0'), solve('1'));
    }
};
```

The following is a fool-proof implementation (good to use during contest), but takes `O(N)` space.

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
        s += s; // simulating cyclic string
        string x, y; // the target strings
        for (int i = 0; i < 2 * N; ++i) {
            x += i % 2 ? '1' : '0';
            y += i % 2 ? '0' : '1';
        }
        for (int i = 0; i < 2 * N; ++i) {
            c1 += x[i] != s[i];
            c2 += y[i] != s[i];
            if (i - N >= 0) {
                c1 -= x[i - N] != s[i - N];
                c2 -= y[i - N] != s[i - N];
            }
            if (i >= N - 1) ans = min({ ans, c1, c2 });
        }
        return ans;
    }
};
```

## Solution 2.

Due to symmetry, if making the result string start with character `0` requires `t` steps, then making the result string start with character `1` requires `N - t` steps.

If the length of `s` is even, picking any index `j > 0` as starting index is equivalent to picking `i = 0` as the starting index and possibly flipping the target string. 

For example, `s = "0110"`, if we pick `j = 1` as the starting index 

```
 v
0110
1010 // target string = "0101" starts from index 1.
// this is equivalent to 
v
0110
1010 // target string = "1010" starts from index 0
```

So, if the length of `s` is even, the answer is `min(t, N - t)`.

When the length of `s` is odd, if we make `i = 1` as the starting index, we need to do the following:

1. Flip the target string. The number of steps needed to make the result string start with character `0` is now `N - t`.
2. Make adjustment for `s[i]`.

For example:

```
     s = "01101"
target = "01010"
            ---
     t = 3
// Now let index 1 be the starting index
           v
     s = "01101"
target = "00101"
// This is the same as
// Step 1:
           v
     s = "01101"
target = "10101" // flipping the original target string
     t = N - t // the number of flips is also flipped
// Step 2:
           v
     s = "01101"
target = "00101" // adjustment for s[0]
// If s[0] == '0', we need to minus 1
// If s[0] == '1', we need to plus 1.
// So, the adjustment is to plus `s[i] == '0' ? -1 : 1`.
```

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minFlips(string s) {
        int N = s.size(), t = 0;
        for (int i = 0; i < N; ++i) t += (s[i] == '0') ^ (i % 2 == 0); // `t` is the number of flips needed to make the result string start with character `0`.
        int ans = min(t, N - t); // `N - t` is the number of flips needed to make the result string start with character `1`.
        if (N % 2 == 0) return ans; // If `N` is even, the answer is `min(t, N - t)`.
        for (int i = 0; i < N - 1; ++i) { // If `N` is odd, we try making `i+1` as the starting index
            t = N - t + (s[i] == '0' ? -1 : 1); // flipping all the target characters make t -> N - t. We need adjust for `s[i]`.
            ans = min(ans, min(t, N - t));
        }
        return ans;
    }
};
```