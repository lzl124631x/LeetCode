# [267. Palindrome Permutation II (Medium)](https://leetcode.com/problems/palindrome-permutation-ii)

<p>Given a string s, return <em>all the palindromic permutations (without duplicates) of it</em>.</p>
<p>You may return the answer in <strong>any order</strong>. If <code>s</code> has no palindromic permutation, return an empty list.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aabb"
<strong>Output:</strong> ["abba","baab"]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abc"
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 16</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>

**Companies**:
[Cruise Automation](https://leetcode.com/company/cruise-automation), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)
* [Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)
* [Palindrome Permutation (Easy)](https://leetcode.com/problems/palindrome-permutation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/palindrome-permutation-ii
// Author: github.com/lzl124631x
// Time: O(8! * 26)
// Space: O(16)
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int cnt[26] = {}, odd = -1, len = 0;
        for (char c : s) cnt[c - 'a']++;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2) {
                if (odd != -1) return {};
                odd = i;
            }
            len += cnt[i] / 2;
        }
        vector<string> ans;
        string tmp;
        function<void()> dfs = [&]() {
            if (tmp.size() == len) {
                string r(rbegin(tmp), rend(tmp));
                ans.push_back(tmp + (odd != -1 ? string(1, 'a' + odd) : "") + r);
                return;
            }
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] == 0 || cnt[i] == 1) continue;
                cnt[i] -= 2;
                tmp.push_back('a' + i);
                dfs();
                tmp.pop_back();
                cnt[i] += 2;
            }
        };
        dfs();
        return ans;
    }
};
```