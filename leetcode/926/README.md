# [926. Flip String to Monotone Increasing (Medium)](https://leetcode.com/problems/flip-string-to-monotone-increasing/)

<p>A binary string is monotone increasing if it consists of some number of <code>0</code>'s (possibly none), followed by some number of <code>1</code>'s (also possibly none).</p>

<p>You are given a binary string <code>s</code>. You can flip <code>s[i]</code> changing it from <code>0</code> to <code>1</code> or from <code>1</code> to <code>0</code>.</p>

<p>Return <em>the minimum number of flips to make </em><code>s</code><em> monotone increasing</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "00110"
<strong>Output:</strong> 1
<strong>Explanation:</strong> We flip the last digit to get 00111.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "010110"
<strong>Output:</strong> 2
<strong>Explanation:</strong> We flip to get 011111, or alternatively 000111.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "00011000"
<strong>Output:</strong> 2
<strong>Explanation:</strong> We flip to get 00000000.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Two Passes

When we separate the string into two parts, the flip count is the sum of:
* The ones at the left side
* The zeros at the right side.

So we try different separation points from left to right, and for each trial we can easily get the flip count by keeping track of the above two counts.

```cpp
// OJ: https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int rightZeros = 0, leftOnes = 0;
        for (char c : s) rightZeros += c == '0';
        int ans = rightZeros;
        for (char c : s) { // we make the current character the last `0`
            if (c == '1') leftOnes++;
            else rightZeros--;
            ans = min(ans, rightZeros + leftOnes);
        }
        return ans;
    }
};
```

## Solution 2. One Pass (DP)

Think in the DP way. Assume we've already solved the sub-problem for substring `s[0..i]`, and the solution for it is `flipCount[i]`.

Then we look at the next character `s[i + 1]`.

* If it's `1`, we can simply use the solution for `s[0..i]`, so `flipCount[i + 1] = flipCount[i]`.
* If it's `0`, we can pick the best one from these two options:
  1. Firstly, we can choose to flip this `0` to `1` and reuse the solution for `s[0..i]`. In this case `flipCount[i + 1] = flipCount[i] + 1`.
  2. What if the best solution is not to flip? Then we need to turn all `1`s in `s[0..i]` into `0`. Assume the count of `1`s in `s[0..i]` is `ones[i]`, then `flipCount[i + 1] = ones[i]`  

In sum:

```
flipCount[0] = 0
ones[0] = 0

flipCount[i + 1] = flipCount[i]                      // if s[i + 1] == '1'
                   min(flipCount[i] + 1, ones[i])    // if s[i + 1] == '0'
    where 1 <= i <= N - 2
```

```cpp
// OJ: https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/189751/C%2B%2B-one-pass-DP-solution-0ms-O(n)-or-O(1)-one-line-with-explaination.
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, ans = 0;
        for (char c : s) {
            if (c == '1') ones++;
            else ans = min(ans + 1, ones);
        }
        return ans;
    }
};
```