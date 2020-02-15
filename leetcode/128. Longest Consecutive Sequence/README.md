# [128. Longest Consecutive Sequence (Hard)](https://leetcode.com/problems/longest-consecutive-sequence/)

<p>Given an unsorted array of integers, find the length of the longest consecutive elements sequence.</p>

<p>Your algorithm should run in O(<em>n</em>) complexity.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>&nbsp;[100, 4, 200, 1, 3, 2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest consecutive elements sequence is <code>[1, 2, 3, 4]</code>. Therefore its length is 4.
</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Binary Tree Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<pair<int, int>> s;
        for (int n : nums) {
            auto it = s.upper_bound(make_pair(n, n));
            if (it != s.end() && it->first == n) continue; 
            int start = n, end = n;
            if (it != s.begin()) {
                auto j = prev(it);
                if (j->second >= n) continue;
                if (j->second + 1 == n) {
                    start = j->first;
                    s.erase(j);
                }
            }
            if (it != s.end() && it->first == n + 1) {
                end = it->second;
                s.erase(it);
            }
            s.emplace(start, end);
        }
        int ans = 0;
        for (auto &p : s) ans = max(ans, p.second - p.first + 1);
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int ans = 1, len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] == nums[i - 1] + 1) ans = max(ans, ++len);
            else len = 1;
        }
        return ans;
    }
};
```

## Solution 3.

Let `m` be a map and `m[n]` be the length of the longest consecutive sequence containing `n`, where `n` is an element in `nums`.

For each `n` in `nums`:
1. If `m[n] > 0`, we've met `n` so we can skip it.
1. We take a look at `m[n - 1]` and `m[n + 1]` and use them to extend the sequence. The extended length is `m[n - 1] + m[n + 1] + 1`. The two endpoints of the extended sequence are two out of `n - m[n - 1]`, `n + m[n - 1]` and `n`. So we update them with the extended length `m[n - 1] + m[n + 1] + 1`.

The maximum `m[n]` is the answer.

```cpp
// OJ: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/longest-consecutive-sequence/discuss/41088/Possibly-shortest-cpp-solution-only-6-lines.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int n : nums) {
            if (m[n]) continue;
            ans = max(ans, m[n] = m[n - m[n - 1]] = m[n + m[n + 1]] = m[n - 1] + m[n + 1] + 1);
        }
        return ans;
    }
};
```