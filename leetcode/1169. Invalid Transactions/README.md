# [1169. Invalid Transactions (Medium)](https://leetcode.com/problems/invalid-transactions/)

<p>A transaction is <em>possibly invalid</em> if:</p>

<ul>
	<li>the amount exceeds $1000, or;</li>
	<li>if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.</li>
</ul>

<p>Each transaction string <code>transactions[i]</code>&nbsp;consists of&nbsp;comma separated values representing&nbsp;the name, time (in minutes), amount, and city of the transaction.</p>

<p>Given a list of <code>transactions</code>,&nbsp;return a list of transactions that are possibly invalid.&nbsp; You may return the answer in any order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
<strong>Output:</strong> ["alice,20,800,mtv","alice,50,100,beijing"]
<strong>Explanation:</strong> The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
<strong>Output:</strong> ["alice,50,1200,mtv"]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
<strong>Output:</strong> ["bob,50,1200,mtv"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>transactions.length &lt;= 1000</code></li>
	<li>Each <code>transactions[i]</code> takes the form <code>"{name},{time},{amount},{city}"</code></li>
	<li>Each <code>{name}</code> and <code>{city}</code>&nbsp;consist of&nbsp;lowercase English letters, and have lengths between <code>1</code> and <code>10</code>.</li>
	<li>Each <code>{time}</code> consist of&nbsp;digits, and represent an integer between <code>0</code> and <code>1000</code>.</li>
	<li>Each <code>{amount}</code>&nbsp;consist of&nbsp;digits, and represent an integer between <code>0</code> and <code>2000</code>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/invalid-transactions/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
struct Transaction {
    string name;
    int time;
    int amount;
    string city;
    Transaction(string t) {
        istringstream ss(t);
        getline(ss, name, ',');
        string token;
        getline(ss, token, ',');
        time = stoi(token);
        getline(ss, token, ',');
        amount = stoi(token);
        ss >> city;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& A) {
        vector<Transaction> B;
        unordered_set<int> invalid;
        for (int i = 0; i < A.size(); ++i) {
            auto t = Transaction(A[i]);
            if (t.amount > 1000) invalid.insert(i);
            B.push_back(t);
        }
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                if (B[i].name == B[j].name && abs(B[i].time - B[j].time) <= 60 && B[i].city != B[j].city) {
                    invalid.insert(i);
                    invalid.insert(j);
                }
            }
        }
        vector<string> ans;
        for (int i : invalid) ans.push_back(A[i]);
        return ans;
    }
};
```

## Solution 1. Sliding Window

```cpp
// OJ: https://leetcode.com/problems/invalid-transactions/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
struct Transaction {
    string name;
    int time;
    int amount;
    string city;
    Transaction(string t) {
        istringstream ss(t);
        getline(ss, name, ',');
        string token;
        getline(ss, token, ',');
        time = stoi(token);
        getline(ss, token, ',');
        amount = stoi(token);
        ss >> city;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& A) {
        unordered_map<string, vector<int>> m;
        vector<Transaction> B;
        unordered_set<int> invalid;
        for (int i = 0; i < A.size(); ++i) {
            auto t = Transaction(A[i]);
            if (t.amount > 1000) invalid.insert(i);
            m[t.name].push_back(i);
            B.push_back(t);
        }
        for (auto &[p, ids] : m) {
            sort(begin(ids), end(ids), [&](int a, int b) { return B[a].time < B[b].time; });
            int i = 0, j = 0, k = 0, N = ids.size();
            unordered_map<string, int> cities;
            while (j < N) {
                while (B[ids[j]].time - B[ids[i]].time > 60) {
                    auto &c = B[ids[i++]];
                    if (--cities[c.city] == 0) cities.erase(c.city);
                }
                if (B[ids[j]].time - B[ids[i]].time <= 60) {
                    auto &c = B[ids[j++]];
                    cities[c.city]++;
                    if (cities.size() > 1) {
                        for (k = max(k, i); k < j; ++k) invalid.insert(ids[k]);
                    }
                }
            }
        }
        vector<string> ans;
        for (int i : invalid) ans.push_back(A[i]);
        return ans;
    }
};
```