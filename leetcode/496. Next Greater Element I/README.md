# [496. Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/)

<p>
You are given two arrays <b>(without duplicates)</b> <code>nums1</code> and <code>nums2</code> where <code>nums1</code>’s elements are subset of <code>nums2</code>. Find all the next greater numbers for <code>nums1</code>'s elements in the corresponding places of <code>nums2</code>. 
</p>

<p>
The Next Greater Number of a number <b>x</b> in <code>nums1</code> is the first greater number to its right in <code>nums2</code>. If it does not exist, output -1 for this number.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> <b>nums1</b> = [4,1,2], <b>nums2</b> = [1,3,4,2].
<b>Output:</b> [-1,3,-1]
<b>Explanation:</b>
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> <b>nums1</b> = [2,4], <b>nums2</b> = [1,2,3,4].
<b>Output:</b> [3,-1]
<b>Explanation:</b>
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
</pre>
<p></p>


<p><b>Note:</b><br>
</p><ol>
<li>All elements in <code>nums1</code> and <code>nums2</code> are unique.</li>
<li>The length of both <code>nums1</code> and <code>nums2</code> would not exceed 1000.</li>
</ol>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Next Greater Element II (Medium)](https://leetcode.com/problems/next-greater-element-ii/)
* [Next Greater Element III (Medium)](https://leetcode.com/problems/next-greater-element-iii/)
* [Daily Temperatures (Medium)](https://leetcode.com/problems/daily-temperatures/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/next-greater-element-i/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};
```