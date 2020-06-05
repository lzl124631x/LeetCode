# [456. 132 Pattern (Medium)](https://leetcode.com/problems/132-pattern/)

<p>
Given a sequence of n integers a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>, a 132 pattern is a subsequence a<sub><b>i</b></sub>, a<sub><b>j</b></sub>, a<sub><b>k</b></sub> such
that <b>i</b> &lt; <b>j</b> &lt; <b>k</b> and a<sub><b>i</b></sub> &lt; a<sub><b>k</b></sub> &lt; a<sub><b>j</b></sub>. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.</p>

<p><b>Note:</b> n will be less than 15,000.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1, 2, 3, 4]

<b>Output:</b> False

<b>Explanation:</b> There is no 132 pattern in the sequence.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [3, 1, 4, 2]

<b>Output:</b> True

<b>Explanation:</b> There is a 132 pattern in the sequence: [1, 4, 2].
</pre>
<p></p>

<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> [-1, 3, 2, 0]

<b>Output:</b> True

<b>Explanation:</b> There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
</pre>
<p></p>

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

## Solution 1. Multiset

For a given middle element `A[i]`, we'd want to use the minimum element to the left of `A[i]` (denote as `a`), and then find the greatest elemnt to the right of `A[i]` which is smaller than `A[i]` (denote as `b`).

For `a` it's easy: we can just use a single variable to keep track of the minimum elemenent we've seen thus far. 

For `b`, we can use a multiset to hold all the values to the right of `A[i]` in descending order, and use binary search to find the greatest element that is smaller than `A[i]`.

```cpp
// OJ: https://leetcode.com/problems/132-pattern/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool find132pattern(vector<int>& A) {
        multiset<int, greater<int>> s(begin(A), end(A));
        int mn = INT_MAX;
        for (int n : A) {
            mn = min(mn, n);
            s.erase(s.find(n));
            auto it = s.upper_bound(n);
            if (it != s.end() && mn < *it) return true;
        }
        return false;
    }
};
```

## Solution 2. Monotonic Stack

Assume the sequence is `a, b, c` (`a < c < b`).

We scan from the right to the left. Keep a monotonically decreasing stack `s` and keep track of the best candidate of `c` in a variable`right`.

The best candidate of `c` must be monotonically increasing because the moment we find that the current element is `< c`, we've found a valid sequence.

As for the stack `s`, we pop all the elements that are smaller than `A[i]`, store the last popped element in `right`, and then push `A[i]` into the stack. Thus `s.top()` and `right` forms a best candidate `b, c` sequence.

Once we find `A[i] < right`, we can return `true`.

```cpp
// OJ: https://leetcode.com/problems/132-pattern/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C%2B%2B-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.
class Solution {
public:
    bool find132pattern(vector<int>& A) {
        stack<int> s;
        int right = INT_MIN;
        for (int i = A.size() - 1; i >= 0; --i) {
            if (A[i] < right) return true;
            while (s.size() && s.top() < A[i]) {
                right = s.top();
                s.pop();
            }
            s.push(A[i]);
        }
        return false;
    }
};
```