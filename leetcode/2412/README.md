# [2412. Minimum Money Required Before Transactions (Hard)](https://leetcode.com/problems/minimum-money-required-before-transactions)

<p>You are given a <strong>0-indexed</strong> 2D integer array <code><font face="monospace">transactions</font></code>, where <code>transactions[i] = [cost<sub>i</sub>, cashback<sub>i</sub>]</code>.</p>
<p>The array describes transactions, where each transaction must be completed exactly once in <strong>some order</strong>. At any given moment, you have a certain amount of <code>money</code>. In order to complete transaction <code>i</code>, <code>money &gt;= cost<sub>i</sub></code> must hold true. After performing a transaction, <code>money</code> becomes <code>money - cost<sub>i</sub> + cashback<sub>i</sub></code>.</p>
<p>Return<em> the minimum amount of </em><code>money</code><em> required before any transaction so that all of the transactions can be completed <strong>regardless of the order</strong> of the transactions.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> transactions = [[2,1],[5,0],[4,2]]
<strong>Output:</strong> 10
<strong>Explanation:
</strong>Starting with money = 10, the transactions can be performed in any order.
It can be shown that starting with money &lt; 10 will fail to complete all transactions in some order.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> transactions = [[3,0],[0,3]]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
- If transactions are in the order [[3,0],[0,3]], the minimum money required to complete the transactions is 3.
- If transactions are in the order [[0,3],[3,0]], the minimum money required to complete the transactions is 0.
Thus, starting with money = 3, the transactions can be performed in any order.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= transactions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>transactions[i].length == 2</code></li>
	<li><code>0 &lt;= cost<sub>i</sub>, cashback<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

### Intuition

The worst case is that we do losing transactions first and then do winning transactions.

### Algorithm

https://leetcode.com/problems/minimum-money-required-before-transactions/solutions/2588034/java-c-python-easy-and-coincise/comments/1606909

<p>First, assume all the transactions have <code>cost &gt;= cashback</code>, that is we never gain any money from any transactions.</p>
<ol>
<li><code>for (auto&amp; a : A)  res += a[0] - a[1];</code>, accumulate all the possible losses
<ul>
<li>Yet <code>res</code> is not the final answer. As we use up all <code>cashback</code> (that is, the <code>- a[1]</code> part), but we can't actually use the <code>cashback</code> of the last transaction, there's no more transactions left for us to spend it on!</li>
</ul>
</li>
<li><code>for (auto&amp; a : A) v = max(v, a[1]);</code>, find max <code>cashback</code>, let the transaction with max <code>cashback</code> be the very last one</li>
<li><code>res + v</code> will be the answer</li>
</ol>
<p>Second, assume in all transactions we have <code>cost &lt; cashback</code>, that is, we always gain money.</p>
<ol>
<li><code>res = 0</code> (just to keep it symmetric)</li>
<li><code>for (auto&amp; a : A) v = max(v, a[0]);</code> find the max cost of any transactions, we only need enough money to do the very first transaction</li>
<li><code>res + v</code> will be the answer</li>
</ol>
<p>Finally, assume we have some transactions that we lose money and some that we gain money.</p>
<ol>
<li><code>for (auto&amp; a : A) res += max(a[0] - a[1], 0);</code> accumulate all the possible losses from transactions that we lose money</li>
<li><code>for (auto&amp; a : A) v = max(v, min(a[0], a[1]));</code>, find the larger of <strong>max <code>cashback</code> from transactions that we lose money</strong> or <strong>max <code>cost</code> from transactions that we gain money</strong>,   the intuition is:
<ol>
<li>For the worst-case scenario, <strong>we first do all the transactions that we lose money, then we do transactions that gain money</strong>
<ul>
<li>To get pass all the losing transactions, <code>v</code> needs to be at least <strong>max <code>cashback</code> from transactions that we lose money</strong>, see the first scenario</li>
<li>To start the very first transactions that we can gain money, <code>v</code> needs to be at least <strong>max <code>cost</code> from transactions that we gain money</strong>, see the second scenario</li>
</ul>
</li>
<li>In the end, <code>v</code> should be the larger of <strong>max <code>cashback</code> from transactions that we lose money</strong> or <strong>max <code>cost</code> from transactions that we gain money</strong>, as the larger one can cover the smaller one. To get the larger one:
<ul>
<li>For transaction we lose money (<code>a[0] &gt;= a[1]</code>), doing <code>min(a[0], a[1])</code> gives <code>a[1]</code>, that is, the <code>cashback</code>.</li>
<li>For transaction we gain money (<code>a[0] &lt; a[1]</code>), doing <code>min(a[0], a[1])</code> gives <code>a[0]</code>, that is, the <code>cost</code></li>
<li>That's where the confusing <code>v = max(v, min(a[0], a[1]))</code> comes from</li>
</ul>
</li>
</ol>
</li>
<li><code>res + v</code> will be the answer</li>
</ol>

```cpp
// OJ: https://leetcode.com/problems/minimum-money-required-before-transactions
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-money-required-before-transactions/solutions/2588034
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& A) {
        long long ans = 0;
        int v = 0;
        for (auto &t: A) {
            v = max(v, min(t[0], t[1]));
            ans += max(t[0] - t[1], 0);
        }
        return ans + v;
    }
}
```