# [215. Kth Largest Element in an Array (Medium)](https://leetcode.com/problems/kth-largest-element-in-an-array/)

<p>Find the <strong>k</strong>th largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <code>[3,2,1,5,6,4] </code>and k = 2
<strong>Output:</strong> 5
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <code>[3,2,3,1,2,4,5,5,6] </code>and k = 4
<strong>Output:</strong> 4</pre>

<p><strong>Note: </strong><br>
You may assume k is always valid, 1 ≤ k ≤ array's length.</p>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Heap](https://leetcode.com/tag/heap/)

**Similar Questions**:
* [Wiggle Sort II (Medium)](https://leetcode.com/problems/wiggle-sort-ii/)
* [Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)
* [Third Maximum Number (Easy)](https://leetcode.com/problems/third-maximum-number/)
* [Kth Largest Element in a Stream (Easy)](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

## Solution 1. Heap Sort

```cpp
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N + klogN)
// Space: O(1)
class Solution {
    void percolateDown(vector<int> &A, int end, int index) {
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
        for (int i = (A.size() >> 1) - 1; i >= 0; --i) percolateDown(A, A.size(), i);
    }
public:
    int findKthLargest(vector<int>& A, int k) {
        heapify(A); // A[0] is the root. Max-root heap.
        int N = A.size();
        for (int i = 1; i < k; ++i) {
            swap(A[0], A[N - 1]);
            --N;
            percolateDown(A, N, 0);
        }
        return A[0];
    }
};
```

## Solution 2. Heap Sort with STL
 
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

## Solution 3. Min-heap

```cpp
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(K)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int n : A) {
            if (q.size() < k) q.push(n);
            else if (q.top() < n) {
                q.pop();
                q.push(n);
            }
        }
        return q.top();
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
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

## Solution 4. Max-heap

```cpp
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N - k + klog(N - k))
// Space: O(N - k)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        priority_queue<int> q;
        k = A.size() - k + 1;
        for (int n : A) {
            if (q.size() < k) q.push(n);
            else if (q.top() > n) {
                q.pop();
                q.push(n);
            }
        }
        return q.top();
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

## Solution 5. Quick Select

Quick select with elements sorted in ascending order.

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
            if (A[j] < pivot) swap(A[i++], A[j]);
        }
        swap(A[i], A[R]);
        return i;
    }
public:
    int findKthLargest(vector<int>& A, int k) {
        int L = 0, R = A.size() - 1;
        k = A.size() - k + 1;
        while (true) {
            int M = partition(A, L, R);
            if (M + 1 == k) return A[M];
            if (M + 1 > k) R = M - 1;
            else L = M + 1;
        }
    }
};
```

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

Or STL

```cpp
// OJ: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N) on average, O(N^2) in the worst case
// Space: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        nth_element(begin(A), begin(A) + k - 1, end(A), greater<int>());
        return A[k - 1];
    }
};
```