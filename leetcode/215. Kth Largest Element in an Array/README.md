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
private:
  void percolateDown(vector<int>&nums, int end, int index) {
    if (index < 0 || index >= end) return;
    int child = 2 * index + 1;
    while (child < end) {
      if (child + 1 < end && nums[child + 1] > nums[child]) ++child;
      if (nums[index] > nums[child]) break;
      swap(nums[index], nums[child]);
      index = child;
      child = 2 * index + 1;
    }
  }
  void heapify(vector<int>&nums) {
    for (int i = (nums.size() >> 1) - 1; i >= 0; --i) {
      percolateDown(nums, nums.size(), i);
    }
  }
public:
  int findKthLargest(vector<int>& nums, int k) {
    heapify(nums);
    int size = nums.size();
    for (int i = 1; i < k; ++i) {
      swap(nums[0], nums[size - 1]);
      --size;
      percolateDown(nums, size, 0);
    }
    return nums[0];
  }
};
```

## Solution 2. Use STL

```cpp
// Author: github.com/lzl124631x
// Time: O(N + klogN)
// Space: O(1)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end());
    while (--k) {
      pop_heap(nums.begin(), nums.end());
      nums.pop_back();
    }
    return nums[0];
  }
};
```

## Solution 3. STL!
```cpp
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end());
    sort_heap(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};
```

## Solution 4. priority_queue
```cpp
// Author: github.com/lzl124631x
// Time: O(k + (N - k)logk)
// Space: O(k)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int n : nums) {
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

## Solution 5. 

```cpp
// Author: github.com/lzl124631x
// Time: O(k + (N - k)logk)
// Space: O(1)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.begin() + k, greater<int>());
    for (int i = k; i < nums.size(); ++i) {
      if (nums[i] > nums[0]) {
        pop_heap(nums.begin(), nums.end());
        swap(nums[k - 1], nums[i]);
        push_heap(nums.begin(), nums.end());
      }
    }
    return nums[0];
  }
};
```