# [651. 4 Keys Keyboard (Medium)](https://leetcode.com/problems/4-keys-keyboard/)

<p>Imagine you have a special keyboard with the following keys: </p>
<p><code>Key 1: (A)</code>:  Print one 'A' on screen.</p>
<p><code>Key 2: (Ctrl-A)</code>: Select the whole screen.</p>
<p><code>Key 3: (Ctrl-C)</code>: Copy selection to buffer.</p>
<p><code>Key 4: (Ctrl-V)</code>: Print buffer on screen appending it after what has already been printed. </p>



<p>Now, you can only press the keyboard for <b>N</b> times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.</p>


<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> N = 3
<b>Output:</b> 3
<b>Explanation:</b> 
We can at most get 3 A's on screen by pressing following key sequence:
A, A, A
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> N = 7
<b>Output:</b> 9
<b>Explanation:</b> 
We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>1 &lt;= N &lt;= 50 </li>
<li>Answers will be in the range of 32-bit signed integer.</li>
</ol>
<p></p>


**Companies**:  
[Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. DP
We have two options for each step:

1. Addition: Pressing 'A' which adds `1` to `M`, with cost of `1`.
1. Multiplication: Pressing 'CTRL+A', 'CTRL+C', and `k` 'CTRL+V's (`k >= 1`), which multiplies `M` by `k+1`, with cost of `k+2`.

Where `M` is the count of 'A's already added.

Let `j = k + 1`, we can see the rule of multiplication: to multiply by `j`, the cost is `j + 1` (`j >= 2`)

Let `dp[i]` be the largest number of written 'A's possible after `i` keypresses.

```
dp[i] = max{
    dp[i - 1] + 1                      Addition
    dp[i - (j + 1)] * j                Multiplication, where j >= 2 && j <= i - 2
}
```

```cpp
// OJ: https://leetcode.com/problems/4-keys-keyboard/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/4-keys-keyboard/solution/
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j < i - 1; ++j) dp[i] = max(dp[i], dp[i - j - 1] * j);
        }
        return dp[N];
    }
};
```

## Solution 2. DP

In the multiplcation case of Solution 1:
* When `j` is even, i.e. `j = 2p` (`p >= 1`), the cost of multiply by `j` is `2p + 1`. We can instead multiply by `p` first, then multiply by `2`, and the total cost is `(p + 1) + (2 + 1) = p + 4`. When `p + 4 <= 2p + 1`, i.e. `p >= 3` or `j >= 6`, we should pick the second way for lower cost.
* When `j` is odd, i.e. `j = 2p+1` (`p >= 1`), the cost of multiply by `j` is `2p + 2`. We can instead multiply by `p + 1` first, then multiply by `2`, and the total cost is `(p + 1 + 1) + (2 + 1) = p + 5`. When `p + 5 <= 2p + 2`, i.e. `p >= 3` or `j >= 7`, we should pick the second way for lower cost.

In sum, multiplying by `j >= 6` is not optimal, so we at most multiply by 5, and the range of `j` is `[2, min(i - 2, 5)]`

```cpp
// OJ: https://leetcode.com/problems/4-keys-keyboard/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/4-keys-keyboard/solution/
class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = min(i - 2, 5); j >= 2; --j) dp[i] = max(dp[i], dp[i - j - 1] * j);
        }
        return dp[N];
    }
};
```