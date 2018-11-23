# [371. Sum of Two Integers (Easy)](https://leetcode.com/problems/sum-of-two-integers/)

<p>Calculate the sum of two integers <i>a</i> and <i>b</i>, but you are <b>not allowed</b> to use the operator <code>+</code> and <code>-</code>.</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>a = <span id="example-input-1-1">1</span>, b = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">3</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>a = -<span id="example-input-2-1">2</span>, b = <span id="example-input-2-2">3</span>
<strong>Output: </strong>1
</pre>
</div>
</div>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sum-of-two-integers/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
```