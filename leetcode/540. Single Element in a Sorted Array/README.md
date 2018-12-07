# [540. Single Element in a Sorted Array (Medium)](https://leetcode.com/problems/single-element-in-a-sorted-array/)

<p>
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once. 
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1,1,2,3,3,4,4,8,8]
<b>Output:</b> 2
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [3,3,7,7,10,11,11]
<b>Output:</b> 10
</pre>
<p></p>

<p><b>Note:</b>
Your solution should run in O(log n) time and O(1) space.
</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

## Solution 1. Binary Search

Use binary search. Initially set `L = 0, R = N - 1`.

Exit condition: If `L == R` then we only have one value, we can break right away. So the exit condition can be `L < R`. BTW, we guarantee there are at least 3 elements in range `[L, R]`.

Let `M = (L + R) / 2`. Now we need to determine which direction to go:

Firstly, take a look at the relationship between `nums[M]` and `nums[M - 1]`:

* If  `nums[M] == nums[M - 1]`, we need to further break it down into two cases:
  * If `[L, M]` have odd number elements, go left by `R = M`. (consider case `1 2 [2] 3 3`)
  * Otherwise, go right by `L = M + 1`. (consider case `1 [1] 2`)
* If `nums[M] != nums[M - 1]`, similarly, further two cases:
  * If `[M, R]` have odd number elements, go right by `L = M`. (consider case `1 1 [2] 2 3`)
  * Otherwise, go left by `R = M - 1`. (consider case `1 [2] 2`)

Eventually, it will stop at `L == R` and returning either `nums[L]` or `nums[R]` is fine.


```cpp
// OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
private:
public:
    int singleNonDuplicate(vector<int>& nums) {
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (nums[M] == nums[M - 1]) {
                if ((M - L + 1) % 2) R = M;
                else L = M + 1;
            } else {
                if ((R - M + 1) % 2) L = M;
                else R = M - 1;
            } 
        }
        return nums[L];
    }
};
```