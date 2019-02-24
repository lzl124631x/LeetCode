# [360. Sort Transformed Array (Medium)](https://leetcode.com/problems/sort-transformed-array/)

<p>Given a <b>sorted</b> array of integers <i>nums</i> and integer values <i>a</i>, <i>b</i> and <i>c</i>. Apply a quadratic function of the form f(<i>x</i>) = <i>ax</i><sup>2</sup> + <i>bx</i> + <i>c</i> to each element <i>x</i> in the array.</p>

<p>The returned array must be in <b>sorted order</b>.</p>

<p>Expected time complexity: <b>O(<i>n</i>)</b></p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-1-1">[-4,-2,2,4]</span>, a = <span id="example-input-1-2">1</span>, b = <span id="example-input-1-3">3</span>, c = <span id="example-input-1-4">5</span>
<strong>Output: </strong><span id="example-output-1">[3,9,15,33]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-2-1">[-4,-2,2,4]</span>, a = <span id="example-input-2-2">-1</span>, b = <span id="example-input-2-3">3</span>, c = <span id="example-input-2-4">5</span>
<strong>Output: </strong><span id="example-output-2">[-23,-5,1,7]</span>
</pre>
</div>
</div>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Squares of a Sorted Array (Easy)](https://leetcode.com/problems/squares-of-a-sorted-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sort-transformed-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int eval(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        float mid = (float)-b / (2 * a);
        int j = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
        int i = j - 1, N = nums.size(), nil = a > 0 ? INT_MAX : INT_MIN;
        vector<int> ans(N);
        for (int k = 0; k < N; ++k) {
            int m = i >= 0 ? eval(nums[i], a, b, c) : nil;
            int n = j < N ? eval(nums[j], a, b, c) : nil;
            if (a > 0 ? m < n : n < m) {
                ans[k] = m;
                --i;
            } else {
                ans[k] = n;
                ++j;
            }
        }
        if (a < 0) reverse(ans.begin(), ans.end());
        return ans;
    }
};
```