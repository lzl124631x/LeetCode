# [697. Degree of an Array (Easy)](https://leetcode.com/problems/degree-of-an-array/)

<p>Given a non-empty array of non-negative integers <code>nums</code>, the <b>degree</b> of this array is defined as the maximum frequency of any one of its elements.</p>
<p>Your task is to find the smallest possible length of a (contiguous) subarray of <code>nums</code>, that has the same degree as <code>nums</code>.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1, 2, 2, 3, 1]
<b>Output:</b> 2
<b>Explanation:</b> 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
</pre>
<p></p>


<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [1,2,2,3,1,4,2]
<b>Output:</b> 6
</pre>
<p></p>

<p><b>Note:</b>
</p><li><code>nums.length</code> will be between 1 and 50,000.</li>
<li><code>nums[i]</code> will be an integer between 0 and 49,999.</li>
<p></p>

**Companies**:  
[Mathworks](https://leetcode.com/company/mathworks), [VMware](https://leetcode.com/company/vmware), [Visa](https://leetcode.com/company/visa)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Maximum Subarray (Easy)](https://leetcode.com/problems/maximum-subarray/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/degree-of-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt, left, right;
        int deg = 0, ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            cnt[n]++;
            if (cnt[n] > deg) deg = cnt[n];
            if (cnt[n] == 1) left[n] = i;
            right[n] = i;
        }
        for (auto p : cnt) {
            if (p.second != deg) continue;
            ans = min(ans, right[p.first] - left[p.first] + 1);
        }
        return ans;
    }
};
```