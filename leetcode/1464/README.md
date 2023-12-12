# [1464. Maximum Product of Two Elements in an Array (Easy)](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array)

Given the array of integers <code>nums</code>, you will choose two different indices <code>i</code> and <code>j</code> of that array. <em>Return the maximum value of</em> <code>(nums[i]-1)*(nums[j]-1)</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,5,2]
<strong>Output:</strong> 12 
<strong>Explanation:</strong> If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,4,5]
<strong>Output:</strong> 16
<strong>Explanation:</strong> Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,7]
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^3</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Cisco](https://leetcode.com/company/cisco), [Samsung](https://leetcode.com/company/samsung)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Sorting](https://leetcode.com/tag/sorting), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue)

**Hints**:
* Use brute force: two loops to select i and j, then select the maximum value of (nums[i]-1)*(nums[j]-1).

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) ans = max(ans, (nums[i] - 1) * (nums[j] - 1)) ;
        }
        return ans;
    }
};
```

## Solution 2. Heap

We just need find the greatest two elements.

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        make_heap(begin(nums), end(nums));
        pop_heap(begin(nums), end(nums));
        pop_heap(begin(nums), end(nums) - 1);
        return (nums.back() - 1) * (*(nums.end() - 2) - 1);
    }
};
```

## Solution 3. Two pass

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto it = max_element(begin(nums), end(nums));
        swap(*it, nums[0]);
        it = max_element(begin(nums) + 1, end(nums));
        return (nums[0] - 1) * (*it - 1);
    }
};
```

## Solution 4. One pass

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (int n : nums) {
            if (n >= a) {
                b = a;
                a = n;
            } else if (n > b) b = n;
        }
        return (a - 1) * (b - 1);
    }
};
```