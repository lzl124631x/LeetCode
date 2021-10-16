# [402. Remove K Digits (Medium)](https://leetcode.com/problems/remove-k-digits/)

<p>Given a non-negative integer <i>num</i> represented as a string, remove <i>k</i> digits from the number so that the new number is the smallest possible.
</p>

<p><b>Note:</b><br>
</p><ul>
<li>The length of <i>num</i> is less than 10002 and will be ≥ <i>k</i>.</li>
<li>The given <i>num</i> does not contain any leading zero.</li>
</ul>

<p></p>

<p><b>Example 1:</b>
</p><pre>Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
</pre>
<p></p>

<p><b>Example 2:</b>
</p><pre>Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
</pre>
<p></p>

<p><b>Example 3:</b>
</p><pre>Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
</pre>
<p></p>

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Create Maximum Number (Hard)](https://leetcode.com/problems/create-maximum-number/)
* [Monotone Increasing Digits (Medium)](https://leetcode.com/problems/monotone-increasing-digits/)
* [Find the Most Competitive Subsequence (Medium)](https://leetcode.com/problems/find-the-most-competitive-subsequence/)

## Solution 1. Mono-stack

### Intuition

We want the answer as lexigraphically **smaller** as possible, so we should use a mono-**increasing** stack which will keep tightening towards lexigraphically smaller result.

### Algorithm 

Use a `string ans` as a mono-increasing stack.

For each character `s[i]`, we push it into `ans`. And before pushing, we need to pop greater characters in `ans` first.

For each character we popped, we need to decrement `k`. And we only keep popping if `k > 0`.

After traversing all characters in `s`, if `k` is still not exhausted, we pop back from `ans` until `k == 0`.

Lastly, removing leading zeros.

```cpp
// OJ: https://leetcode.com/problems/remove-k-digits/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string removeKdigits(string s, int k) {
        if (k == s.size()) return "0";
        string ans;
        for (int i = 0, N = s.size(); i < N; ++i) {
            while (k > 0 && ans.size() && s[i] < ans.back()) {
                ans.pop_back();
                --k;
            }
            ans.push_back(s[i]);
        }
        while (k > 0) {
            ans.pop_back();
            --k;
        }
        auto begin = ans.find_first_not_of('0');
        return begin == string::npos ? "0" : ans.substr(begin);
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/remove-k-digits/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string removeKdigits(string s, int k) {
        string ans;
        for (int i = 0, N = s.size(); i < N; ++i) {
            while (ans.size() && i - ans.size() < k && s[i] < ans.back()) ans.pop_back(); // We've visited `i` elements (`s[0..i-1]`) and kept `ans.size()` elements, so we've removed `i - ans.size()` elements. If `i - ans.size() < k`, we can continue popping; otherwise, we should stop popping because that will result in excessive popping.
            if (ans.size() < N - k) ans.push_back(s[i]); // We can only keep exactly `N - k` elements in `ans`, so we only push if `ans.size < N - k`.
        }
        auto begin = ans.find_first_not_of('0');
        return begin == string::npos ? "0" : ans.substr(begin);
    }
};
```