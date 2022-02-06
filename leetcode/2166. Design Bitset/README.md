# [2166. Design Bitset (Medium)](https://leetcode.com/problems/design-bitset/)

<p>A <strong>Bitset</strong> is a data structure that compactly stores bits.</p>

<p>Implement the <code>Bitset</code> class:</p>

<ul>
	<li><code>Bitset(int size)</code> Initializes the Bitset with <code>size</code> bits, all of which are <code>0</code>.</li>
	<li><code>void fix(int idx)</code> Updates the value of the bit at the index <code>idx</code> to <code>1</code>. If the value was already <code>1</code>, no change occurs.</li>
	<li><code>void unfix(int idx)</code> Updates the value of the bit at the index <code>idx</code> to <code>0</code>. If the value was already <code>0</code>, no change occurs.</li>
	<li><code>void flip()</code> Flips the values of each bit in the Bitset. In other words, all bits with value <code>0</code> will now have value <code>1</code> and vice versa.</li>
	<li><code>boolean all()</code> Checks if the value of <strong>each</strong> bit in the Bitset is <code>1</code>. Returns <code>true</code> if it satisfies the condition, <code>false</code> otherwise.</li>
	<li><code>boolean one()</code> Checks if there is <strong>at least one</strong> bit in the Bitset with value <code>1</code>. Returns <code>true</code> if it satisfies the condition, <code>false</code> otherwise.</li>
	<li><code>int count()</code> Returns the <strong>total number</strong> of bits in the Bitset which have value <code>1</code>.</li>
	<li><code>String toString()</code> Returns the current composition of the Bitset. Note that in the resultant string, the character at the <code>i<sup>th</sup></code> index should coincide with the value at the <code>i<sup>th</sup></code> bit of the Bitset.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["Bitset", "fix", "fix", "flip", "all", "unfix", "flip", "one", "unfix", "count", "toString"]
[[5], [3], [1], [], [], [0], [], [], [0], [], []]
<strong>Output</strong>
[null, null, null, null, false, null, null, true, null, 2, "01010"]

<strong>Explanation</strong>
Bitset bs = new Bitset(5); // bitset = "00000".
bs.fix(3);     // the value at idx = 3 is updated to 1, so bitset = "00010".
bs.fix(1);     // the value at idx = 1 is updated to 1, so bitset = "01010". 
bs.flip();     // the value of each bit is flipped, so bitset = "10101". 
bs.all();      // return False, as not all values of the bitset are 1.
bs.unfix(0);   // the value at idx = 0 is updated to 0, so bitset = "00101".
bs.flip();     // the value of each bit is flipped, so bitset = "11010". 
bs.one();      // return True, as there is at least 1 index with value 1.
bs.unfix(0);   // the value at idx = 0 is updated to 0, so bitset = "01010".
bs.count();    // return 2, as there are 2 bits with value 1.
bs.toString(); // return "01010", which is the composition of bitset.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= size &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= idx &lt;= size - 1</code></li>
	<li>At most <code>10<sup>5</sup></code> calls will be made <strong>in total</strong> to <code>fix</code>, <code>unfix</code>, <code>flip</code>, <code>all</code>, <code>one</code>, <code>count</code>, and <code>toString</code>.</li>
	<li>At least one call will be made to <code>all</code>, <code>one</code>, <code>count</code>, or <code>toString</code>.</li>
	<li>At most <code>5</code> calls will be made to <code>toString</code>.</li>
</ul>


**Similar Questions**:
* [Design Underground System (Medium)](https://leetcode.com/problems/design-underground-system/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-bitset/
// Author: github.com/lzl124631x
// Time:
//      Bitset, toString: O(N)
//      fix, unfix, flip, all, one, count: O(1)
// Space: O(N)
class Bitset {
    string s;
    int cnt = 0, flp = 0;
public:
    Bitset(int size) : s(size, '0') {
    }
    void fix(int idx) {
        char from = flp == 0 ? '0' : '1', to = from == '0' ? '1' : '0'; 
        if (s[idx] == from) {
            ++cnt;
            s[idx] = to;
        }
    }
    void unfix(int idx) {
        char from = flp == 0 ? '1' : '0', to = from == '0' ? '1' : '0';
        if (s[idx] == from) {
            --cnt;
            s[idx] = to;
        }
    }
    void flip() {
        flp = 1 - flp;
        cnt = s.size() - cnt;
    }
    bool all() {
        return cnt == s.size();
    }
    bool one() {
        return cnt;
    }
    int count() {
        return cnt;
    }
    string toString() {
        if (flp == 0) return s;
        auto t = s;
        for (char &c : t) c = c == '1' ? '0' : '1';
        return t;
    }
};
```