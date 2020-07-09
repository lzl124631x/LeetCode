# [15. 3Sum (Medium)](https://leetcode.com/problems/3sum/)

<p>Given an array <code>nums</code> of <em>n</em> integers, are there elements <em>a</em>, <em>b</em>, <em>c</em> in <code>nums</code> such that <em>a</em> + <em>b</em> + <em>c</em> = 0? Find all unique triplets in the array which gives the sum of zero.</p>

<p><strong>Note:</strong></p>

<p>The solution set must not contain duplicate triplets.</p>

<p><strong>Example:</strong></p>

<pre>Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [3Sum Closest (Medium)](https://leetcode.com/problems/3sum-closest/)
* [4Sum (Medium)](https://leetcode.com/problems/4sum/)
* [3Sum Smaller (Medium)](https://leetcode.com/problems/3sum-smaller/)

## Solution 1.

Sort the array in ascending order.

Pin the first number as `A[i]`. For the other two numbers, we can use two pointers to scan `A[(i+1)..(N-1)]`, one from `i+1` rightward, one from `N-1` leftward.

```cpp
// OJ: https://leetcode.com/problems/3sum/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        int N = A.size();
        for (int i = 0; i < N - 2; ++i) {
            if (i && A[i] == A[i - 1]) continue;
            int L = i + 1, R = N - 1;
            while (L < R) {
                int sum = A[i] + A[L] + A[R];
                if (sum == 0) ans.push_back({ A[i], A[L], A[R] });
                if (sum >= 0) {
                    --R;
                    while (L < R && A[R] == A[R + 1]) --R;
                }
                if (sum <= 0) {
                    ++L;
                    while (L < R && A[L] == A[L - 1]) ++L;
                }
            }
        }
        return ans;
    }
};
```