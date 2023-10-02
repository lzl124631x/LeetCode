# [321. Create Maximum Number (Hard)](https://leetcode.com/problems/create-maximum-number/)

<p>Given two arrays of length <code>m</code> and <code>n</code> with digits <code>0-9</code> representing two numbers. Create the maximum number of length <code>k &lt;= m + n</code> from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the <code>k</code> digits.</p>

<p><strong>Note: </strong>You should try to optimize your time and space complexity.</p>

<p><b>Example 1:</b></p>

<pre><strong>Input:</strong>
nums1 = <code>[3, 4, 6, 5]</code>
nums2 = <code>[9, 1, 2, 5, 8, 3]</code>
k = <code>5</code>
<strong>Output:</strong>
<code>[9, 8, 6, 5, 3]</code></pre>

<p><b>Example 2:</b></p>

<pre><strong>Input:</strong>
nums1 = <code>[6, 7]</code>
nums2 = <code>[6, 0, 4]</code>
k = <code>5</code>
<strong>Output:</strong>
<code>[6, 7, 6, 0, 4]</code></pre>

<p><b>Example 3:</b></p>

<pre><strong>Input:</strong>
nums1 = <code>[3, 9]</code>
nums2 = <code>[8, 9]</code>
k = <code>3</code>
<strong>Output:</strong>
<code>[9, 8, 9]</code>
</pre>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Remove K Digits (Medium)](https://leetcode.com/problems/remove-k-digits/)
* [Maximum Swap (Medium)](https://leetcode.com/problems/maximum-swap/)

## Solution 1. Greedy

Assume we take `i` numbers from `A` and `k - i` numbers from `B`, `max(0, k - N) <= i <= min(k, M)`.

We can greedily get the subsequence of size `i` from `A` using a decreasing monoqueue of size `i`.

For each `i`, we get `a = maxSubarray(A, i), b = maxSubarray(B, k - i)` then greedily merge these two arrays.

The `merge` function is similar to merge-sorting two sorted list.

For time complexity, the for loop in `maxNumber` will run at most `M` times. The `merge` function at most takes `O((M+N)^2)` times due to the `for` loop and `greater` function. So overall the time complexity is `O(M * (M + N)^2)`.

```cpp
// OJ: https://leetcode.com/problems/create-maximum-number/
// Author: github.com/lzl124631x
// Time: O(M * (M + N)^2)
// Space: O(M + N)
// Ref: https://discuss.leetcode.com/topic/32272/share-my-greedy-solution
class Solution {
    vector<int> maxSubarray(vector<int> &A, int k) {
        int N = A.size();
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            while (ans.size() && ans.back() < A[i] && k - ans.size() < N - i) ans.pop_back();
            if (ans.size() < k) ans.push_back(A[i]);
        }
        return ans;
    }
    bool greater(vector<int> &A, int i, vector<int> &B, int j) {
        for (; i < A.size() && j < B.size() && A[i] == B[j]; ++i, ++j);
        return j == B.size() || (i < A.size() && A[i] > B[j]);
    }
    vector<int> merge(vector<int> &A, vector<int> &B, int k) {
        vector<int> ans;
        for (int i = 0, j = 0, r = 0; r < k; ++r) {
            ans.push_back(greater(A, i, B, j) ? A[i++] : B[j++]);
        }
        return ans;
    }
public:
    vector<int> maxNumber(vector<int>& A, vector<int>& B, int k) {
        int M = A.size(), N = B.size();
        vector<int> ans;
        for (int i = max(0, k - N); i <= k && i <= M; ++i) {
            auto a = maxSubarray(A, i), b = maxSubarray(B, k - i), v = merge(a, b, k);
            if (greater(v, 0, ans, 0)) ans = v;
        }
        return ans;
    }
};
```

Minor simplification using `vector`'s relational operator `<` and `lexicographical_compare`.

```cpp
// OJ: https://leetcode.com/problems/create-maximum-number/
// Author: github.com/lzl124631x
// Time: O(M * (M + N)^2)
// Space: O(M + N)
// Ref: https://leetcode.com/problems/create-maximum-number/discuss/77286/Short-Python-Ruby-C%2B%2B
class Solution {
    vector<int> maxSubarray(vector<int> &A, int k) {
        int N = A.size();
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            while (ans.size() && ans.back() < A[i] && k - ans.size() < N - i) ans.pop_back();
            if (ans.size() < k) ans.push_back(A[i]);
        }
        return ans;
    }
    vector<int> merge(vector<int> A, vector<int> B, int k) {
        vector<int> ans;
        for (int i = 0, j = 0, r = 0; r < k; ++r) {
            ans.push_back(lexicographical_compare(begin(A) + i, end(A), begin(B) + j, end(B)) ? B[j++] : A[i++]);
        }
        return ans;
    }
public:
    vector<int> maxNumber(vector<int>& A, vector<int>& B, int k) {
        int M = A.size(), N = B.size();
        vector<int> ans;
        for (int i = max(0, k - N); i <= k && i <= M; ++i) {
            ans = max(ans, merge(maxSubarray(A, i), maxSubarray(B, k - i), k));
        }
        return ans;
    }
};
```