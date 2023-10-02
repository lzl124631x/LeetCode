# [179. Largest Number (Medium)](https://leetcode.com/problems/largest-number/)

<p>Given a list of non negative integers, arrange them such that they form the largest number.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <code>[10,2]</code>
<strong>Output:</strong> "<code>210"</code></pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <code>[3,30,34,5,9]</code>
<strong>Output:</strong> "<code>9534330"</code>
</pre>

<p><strong>Note:</strong> The result may be very large, so you need to return a string instead of an integer.</p>


**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-number/
// Author: github.com/lzl124631x
// Time: O(NlogN * W) where W is the max length of the number strings.
// Space: O(NW)
class Solution {
public:
    string largestNumber(vector<int>& A) {
        vector<string> v;
        for (int n : A) v.push_back(to_string(n));
        sort(begin(v), end(v), [](auto &a, auto &b) {
            for (int i = 0; i < a.size() + b.size(); ++i) {
                char x = i < a.size() ? a[i] : b[i - a.size()], y = i < b.size() ? b[i] : a[i - b.size()];
                if (x != y) return x > y;
            } 
            return false; // don't return true which will result in infinite loop
        });
        if (v[0] == "0") return "0";
        string ans;
        for (auto &s : v) ans += s;
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/largest-number/
// Author: github.com/lzl124631x
// Time: O(NlogN * W) where W is the max length of the number strings.
// Space: O(NW)
class Solution {
public:
    string largestNumber(vector<int>& A) {
        vector<string> v;
        for (int n : A) v.push_back(to_string(n));
        sort(begin(v), end(v), [](auto &a, auto &b) { return a + b > b + a; });
        if (v[0] == "0") return "0";
        string ans;
        for (auto &s : v) ans += s;
        return ans;
    }
};
```