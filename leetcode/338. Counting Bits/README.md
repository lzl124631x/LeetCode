# [338. Counting Bits (Easy)](https://leetcode.com/problems/counting-bits/)

<p>Given an integer <code>n</code>, return <em>an array </em><code>ans</code><em> of length </em><code>n + 1</code><em> such that for each </em><code>i</code><em> </em>(<code>0 &lt;= i &lt;= n</code>)<em>, </em><code>ans[i]</code><em> is the <strong>number of </strong></em><code>1</code><em><strong>'s</strong> in the binary representation of </em><code>i</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> [0,1,1]
<strong>Explanation:</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> [0,1,1,2,1,2]
<strong>Explanation:</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
3 --&gt; 11
4 --&gt; 100
5 --&gt; 101
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>It is very easy to come up with a solution with a runtime of <code>O(n log n)</code>. Can you do it in linear time <code>O(n)</code> and possibly in a single pass?</li>
	<li>Can you do it without using any built-in function (i.e., like <code>__builtin_popcount</code> in C++)?</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits/)

## Solution 1. DP

All the numbers of power of 2 only have a single bit.

For each number between `2^k` and `2^(k+1)`, we can get them by adding `1, 2, 3, ..., 2^k - 1` to `2^k`.

And `1, 2, 3, ..., 2^k - 1` doesn't have bit overlap with `2^k`.

```cpp
// OJ: https://leetcode.com/problems/counting-bits
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i *= 2) {
            ans[i] = 1;
            for (int j = 1; j < i && i + j <= n; ++j) ans[i + j] = ans[i] + ans[j];
        }
        return ans;
    }
};
```

## Solution 2. DP

`i & -i` is the lowest bit of `i`. Let `dp[i]` be the number of bits of `i`.

```
dp[i] = 1 + dp[i - (i & -i)]
```

```cpp
// OJ: https://leetcode.com/problems/counting-bits/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; ++i) ans[i] = 1 + ans[i - (i & -i)];
        return ans;
    }
};
```

## Solution 3. DP

```cpp
// OJ: https://leetcode.com/problems/counting-bits
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; ++i) ans[i] = ans[i / 2] + (i % 2);
        return ans;
    }
};
```

## Solution 4. DP

DP based on highest bit

```cpp
// OJ: https://leetcode.com/problems/counting-bits/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1, hb = 1; i <= n; ++i) {
            if ((hb & i) == 0) hb <<= 1;
            ans[i] = 1 + ans[i - hb];
        }
        return ans;
    }
};
```