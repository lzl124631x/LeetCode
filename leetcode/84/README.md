# [84. Largest Rectangle in Histogram (Hard)](https://leetcode.com/problems/largest-rectangle-in-histogram/)

<p>Given an array of integers <code>heights</code> representing the histogram's bar height where the width of each bar is <code>1</code>, return <em>the area of the largest rectangle in the histogram</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg" style="width: 522px; height: 242px;">
<pre><strong>Input:</strong> heights = [2,1,5,6,2,3]
<strong>Output:</strong> 10
<strong>Explanation:</strong> The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg" style="width: 202px; height: 362px;">
<pre><strong>Input:</strong> heights = [2,4]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= heights[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [Snapchat](https://leetcode.com/company/snapchat), [HBO](https://leetcode.com/company/hbo), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Stack](https://leetcode.com/tag/stack/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

**Similar Questions**:
* [Maximal Rectangle (Hard)](https://leetcode.com/problems/maximal-rectangle/)
* [Maximum Score of a Good Subarray (Hard)](https://leetcode.com/problems/maximum-score-of-a-good-subarray/)

## Solution 1. Monotonic Stack (Left and Right)

For a specific bar `A[i]`, to form the largest rectangle we can form using `A[i]`, we need to find the previous and next smaller element.

Assume their indexes are `prevSmaller[i]` and `nextSmaller[i]` respectively. So, `A[prevSmaller[i]]` is the index of the closest element to left of `A[i]` that is smaller than `A[i]`, and `A[nextSmaller[i]]` is the index of the closest element to the right of `A[i]` that is smaller than `A[i]`.

We can use similar solution as in [496. Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/), i.e. Monotoic Stack, to get these `prevSmaller` and `nextSmaller` arrays.

Then for each `A[i]`, the area of the max rectangle we can form using `A[i]` is `(nextSmaller[i] - prevSmaller[i] - 1) * A[i]`.

In this implementation, we can precompute `nextSmaller` array and compute `prevSmaller` values on the fly.

```cpp
// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> nextSmaller(N);
        stack<int> s; // strictly-increasing mono-stack
        for (int i = N - 1; i >= 0; --i) {
            while (s.size() && A[i] <= A[s.top()]) s.pop();
            nextSmaller[i] = s.size() ? s.top() : N; // log nextSmaller for the current `i` on push
            s.push(i);
        }
        s = {};
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[i] <= A[s.top()]) s.pop();
            int prevSmaller = s.size() ? s.top() : -1;
            ans = max(ans, (nextSmaller[i] - prevSmaller - 1) * A[i]);
            s.push(i);
        }
        return ans;
    }
};
```

Another variant:

```cpp
// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> prev(N, -1), next(N, N);
        stack<int> s; // non-decreasing mono-stack
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[i] < A[s.top()]) {
                next[s.top()] = i; // log `next` of elements in stack on pop
                s.pop();
            }
            s.push(i);
        }
        s = {};
        for (int i = N - 1; i >= 0; --i) {
            while (s.size() && A[i] < A[s.top()]) {
                prev[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < N; ++i) {
            ans = max(ans, A[i] * (next[i] - prev[i] - 1));
        }
        return ans;
    }
};
```

## Solution 2. Monotonic Stack (One Pass)

If we use the current `A[i]` as the right edge, when `A[i] <= A[s.top()]`:
* We use `A[s.top()]` as the height of the rectangle
* `s.pop()`
* The left edge `left = s.size() ? s.top() : - 1`.
* The area of this rectangle is `(i - left - 1) * height`

```cpp
// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.push_back(0); // append a zero at the end so that we can pop all elements from the stack and calculate the corresponding areas
        int N = A.size(), ans = 0;
        stack<int> s; // strictly-increasing mono-stack
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[i] <= A[s.top()]) { // Take `A[i]` as the right edge
                int height = A[s.top()]; // Take the popped element as the height
                s.pop();
                int left = s.size() ? s.top() : -1; // Take the element left on the stack as the left edge
                ans = max(ans, (i - left - 1) * height);
            }
            s.push(i);
        }
        return ans;
    }
};
```

## Solution 3. DP

We can use DP to compute the `prevSmaller` and `nextSmaller` arrays.

This is an `O(N)` solution because each computed `prevSmaller`/`nextSmaller` value is used at most once when computing a new `prevSmaller`/`nextSmaller` value.

```cpp
// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28902/5ms-O(n)-Java-solution-explained-(beats-96)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> prevSmaller(N, -1), nextSmaller(N, N);
        for (int i = N - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < N && A[j] >= A[i]) j = nextSmaller[j];
            nextSmaller[i] = j;
        }
        for (int i = 1; i < N; ++i) {
            int j = i - 1;
            while (j >= 0 && A[j] >= A[i]) j = prevSmaller[j];
            prevSmaller[i] = j;
        }
        for (int i = 0; i < N; ++i) ans = max(ans, (nextSmaller[i] - prevSmaller[i] - 1) * A[i]);
        return ans;
    }
};
```