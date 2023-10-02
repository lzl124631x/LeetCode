# [2303. Calculate Amount Paid in Taxes (Easy)](https://leetcode.com/problems/calculate-amount-paid-in-taxes)

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>brackets</code> where <code>brackets[i] = [upper<sub>i</sub>, percent<sub>i</sub>]</code> means that the <code>i<sup>th</sup></code> tax bracket has an upper bound of <code>upper<sub>i</sub></code> and is taxed at a rate of <code>percent<sub>i</sub></code>. The brackets are <strong>sorted</strong> by upper bound (i.e. <code>upper<sub>i-1</sub> &lt; upper<sub>i</sub></code> for <code>0 &lt; i &lt; brackets.length</code>).</p>
<p>Tax is calculated as follows:</p>
<ul>
	<li>The first <code>upper<sub>0</sub></code> dollars earned are taxed at a rate of <code>percent<sub>0</sub></code>.</li>
	<li>The next <code>upper<sub>1</sub> - upper<sub>0</sub></code> dollars earned are taxed at a rate of <code>percent<sub>1</sub></code>.</li>
	<li>The next <code>upper<sub>2</sub> - upper<sub>1</sub></code> dollars earned are taxed at a rate of <code>percent<sub>2</sub></code>.</li>
	<li>And so on.</li>
</ul>
<p>You are given an integer <code>income</code> representing the amount of money you earned. Return <em>the amount of money that you have to pay in taxes.</em> Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> brackets = [[3,50],[7,10],[12,25]], income = 10
<strong>Output:</strong> 2.65000
<strong>Explanation:</strong>
Based on your income, you have 3 dollars in the 1<sup>st</sup> tax bracket, 4 dollars in the 2<sup>nd</sup> tax bracket, and 3 dollars in the 3<sup>rd</sup> tax bracket.
The tax rate for the three tax brackets is 50%, 10%, and 25%, respectively.
In total, you pay $3 * 50% + $4 * 10% + $3 * 25% = $2.65 in taxes.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> brackets = [[1,0],[4,25],[5,50]], income = 2
<strong>Output:</strong> 0.25000
<strong>Explanation:</strong>
Based on your income, you have 1 dollar in the 1<sup>st</sup> tax bracket and 1 dollar in the 2<sup>nd</sup> tax bracket.
The tax rate for the two tax brackets is 0% and 25%, respectively.
In total, you pay $1 * 0% + $1 * 25% = $0.25 in taxes.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> brackets = [[2,50]], income = 0
<strong>Output:</strong> 0.00000
<strong>Explanation:</strong>
You have no income to tax, so you have to pay a total of $0 in taxes.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= brackets.length &lt;= 100</code></li>
	<li><code>1 &lt;= upper<sub>i</sub> &lt;= 1000</code></li>
	<li><code>0 &lt;= percent<sub>i</sub> &lt;= 100</code></li>
	<li><code>0 &lt;= income &lt;= 1000</code></li>
	<li><code>upper<sub>i</sub></code> is sorted in ascending order.</li>
	<li>All the values of <code>upper<sub>i</sub></code> are <strong>unique</strong>.</li>
	<li>The upper bound of the last tax bracket is greater than or equal to <code>income</code>.</li>
</ul>

**Companies**:
[Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Simulation](https://leetcode.com/tag/simulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/calculate-amount-paid-in-taxes
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    double calculateTax(vector<vector<int>>& A, int income) {
        int prev = 0;
        double ans = 0;
        for (auto &v : A) {
            int upper = v[0], percent = v[1];
            if (income <= upper) {
                ans += (double)(income - prev) * percent / 100;
                break;
            } else ans += (double)(upper - prev) * percent / 100;
            prev = upper;
        }
        return ans;
    }
};
```