# [1611. Minimum One Bit Operations to Make Integers Zero (Hard)](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero)

<p>Given an integer <code>n</code>, you must transform it into <code>0</code> using the following operations any number of times:</p>

<ul>
	<li>Change the rightmost (<code>0<sup>th</sup></code>) bit in the binary representation of <code>n</code>.</li>
	<li>Change the <code>i<sup>th</sup></code> bit in the binary representation of <code>n</code> if the <code>(i-1)<sup>th</sup></code> bit is set to <code>1</code> and the <code>(i-2)<sup>th</sup></code> through <code>0<sup>th</sup></code> bits are set to <code>0</code>.</li>
</ul>

<p>Return <em>the minimum number of operations to transform </em><code>n</code><em> into </em><code>0</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> The binary representation of 3 is &quot;11&quot;.
&quot;<u>1</u>1&quot; -&gt; &quot;<u>0</u>1&quot; with the 2<sup>nd</sup> operation since the 0<sup>th</sup> bit is 1.
&quot;0<u>1</u>&quot; -&gt; &quot;0<u>0</u>&quot; with the 1<sup>st</sup> operation.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 6
<strong>Output:</strong> 4
<strong>Explanation:</strong> The binary representation of 6 is &quot;110&quot;.
&quot;<u>1</u>10&quot; -&gt; &quot;<u>0</u>10&quot; with the 2<sup>nd</sup> operation since the 1<sup>st</sup> bit is 1 and 0<sup>th</sup> through 0<sup>th</sup> bits are 0.
&quot;01<u>0</u>&quot; -&gt; &quot;01<u>1</u>&quot; with the 1<sup>st</sup> operation.
&quot;0<u>1</u>1&quot; -&gt; &quot;0<u>0</u>1&quot; with the 2<sup>nd</sup> operation since the 0<sup>th</sup> bit is 1.
&quot;00<u>1</u>&quot; -&gt; &quot;00<u>0</u>&quot; with the 1<sup>st</sup> operation.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Oracle](https://leetcode.com/company/oracle), [McKinsey](https://leetcode.com/company/mckinsey), [VMware](https://leetcode.com/company/vmware), [Expedia](https://leetcode.com/company/expedia)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Memoization](https://leetcode.com/tag/memoization)

**Similar Questions**:
* [Minimum Number of Operations to Make Array Continuous (Hard)](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous)
* [Apply Bitwise Operations to Make Strings Equal (Medium)](https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal)

**Hints**:
* The fastest way to convert n to zero is to remove all set bits starting from the leftmost one. Try some simple examples to learn the rule of how many steps are needed to remove one set bit.
* consider n=2^k case first, then solve for all n.

## Solution 1.

Operation 1 is `n ^ 1`. Operation 2 is `n ^ (lowbit(n) << 1)` where `lowbit(n) = n & -n`, i.e. the right most bit 1.

n | f(n)
---|---
0 | 0
1 | 1
2 | 3
3 | 2
4 | 7
5 | 6
6 | 4
7 | 5
8 | 15
9 | 14
10 | 12
11 | 13
12 | 8
13 | 9
14 | 11
15 | 10
16 | 31
17 | 30
18 | 28
19 | 29
20 | 24

Observations:

**Observation 1**: Since we are looking for the shortest path, BFS is the first option. But since `n <= 1e9` and the steps to get to 0 might be greater than `n`, BFS will get TLE.

**Observation 2**: We must do operation 1 and 2 alternatively because redoing the same operation is just wasting time.

**Observation 3**: Based on observation 2, we must start with operation 1 or operation 2 and keep doing the operations alternatively to get to 0.

Then how do we determine which operation to start with? I found it depends on the number of bit 1s in `n`.

**If there are odd number of bit 1s in `n`, we start with operation 1; otherwise we start with operation 2.**

For example:

```
n = 2
10 -- operation 1
11 -- operation 2
01 -- operation 1
00
```
And as you can see above, for `n = 3`, we start with operation 2.

This is true because both operation will change the parity of the number of bit 1s in `n`. So if we start with operation 1 for `n` with odd bit 1s, then we must start with operation 2 for `operation1(n)` which has even bit 1s. Since `n = 1` starts with operation 1, so the observation above is correct.

With this observation, we can first check the parity of bit 1s in `n`, then apply operation 1 and 2 alternatively. But this will get TLE because it's still `O(N)` time complexity.

**Observation 4**: If `n = 2^k`, then `f(n) = 2^(k + 1) - 1`. For example, `f(8) = 15`.

In order to get from `n = 2^k` to `2^(k-1)`, we need to visit all the binary numbers under `2^k`. For example, to get from `n = 4` to `2`, we need to do:

```
100 -- 1
101 -- 2
111 -- 3
110 -- 4
010
```

So we have `f(2^k) = 2^k + f(2^(k-1))`. And since `f(1) = 1`, we can get that `f(2^k) = 2^(k + 1) - 1`.

**Observation 5**:

Our goal is always to remove the highest bit 1 first (let's denote it as `highestBit`). To remove the highest bit 1, we must turn the bit after the highest bit 1 to be 1 (let's denote it as `secondHighestBit`).

So if `secondHighestBit` is 1, i.e. `n = 11xxx...xxx`, then the we can do the following:

```
11xxx...xxx --- 1
11000...000 --- 2
01000...000 --- 3
00000...000
```

The steps required for process 2 and 3 are known, `1` and `2^k-1` respectively (assuming the highest bit 1 is `2^k`), `2^k` steps in total. The steps required for process 1 is exactly `f(xxx...xxx)` where `xxx...xxx` are the bits after the second highest bit.

As you can see, it's a recursive process.

Now consider `n = 10xxx...xxx`, then we need to first turn it into `11000...000`.

How many steps are required to get from `10xxx...xxx` to `11000...000`?

(When we ignore the leading 1) It's the same as the steps required from `0xxx...xxx` to `1000...000`, or the other way around from `1000...000` to `0xxx...xxx`.

Since we know `f(1000...000)`, and once we know `f(0xxx...xxx)`, we can get the steps required from `10xxx...xxx` to `11000...000`, which is `f(1000...000) - f(0xxx...xxx)`.

Again, this is a recursive problem.

Let's summarize this observation.

Let

$$ n = 2^k \cdot x_k + 2^{k-1} \cdot x_{k-1} + 2^{k-2} \cdot x_{k-2} + ... + 2^0 \cdot x_0 $$

where $x_k$ is the leftmost bit 1.

Note that 

$$f(2^k + 2^{k-1}) = f(2^{k-1}) + 1 = 2^k$$

If $x_{k-1}$ is `1`, then

$$ f(n) = f(2^{k-2} \cdot x_{k-2} + ... + 2^0 \cdot x_0) + f(2^k + 2^{k-1}) $$

$$ f(n) = f(2^{k-2} \cdot x_{k-2} + ... + 2^0 \cdot x_0) + 2^k $$

If $x_{k-1}$ is `0`, then 

$$f(n) = f(2^k + 2^{k-1}) + f(2^{k-1}) - f(2^{k-2} \cdot x_{k-2} + ... + 2^0 \cdot x_0)$$

$$f(n) = 2^{k+1}-1 - f(2^{k-2} \cdot x_{k-2} + ... + 2^0 \cdot x_0)$$

```cpp
// OJ: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n <= 1) return n;
        unsigned first = 1 << (31 - __builtin_clz(n)), second = (first >> 1) & n, rest = minimumOneBitOperations(n & ~first & ~second);
        return second ? first + rest : (first << 1) - 1 - rest;
    }
};
```

## Solution 2. Gray Code

`n` is actually the `f(n)`-th Gray Code. We can use the following code to convert the gray code `n` to its corresponding binary number `f(n)`.

See more about Gray Code [here](https://en.wikipedia.org/wiki/Gray_code)

```cpp
// OJ: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        while (n) {
            ans ^= n;
            n >>= 1;
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int minimumOneBitOperations(int n) {
        n ^= n >> 16;
        n ^= n >> 8;
        n ^= n >> 4;
        n ^= n >> 2;
        n ^= n >> 1;
        return n;
    }
};
```