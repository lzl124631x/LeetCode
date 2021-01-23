# [1734. Decode XORed Permutation (Medium)](https://leetcode.com/problems/decode-xored-permutation/)

<p>There is an integer array <code>perm</code> that is a permutation of the first <code>n</code> positive integers, where <code>n</code> is always <strong>odd</strong>.</p>

<p>It was encoded into another integer array <code>encoded</code> of length <code>n - 1</code>, such that <code>encoded[i] = perm[i] XOR perm[i + 1]</code>. For example, if <code>perm = [1,3,2]</code>, then <code>encoded = [2,1]</code>.</p>

<p>Given the <code>encoded</code> array, return <em>the original array</em> <code>perm</code>. It is guaranteed that the answer exists and is unique.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> encoded = [3,1]
<strong>Output:</strong> [1,2,3]
<strong>Explanation:</strong> If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> encoded = [6,5,4,6]
<strong>Output:</strong> [2,4,1,5,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;&nbsp;10<sup>5</sup></code></li>
	<li><code>n</code>&nbsp;is odd.</li>
	<li><code>encoded.length == n - 1</code></li>
</ul>


**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

A common trick of solve bit manipulation problem on an array of numbers is to consider them bit by bit.

Consider the `i`-th bit of all the numbers. It only has two options, `0` or `1`. If we use `0` there, we can use the `encoded` array to deduce the `i`-th bits of all the other numbers. We can count the number of `1`s and compare the count with the count of `1`s at the `i`-th bit of integers from `1` to `N`.

If the counts match, we choose `0`. Otherwise we choose `1`.

Since `N` is at most `1e5`, so just need to compare `0`-th to `floor(log2(1e5)) = 16`-th bits.

Is it possible that choosing `0` or `1` results in the same count? No, because choosing `0` or `1` will yield two exactly opposite sequence. Since `n` is odd, these two sequence won't have the same number of `1`s.

```cpp
// OJ: https://leetcode.com/problems/decode-xored-permutation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> decode(vector<int>& A) {
        int N = A.size() + 1;
        vector<int> ans(N);
        for (int i = 0; i <= 16; ++i) {
            int target = 0, bit = 0, cnt = 0;
            for (int j = 1; j <= N; ++j) target += j >> i & 1;
            for (int n : A) {
                bit ^= n >> i & 1;
                cnt += bit;
            }
            ans[0] |= (cnt != target) << i;
            for (int j = 1; j < N; ++j) {
                int x = A[j - 1] >> i & 1, prev = ans[j - 1] >> i & 1, b = x ^ prev;
                ans[j] |= b << i;
            }
        }
        return ans;
    }
};
```

## Solution 2.

If we can find the correct first number, we can deduce all other numbers in `O(N)` time.

To find the first number, we can use the fact that `n` is odd. So:

```
a2 ^ a3 = A[1]
a4 ^ a5 = A[3]
...
```

So `a2 ^ a3 ^ a4 ^ ... ^ an = A[1] ^ A[3] ^ ...`

Since `a1 ^ a2 ^ a3 ^ ... ^ an = 1 ^ 2 ^ 3 ^ ... ^ n`, `a1 = 1 ^ 2 ^ 3 ^ ... ^ n ^ A[1] ^ A[3] ^ ...`.

```cpp
// OJ: https://leetcode.com/problems/decode-xored-permutation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/decode-xored-permutation/discuss/1031107/JavaC%2B%2BPython-Straight-Forward-Solution
class Solution {
public:
    vector<int> decode(vector<int>& A) {
        int first = 0;
        for (int i = 1; i < A.size(); i += 2) first ^= A[i];
        for (int i = 1; i <= A.size() + 1; ++i) first ^= i;
        vector<int> ans = {first};
        for (int n : A) ans.push_back(n ^ ans.back());
        return ans;
    }
};
```

Actually since `n` is odd, we can get the `1 ^ 2 ^ 3 ^ ... ^ n` in `O(1)` time.

Since `2 ^ 3 = 1`, `4 ^ 5 = 1`, `6 ^ 7 = 1` ..., so `XOR(1) = 1`, `XOR(3) = 0`, `XOR(5) = 1`, `XOR(7) = 0` ... where `XOR(n) = 1 ^ 2 ^ ... ^ n`.

So `XOR(n) = 1 - n / 2 % 2`.

```cpp
// OJ: https://leetcode.com/problems/decode-xored-permutation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/decode-xored-permutation/discuss/1031107/JavaC%2B%2BPython-Straight-Forward-Solution
class Solution {
public:
    vector<int> decode(vector<int>& A) {
        int N = A.size() + 1, first = 1 - N / 2 % 2;
        for (int i = 1; i < A.size(); i += 2) first ^= A[i];
        vector<int> ans = {first};
        for (int n : A) ans.push_back(n ^ ans.back());
        return ans;
    }
};
```
