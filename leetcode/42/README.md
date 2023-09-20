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
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Adobe](https://leetcode.com/company/adobe), [Intel](https://leetcode.com/company/intel), [Rubrik](https://leetcode.com/company/rubrik), [Uber](https://leetcode.com/company/uber), [Citadel](https://leetcode.com/company/citadel), [Snapchat](https://leetcode.com/company/snapchat), [VMware](https://leetcode.com/company/vmware), [Qualtrics](https://leetcode.com/company/qualtrics), [Paypal](https://leetcode.com/company/paypal), [Tesla](https://leetcode.com/company/tesla), [Zoho](https://leetcode.com/company/zoho), [Intuit](https://leetcode.com/company/intuit), [Oracle](https://leetcode.com/company/oracle)

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
        int N = A.size(), ans = 0, left = 0;
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

## Solution 2. Monotonic stack

This solution is similar to the Monotonic Stack solution to [84. Largest Rectangle in Histogram (Hard)](https://leetcode.com/problems/largest-rectangle-in-histogram/).

The intuition is that once we see a taller `A[i]`, all `A[j] <= A[i]` (`j < i`) are no longer relevant because we will at most use `A[i]` as the left edge.

So, we maintain a monotonic stack `s` storing the relevant indices.

For each `A[i]`, we pop indices `<= A[i]` from `s`. For each popped index `mid`, the index triple `s.top(), mid, i` forms a rectangle of water. The width is `i - s.top() - 1`, the height is `min(A[s.top()], A[i]) - A[mid]`.

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& A) {
        int N = A.size(), ans = 0;
        stack<int> s;
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[i] >= A[s.top()]) {
                int mid = s.top();
                s.pop();
                if (s.size()) ans += (i - s.top() - 1) * (min(A[i], A[s.top()]) - A[mid]);
            }
            s.push(i);
        }
        return ans;
    }
};
```

## Solution 3. Two Pointers

Can we save the `O(N)` space in solution 1? The space is taken by the `right` array storing the maximum heights. We can try using a single pointer instead.

Let's traverse `i` from `0` rightwards. For each `A[i]`, instead of using `right[i]` -- the tallest height to the right of `A[i]`, we use a pointer `j = N-1`. As long as `A[j] >= A[i]`, the height of the water filled at index `i` is determined only by `left` -- `left - A[i]`.

So, we keep incrementing `i` and fill `left - A[i]` at index `i`, until `A[i] > A[j]`.

Now, the setup is reversed. Due to symmetry, now we should keep decrementing `j` and fill `right - A[j]` at index `j`, until `A[j] >= A[i]`.

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int trap(vector<int>& A) {
        int i = 0, j = A.size() - 1, left = 0, right = 0, ans = 0;
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