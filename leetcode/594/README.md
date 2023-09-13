# [594. Longest Harmonious Subsequence (Easy)](https://leetcode.com/problems/longest-harmonious-subsequence/)

<p>We define a harmonious array is an array where the difference between its maximum value and its minimum value is <b>exactly</b> 1.</p>

<p>Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible <a href="https://en.wikipedia.org/wiki/Subsequence">subsequences</a>.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1,3,2,2,5,2,3,7]
<b>Output:</b> 5
<b>Explanation:</b> The longest harmonious subsequence is [3,2,2,2,3].
</pre>
<p></p>

<p><b>Note:</b>
The length of the input array will not exceed 20,000.
</p>



**Companies**:  
[LiveRamp](https://leetcode.com/company/liveramp)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-harmonious-subsequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnts;
        int ans = 0;
        for (int n : nums) cnts[n]++;
        for (auto &p : cnts) {
            if (cnts.find(p.first + 1) == cnts.end()) continue;
            ans = max(ans, p.second + cnts[p.first + 1]);
        }
        return ans;
    }
};
```