# [42. Trapping Rain Water (Hard)](https://leetcode.com/problems/trapping-rain-water/)

<p>Given <code>n</code> non-negative integers representing an elevation map where the width of each bar is <code>1</code>, compute how much water it can trap after raining.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;">
<pre><strong>Input:</strong> height = [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> height = [4,2,0,3,2,5]
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>0 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Yandex](https://leetcode.com/company/yandex), [Rubrik](https://leetcode.com/company/rubrik), [Snapchat](https://leetcode.com/company/snapchat), [Lyft](https://leetcode.com/company/lyft), [Grab](https://leetcode.com/company/grab), [C3 IoT](https://leetcode.com/company/c3-iot)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Stack](https://leetcode.com/tag/stack/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

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

Or compute `left` on the fly.

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

Or use a mono-increasing stack which potentially saves some space because it only push new elements into the stack if the element is greater than the element at the stack top.

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& A) {
        stack<int> right;
        int N = A.size(), ans = 0, left = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (right.empty() || A[i] > A[right.top()]) right.push(i);
        }
        for (int i = 0; i < N; ++i) {
            if (right.top() == i) right.pop();
            int h = min(left, right.size() ? A[right.top()] : 0);
            ans += max(h - A[i], 0);
            left = max(left, A[i]);
        }
        return ans;
    }
};
```

## Solution 2. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int trap(vector<int>& A) {
        int i = 0, j = A.size() - 1, ans = 0;
        while (i < j) {
            if (A[i] < A[j]) {
                int h = A[i];
                while (i < j && A[i] <= h) {
                    ans += h - A[i];
                    ++i;
                }
            } else {
                int h = A[j];
                while (i < j && A[j] <= h) {
                    ans += h - A[j];
                    --j;
                }
            }
        }
        return ans;
    }
};
```

Or

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