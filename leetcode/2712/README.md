# [2712. Minimum Cost to Make All Characters Equal (Medium)](https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal)

<p>You are given a <strong>0-indexed</strong> binary string <code>s</code> of length <code>n</code> on which you can apply two types of operations:</p>

<ul>
	<li>Choose an index <code>i</code> and invert all characters from&nbsp;index <code>0</code> to index <code>i</code>&nbsp;(both inclusive), with a cost of <code>i + 1</code></li>
	<li>Choose an index <code>i</code> and invert all characters&nbsp;from&nbsp;index <code>i</code> to index <code>n - 1</code>&nbsp;(both inclusive), with a cost of <code>n - i</code></li>
</ul>

<p>Return <em>the <strong>minimum cost </strong>to make all characters of the string <strong>equal</strong></em>.</p>

<p><strong>Invert</strong> a character means&nbsp;if its value is &#39;0&#39; it becomes &#39;1&#39; and vice-versa.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0011&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> Apply the second operation with <code>i = 2</code> to obtain <code>s = &quot;0000&quot; for a cost of 2</code>. It can be shown that 2 is the minimum cost to make all characters equal.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;010101&quot;
<strong>Output:</strong> 9
<strong>Explanation:</strong> Apply the first operation with i = 2 to obtain s = &quot;101101&quot; for a cost of 3.
Apply the first operation with i = 1 to obtain s = &quot;011101&quot; for a cost of 2. 
Apply the first operation with i = 0 to obtain s = &quot;111101&quot; for a cost of 1. 
Apply the second operation with i = 4 to obtain s = &quot;111110&quot; for a cost of 2.
Apply the second operation with i = 5 to obtain s = &quot;111111&quot; for a cost of 1. 
The total cost to make all characters equal is 9. It can be shown that 9 is the minimum cost to make all characters equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code></li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Greedy](https://leetcode.com/tag/greedy)

**Similar Questions**:
* [Flip String to Monotone Increasing (Medium)](https://leetcode.com/problems/flip-string-to-monotone-increasing)

**Hints**:
* For every index i, calculate the number of operations required to make the prefix [0, i - 1] equal to the character at index i, denoted prefix[i].
* For every index i, calculate the number of operations required to make the suffix [i + 1, n - 1] equal to the character at index i, denoted suffix[i].
* The final string will contain at least one character that is left unchanged; Therefore, the answer is the minimum of prefix[i] + suffix[i] for every i in [0, n - 1].

## Solution 1. DP

Let `left[0/1][i+1]` be the cost of turning all `s[0..i]` to `0/1`, and `right[0/1][i]` be the cost of turning all `s[i..N-1]` to `0/1`. The answer is the minimum of all `left[0][i] + right[0][i], left[1][i] + right[1][i]` (`0 <= i <= N`).

For `left[0/1][i+1]`:
```
// If `s[i] == 0`
left[0][i+1] = min(left[0][i], // turn s[0..i-1] to 0
                    left[1][i] + i) // turn s[0..i-1] to 1, then flip s[0..i-1] to 1 with cost i
left[1][i+1] = min(left[0][i] + i + 1, // turn s[0..i-1] to 0, then flip s[0..i] to 1 with cost i+1
                    left[1][i] + 2*i + 1) // turn s[0..i-1] to 1, then flip s[0..i-1] to 0 with cost i, then flip s[0..i] to 1 with cost i+1
             = min(left[0][i], left[1][i] + i) + i + 1
// If `s[i] == 1`
left[0][i+1] = min(left[0][i] + 2*i + 1, // turn s[0..i-1] to 0, then flip s[0..i-1] to 1 with cost i, then flip s[0..i] to 0 with cost i+1
                    left[1][i] + i + 1) // turn s[0..i-1] to 1, then flip s[0..i] with cost i + 1
             = min(left[0][i] + i, left[1][i]) + i + 1
left[1][i+1] = min(left[0][i] + i, // turn s[0..i-1] to 0, then flip s[0..i-1] to 1 with cost i
                    left[1][i]) // turn s[0..i-1] to 1
```

Similarly

```
if s[i] == 0
right[0][i] = min(right[0][i+1], right[1][i+1] + N - i - 1)
right[1][i] = min(right[0][i+1], right[1][i+1] + N - i - 1) + N - i
if s[i] == 1
right[0][i] = min(right[0][i+1] + N - i - 1, right[1][i+1]) + N - i
right[1][i] = min(right[0][i+1] + N - i - 1, right[1][i+1])
```

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long minimumCost(string s) {
        long long N = s.size(), ans = LLONG_MAX;
        vector<vector<long long>> right(2, vector<long long>(N + 1)), left(2, vector<long long>(N + 1));
        for (int i = N - 1; i >= 0; --i) {
            if (s[i] == '0') {
                long long val = min(right[0][i + 1], right[1][i + 1] + N - i - 1);
                right[0][i] = val;
                right[1][i] = val + N - i;
            } else {
                long long val = min(right[0][i + 1] + N - i - 1, right[1][i + 1]);
                right[0][i] = val + N - i;
                right[1][i] = val;
            }
        }
        for (int i = 0; i < N; ++i) {
            if (s[i] == '0') {
                long long val = min(left[0][i], left[1][i] + i);
                left[0][i + 1] = val;
                left[1][i + 1] = val + i + 1;
            } else {
                long long val = min(left[0][i] + i, left[1][i]);
                left[0][i + 1] = val + i + 1;
                left[1][i + 1] = val;
            }
        }
        for (int i = 0; i <= N; ++i) {
            ans = min({ ans, left[0][i] + right[0][i], left[1][i] + right[1][i] });
        }
        return ans;
    }
};
```

## Solution 2. Greedy

We scan from left to right. Whenever we see two characters (`s[i-1]` and `s[i]`) that are different, we pick the minimum between these two options:

* Flip `s[0..i-1]` with cost `i`
* Flip `s[i..N-1]` with cost `N-i`

This algorithm works because the order in which we do the flips doesn't matter. Let's say we made the choice at `s[0]` vs `s[1]`, and now we look at `s[1]` vs `s[2]`, no matter which choice we make, `s[0]` and `s[1]` will be flipped together.

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/solutions/3570185/single-pass-iterative-easy-explanation-think-greedy-one-line-clean-code-c/
class Solution {
public:
    long long minimumCost(string s) {
        long long N = s.size(), ans = 0;
        for (int i = 1; i < N; ++i) {
            if (s[i] != s[i - 1]) ans += min((long long)i, N - i);
        }
        return ans;
    }
};
```