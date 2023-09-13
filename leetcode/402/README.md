# [402. Remove K Digits (Medium)](https://leetcode.com/problems/remove-k-digits/)

<p>Given string num representing a non-negative integer <code>num</code>, and an integer <code>k</code>, return <em>the smallest possible integer after removing</em> <code>k</code> <em>digits from</em> <code>num</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = "1432219", k = 3
<strong>Output:</strong> "1219"
<strong>Explanation:</strong> Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "10200", k = 1
<strong>Output:</strong> "200"
<strong>Explanation:</strong> Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = "10", k = 2
<strong>Output:</strong> "0"
<strong>Explanation:</strong> Remove all the digits from the number and it is left with nothing which is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> consists of only digits.</li>
	<li><code>num</code> does not have any leading zeros except for the zero itself.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [MakeMyTrip](https://leetcode.com/company/makemytrip)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

**Similar Questions**:
* [Create Maximum Number (Hard)](https://leetcode.com/problems/create-maximum-number/)
* [Monotone Increasing Digits (Medium)](https://leetcode.com/problems/monotone-increasing-digits/)
* [Find the Most Competitive Subsequence (Medium)](https://leetcode.com/problems/find-the-most-competitive-subsequence/)

## Solution 1. Mono-stack

### Intuition

We want the answer as lexigraphically **smaller** as possible, so we should use a mono-**increasing** stack which will keep tightening towards lexigraphically smaller result.

### Algorithm 

Use a `string ans` as a mono-increasing stack.

For each character `s[i]`, we push it into `ans`. And before pushing, we need to pop `ans.back()` if 
1. we have delete allowance -- `i - ans.size() < k` where `i - ans.size()` is the number of deleted characters.
2. `ans.back() > s[i]`

**Only pop _strictly greater_ characters**. Consider example `s = "112", k = 1` and `s = "110", k = 1`. We need to keep both `1`s, and determine whether we want to pop the `1`s when we look at the character(s) after them.

**Don't put characters beyond `N - k` window**: Any characters that lands beyond window `N - k` should be deleted right away because they are no better than those within the window.

Lastly, removing leading zeros.

```cpp
// OJ: https://leetcode.com/problems/remove-k-digits/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string removeKdigits(string s, int k) {
        if (s.size() == k) return "0";
        string ans;
        for (int i = 0, N = s.size(); i < N; ++i) {
            while (i - ans.size() < k && ans.size() && ans.back() > s[i]) ans.pop_back(); // if we have delete allowance and `ans.back()` is greater than `s[i]`, we pop `ans.back()`
            if (ans.size() < N - k) ans.push_back(s[i]); // any character that was ever left beyond the valid window should be deleted.
        }
        auto i = ans.find_first_not_of('0'); // remove leading `0`s
        return i == string::npos ? "0" : ans.substr(i);
    }
};
```