# [632. Smallest Range Covering Elements from K Lists (Hard)](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists)

<p>You have <code>k</code> lists of sorted integers in <strong>non-decreasing&nbsp;order</strong>. Find the <b>smallest</b> range that includes at least one number from each of the <code>k</code> lists.</p>

<p>We define the range <code>[a, b]</code> is smaller than range <code>[c, d]</code> if <code>b - a &lt; d - c</code> <strong>or</strong> <code>a &lt; c</code> if <code>b - a == d - c</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
<strong>Output:</strong> [20,24]
<strong>Explanation: </strong>
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [[1,2,3],[1,2,3],[1,2,3]]
<strong>Output:</strong> [1,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums.length == k</code></li>
	<li><code>1 &lt;= k &lt;= 3500</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 50</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code>&nbsp;is sorted in <strong>non-decreasing</strong> order.</li>
</ul>


**Companies**:
[Flipkart](https://leetcode.com/company/flipkart), [Amazon](https://leetcode.com/company/amazon), [Snapchat](https://leetcode.com/company/snapchat), [Pinterest](https://leetcode.com/company/pinterest), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Adobe](https://leetcode.com/company/adobe), [Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft), [Lyft](https://leetcode.com/company/lyft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Greedy](https://leetcode.com/tag/greedy), [Sliding Window](https://leetcode.com/tag/sliding-window), [Sorting](https://leetcode.com/tag/sorting), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue)

**Similar Questions**:
* [Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring)

## Solution 1. Two Pointers

The range can be initialized as `{ min(min(A)), max(max(A)) }`.

For input `[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]`, the `ans` is initialized as `{0, 30}`.

We can gradually shrink the max value from `max(max(A))` to `max(min(A))`, `30, 26, 24, 20, 18, 15, 12 10, 9, 5`.

During this process, each max value has a corresponding greatest min value

```
max   min
30 -> 30, 26, 24, (20)
26 -> (20)
24 -> (20)
20 -> 20, 18, (15)
...
```

We can use two pointers. One pointer scans the max value, and the other pointer looks for the corresponding greatest min value.

### Time complexity

In the worst case, the pointers needs to scan through all the elements. Assume the maximum length of `A[i]` is `N`, then there are `O(NK)` elements.

For each pair of `{ min, max }` pointed by the two pointers, we need to run the `valid` function to check if this range is valid, which takes `O(KlogN)` time.

So overall the time complexity is `O(K^2 * NlogN)`.

```cpp
// OJ: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
// Author: github.com/lzl124631x
// Time: O(K^2 * NlogN)
// Space: O(NK)
class Solution {
    bool valid(vector<vector<int>> &A, int mn, int mx) {
        for (auto &v : A) {
            if (lower_bound(begin(v), end(v), mn) == upper_bound(begin(v), end(v), mx)) return false;
        }
        return true;
    }
public:
    vector<int> smallestRange(vector<vector<int>>& A) {
        set<int> s;
        for (auto &v : A) {
            for (int n : v) s.insert(n);
        }
        auto i = s.rbegin(), j = s.rbegin();
        vector<int> ans = { *s.begin(), *s.rbegin() };
        while (j != s.rend()) {
            int mx = *i;
            while (j != s.rend() && !valid(A, *j, mx)) ++j;
            if (j != s.rend() && (mx - *j < ans[1] - ans[0] || (mx - *j == ans[1] - ans[0] && *j < ans[0]))) ans = { *j, mx };
            if (j == i) ++j;
            ++i;
        }
        return ans;
    }
};
```

## Solution 2. Next Pointer Array + Min Heap

From each `A[i]` we select a single element, with which we can form a group of `k` numbers. The difference between the max and min values is the smallest range covering these `k` numbers, which in turn covers the `k` arrays in `A`.

So our goal is to find a group of numbers that can minimize the difference of its max and min values.

Let's start this group of numbers using all the min values in each `A[i]`. Getting its max and min value can give us a range covering it. Then what do we do next?

Since they are all min values, we can only **increase** one of them. Which one should we increase so that we can possibly shrink the range? That's the min values among those numbers.

We can use a `vector<int> next(A.size())` to keep track of the next element we are going to visit. Each round we increment the `next[i]` whose corresponding `A[i][next[i]]` is the minimum in the group.

After this operation, the new maximum must be either the old max value or this new `A[i][next[i]]`, so using a single variable can keep track of the max value of the range. For the min value, we can use a min heap to keep track of it.

### Time complexity

In the worst case, we need to visit all the elements. Assume the maximum length of `A[i]` is `N`, then there are `O(NK)` elements.

There are `K` elements in the min heap. During initialization, pushing `K` elements into the min heap takes `O(KlogK)` time. Each push/pop takes `O(logK)` time.

So overall the time complexity is `O(NKlogK)`.

```cpp
// OJ: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
// Author: github.com/lzl124631x
// Time: O(NKlogK)
// Space: O(K)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& A) {
        int N = A.size(), mx = INT_MIN;
        vector<int> ans = { 0, 200001 }, next(N);
        auto cmp = [&](int a, int b) { return A[a][next[a]] > A[b][next[b]]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < N; ++i) {
            pq.push(i);
            mx = max(mx, A[i][0]);
        }
        while (true) {
            int i = pq.top(), mn = A[i][next[i]];
            pq.pop();
            if (ans[1] - ans[0] > mx - mn) ans = { A[i][next[i]], mx };
            if (++next[i] == A[i].size()) break;
            pq.push(i);
            mx = max(mx, A[i][next[i]]);
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists
// Author: github.com/lzl124631x
// Time: O(NKlogK)
// Space: O(K)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& A) {
        typedef array<int, 2> PII;
        auto cmp = [&](auto &a, auto &b) { return A[a[0]][a[1]] > A[b[0]][b[1]]; };
        priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
        int N = A.size(), mx = INT_MIN, first = INT_MAX, len = INT_MAX;
        for (int i = 0; i < N; ++i) {
            pq.push({ i, 0 });
            mx = max(mx, A[i][0]);
        }
        while (true) {
            auto [i, j] = pq.top();
            pq.pop();
            int newLen = mx - A[i][j] + 1;
            if (newLen < len) {
                first = A[i][j];
                len = newLen;
            }
            if (j + 1 == A[i].size()) break;
            pq.push({ i, j + 1 });
            mx = max(mx, A[i][j + 1]);
        }
        return {first, first + len - 1};
    }
};
```

## Solution 3. Min Heap + Multiset

Similar to Solution 2, but we use a `multiset` to keep track of the numbers within the sliding window.

```cpp
// OJ: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists
// Author: github.com/lzl124631x
// Time: O(NKlogK)
// Space: O(K)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& A) {
        int N = A.size(), first = INT_MAX, len = INT_MAX;
        typedef array<int, 2> PII;
        auto cmp = [&](auto &a, auto &b) { return A[a[0]][a[1]] > A[b[0]][b[1]]; };
        priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
        multiset<int> s;
        for (int i = 0; i < N; ++i) {
            pq.push({i, 0});
            s.insert(A[i][0]);
        }
        while (true) {
            int fst = *s.begin(), lst = *s.rbegin(), newLen = lst - fst + 1;
            if (newLen < len || (len == newLen && fst < first)) {
                first = fst;
                len = newLen;
            }
            auto [i, j] = pq.top();
            pq.pop();
            s.erase(s.find(A[i][j]));
            if (j + 1 == A[i].size()) break;
            s.emplace(A[i][j + 1]);
            pq.push({i, j + 1});
        }
        return {first, first + len - 1};
    }
};
```