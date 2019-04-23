# [912. Sort an Array (Medium)](https://leetcode.com/problems/sort-an-array/)

<p>Given an array of integers <code>nums</code>, sort the array in ascending order.</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong>&nbsp;[5,2,3,1]
<strong>Output:</strong> [1,2,3,5]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>[5,1,1,2,0,0]
<strong>Output: </strong>[0,0,1,1,2,5]
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 10000</code></li>
	<li><code>-50000 &lt;= A[i] &lt;= 50000</code></li>
</ol>


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
// Time: O(NlogN) on average
// Space: O(1)
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

## Solution 3. Merge Sort

```cpp
// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
private:
    vector<int> tmp;
    void mergeSort(vector<int> &nums, int start, int end) {
        if (start + 1 >= end) return;
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid, end);
        for (int i = start, j = mid, k = 0; i < mid || j < end; ++k) {
            tmp[k] = (i >= mid || (j < end && nums[j] < nums[i])) ? nums[j++] : nums[i++];
        }
        for (int i = start; i < end; ++i) nums[i] = tmp[i - start];
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        tmp = vector<int>(nums.size());
        mergeSort(nums, 0, nums.size());
        return nums;
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
private:
    void heapify(vector<int> &nums) {
        for (int i = nums.size() / 2 - 1; i >= 0; --i)
            siftDown(nums, i, nums.size());
    }
    void siftDown(vector<int> &nums, int hole, int end) {
        int next = 2 * hole + 1;
        while (next < end) {
            if (next + 1 < end && nums[next + 1] > nums[next]) ++next;
            if (nums[hole] > nums[next]) break;
            swap(nums[hole], nums[next]);
            hole = next;
            next = 2 * next + 1;
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapify(nums);
        for (int i = nums.size() - 1; i > 0; --i) {
            swap(nums[0], nums[i]);
            siftDown(nums, 0, i);
        }
        return nums;
    }
};
```