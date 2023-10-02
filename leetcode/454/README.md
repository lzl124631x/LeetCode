# [454. 4Sum II (Medium)](https://leetcode.com/problems/4sum-ii/)

<p>Given four integer arrays <code>nums1</code>, <code>nums2</code>, <code>nums3</code>, and <code>nums4</code> all of length <code>n</code>, return the number of tuples <code>(i, j, k, l)</code> such that:</p>

<ul>
	<li><code>0 &lt;= i, j, k, l &lt; n</code></li>
	<li><code>nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The two tuples are:
1. (0, 0, 0, 1) -&gt; nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -&gt; nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>n == nums2.length</code></li>
	<li><code>n == nums3.length</code></li>
	<li><code>n == nums4.length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>-2<sup>28</sup> &lt;= nums1[i], nums2[i], nums3[i], nums4[i] &lt;= 2<sup>28</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [4Sum (Medium)](https://leetcode.com/problems/4sum/)

## Solution 1. Map + Bi-directional Search

Use map to store the counts of different sums in `AB` and `CD`. Use two pointers one from smallest in `AB` going to greater values, and the other one from greatest in `CD` to smaller values. Whenever found a pair summing to 0, add `count1 * count2` to the result.

### Time complexity

The `sum` function iterates through `O(N^2)` pairs and accessing the `map` at most take `O(log(N^2))=O(logN)` time. So the `sum` takes `O(N^2 * logN)` time.

Each `map` has `O(N^2)` data in the worst case and the bi-directional search only traverse each map once at most, so the searching takes `O(N^2)` time.

So, overall it takes `O(N^2 * logN)` time.

```cpp
// OJ: https://leetcode.com/problems/4sum-ii
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N^2)
class Solution {
private:
    void sum(vector<int> &A, vector<int> &B, map<int, int> &m) {
        for (auto a : A) {
            for (auto b : B) m[a + b]++;
        }
    }
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> a, b;
        sum(A, B, a);
        sum(C, D, b);
        auto i = a.begin();
        auto j = b.rbegin();
        int ans = 0;
        while (i != a.end() && j != b.rend()) {
            if (i->first + j->first == 0) {
                ans += i->second * j->second;
                ++i;
                ++j;
            } else if (i->first + j->first < 0) ++i;
            else ++j;
        }
        return ans;
    }
};
```

## Solution 2. Two unordered_map

Similar to Solution 1, but use `unordered_map` instead. Loop through one of it, and find if the counterpart exists.

```cpp
// OJ: https://leetcode.com/problems/4sum-ii
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N = A.size(), ans = 0;
        unordered_map<int, int> a, b;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a[A[i] + B[j]]++;
                b[C[i] + D[j]]++;
            }
        } 
        for (auto &[m, cnt] : a) {
            if (b.count(-m)) ans += cnt * b[-m];
        }
        return ans;
    }
};
```

## Solution 3. One unordered_map

```cpp
// OJ: https://leetcode.com/problems/4sum-ii
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        for (auto a : A) {
            for (auto b : B) m[a + b]++;
        }
        int cnt = 0;
        for (auto c : C) {
            for (auto d : D) {
                if (m.find(-c - d) != m.end()) {
                    cnt += m[-c - d];
                }
            }
        }
        return cnt;
    }
};
```