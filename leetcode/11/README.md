# [11. Container With Most Water (Medium)](https://leetcode.com/problems/container-with-most-water/)

<p>Given <i>n</i> non-negative integers <i>a<sub>1</sub></i>, <i>a<sub>2</sub></i>, ..., <i>a<sub>n&nbsp;</sub></i>, where each represents a point at coordinate (<i>i</i>, <i>a<sub>i</sub></i>). <i>n</i> vertical lines are drawn such that the two endpoints of line <i>i</i> is at (<i>i</i>, <i>a<sub>i</sub></i>) and (<i>i</i>, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.</p>

<p><strong>Note:&nbsp;</strong>You may not slant the container and <i>n</i> is at least 2.</p>

<p>&nbsp;</p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg" style="width: 600px; height: 287px;"></p>

<p><small>The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain&nbsp;is 49. </small></p>

<p>&nbsp;</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [1,8,6,2,5,4,8,3,7]
<strong>Output:</strong> 49</pre>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Trapping Rain Water (Hard)](https://leetcode.com/problems/trapping-rain-water/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/container-with-most-water/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int maxArea(vector<int>& A) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            if (!A[i]) continue;
            for (int j = i + 1 + ans / A[i]; j < N; ++j) {
                ans = max(ans, min(A[i], A[j]) * (j - i));
            }
        }
        return ans;
    }
};
```

## Solution 2. Two Pointers

Keep two pointers `L = 0, R = N - 1` and move them inwards. They form two edges of the container and the volumn is `(R - L) * min(A[L], A[R])`.

We start from the container with the maximum width. Now we need to decrease the width and try to increase the height if possible (compromising on width and looking forward to greater height).

The strategy of moving the pointers is that we always move the smaller edge inwards.

Reason: Assume `A[L] > A[R]`, then all the pairs of `A[R]` with `A[i]` (`L < i < R`) can be discarded because the width between `A[i]` and `A[R]` is less AND the height of the container won't be taller than `A[R]`.

Thus, to discardi all the pairs of `A[R]` with `A[i]` (`L < i < R`), we can simply `--R`.

If the height of the two edges are the same, moving either one is fine because the change won't increase the volumn either way. BUT, we shouldn't break here because the volumn might increase later. Example case `[1, 100, 200, 1]`.

```cpp
// OJ: https://leetcode.com/problems/container-with-most-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
class Solution {
public:
    int maxArea(vector<int>& A) {
        int ans = 0, L = 0, R = A.size() - 1;
        while (L < R) {
            ans = max(ans, (R - L) * min(A[L], A[R]));
            if (A[L] < A[R]) ++L; // Move the smaller edge
            else --R;
        }
        return ans;
    }
};
```