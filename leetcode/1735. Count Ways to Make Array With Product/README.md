# [1735. Count Ways to Make Array With Product (Hard)](https://leetcode.com/problems/count-ways-to-make-array-with-product/)

<p>You are given a 2D integer array, <code>queries</code>. For each <code>queries[i]</code>, where <code>queries[i] = [n<sub>i</sub>, k<sub>i</sub>]</code>, find the number of different ways you can place positive integers into an array of size <code>n<sub>i</sub></code> such that the product of the integers is <code>k<sub>i</sub></code>. As the number of ways may be too large, the answer to the <code>i<sup>th</sup></code> query is the number of ways <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>Return <em>an integer array </em><code>answer</code><em> where </em><code>answer.length == queries.length</code><em>, and </em><code>answer[i]</code><em> is the answer to the </em><code>i<sup>th</sup></code><em> query.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> queries = [[2,6],[5,1],[73,660]]
<strong>Output:</strong> [4,1,50734910]
<strong>Explanation:</strong>&nbsp;Each query is independent.
[2,6]: There are 4 ways to fill an array of size 2 that multiply to 6: [1,6], [2,3], [3,2], [6,1].
[5,1]: There is 1 way to fill an array of size 5 that multiply to 1: [1,1,1,1,1].
[73,660]: There are 1050734917 ways to fill an array of size 73 that multiply to 660. 1050734917 modulo 10<sup>9</sup> + 7 = 50734910.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
<strong>Output:</strong> [1,2,3,10,5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>4</sup> </code></li>
	<li><code>1 &lt;= n<sub>i</sub>, k<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-ways-to-make-array-with-product/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
// Ref: https://leetcode.com/problems/count-ways-to-make-array-with-product/discuss/1031066/c%2B%2B-Prime-Factorization-Stars-and-Bars-*Comments-and-Clear-Explanation*
const int MOD = 1e9 + 7;
typedef long long int64;
const int N = 1e5 + 10;
int fact[N], ifact[N], inv[N];
struct comb_init {
    comb_init() {
        inv[1] = 1;
        for (int i = 2; i < N; ++i) {
            inv[i] = (MOD - MOD / i) * (int64)inv[MOD % i] % MOD;
        }
        fact[0] = ifact[0] = 1;
        for (int i = 1; i < N; ++i) {
            fact[i] = (int64)fact[i - 1] * i % MOD;
            ifact[i] = (int64)ifact[i - 1] * inv[i] % MOD;
        }
    }
} comb_init_;
int64 comb(int n, int m) {
    if (n < m || m < 0) return 0;
    return (int64)fact[n] * ifact[m] % MOD * ifact[n - m] % MOD;
}
class Solution {
public:
    vector<int> factorize(int m) { // returns a array of the counts of different prime factors of `m`. E.g. m = 24 = 2^3 * 3^1, so this returns [3, 1].
        vector<int> ans;
        for (int i = 2; i * i <= m; ++i) {
            if (m % i) continue;
            int cnt = 0;
            while (m % i == 0) {
                m /= i;
                ++cnt;
            }
            ans.push_back(cnt);
        }
        if (m > 1) ans.push_back(1);
        return ans;
    }
    vector<int> waysToFillArray(vector<vector<int>>& q) {
        vector<int> ans;
        for (auto& v : q) {
            int n = v[0], m = v[1];
            auto f = factorize(m);
            int cur = 1;
            for (auto& x : f) cur = cur * comb(x + n - 1, x) % MOD; 
            ans.push_back(cur);
        }
        return ans;
    }
};
```