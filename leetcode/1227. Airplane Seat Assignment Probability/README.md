# [1227. Airplane Seat Assignment Probability (Medium)](https://leetcode.com/problems/airplane-seat-assignment-probability/)

<p><code data-stringify-type="code">n</code>&nbsp;passengers board an airplane with exactly&nbsp;<code data-stringify-type="code">n</code>&nbsp;seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of passengers will:</p>

<ul>
	<li>Take their own seat if it is still available,&nbsp;</li>
	<li>Pick other seats randomly when they find their seat occupied&nbsp;</li>
</ul>

<p>What is the probability that the n-th person can get his own seat?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1.00000
<strong>Explanation: </strong>The first person can only get the first seat.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 0.50000
<strong>Explanation: </strong>The second person has a probability of 0.5 to get the second seat (when first person gets the first seat).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
</ul>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Brainteaser](https://leetcode.com/tag/brainteaser/), [Probability and Statistics](https://leetcode.com/tag/probability-and-statistics/)

## Solution 1.

Ref:
* https://leetcode.com/problems/airplane-seat-assignment-probability/discuss/411905/It's-not-obvious-to-me-at-all.-Foolproof-explanation-here!!!-And-proof-for-why-it's-12
* https://leetcode.com/problems/airplane-seat-assignment-probability/discuss/420455/Proof-without-mathThree-tiny-stories

```cpp
// OJ: https://leetcode.com/problems/airplane-seat-assignment-probability/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : 0.5;
    }
};
```