# [484. Find Permutation (Medium)](https://leetcode.com/problems/find-permutation)

<p>A permutation <code>perm</code> of <code>n</code>&nbsp;integers of all the integers in the range <code>[1, n]</code> can be represented as a string <code>s</code> of length <code>n - 1</code> where:</p>
<ul>
	<li><code>s[i] == 'I'</code> if <code>perm[i] &lt; perm[i + 1]</code>, and</li>
	<li><code>s[i] == 'D'</code> if <code>perm[i] &gt; perm[i + 1]</code>.</li>
</ul>
<p>Given a string <code>s</code>, reconstruct the lexicographically smallest permutation <code>perm</code> and return it.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "I"
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> [1,2] is the only legal permutation that can represented by s, where the number 1 and 2 construct an increasing relationship.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "DI"
<strong>Output:</strong> [2,1,3]
<strong>Explanation:</strong> Both [2,1,3] and [3,1,2] can be represented as "DI", but since we want to find the smallest lexicographical permutation, you should return [2,1,3]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'I'</code> or <code>'D'</code>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Using a Robot to Print the Lexicographically Smallest String (Medium)](https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-permutation
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans{1};
        for (char c : s) {
            if (c == 'D') {
                ans.push_back(ans.back());
                for (int i = ans.size() - 2; i >= 0 && ans[i] == ans[i + 1]; --i) ans[i]++;
            } else {
                ans.push_back(ans.size() + 1);
            }
        }
        return ans;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/find-permutation
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findPermutation(string s) {
        int N = s.size(), mx = 0, d = s[0] == 'D';
        vector<int> cnt;
        for (int i = 0; i < N;) {
            int start = i++;
            while (i < N && s[i] == s[i - 1]) ++i;
            cnt.push_back(i - start);
        }
        vector<int> ans;
        for (int i = 0; i < cnt.size(); ++i) {
            int c = cnt[i];
            if (ans.empty()) ++c;
            if (d) {
                int n = ans.empty() ? c : mx - 1;
                mx = max(n, mx);
                for (int j = 0; j < c; ++j) ans.push_back(n--);
            } else {
                int n = mx + 1;
                for (int j = 0; j < c; ++j) ans.push_back(n++);
                if (i < cnt.size() - 1) ans.back() += cnt[i + 1];
                mx = ans.back();
            }
            d = 1 - d;
        }
        return ans;
    }
};
```