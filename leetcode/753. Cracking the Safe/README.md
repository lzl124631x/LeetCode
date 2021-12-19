# [753. Cracking the Safe (Hard)](https://leetcode.com/problems/cracking-the-safe/)

<p>There is a safe protected by a password. The password is a sequence of <code>n</code> digits where each digit can be in the range <code>[0, k - 1]</code>.</p>

<p>The safe has a peculiar way of checking the password. When you enter in a sequence, it checks the <strong>most recent </strong><code>n</code><strong> digits</strong> that were entered each time you type a digit.</p>

<ul>
	<li>For example, the correct password is <code>"345"</code> and you enter in <code>"012345"</code>:

	<ul>
		<li>After typing <code>0</code>, the most recent <code>3</code> digits is <code>"0"</code>, which is incorrect.</li>
		<li>After typing <code>1</code>, the most recent <code>3</code> digits is <code>"01"</code>, which is incorrect.</li>
		<li>After typing <code>2</code>, the most recent <code>3</code> digits is <code>"012"</code>, which is incorrect.</li>
		<li>After typing <code>3</code>, the most recent <code>3</code> digits is <code>"123"</code>, which is incorrect.</li>
		<li>After typing <code>4</code>, the most recent <code>3</code> digits is <code>"234"</code>, which is incorrect.</li>
		<li>After typing <code>5</code>, the most recent <code>3</code> digits is <code>"345"</code>, which is correct and the safe unlocks.</li>
	</ul>
	</li>
</ul>

<p>Return <em>any string of <strong>minimum length</strong> that will unlock the safe <strong>at some point</strong> of entering it</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1, k = 2
<strong>Output:</strong> "10"
<strong>Explanation:</strong> The password is a single digit, so enter each digit. "01" would also unlock the safe.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, k = 2
<strong>Output:</strong> "01100"
<strong>Explanation:</strong> For each possible password:
- "00" is typed in starting from the 4<sup>th</sup> digit.
- "01" is typed in starting from the 1<sup>st</sup> digit.
- "10" is typed in starting from the 3<sup>rd</sup> digit.
- "11" is typed in starting from the 2<sup>nd</sup> digit.
Thus "01100" will unlock the safe. "01100", "10011", and "11001" would also unlock the safe.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 4</code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
	<li><code>1 &lt;= k<sup>n</sup> &lt;= 4096</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Eulerian Circuit](https://leetcode.com/tag/eulerian-circuit/)


## Solution 1. DFS

Given `n` and `k`, there will be `k^n` unique passwords. When I was solving this problem, I had an assumption that
* the best answer should have each of those passwords appear exactly once
* each password should exactly use the last `n-1` digits of its previous password.

This assumption can be proved by [De Bruijn sequence](https://en.wikipedia.org/wiki/De_Bruijn_sequence).

So the answer should be of length `n + k^n - 1`.

We can use DFS to try all digits at each level and backtrack if the new digit can't form a new password. Once we've visited `k^n` unique passwords, we know that we've found the answer.

```cpp
// OJ: https://leetcode.com/problems/cracking-the-safe/
// Author: github.com/lzl124631x
// Time: O((NK)^(K^N))
// Space: O(N*(K^N))
class Solution {
private:
public:
    string crackSafe(int n, int k) {
        string ans(n, '0');
        unordered_set<string> seen{{ans}};
        int goal = pow(k, n);
        function<bool()> dfs = [&]() {
            if (seen.size() == goal) return true;
            for (int i = 0; i < k; ++i) {
                ans += '0' + i;
                auto pwd = ans.substr(ans.size() - n);
                if (!seen.count(pwd)) {
                    seen.insert(pwd);
                    if (dfs()) return true;
                    seen.erase(pwd);
                }
                ans.pop_back();
            }
            return false;
        };
        dfs();
        return ans;
    }
};
```

## Solution 2. DFS (post-order Hierholzer's algorithm)

We can think of this problem as a problem of finding an Eulerian path (a path visiting every edge exactly once) on the following graph: there are `k^(n − 1)` nodes with each node standing for `n - 1` digits and having `k` edges

For example, when `k = 4, n = 3`, the nodes are `'00', '01', '02', ..., '32', '33'` and each node has 4 edges `'0', '1', '2', '3'`. A node plus edge represents a _complete edge_ which forms a password and is a substring of our answer.

Any connected directed graph where all nodes have equal in-degree and out-degree has an Eulerian circuit (an Eulerian path ending where it started.) Because our graph is highly connected and symmetric, we should expect intuitively that taking any path greedily in some order will probably result in an Eulerian path.

This intuition is called Hierholzer's algorithm: whenever there is an Eulerian circuit, we can construct it greedily. Please see my note of this algorithm [here](https://github.com/lzl124631x/algorithm/blob/master/graph/eulerian-path.md).

Note that we shouldn't add the edge into the answer right after we visit it, because it will cause us to get stuck prematurely. For example, with `k = 2, n = 2`, we have the nodes `'0', '1'`. If we greedily visit complete edges `'00', '01', '10'`, we will be stuck at the node `'0'` prematurely. So we should record the edges in post-order, that is, after finding a complete Eulerian circuit, keep recording the edges into answer as we back-tracking to the start node.

Again, take the `k = 2, n = 2` as example, we visit the complete edges in the following order:

```
 a     0     b     1     c     0     d
(0) ------> (0) ------> (1) ------> (0) [Stuck! Backtrack]
      [00]        [01]   |    [10]
                         |
                         |     1      e
                         └---------> (1) [All passwords visited!]
                              [11]
```

We output `d -> e -> c -> b` i.e. `0110` to the `ans` string. Since `start = "0"`, the answer is `ans + start = "01100"`.

```cpp
// OJ: https://leetcode.com/problems/cracking-the-safe/
// Author: github.com/lzl124631x
// Time: O(N^(K^N))
// Space: O(N*(K^N))
class Solution {
public:
    string crackSafe(int n, int k) {
        if (n == 1 && k == 1) return "0";
        unordered_set<string> seen;
        string ans, start(n - 1, '0');
        function<void(string)> euler = [&](string u) {
            for (char c = '0'; c < '0' + k; ++c) {
                auto v = u + c;
                if (seen.count(v)) continue;
                seen.insert(v);
                euler(v.substr(1));
                ans.push_back(c);
            }
        };
        euler(start);
        return ans + start;
    }
};
```