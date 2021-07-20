# [1471. The k Strongest Values in an Array (Medium)](https://leetcode.com/problems/the-k-strongest-values-in-an-array/)

<p>Given an array of integers <code>arr</code>&nbsp;and an integer <code>k</code>.</p>

<p>A value <code>arr[i]</code> is said to be stronger than a value <code>arr[j]</code> if <code>|arr[i] - m| &gt; |arr[j]&nbsp;- m|</code> where <code>m</code> is the <strong>median</strong> of the array.<br>
If <code>|arr[i] - m| == |arr[j] - m|</code>, then <code>arr[i]</code> is said to be stronger than <code>arr[j]</code> if <code>arr[i] &gt; arr[j]</code>.</p>

<p>Return <em>a list of the strongest <code>k</code></em> values in the array. return the answer <strong>in any arbitrary order</strong>.</p>

<p><strong>Median</strong> is the middle value in an ordered integer list. More formally, if the length of the list is n, the median is the element in position <code>((n - 1) / 2)</code> in the sorted list&nbsp;<strong>(0-indexed)</strong>.</p>

<ul>
	<li>For <code>arr =&nbsp;[6, -3, 7, 2, 11]</code>,&nbsp;<code>n = 5</code> and the median is obtained by sorting the array&nbsp;<code>arr = [-3, 2, 6, 7, 11]</code> and the median is <code>arr[m]</code> where <code>m = ((5 - 1) / 2) = 2</code>. The median is <code>6</code>.</li>
	<li>For <code>arr =&nbsp;[-7, 22, 17, 3]</code>,&nbsp;<code>n = 4</code> and the median is obtained by sorting the array&nbsp;<code>arr = [-7, 3, 17, 22]</code> and the median is <code>arr[m]</code> where <code>m = ((4 - 1) / 2) = 1</code>. The median is <code>3</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,4,5], k = 2
<strong>Output:</strong> [5,1]
<strong>Explanation:</strong> Median is 3, the elements of the array sorted by the strongest are [5,1,4,2,3]. The strongest 2 elements are [5, 1]. [1, 5] is also <strong>accepted</strong> answer.
Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1 because 5 &gt; 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,1,3,5,5], k = 2
<strong>Output:</strong> [5,5]
<strong>Explanation:</strong> Median is 3, the elements of the array sorted by the strongest are [5,5,1,1,3]. The strongest 2 elements are [5, 5].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [6,7,11,7,6,8], k = 5
<strong>Output:</strong> [11,8,6,6,7]
<strong>Explanation:</strong> Median is 7, the elements of the array sorted by the strongest are [11,8,6,6,7,7].
Any permutation of [11,8,6,6,7] is <strong>accepted</strong>.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> arr = [6,-3,7,2,11], k = 3
<strong>Output:</strong> [-3,11,2]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> arr = [-7,22,17,3], k = 2
<strong>Output:</strong> [22,17]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>-10^5 &lt;= arr[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
</ul>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1. Sort

```cpp
// OJ: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> getStrongest(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int m = A[(A.size() - 1) / 2];
        sort(A.begin(), A.end(), [&](int &a, int &b) {
            return abs(a - m) == abs(b - m) ? a > b : (abs(a - m) > abs(b - m));
        });
        return vector<int> (A.begin(), A.begin() + k);
    }
};
```

## Solution 2. Two pointers

```cpp
// OJ: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
// Ref: https://leetcode.com/problems/the-k-strongest-values-in-an-array/discuss/674384/C%2B%2BJavaPython-Two-Pointers-%2B-3-Bonuses
class Solution {
public:
    vector<int> getStrongest(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int m = A[(A.size() - 1) / 2], i = 0, j = A.size() - 1;
        vector<int> ans;
        while (ans.size() < k) {
            if (A[j] - m >= m - A[i]) ans.push_back(A[j--]);
            else ans.push_back(A[i++]);
        }
        return ans;
    }
};
```

## Solution 3. Quick Select

```cpp
// OJ: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N) on average, O(N^2) in the worst case
// Space: O(1)
// Ref: https://leetcode.com/problems/the-k-strongest-values-in-an-array/discuss/674384/C%2B%2BJavaPython-Two-Pointers-%2B-3-Bonuses
class Solution {
public:
    vector<int> getStrongest(vector<int>& A, int k) {
        nth_element(A.begin(), A.begin() + (A.size() - 1) / 2, A.end());
        int m = A[(A.size() - 1) / 2];
        partial_sort(A.begin(), A.begin() + k, A.end(), [&](int a, int b) {
            return abs(a - m) == abs(b - m) ? a > b : abs(a - m) > abs(b - m);
        });
        return vector<int>(begin(A), begin(A) + k);
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N) on average, O(N^2) in the worst case
// Space: O(2)
class Solution {
public:
    vector<int> getStrongest(vector<int>& A, int k) {
        nth_element(begin(A), begin(A) + (A.size() - 1) / 2, end(A));
        int m = A[(A.size() - 1) / 2];
        nth_element(begin(A), begin(A) + k - 1, end(A), [&](int a, int b) { 
            return abs(a - m) == abs(b - m) ? a > b : abs(a - m) > abs(b - m);
        });
        return vector<int>(begin(A), begin(A) + k);
    }
};
```

## Solution 4. Heap

* `nth_element` is quick select taking `O(N)`.
* `priority_queue` initialized with array is `make_heap` (aka heapify), which is `O(N)`.
* Pulling from priority queue is `O(logN)` and we do it `k` times.

```cpp
// OJ: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N + KlogN)
// Space: O(1)
// Ref: https://leetcode.com/problems/the-k-strongest-values-in-an-array/discuss/674384/C%2B%2BJavaPython-Two-Pointers-%2B-3-Bonuses
class Solution {
public:
    vector<int> getStrongest(vector<int>& A, int k) {
        nth_element(A.begin(), A.begin() + (A.size() - 1) / 2, A.end());
        int m = A[(A.size() - 1) / 2];
        auto cmp = [&](int a, int b) {
            return abs(a - m) == abs(b - m) ? a < b : abs(a - m) < abs(b - m); 
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(begin(A), end(A), cmp);
        vector<int> ans;
        while (ans.size() < k) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};
```