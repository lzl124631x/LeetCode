# [2241. Design an ATM Machine (Medium)](https://leetcode.com/problems/design-an-atm-machine/)

<p>There is an ATM machine that stores banknotes of <code>5</code> denominations: <code>20</code>, <code>50</code>, <code>100</code>, <code>200</code>, and <code>500</code> dollars. Initially the ATM is empty. The user can use the machine to deposit or withdraw any amount of money.</p>

<p>When withdrawing, the machine prioritizes using banknotes of <strong>larger</strong> values.</p>

<ul>
	<li>For example, if you want to withdraw <code>$300</code> and there are <code>2</code> <code>$50</code> banknotes, <code>1</code> <code>$100</code> banknote, and <code>1</code> <code>$200</code> banknote, then the machine will use the <code>$100</code> and <code>$200</code> banknotes.</li>
	<li>However, if you try to withdraw <code>$600</code> and there are <code>3</code> <code>$200</code> banknotes and <code>1</code> <code>$500</code> banknote, then the withdraw request will be rejected because the machine will first try to use the <code>$500</code> banknote and then be unable to use banknotes to complete the remaining <code>$100</code>. Note that the machine is <strong>not</strong> allowed to use the <code>$200</code> banknotes instead of the <code>$500</code> banknote.</li>
</ul>

<p>Implement the ATM class:</p>

<ul>
	<li><code>ATM()</code> Initializes the ATM object.</li>
	<li><code>void deposit(int[] banknotesCount)</code> Deposits new banknotes in the order <code>$20</code>, <code>$50</code>, <code>$100</code>, <code>$200</code>, and <code>$500</code>.</li>
	<li><code>int[] withdraw(int amount)</code> Returns an array of length <code>5</code> of the number of banknotes that will be handed to the user in the order <code>$20</code>, <code>$50</code>, <code>$100</code>, <code>$200</code>, and <code>$500</code>, and update the number of banknotes in the ATM after withdrawing. Returns <code>[-1]</code> if it is not possible (do <strong>not</strong> withdraw any banknotes in this case).</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"]
[[], [[0,0,1,2,1]], [600], [[0,1,0,1,1]], [600], [550]]
<strong>Output</strong>
[null, null, [0,0,1,0,1], null, [-1], [0,1,0,0,1]]

<strong>Explanation</strong>
ATM atm = new ATM();
atm.deposit([0,0,1,2,1]); // Deposits 1 $100 banknote, 2 $200 banknotes,
                          // and 1 $500 banknote.
atm.withdraw(600);        // Returns [0,0,1,0,1]. The machine uses 1 $100 banknote
                          // and 1 $500 banknote. The banknotes left over in the
                          // machine are [0,0,0,2,0].
atm.deposit([0,1,0,1,1]); // Deposits 1 $50, $200, and $500 banknote.
                          // The banknotes in the machine are now [0,1,0,3,1].
atm.withdraw(600);        // Returns [-1]. The machine will try to use a $500 banknote
                          // and then be unable to complete the remaining $100,
                          // so the withdraw request will be rejected.
                          // Since the request is rejected, the number of banknotes
                          // in the machine is not modified.
atm.withdraw(550);        // Returns [0,1,0,0,1]. The machine uses 1 $50 banknote
                          // and 1 $500 banknote.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>banknotesCount.length == 5</code></li>
	<li><code>0 &lt;= banknotesCount[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= amount &lt;= 10<sup>9</sup></code></li>
	<li>At most <code>5000</code> calls <strong>in total</strong> will be made to <code>withdraw</code> and <code>deposit</code>.</li>
	<li>At least <strong>one</strong> call will be made to each function <code>withdraw</code> and <code>deposit</code>.</li>
</ul>


**Similar Questions**:
* [Simple Bank System (Medium)](https://leetcode.com/problems/simple-bank-system/)
* [Minimum Number of Operations to Convert Time (Easy)](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-an-atm-machine/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(1)
class ATM {
    long val[5] = {20,50,100,200,500}, cnt[5] = {};
public:
    ATM() {}
    void deposit(vector<int> c) {
        for (int i = 0; i < 5; ++i) cnt[i] += c[i];
    }
    vector<int> withdraw(int n) {
        vector<int> ans(5);
        for (int i = 4; i >= 0 && n; --i) {
            ans[i] = min(cnt[i], n / val[i]);
            n -= val[i] * ans[i];
        }
        if (n) return {-1};
        for (int i = 0; i < 5; ++i) cnt[i] -= ans[i];
        return ans;
    }
};
```