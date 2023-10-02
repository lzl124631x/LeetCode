# [1963. Minimum Number of Swaps to Make the String Balanced (Medium)](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/)

<p>You are given a <strong>0-indexed</strong> string <code>s</code> of <strong>even</strong> length <code>n</code>. The string consists of <strong>exactly</strong> <code>n / 2</code> opening brackets <code>'['</code> and <code>n / 2</code> closing brackets <code>']'</code>.</p>

<p>A string is called <strong>balanced</strong> if and only if:</p>

<ul>
	<li>It is the empty string, or</li>
	<li>It can be written as <code>AB</code>, where both <code>A</code> and <code>B</code> are <strong>balanced</strong> strings, or</li>
	<li>It can be written as <code>[C]</code>, where <code>C</code> is a <strong>balanced</strong> string.</li>
</ul>

<p>You may swap the brackets at <strong>any</strong> two indices <strong>any</strong> number of times.</p>

<p>Return <em>the <strong>minimum</strong> number of swaps to make </em><code>s</code> <em><strong>balanced</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "][]["
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "]]][[["
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "[]"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The string is already balanced.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>6</sup></code></li>
	<li><code>n</code> is even.</li>
	<li><code>s[i]</code> is either <code>'[' </code>or <code>']'</code>.</li>
	<li>The number of opening brackets <code>'['</code> equals <code>n / 2</code>, and the number of closing brackets <code>']'</code> equals <code>n / 2</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Remove Invalid Parentheses (Hard)](https://leetcode.com/problems/remove-invalid-parentheses/)
* [Minimum Add to Make Parentheses Valid (Medium)](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)
* [Minimum Remove to Make Valid Parentheses (Medium)](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)
* [Minimum Insertions to Balance a Parentheses String (Medium)](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)

## Solution 1. Two Pointers

**Intuition**: We keep looking for the first unmatched `]` from left and the first unmatched `[` from the right, and swap them.

**Algorithm**: Use two pointers `L = 0, R = N - 1`, and two counters `left` and `right` which are the number of unmatched `[`/`]` from left/right, respectively. For example, if we've seen `[[]` from the left, then `left = 1` because there is one `[` unmatched.

We keep incrementing `L` and decrementing `R` until `left` and `right` become `-1`. And we swap `s[L]` and `s[R]` and set `left = right = 1`.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSwaps(string s) {
        int left = 0, right = 0, N = s.size(), L = 0, R = N - 1, ans = 0; 
        while (L < R) {
            for (; L < R; ++L) {
                left += s[L] == '[' ? 1 : -1;
                if (left == -1) break;
            }
            if (L >= R) break; // no more unmatched branchets, break
            for (; L < R; --R) {
                right += s[R] == ']' ? 1 : -1;
                if (right == -1) break;
            }
            left = right = 1; // after swapping `s[L]` and `s[R]`, `left` and `right` will become `1`.
            ++L, --R;
            ++ans;
        }
        return ans;
    }
};
```

## Solution 2. Two Pointers

Find the first unmatched `]` from the left, and swap it with the first `[` from the right.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSwaps(string s) {
        int N = s.size(), cnt = 0, j = N - 1, ans = 0;
        for (int i = 0; i < j; ++i) {
            cnt += s[i] == '[' ? 1 : -1;
            if (cnt == -1) { // found an unmatched `]`
                while (s[j] == ']') --j; // swap with the rightmost `[`
                cnt = 1;
                ++ans;
            }
        }
        return ans;
    }
};
```

## Solution 3. Math

We can discard all the balanced components first. The remaining string must be in this form

```
]]]]...[[[[...
```

The optimal approach is to balance 2 sets of brackets at a time using 1 swap.

For example:

```
]]]]]][[[[[[
// swap 1
    v  v
]]]][][][[[[
// swap 2
  v      v
]][][][][][[
// swap 3
v          v
[][][][][][]
```

We can write the number of mismatches and the corresponding optimal swaps

```
mismatches = 0, 1, 2, 3, 4, 5, 6, ...
     swaps = 0, 1, 1, 2, 2, 3, 3, ...
```

We can see the pattern is `swaps = (mismatches + 1) / 2`.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSwaps(string s) {
        int N = s.size(), cnt = 0, mismatch = 0;
        for (char c : s) {
            if (c == '[') ++cnt;
            else if (cnt > 0) --cnt;
            else ++mismatch;
        }
        return (mismatch + 1) / 2;
    }
};
```