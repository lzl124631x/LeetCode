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
// Time: O(NlogK)
// Space: O(N + K)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        vector<int> ans;
        if (m.size() == k) {
            for (auto &p : m) ans.push_back(p.first);
            return ans;
        }
        auto cmp = [&](int a, int b) { return m[a] > m[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp); // keep a min-heap of size at most k
        for (auto &p : m) {
            q.push(p.first);
            if (q.size() > k) q.pop();
        }
        while (ans.size() < k) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};
```

## Solution 2. Quick Select

```cpp
// OJ: https://leetcode.com/problems/top-k-frequent-elements/
// Author: github.com/lzl124631x
// Time: O(N) on average, O(N^2) in the worst case
// Space: O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        if (A.size() == k) return A;
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        vector<int> ans;
        for (auto &p : m) ans.push_back(p.first);
        if (m.size() == k) return ans;
        nth_element(begin(ans), begin(ans) + k - 1, end(ans), [&](int a, int b) { return m[a] > m[b]; });
        ans.resize(k);
        return ans;
    }
};
```