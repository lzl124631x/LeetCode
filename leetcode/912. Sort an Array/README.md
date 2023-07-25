# [912. Sort an Array (Medium)](https://leetcode.com/problems/sort-an-array/)

<p>Given an array of integers <code>nums</code>, sort the array in ascending order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [5,2,3,1]
<strong>Output:</strong> [1,2,3,5]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [5,1,1,2,0,0]
<strong>Output:</strong> [0,0,1,1,2,5]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-5 * 10<sup>4</sup> &lt;= nums[i] &lt;= 5 * 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Merge Sort](https://leetcode.com/tag/merge-sort/), [Bucket Sort](https://leetcode.com/tag/bucket-sort/), [Radix Sort](https://leetcode.com/tag/radix-sort/), [Counting Sort](https://leetcode.com/tag/counting-sort/)

## Solution 1. STL

```cpp
// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};
```

## Solution 2. Quick Sort

```cpp
// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN) on average, O(N^2) in the worst case
// Space: O(logN) on average, O(N) in the worst case
class Solution {
private:
    int partition(vector<int> &nums, int L, int R, int pivot) {
        swap(nums[pivot], nums[R]);
        for (int i = L; i < R; ++i) {
            if (nums[i] >= nums[R]) continue;
            swap(nums[i], nums[L++]);
        }
        swap(nums[L], nums[R]);
        return L;
    }
    void quickSort(vector<int> &nums, int L, int R) {
        if (L >= R) return;
        int M = partition(nums, L, R, rand() % (R - L + 1) + L);
        quickSort(nums, L, M - 1);
        quickSort(nums, M + 1, R);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srand (time(NULL));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN) on average, O(N^2) in the worst case
// Space: O(logN) on average, O(N) in the worst case
class Solution {
private:
    int partition(vector<int> &A, int L, int R, int pivot) {
        swap(A[pivot], A[R]);
        int i = L, j = R;
        while (i < j) {
            while (i < j && A[i] < A[R]) ++i;
            while (i < j && A[j] >= A[R]) --j;
            swap(A[i], A[j]);
        }
        swap(A[i], A[R]);
        return i;
    }
    void quickSort(vector<int> &A, int L, int R) {
        if (L >= R) return;
        int M = partition(A, L, R, rand() % (R - L + 1) + L);
        quickSort(A, L, M - 1);
        quickSort(A, M + 1, R);
    }
public:
    vector<int> sortArray(vector<int>& A) {
        srand (time(NULL));
        quickSort(A, 0, A.size() - 1);
        return A;
    }
};
```

## Solution 3. Merge Sort

```cpp
// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> sortArray(vector<int>& A) {
        int N = A.size();
        vector<int> tmp(N);
        function<void(int, int)> mergeSort = [&](int begin, int end) {
            if (begin + 1 >= end) return;
            int mid = (begin + end) / 2;
            mergeSort(begin, mid);
            mergeSort(mid, end);
            for (int i = begin, j = mid, k = begin; k < end; ++k) {
                if (j == end || (i < mid && A[i] <= A[j])) tmp[k] = A[i++];
                else tmp[k] = A[j++];
            }
            for (int i = begin; i < end; ++i) A[i] = tmp[i];
        };
        mergeSort(0, N);
        return A;
    }
};
```

## Solution 4. Heap Sort

```cpp
// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
    void heapify(vector<int> &A) {
        for (int i = A.size() / 2 - 1; i >= 0; --i) { // The parent node with the greatest index is `A[N / 2 - 1]`
            siftDown(A, i, A.size()); // Keep sifting down all the parent nodes from bottom up
        }
    }
    void siftDown(vector<int> &A, int hole, int end) {
        int next = 2 * hole + 1; // `next` is the left child of `hole`
        while (next < end) {
            if (next + 1 < end && A[next + 1] > A[next]) ++next; // if the right child is greater than left child, use right child instead.
            if (A[hole] > A[next]) break; // if the parent node is already greater than its greatest child, we don't need to sift it down.
            swap(A[hole], A[next]); // otherwise, keep sifting it down until the parent node `hole` doesn't have any child, i.e. `next >= end`
            hole = next;
            next = 2 * hole + 1;
        }
    }
public:
    vector<int> sortArray(vector<int>& A) {
        heapify(A); // max heap. Heap top at `A[0]`
        for (int i = A.size() - 1; i > 0; --i) {
            swap(A[0], A[i]); // keep swapping heap top to the tail of the heap
            siftDown(A, 0, i); // For the new `A[0]`, sift it down.
        }
        return A;
    }
};
```