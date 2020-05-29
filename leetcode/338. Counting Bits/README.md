# [338. Counting Bits (Medium)](https://leetcode.com/problems/counting-bits/)

<p>Given a non negative integer number <b>num</b>. For every numbers <b>i</b> in the range <b>0 ≤ i ≤ num</b> calculate the number of 1's in their binary representation and return them as an array.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">2</span>
<strong>Output: </strong><span id="example-output-1">[0,1,1]</span></pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">5</span>
<strong>Output: </strong><code>[0,1,1,2,1,2]</code>
</pre>

<p><b>Follow up:</b></p>

<ul>
	<li>It is very easy to come up with a solution with run time <b>O(n*sizeof(integer))</b>. But can you do it in linear time <b>O(n)</b> /possibly in a single pass?</li>
	<li>Space complexity should be <b>O(n)</b>.</li>
	<li>Can you do it like a boss? Do it without using any builtin function like <b>__builtin_popcount</b> in c++ or in any other language.</li>
</ul>

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
  vector<int> countBits(int num) {
    vector<int> ans(num + 1);
    for (int i = 1; i <= num; i *= 2) {
      ans[i] = 1;
      for (int j = 1; j < i && i + j <= num; ++j) ans[i + j] = ans[i] + ans[j];
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
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        for (int i = 1; i <= num; ++i) ans[i] = 1 + ans[i - (i & -i)];
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
  vector<int> countBits(int num) {
    vector<int> ans(num + 1, 0);
    for (int i = 1; i <= num; ++i) ans[i] = ans[i / 2] + (i % 2);
    return ans;
  }
};
```