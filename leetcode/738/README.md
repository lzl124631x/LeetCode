# [738. Monotone Increasing Digits (Medium)](https://leetcode.com/problems/monotone-increasing-digits/)

<p>Given a non-negative integer <code>n</code>, find the largest number that is less than or equal to <code>n</code> with monotone increasing digits.</p>

<p>(Recall that an integer has <i>monotone increasing digits</i> if and only if each pair of adjacent digits <code>x</code> and <code>y</code> satisfy <code>x &lt;= y</code>.)</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> n = 10
<b>Output:</b> 9
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> n = 1234
<b>Output:</b> 1234
</pre>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> n = 332
<b>Output:</b> 299
</pre>

<p><b>Note:</b> <code>n</code> is an integer in the range <code>[0, 10^9]</code>.</p>


**Companies**:  
[SAP](https://leetcode.com/company/sap)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Remove K Digits (Medium)](https://leetcode.com/problems/remove-k-digits/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/monotone-increasing-digits/
// Author: github.com/lzl124631x
// Time: O(log_10^N)
// Space: O(log_10^N)
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> v;
        while (n) {
            v.push_back(n % 10);
            n /= 10;
        }
        int i = v.size() - 2, ans = 0;
        for (; i >= 0 && v[i] >= v[i + 1]; --i);
        if (i >= 0) {
            while (i + 2 < v.size() && v[i + 1] == v[i + 2]) ++i;
            v[i + 1]--;
            while (i >= 0) v[i--] = 9;
        }
        while (v.size()) {
            ans = ans * 10 + v.back();
            v.pop_back();
        }
        return ans; 
    }
};
```