# [1054. Distant Barcodes (Medium)](https://leetcode.com/problems/distant-barcodes/)

<p>In a warehouse, there is a row of barcodes, where the <code>i</code>-th barcode is&nbsp;<code>barcodes[i]</code>.</p>

<p>Rearrange the barcodes so that no two adjacent barcodes are equal.&nbsp; You may return any answer, and it is guaranteed an answer exists.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,1,1,2,2,2]</span>
<strong>Output: </strong><span id="example-output-1">[2,1,2,1,2,1]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,1,1,1,2,2,3,3]</span>
<strong>Output: </strong><span id="example-output-2">[1,3,1,3,2,1,2,1]</span></pre>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= barcodes.length &lt;= 10000</code></li>
	<li><code>1 &lt;= barcodes[i] &lt;= 10000</code></li>
</ol>

<div>
<div>&nbsp;</div>
</div>

**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1. Greedy + Heap

```cpp
// OJ: https://leetcode.com/problems/distant-barcodes/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& A) {
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        auto cmp = [&](int a, int b) { return cnt[a] < cnt[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (auto &p : cnt) q.push(p.first);
        int prev = 0;
        vector<int> ans;
        while (q.size()) {
            int n = q.top();
            q.pop();
            ans.push_back(n);
            if (prev) q.push(prev);
            if (--cnt[n]) prev = n;
            else prev = 0;
        }
        return ans;
    }
};
```

## Solution 2. Interleaving Placement

```cpp
// OJ: https://leetcode.com/problems/distant-barcodes/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& A) {
        unordered_map<int, int> cnt;
        set<pair<int, int>> s;
        for (int n : A) cnt[n]++;
        for (auto &p : cnt) s.emplace(p.second, p.first);
        int j = 0, N = A.size();
        vector<int> ans(N);
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            for (int c = 0; c < it->first; ++c, j += 2) {
                if (j >= N) j = 1;
                ans[j] = it->second;
            }
        }
        return ans;
    }
};
```

## Solution 3. 

Just fill the most frequent number first. The others can be filled irrespective of their frequency.

```cpp
// OJ: https://leetcode.com/problems/distant-barcodes/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& A) {
        short cnt[10001] = {}, maxCnt = 0, num = 0, j = 0;
        for (int n : A) {
            maxCnt = max(maxCnt, ++cnt[n]);
            if (maxCnt == cnt[n]) num = n;
        }
        for (int i = 0; i <= 10000; ++i) {
            int n = i ? i : num;
            while (cnt[n]-- > 0) {
                A[j] = n;
                j = (j + 2) % A.size();
                if (j == 0) j = 1;
            }
        }
        return A;
    }
};
```