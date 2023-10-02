# [347. Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)

<p>Given a non-empty array of integers, return the <b><i>k</i></b> most frequent elements.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-1-1">[1,1,1,2,2,3]</span>, k = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">[1,2]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-2-1">[1]</span>, k = <span id="example-input-2-2">1</span>
<strong>Output: </strong><span id="example-output-2">[1]</span></pre>
</div>

<p><b>Note: </b></p>

<ul>
	<li>You may assume <i>k</i> is always valid, 1 ≤ <i>k</i> ≤ number of unique elements.</li>
	<li>Your algorithm's time complexity <b>must be</b> better than O(<i>n</i> log <i>n</i>), where <i>n</i> is the array's size.</li>
	<li>It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.</li>
	<li>You can return the answer in any order.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Heap](https://leetcode.com/tag/heap/)

**Similar Questions**:
* [Word Frequency (Medium)](https://leetcode.com/problems/word-frequency/)
* [Kth Largest Element in an Array (Medium)](https://leetcode.com/problems/kth-largest-element-in-an-array/)
* [Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)
* [Split Array into Consecutive Subsequences (Medium)](https://leetcode.com/problems/split-array-into-consecutive-subsequences/)
* [Top K Frequent Words (Medium)](https://leetcode.com/problems/top-k-frequent-words/)
* [K Closest Points to Origin (Medium)](https://leetcode.com/problems/k-closest-points-to-origin/)

## Solution 1. Heap

```cpp
// OJ: https://leetcode.com/problems/top-k-frequent-elements/
// Author: github.com/lzl124631x
// Time: O(N + UlogK) where `U` is the number of unique elements in `A`.
// Space: O(U)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        vector<int> ans;
        if (cnt.size() == k) {
            for (auto &[n, c] : cnt) ans.push_back(n);
            return ans;
        }
        auto cmp = [&](int a, int b) { return cnt[a] > cnt[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); // keep a min-heap of size at most k
        for (auto &[n, c] : cnt) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        while (pq.size()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
```

Or use `make_heap` and `pop_heap`.

```cpp
// OJ: https://leetcode.com/problems/top-k-frequent-elements/
// Author: github.com/lzl124631x
// Time: O(N + UlogK) where `U` is the number of unique elements in `A`.
// Space: O(U)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        vector<int> nums, ans;
        for (auto &[n, c] : cnt) nums.push_back(n);
        if (nums.size() == k) return nums;
        auto cmp = [&](int a, int b) { return cnt[a] < cnt[b]; };
        make_heap(begin(nums), end(nums), cmp);
        while (k--) {
            pop_heap(begin(nums), end(nums), cmp);
            ans.push_back(nums.back());
            nums.pop_back();
        }
        return ans;
    }
};
```

## Solution 2. Quick Select

```cpp
// OJ: https://leetcode.com/problems/top-k-frequent-elements/
// Author: github.com/lzl124631x
// Time: O(N + U) on average, O(N + U^2) in the worst case
// Space: O(U)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        vector<int> ans;
        for (auto &[n, c] : cnt) ans.push_back(n);
        if (ans.size() == k) return ans;
        auto partition = [&](int L, int R) {
            int i = L, j = L, pivotIndex = L + rand() % (R - L + 1), pivot = cnt[ans[pivotIndex]];
            swap(ans[pivotIndex], ans[R]);
            for (; i < R; ++i) {
                if (cnt[ans[i]] > pivot) swap(ans[i], ans[j++]);
            }
            swap(ans[j], ans[R]);
            return j;
        };
        auto quickSelect = [&](int k) {
            int L = 0, R = ans.size() - 1;
            while (L < R) {
                int M = partition(L, R);
                if (M + 1 == k) break;
                if (M + 1 > k) R = M - 1;
                else L = M + 1;
            }
        };
        quickSelect(k);
        ans.resize(k);
        return ans;
    }
};
```

Or use STL's `nth_element`.

```cpp
// OJ: https://leetcode.com/problems/top-k-frequent-elements/
// Author: github.com/lzl124631x
// Time: O(N + U) on average, O(N + U^2) in the worst casee
// Space: O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        vector<int> ans;
        for (auto &[n, c] : cnt) ans.push_back(n);
        if (ans.size() == k) return ans;
        nth_element(begin(ans), begin(ans) + k - 1, end(ans), [&](int a, int b) { return cnt[a] > cnt[b]; });
        ans.resize(k);
        return ans;
    }
};
```