# [672. Bulb Switcher II (Medium)](https://leetcode.com/problems/bulb-switcher-ii/)

<p>There is a room with <code>n</code> lights which are turned on initially and 4 buttons on the wall. After performing exactly <code>m</code> unknown operations towards buttons, you need to return how many different kinds of status of the <code>n</code> lights could be.</p>

<p>Suppose <code>n</code> lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:</p>

<ol>
	<li>Flip all the lights.</li>
	<li>Flip lights with even numbers.</li>
	<li>Flip lights with odd numbers.</li>
	<li>Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...</li>
</ol>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> n = 1, m = 1.
<b>Output:</b> 2
<b>Explanation:</b> Status can be: [on], [off]
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> n = 2, m = 1.
<b>Output:</b> 3
<b>Explanation:</b> Status can be: [on, off], [off, on], [off, off]
</pre>

<p>&nbsp;</p>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> n = 3, m = 1.
<b>Output:</b> 4
<b>Explanation:</b> Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].
</pre>

<p>&nbsp;</p>

<p><b>Note:</b> <code>n</code> and <code>m</code> both fit in range [0, 1000].</p>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Bulb Switcher (Medium)](https://leetcode.com/problems/bulb-switcher/)
* [Bulb Switcher III (Medium)](https://leetcode.com/problems/bulb-switcher-iii/)

## Solution 1.

### Intuition

The search space is very large ($2^N$ states of lights, naively $4^M$ operation sequences). We need to reduce it.

**The first 6 lights uniquely determine the rest of the lights** because every operation that changes the `x`-th light also modifies the `x+6`-th light.

The order of operations doesn't matter. Doing operation A followed by B is the same as doing operation B followed by A. So **we can assume we do all the operations in order**.

Finally, doing the same operation twice is the same as doing nothing. So **we only need to consider whether we do an operation `0` or `1` times**.

### Algorithm

Say we do the `i`-th operation `time[i]` times (`0 <= i < 4` and `times[i] = 0 or 1`). What are the possible residues? 



```cpp
// OJ: https://leetcode.com/problems/bulb-switcher-ii/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/bulb-switcher-ii/solution/
class Solution {
public:
    int flipLights(int n, int m) {
        unordered_set<int> seen;
        n = min(n, 6);
        int shift = 6 - n;
        for (int i = 0; i < 16; ++i) {
            int cnt = __builtin_popcount(i);
            if (cnt % 2 == m % 2 && cnt <= m) {
                int lights = 0;
                if ((i >> 0) & 1) lights ^= 0b111111 >> shift;
                if ((i >> 1) & 1) lights ^= 0b010101 >> shift;
                if ((i >> 2) & 1) lights ^= 0b101010 >> shift;
                if ((i >> 3) & 1) lights ^= 0b100100 >> shift;
                seen.insert(lights);
            }
        }
        return seen.size();
    }
};
```