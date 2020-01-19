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