# [42. Trapping Rain Water (Hard)](https://leetcode.com/problems/trapping-rain-water/)

<p>Given <em>n</em> non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;"><br>
<small>The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. <strong>Thanks Marcos</strong> for contributing this image!</small></p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>Output:</strong> 6</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Container With Most Water (Medium)](https://leetcode.com/problems/container-with-most-water/)
* [Product of Array Except Self (Medium)](https://leetcode.com/problems/product-of-array-except-self/)
* [Trapping Rain Water II (Hard)](https://leetcode.com/problems/trapping-rain-water-ii/)
* [Pour Water (Medium)](https://leetcode.com/problems/pour-water/)

## Solution 1.

The water that can be held at position `i` is `max(0, min(left[i], right[i]) - A[i])` where `left[i]` is the maximum height to the left of `i` and `right[i]` is the maximum height to the right of `i`.

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> left(N, 0), right(N, 0);
        for (int i = 1; i < N; ++i) left[i] = max(left[i - 1], A[i - 1]);
        for (int i = N - 2; i >= 0; --i) right[i] = max(right[i + 1], A[i + 1]);
        for (int i = 1; i < N - 1; ++i) ans += max(0, min(left[i], right[i]) - A[i]);
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& A) {
        int N = A.size(), ans = 0, mx = 0, left = 0;
        vector<int> right(N);
        for (int i = N - 2; i >= 0; --i) right[i] = max(right[i + 1], A[i + 1]);
        for (int i = 0; i < N; ++i) {
            ans += max(0, min(left, right[i]) - A[i]);
            left = max(left, A[i]);
        }
        return ans;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& A) {
        stack<int> s;
        int N = A.size(), ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (s.empty() || A[i] > A[s.top()]) s.push(i);
        }
        for (int i = 0; i < N - 1;) {
            int h = A[i];
            if (i == s.top()) {
                s.pop();
                h = A[s.top()];
            }
            int j = i + 1;
            while (j < N && A[j] < h) ans += h - A[j++];
            i = j;
        }
        return ans;
    }
};
```

## Solution 3. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int trap(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), ans = 0, i = 0, j = N - 1, left = 0, right = 0;
        while (i < j) {
            if (A[i] < A[j]) {
                left = max(left, A[i]);
                ans += left - A[i++];
            } else {
                right = max(right, A[j]);
                ans += right - A[j--];
            }
        }
        return ans;
    }
};
```