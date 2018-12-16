# [754. Reach a Number (Easy)](https://leetcode.com/problems/reach-a-number/)

<p>
You are standing at position <code>0</code> on an infinite number line.  There is a goal at position <code>target</code>.
</p><p>
On each move, you can either go left or right.  During the <i>n</i>-th move (starting from 1), you take <i>n</i> steps.
</p><p>
Return the minimum number of steps required to reach the destination.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> target = 3
<b>Output:</b> 2
<b>Explanation:</b>
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> target = 2
<b>Output:</b> 3
<b>Explanation:</b>
On the first move we step from 0 to 1.
On the second move we step  from 1 to -1.
On the third move we step from -1 to 2.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><li><code>target</code> will be a non-zero integer in the range <code>[-10^9, 10^9]</code>.</li>
<p></p>

**Companies**:  
[InMobi](https://leetcode.com/company/inmobi)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

Try to find pattern:

Firstly, for numbers `n(n+1)/2`, they require `n` steps, where `n >= 1`. For example, `1 = 1`, `3 = 1 + 2`, `6 = 1 + 2 + 3`...

How to get the numbers inbetween?

Think of `2`: the smallest `n(n+1)/2` greater than `2` is `3`. If we invert `3`'s component `1` or `2`, we actually subtract `1*2` or `2*2` from `3`. Notice the subtraction is using even number. But `3 - 2 = 1` is an odd number. So we can't get `2` from `3`.

Consider the next `n(n+1)/2`, which is `6`. `6 - 2 = 4`. So we can invert `4 / 2 = 2` in equation `6 = 1 + 2 + 3` to get `2 = 1 - 2 + 3`.

Let's examine our algorithm with two more test cases.

For `4`, the next `n(n+1)/2` is `6`. Since `6 - 4 = 2`, so we can invert `1` in `6 = 1 + 2 + 3` to get `4 = -1 + 2 + 3`.

For `5`:
* check `6`, `6 - 5 = 1`, doesn't work.
* check `10 = 1+..+4`, `10 - 5 = 5`, doesn't work.
* check `15 = 1+..+5`, `15 - 5 = 10`. Works! `5 = 1 + 2 + 3 + 4 - 5`.

In sum, keep computing `sum = n(n+1)/2`. If `sum` is greater than or equal to `target` and `(sum - target) % 2 == 0`, the corresponding `n` is the answer.

```cpp
// OJ: https://leetcode.com/problems/reach-a-number/
// Author: github.com/lzl124631x
// Time: O(sqrt(T))
// Space: O(1)
class Solution {
public:
    int reachNumber(int target) {
        int i = 0, sum = 0;
        target = abs(target);
        while (sum < target || (sum - target) % 2 != 0) {
            sum += ++i;
        }
        return i;
    }
};
```