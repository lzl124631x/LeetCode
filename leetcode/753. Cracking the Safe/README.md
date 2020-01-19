# [753. Cracking the Safe (Hard)](https://leetcode.com/problems/cracking-the-safe/)

<p>There is a box protected by a password. The password is a sequence of&nbsp;<code>n</code> digits&nbsp;where each digit can be one of the first <code>k</code> digits <code>0, 1, ..., k-1</code>.</p>

<p>While entering a password,&nbsp;the last <code>n</code> digits entered will automatically be matched against the correct password.</p>

<p>For example, assuming the correct password is <code>"345"</code>,&nbsp;if you type <code>"012345"</code>, the box will open because the correct password matches the suffix of the entered password.</p>

<p>Return any password of <strong>minimum length</strong> that is guaranteed to open the box at some point of entering it.</p>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> n = 1, k = 2
<b>Output:</b> "01"
<b>Note:</b> "10" will be accepted too.
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> n = 2, k = 2
<b>Output:</b> "00110"
<b>Note:</b> "01100", "10011", "11001" will be accepted too.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li><code>n</code> will be in the range <code>[1, 4]</code>.</li>
	<li><code>k</code> will be in the range <code>[1, 10]</code>.</li>
	<li><code>k^n</code> will be at most <code>4096</code>.</li>
</ol>

<p>&nbsp;</p>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

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
    unordered_set<string> s;
    string ans;
    int N, K, cnt;
    bool dfs(string &str) {
        if (s.size() == cnt) {
            ans = str;
            return true;
        }
        for (int i = 0; i < K; ++i) {
            str.push_back('0' + i);
            auto pwd = str.substr(str.size() - N, N);
            if (!s.count(pwd)) {
                s.insert(pwd);
                if (dfs(str)) return true;
                s.erase(pwd);
            }
            str.pop_back();
        }
        return false;
    }
public:
    string crackSafe(int n, int k) {
        string str(n, '0');
        s.insert(str);
        N = n, K = k, cnt = pow(K, N);
        dfs(str);
        return ans;
    }
};
```

## Solution 2. DFS (post-order Hierholzer's algorithm)

We can think of this problem as the problem of finding an Euler path (a path visiting every edge exactly once) on the following graph: there are `k^(n − 1)` nodes with each node standing for `n - 1` digits and having `k` edges

For example, when `k = 4, n = 3`, the nodes are `'00', '01', '02', ..., '32', '33'` and each node has 4 edges `'0', '1', '2', '3'`. A node plus edge represents a _complete edge_ which forms a password and is a substring of our answer.

Any connected directed graph where all nodes have equal in-degree and out-degree has an Euler circuit (an Euler path ending where it started.) Because our graph is highly connected and symmetric, we should expect intuitively that taking any path greedily in some order will probably result in an Euler path.

This intuition is called Hierholzer's algorithm: whenever there is an Euler cycle, we can construct it greedily. Please see my note of this algorithm [here](../../notes/euler-path.md).

Note that we shouldn't add the edge into the answer right after we visit it, because it will cause us to get stuck prematurely. For example, with `k = 2, n = 2`, we have the nodes `'0', '1'`. If we greedily visit complete edges `'00', '01', '10'`, we will be stuck at the node `'0'` prematurely. So we should record the edges in post-order, that is after finding a complete Euler circuit, keep recording the edges into answer as we back-tracking to the start node.

Again, take the `k = 2, n = 2` as example, we visit the complete edges in the following order:

```
00
01
10 (stuck, back-track)
11
10 (all edges visited!)
```

So when we reached `0` in the end, we start to pop the edges we've visited into answer, i.e. `0 -> 1 -> 1 -> 0`. And in the end push the start node `0` into the answer -- `'01100'`.

```cpp
// OJ: https://leetcode.com/problems/cracking-the-safe/
// Author: github.com/lzl124631x
// Time: O(N^(K^N))
// Space: O(N*(K^N))
// Ref: https://leetcode.com/problems/cracking-the-safe/solution/
class Solution {
private:
    unordered_set<string> s;
    string ans;
    void dfs(string node, int k) {
        for (char i = '0'; i < '0' + k; ++i) {
            auto pwd = node + i;
            if (!s.count(pwd)) {
                s.insert(pwd);
                dfs(pwd.substr(1), k);
                ans.push_back(i);
            }
        }
    }
public:
    string crackSafe(int n, int k) {
        if (n == 1 && k == 1) return "0";
        string str(n - 1, '0');
        dfs(str, k);
        return ans + str;
    }
};
```