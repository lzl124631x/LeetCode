# [780. Reaching Points (Hard)](https://leetcode.com/problems/reaching-points/)

<p>A move consists of taking a point <code>(x, y)</code> and transforming it to either <code>(x, x+y)</code> or <code>(x+y, y)</code>.</p>

<p>Given a starting point <code>(sx, sy)</code> and a target point <code>(tx, ty)</code>, return <code>True</code> if and only if a sequence of moves exists to transform the point <code>(sx, sy)</code> to <code>(tx, ty)</code>. Otherwise, return <code>False</code>.</p>

<pre><strong>Examples:</strong>
<strong>Input:</strong> sx = 1, sy = 1, tx = 3, ty = 5
<strong>Output:</strong> True
<strong>Explanation:</strong>
One series of moves that transforms the starting point to the target is:
(1, 1) -&gt; (1, 2)
(1, 2) -&gt; (3, 2)
(3, 2) -&gt; (3, 5)

<strong>Input:</strong> sx = 1, sy = 1, tx = 2, ty = 2
<strong>Output:</strong> False

<strong>Input:</strong> sx = 1, sy = 1, tx = 1, ty = 1
<strong>Output:</strong> True

</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>sx, sy, tx, ty</code> will all be integers in the range <code>[1, 10^9]</code>.</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

Starting from `(sx, sy)` will get TLE since there are many branches we need to try.

Instead, we should start from `(tx, ty)` since there could be only a single valid route.

If `tx > ty`, the previous point must be `(tx - ty, ty)`.

If `tx < ty`, the previous point must be `(tx, ty - tx)`.

`tx` and `ty` can't be the same otherwise the previous point will have `0` value in the coordinates.

If `tx > ty`, instead of keeping subtracting `ty` which could be slow when `tx` is very large and `ty` is very small, we do `tx %= ty`. The `tx < ty` case is symmetrical.

We loop until `tx <= sx` or `ty <= sy`, then we have two valid cases:

* `sx == tx`, `ty >= sy` and `ty - sy` is divisible by `sx`.
* `sy == sy`, `sx >= tx` and `tx - sx` is divisible by `sy`.

```cpp
// OJ: https://leetcode.com/problems/reaching-points/
// Author: github.com/lzl124631x
// Time: O(log(max(tx, ty)))
// Space: O(1)
// Ref: https://leetcode.com/problems/reaching-points/discuss/114856/JavaC%2B%2BPython-Modulo-from-the-End
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty) {
            if (tx < ty) ty %= tx;
            else tx %= ty;
        }
        return (sx == tx && sy <= ty && (ty - sy) % sx == 0)
            || (sy == ty && sx <= tx && (tx - sx) % sy == 0);
    }
};
```