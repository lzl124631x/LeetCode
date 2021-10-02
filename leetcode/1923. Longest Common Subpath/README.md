# [1923. Longest Common Subpath (Hard)](https://leetcode.com/problems/longest-common-subpath/)

<p>There is a country of <code>n</code> cities numbered from <code>0</code> to <code>n - 1</code>. In this country, there is a road connecting <b>every pair</b> of cities.</p>

<p>There are <code>m</code> friends numbered from <code>0</code> to <code>m - 1</code> who are traveling through the country. Each one of them will take a path consisting of some cities. Each path is represented by an integer array that contains the visited cities in order. The path may contain a city <strong>more than once</strong>, but the same city will not be listed consecutively.</p>

<p>Given an integer <code>n</code> and a 2D integer array <code>paths</code> where <code>paths[i]</code> is an integer array representing the path of the <code>i<sup>th</sup></code> friend, return <em>the length of the <strong>longest common subpath</strong> that is shared by <strong>every</strong> friend's path, or </em><code>0</code><em> if there is no common subpath at all</em>.</p>

<p>A <strong>subpath</strong> of a path is a contiguous sequence of cities within that path.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 5, paths = [[0,1,<u>2,3</u>,4],
                       [<u>2,3</u>,4],
                       [4,0,1,<u>2,3</u>]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest common subpath is [2,3].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3, paths = [[0],[1],[2]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no common subpath shared by the three paths.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 5, paths = [[<u>0</u>,1,2,3,4],
                       [4,3,2,1,<u>0</u>]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The possible longest common subpaths are [0], [1], [2], [3], and [4]. All have a length of 1.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>m == paths.length</code></li>
	<li><code>2 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>sum(paths[i].length) &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= paths[i][j] &lt; n</code></li>
	<li>The same city is not listed multiple times consecutively in <code>paths[i]</code>.</li>
</ul>


**Similar Questions**:
* [Reconstruct Itinerary (Medium)](https://leetcode.com/problems/reconstruct-itinerary/)

## Solution 1. Rolling Hash + Binary Answer

```cpp
// OJ: https://leetcode.com/problems/longest-common-subpath/
// Author: github.com/lzl124631x
// Time: O(N + logM * P) where P is the total length of all paths.
// Space: O(M)
class Solution {
    bool valid(vector<vector<int>> &A, int len) {
        unordered_map<unsigned long long, int> m;
        unordered_set<unsigned long long> s; // Note that we must use `unsigned long long` to reduce the chance of hash conflict
        unsigned d = 16777619;
        for (auto &v : A) {
            s.clear();
            unsigned long long h = 0, p = 1;
            for (int i = 0; i < v.size(); ++i) {
                h = h * d + v[i];
                if (i >= len) h -= v[i - len] * p;
                else p *= d;
                if (i >= len - 1) s.insert(h);
            }
            for (auto x : s) {
                if (++m[x] == A.size()) return true;
            }
        }
        return false;
    }
public:
    int longestCommonSubpath(int n, vector<vector<int>>& A) {
        int minLen = INT_MAX;
        for (auto &v : A) minLen = min(minLen, (int)v.size());
        int L = 0, R = minLen;
        while (L < R) {
            int M = (L + R + 1) / 2;
            if (valid(A, M)) L = M;
            else R = M - 1;
        }
        return L;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/longest-common-subpath/
// Author: github.com/lzl124631x
// Time: O(N + logM * P) where P is the total length of all paths.
// Space: O(M)
class Solution {
    bool valid(vector<vector<int>> &A, int len) {
        unordered_set<unsigned long long> s, tmp;
        for (int i = 0; i < A.size() && (i == 0 || s.size()); ++i) {
            unsigned long long d = 1099511628211, h = 0, p = 1;
            tmp.clear();
            swap(s, tmp);
            for (int j = 0; j < A[i].size(); ++j) {
                h = h * d + A[i][j];
                if (j < len) p *= d;
                else h -= A[i][j - len] * p;
                if (j >= len - 1 && (i == 0 || tmp.count(h))) s.insert(h);
            }
        }
        return s.size();
    }
public:
    int longestCommonSubpath(int n, vector<vector<int>>& A) {
        int L = 0, R = min_element(begin(A), end(A), [](auto &a, auto &b) { return a.size() < b.size(); })->size();
        while (L < R) {
            int M = (L + R + 1) / 2;
            if (valid(A, M)) L = M;
            else R = M - 1;
        }
        return L;
    }
};
```