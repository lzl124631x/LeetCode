# [2021. Brightest Position on Street (Medium)](https://leetcode.com/problems/brightest-position-on-street/)

<p>A perfectly straight street is represented by a number line. The street has street lamp(s) on it and is represented by a 2D integer array <code>lights</code>. Each <code>lights[i] = [position<sub>i</sub>, range<sub>i</sub>]</code> indicates that there is a street lamp at position <code>position<sub>i</sub></code> that lights up the area from <code>[position<sub>i</sub> - range<sub>i</sub>, position<sub>i</sub> + range<sub>i</sub>]</code> (<strong>inclusive</strong>).</p>

<p>The <strong>brightness</strong> of a position <code>p</code> is defined as the number of street lamp that light up the position <code>p</code>.</p>

<p>Given <code>lights</code>, return <em>the <strong>brightest</strong> position on the</em><em> street. If there are multiple brightest positions, return the <strong>smallest</strong> one.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2021/09/28/image-20210928155140-1.png" style="width: 700px; height: 165px;">
<pre><strong>Input:</strong> lights = [[-3,2],[1,2],[3,3]]
<strong>Output:</strong> -1
<strong>Explanation:</strong>
The first street lamp lights up the area from [(-3) - 2, (-3) + 2] = [-5, -1].
The second street lamp lights up the area from [1 - 2, 1 + 2] = [-1, 3].
The third street lamp lights up the area from [3 - 3, 3 + 3] = [0, 6].

Position -1 has a brightness of 2, illuminated by the first and second street light.
Positions 0, 1, 2, and 3 have a brightness of 2, illuminated by the second and third street light.
Out of all these positions, -1 is the smallest, so return it.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> lights = [[1,0],[0,1]]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The first street lamp lights up the area from [1 - 0, 1 + 0] = [1, 1].
The second street lamp lights up the area from [0 - 1, 0 + 1] = [-1, 1].

Position 1 has a brightness of 2, illuminated by the first and second street light.
Return 1 because it is the brightest position on the street.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> lights = [[1,2]]
<strong>Output:</strong> -1
<strong>Explanation:</strong>
The first street lamp lights up the area from [1 - 2, 1 + 2] = [-1, 3].

Positions -1, 0, 1, 2, and 3 have a brightness of 1, illuminated by the first street light.
Out of all these positions, -1 is the smallest, so return it.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= lights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>lights[i].length == 2</code></li>
	<li><code>-10<sup>8</sup> &lt;= position<sub>i</sub> &lt;= 10<sup>8</sup></code></li>
	<li><code>0 &lt;= range<sub>i</sub> &lt;= 10<sup>8</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

**Similar Questions**:
* [Minimum Number of Buckets Required to Collect Rainwater from Houses (Medium)](https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/)

## Solution 1. Heap

```cpp
// OJ: https://leetcode.com/problems/brightest-position-on-street/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int brightestPosition(vector<vector<int>>& A) {
        for (auto &v : A) {
            int p = v[0], r = v[1];
            v[0] = p - r;
            v[1] = p + r;
        }
        sort(begin(A), end(A));
        priority_queue<int, vector<int>, greater<>> pq;
        int ans = INT_MIN, size = 0;
        for (auto &v : A) {
            int begin = v[0], end = v[1];
            while (pq.size() && pq.top() < begin) pq.pop();
            pq.push(end);
            if (pq.size() > size) {
                size = pq.size();
                ans = begin;
            } 
        }
        return ans;
    }
};
```

## Solution 2. Line Sweep

```cpp
// OJ: https://leetcode.com/problems/brightest-position-on-street/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int brightestPosition(vector<vector<int>>& A) {
        vector<int> begin, end;
        for (auto &v : A) {
            begin.push_back(v[0] - v[1]);
            end.push_back(v[0] + v[1]);
        }
        sort(begin.begin(), begin.end());
        sort(end.begin(), end.end());
        int i = 0, j = 0, N = A.size(), ans = INT_MIN, size = 0;
        for (; i < N; ++i) {
            while (end[j] < begin[i]) ++j;
            if (i - j + 1 > size) {
                size = i - j + 1;
                ans = begin[i];
            }
        }
        return ans;
    }
};
```

## Solution 3. Difference Array

```cpp
// OJ: https://leetcode.com/problems/brightest-position-on-street/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int brightestPosition(vector<vector<int>>& A) {
        map<int, int> m;
        for (auto &v : A) {
            m[v[0] - v[1]]++;
            m[v[0] + v[1] + 1]--;
        }
        int size = 0, ans = INT_MIN, cnt = 0;
        for (auto &[index, diff] : m) {
            cnt += diff;
            if (cnt > size) {
                size = cnt;
                ans = index;
            }
        }
        return ans;
    }
};
```