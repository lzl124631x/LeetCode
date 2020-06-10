# [84. Largest Rectangle in Histogram (Hard)](https://leetcode.com/problems/largest-rectangle-in-histogram/)

<p>Given <em>n</em> non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.</p>

<p>&nbsp;</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/histogram.png" style="width: 188px; height: 204px;"><br>
<small>Above is a histogram where width of each bar is 1, given height = <code>[2,1,5,6,2,3]</code>.</small></p>

<p>&nbsp;</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png" style="width: 188px; height: 204px;"><br>
<small>The largest rectangle is shown in the shaded area, which has area = <code>10</code> unit.</small></p>

<p>&nbsp;</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [2,1,5,6,2,3]
<strong>Output:</strong> 10
</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Maximal Rectangle (Hard)](https://leetcode.com/problems/maximal-rectangle/)

## Solution 1. Monotonic Stack

For a specific bar `A[i]`, to form the largest rectangle we can form using `A[i]`, we need to find the previous and next smaller element.

Assume their indexes are `left[i]` and `right[i]` respectively. So, `A[left[i]]` is the first element to left of `A[i]` that is smaller than `A[i]`, and `A[right[i]]` is the first element to the right of `A[i]` that is smaller than `A[i]`.

We can use similar solution as in [496. Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/), i.e. Monotoic Stack, to get these `left` and `right` arrays.

Then for each `A[i]`, the area of the max rectangle we can form using `A[i]` is `(right[i] - left[i] - 1) * A[i]`.

```cpp
// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.insert(A.begin(), 0);
        A.push_back(0);
        int N = A.size(), ans = 0;
        vector<int> left(N), right(N), s;
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[s.back()] > A[i]) {
                right[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        s.clear();
        for (int i = N - 1; i >= 0; --i) {
            while (s.size() && A[s.back()] > A[i]) {
                left[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        for (int i = 0; i < N; ++i) ans = max(ans, (right[i] - left[i] - 1) * A[i]); 
        return ans;
    }
};
```

If we just compute `left` array and get the `right` value on the fly:

```cpp
// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.insert(A.begin(), 0);
        A.push_back(0);
        int N = A.size(), ans = 0;
        vector<int> left(N), s;
        for (int i = N - 1; i >= 0; --i) {
            while (s.size() && A[s.back()] > A[i]) {
                left[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        s.clear();
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[s.back()] > A[i]) {
                ans = max(ans, (i - left[s.back()] - 1) * A[s.back()]);
                s.pop_back();
            }
            s.push_back(i);
        }
        return ans;
    }
};
```

## Solution 2. Monotonic Stack

In fact, the `left` array is also unnecessary because the next-to-the-top element in the stack is `left[s.top()]`.

```cpp
// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.push_back(0);
        int N = A.size(), ans = 0;
        stack<int> s;
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[s.top()] >= A[i]) {
                int h = A[s.top()];
                s.pop();
                int j = s.size() ? s.top() : -1;
                ans = max(ans, h * (i - j - 1));
            }
            s.push(i);
        }
        return ans;
    }
};
```

## Solution 3.

Instead of using `stack`, we can reuse the previously computed `left` and `right` values to get the `left` and `right` values for the current `A[i]`.

```cpp
// OJ: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28902/5ms-O(n)-Java-solution-explained-(beats-96)
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), ans = 0;
        vector<int> left(N), right(N);
        left[0] = -1;
        right[N - 1] = N;
        for (int i = 1; i < N; ++i) {
            int j = i - 1;
            while (j >= 0 && A[j] >= A[i]) j = left[j];
            left[i] = j;
        }
        for (int i = N - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < N && A[j] >= A[i]) j = right[j];
            right[i] = j;
        }
        for (int i = 0; i < N; ++i) ans = max(ans, (right[i] - left[i] - 1) * A[i]);
        return ans;
    }
};
```