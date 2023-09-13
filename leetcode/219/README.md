# [219. Contains Duplicate II (Easy)](https://leetcode.com/problems/contains-duplicate-ii/)

<p>Given an array of integers and an integer <i>k</i>, find out whether there are two distinct indices <i>i</i> and <i>j</i> in the array such that <b>nums[i] = nums[j]</b> and the <b>absolute</b> difference between <i>i</i> and <i>j</i> is at most <i>k</i>.</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-1-1">[1,2,3,1]</span>, k = <span id="example-input-1-2">3</span>
<strong>Output: </strong><span id="example-output-1">true</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-2-1">[1,0,1,1]</span>, k = <span id="example-input-2-2">1</span>
<strong>Output: </strong><span id="example-output-2">true</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-3-1">[1,2,3,1,2,3]</span>, k = <span id="example-input-3-2">2</span>
<strong>Output: </strong><span id="example-output-3">false</span>
</pre>
</div>
</div>
</div>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Contains Duplicate (Easy)](https://leetcode.com/problems/contains-duplicate/)
* [Contains Duplicate III (Medium)](https://leetcode.com/problems/contains-duplicate-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/contains-duplicate-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& A, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
            if (m.count(A[i]) && i - m[A[i]] <= k) return true;
            m[A[i]] = i;
        }
        return false;
    }
};
```