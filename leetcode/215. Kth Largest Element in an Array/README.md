# [215. Kth Largest Element in an Array (Medium)](https://leetcode.com/problems/kth-largest-element-in-an-array/)

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>largest element in the array</em>.</p>

<p>Note that it is the <code>k<sup>th</sup></code> largest element in the sorted order, not the <code>k<sup>th</sup></code> distinct element.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,1,5,6,4], k = 2
<strong>Output:</strong> 5
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,3,1,2,4,5,5,6], k = 4
<strong>Output:</strong> 4
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [LinkedIn](https://leetcode.com/company/linkedin), [Microsoft](https://leetcode.com/company/microsoft), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Adobe](https://leetcode.com/company/adobe), [Spotify](https://leetcode.com/company/spotify), [Shopee](https://leetcode.com/company/shopee), [ServiceNow](https://leetcode.com/company/servicenow), [eBay](https://leetcode.com/company/ebay), [Walmart Labs](https://leetcode.com/company/walmart-labs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Quickselect](https://leetcode.com/tag/quickselect/)

**Similar Questions**:
* [Wiggle Sort II (Medium)](https://leetcode.com/problems/wiggle-sort-ii/)
* [Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)
* [Third Maximum Number (Easy)](https://leetcode.com/problems/third-maximum-number/)
* [Kth Largest Element in a Stream (Easy)](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
* [K Closest Points to Origin (Medium)](https://leetcode.com/problems/k-closest-points-to-origin/)
* [Find the Kth Largest Integer in the Array (Medium)](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/)
* [Find Subsequence of Length K With the Largest Sum (Easy)](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/)
* [K Highest Ranked Items Within a Price Range (Medium)](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/)

## Solution 1. Heap Sort

```cpp
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N + klogN)
// Space: O(1)
class Solution {
    void siftDown(vector<int> &A, int end, int index) {
        if (index < 0 || index >= end) return;
        int child = 2 * index + 1;
        while (child < end) {
            if (child + 1 < end && A[child + 1] > A[child]) ++child;
            if (A[index] > A[child]) break;
            swap(A[index], A[child]);
            index = child;
            child = 2 * index + 1;
        }
    }
    void heapify(vector<int> &A) {
        for (int i = A.size() / 2 - 1; i >= 0; --i) siftDown(A, A.size(), i);
    }
public:
    int findKthLargest(vector<int>& A, int k) {
        heapify(A);
        int N = A.size();
        for (int i = 1; i < k; ++i) {
            swap(A[0], A[N - 1]);
            --N;
            siftDown(A, N, 0);
        }
        return A[0];
    }
};
```

Or use STL's `make_heap` and `pop_heap`.
 
```cpp
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N + klogN)
// Space: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        make_heap(begin(A), end(A));
        while (--k) {
            pop_heap(begin(A), end(A));
            A.pop_back();
        }
        return A[0];
    }
};
```

## Solution 2. Min-heap

```cpp
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(K)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (int n : A) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(k + (N - k)logk)
// Space: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        make_heap(begin(A), begin(A) + k, greater<int>());
        for (int i = k; i < A.size(); ++i) {
            if (A[i] <= A[0]) continue;
            pop_heap(begin(A), begin(A) + k, greater<int>());
            swap(A[i], A[k - 1]);
            push_heap(begin(A), begin(A) + k, greater<int>());
        }
        return A[0];
    }
};
```

## Solution 3. Max-heap

```cpp
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N - k + klog(N - k))
// Space: O(N - k)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        priority_queue<int> pq;
        k = A.size() - k + 1;
        for (int n : A) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O((N - k) + klog(N - k))
// Space: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        int len = A.size() - k + 1;
        make_heap(begin(A), begin(A) + len); // maintain a max-heap in [0, N - k]
        for (int i = len; i < A.size(); ++i) {
            if (A[i] >= A[0]) continue;
            pop_heap(begin(A), begin(A) + len);
            swap(A[i], A[len - 1]);
            push_heap(begin(A), begin(A) + len);
        }
        return A[0];
    }
};
```

Or we can combine the max-heap and min-heap depending on `k`.


```cpp
// OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(Nlog(min(k, N - k)))
// Space: O(min(k, N - k))
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        function<bool(int, int)> cmp = greater<int>();
        int size = k;
        if (k > A.size() / 2) {
            cmp = less<int>();
            size = A.size() - k + 1;
        }
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int n : A) {
            pq.push(n);
            if (pq.size() > size) pq.pop();
        }
        return pq.top();
    }
};
```

## Solution 4. Quick Select

Quick select with elements sorted in descending order.

```cpp
// OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N) on averge, O(N^2) in the worst case
// Space: O(1)
class Solution {
    int partition(vector<int> &A, int L, int R) {
        int i = L, pivotIndex = L + rand() % (R - L + 1), pivot = A[pivotIndex];
        swap(A[pivotIndex], A[R]);
        for (int j = L; j < R; ++j) {
            if (A[j] > pivot) swap(A[i++], A[j]);
        }
        swap(A[i], A[R]);
        return i;
    }
public:
    int findKthLargest(vector<int>& A, int k) {
        int L = 0, R = A.size() - 1;
        while (true) {
            int M = partition(A, L, R);
            if (M + 1 == k) return A[M];
            if (M + 1 > k) R = M - 1;
            else L = M + 1;
        }
    }
};
```

Or use STL's `nth_element`.

```cpp
// OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N) on average, O(N^2) in the worst case
// Space: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        nth_element(begin(A), begin(A) + k - 1, end(A), greater<>());
        return A[k - 1];
    }
};
```

Or use `partial_sort`

```cpp
// OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N) on average, O(N^2) in the worst case
// Space: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        partial_sort(begin(A), begin(A) + k, end(A), greater<>());
        return A[k - 1];
    }
};
```