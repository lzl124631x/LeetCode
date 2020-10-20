# [1622. Fancy Sequence (Hard)](https://leetcode.com/problems/fancy-sequence/)

<p>Write an API that generates fancy sequences using the <code>append</code>, <code>addAll</code>, and <code>multAll</code> operations.</p>

<p>Implement the <code>Fancy</code> class:</p>

<ul>
	<li><code>Fancy()</code> Initializes the object with an empty sequence.</li>
	<li><code>void append(val)</code> Appends an integer <code>val</code> to the end of the sequence.</li>
	<li><code>void addAll(inc)</code> Increments all existing values in the sequence by an integer <code>inc</code>.</li>
	<li><code>void multAll(m)</code> Multiplies all existing values in the sequence by an integer <code>m</code>.</li>
	<li><code>int getIndex(idx)</code> Gets the current value at index <code>idx</code> (0-indexed) of the sequence <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>. If the index is greater or equal than the length of the sequence, return <code>-1</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
<strong>Output</strong>
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

<strong>Explanation</strong>
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -&gt; [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -&gt; [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -&gt; [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -&gt; [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= val, inc, m &lt;= 100</code></li>
	<li><code>0 &lt;= idx &lt;= 10<sup>5</sup></code></li>
	<li>At most <code>10<sup>5</sup></code> calls total will be made to <code>append</code>, <code>addAll</code>, <code>multAll</code>, and <code>getIndex</code>.</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Design](https://leetcode.com/tag/design/)

## Solution 1.

```python
# OJ: https://leetcode.com/problems/fancy-sequence/
# Author: github.com/lzl124631x
# Time: O(1) for all
# Space: O(N)
# Ref: https://leetcode.com/problems/fancy-sequence/discuss/898753/Python-Time-O(1)-for-each
class Fancy:
    def __init__(self):
        self.A = []
        self.add = [0]
        self.mul = [1]
    def append(self, val: int) -> None:
        self.A.append(val)
        self.add.append(self.add[-1])
        self.mul.append(self.mul[-1])
    def addAll(self, inc: int) -> None:
        self.add[-1] += inc
    def multAll(self, m: int) -> None:
        self.add[-1] *= m
        self.mul[-1] *= m
    def getIndex(self, i: int) -> int:
        if i >= len(self.A): return -1
        m = self.mul[-1] // self.mul[i]
        inc = self.add[-1] - self.add[i] * m
        return int((self.A[i] * m + inc) % (10 ** 9 + 7))
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/fancy-sequence/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
// Ref: https://leetcode.com/problems/fancy-sequence/discuss/898861/C%2B%2B-Math-Solution-O(1)-extra-space-and-O(1)-time-for-each
class Fancy {
    typedef unsigned long UL;
    UL mod = 1e9 + 7, len = 0, increment = 0, mul = 1, A[100001];
    UL modPow(UL base, UL exp) {
        UL ans = 1, p = base;
        for (; exp; exp >>= 1) {
            if (exp & 1) ans = (ans * p) % mod;
            p = (p * p) % mod;
        }
        return ans;
    }
public:
    Fancy() {}
    void append(int val) {
        A[len++] = (((val - increment + mod) % mod) * modPow(mul, mod - 2)) % mod;
    }
    void addAll(int inc) {
        increment = (increment + inc) % mod;
    }
    void multAll(int m) {
        mul = (mul * m) % mod;
        increment = (increment * m) % mod;
    }
    int getIndex(int i) {
        return i >= len ? -1 : ((A[i] * mul) % mod + increment) % mod;
    }
};
```
