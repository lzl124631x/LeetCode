# [2043. Simple Bank System (Medium)](https://leetcode.com/problems/simple-bank-system/)

<p>You have been tasked with writing a program for a popular bank that will automate all its incoming transactions (transfer, deposit, and withdraw). The bank has <code>n</code> accounts numbered from <code>1</code> to <code>n</code>. The initial balance of each account is stored in a <strong>0-indexed</strong> integer array <code>balance</code>, with the <code>(i + 1)<sup>th</sup></code> account having an initial balance of <code>balance[i]</code>.</p>

<p>Execute all the <strong>valid</strong> transactions. A transaction is <strong>valid</strong> if:</p>

<ul>
	<li>The given account number(s) are between <code>1</code> and <code>n</code>, and</li>
	<li>The amount of money withdrawn or transferred from is <strong>less than or equal</strong> to the balance of the account.</li>
</ul>

<p>Implement the <code>Bank</code> class:</p>

<ul>
	<li><code>Bank(long[] balance)</code> Initializes the object with the <strong>0-indexed</strong> integer array <code>balance</code>.</li>
	<li><code>boolean transfer(int account1, int account2, long money)</code> Transfers <code>money</code> dollars from the account numbered <code>account1</code> to the account numbered <code>account2</code>. Return <code>true</code> if the transaction was successful, <code>false</code> otherwise.</li>
	<li><code>boolean deposit(int account, long money)</code> Deposit <code>money</code> dollars into the account numbered <code>account</code>. Return <code>true</code> if the transaction was successful, <code>false</code> otherwise.</li>
	<li><code>boolean withdraw(int account, long money)</code> Withdraw <code>money</code> dollars from the account numbered <code>account</code>. Return <code>true</code> if the transaction was successful, <code>false</code> otherwise.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
<strong>Output</strong>
[null, true, true, true, false, false]

<strong>Explanation</strong>
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // return true, account 3 has a balance of $20, so it is valid to withdraw $10.
                         // Account 3 has $20 - $10 = $10.
bank.transfer(5, 1, 20); // return true, account 5 has a balance of $30, so it is valid to transfer $20.
                         // Account 5 has $30 - $20 = $10, and account 1 has $10 + $20 = $30.
bank.deposit(5, 20);     // return true, it is valid to deposit $20 to account 5.
                         // Account 5 has $10 + $20 = $30.
bank.transfer(3, 4, 15); // return false, the current balance of account 3 is $10,
                         // so it is invalid to transfer $15 from it.
bank.withdraw(10, 50);   // return false, it is invalid because account 10 does not exist.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == balance.length</code></li>
	<li><code>1 &lt;= n, account, account1, account2 &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= balance[i], money &lt;= 10<sup>12</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <strong>each</strong> function <code>transfer</code>, <code>deposit</code>, <code>withdraw</code>.</li>
</ul>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/simple-bank-system/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
class Bank {
    vector<long long> balance;
    bool valid(int account) {
        return account > 0 && account <= balance.size();
    }
    bool enough(int account, long long money) {
        return balance[account - 1] >= money;
    }
public:
    Bank(vector<long long>& balance) : balance(balance) {}
    bool transfer(int from, int to, long long money) {
        if (valid(from) && valid(to) && enough(from, money)) {
            balance[from - 1] -= money;
            balance[to - 1] += money;
            return true;
        }
        return false;
    }
    bool deposit(int account, long long money) {
        if (valid(account)) {
            balance[account - 1] += money;
            return true;
        }
        return false;
    }
    bool withdraw(int account, long long money) {
        if (valid(account) && enough(account, money)) {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};
```

We can also implement `transfer` using `withdraw` and `deposit`.

```cpp
bool transfer(int from, int to, long long money) {
    return valid(to) && withdraw(from, money) && deposit(to, money);
}
```

## Discuss

https://leetcode.com/problems/simple-bank-system/discuss/1525207/C%2B%2B-Straightforward