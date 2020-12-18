# [454. 4Sum II (Medium)](https://leetcode.com/problems/4sum-ii/)

<p>Given four lists A, B, C, D of integer values, compute how many tuples <code>(i, j, k, l)</code> there are such that <code>A[i] + B[j] + C[k] + D[l]</code> is zero.</p>

<p>To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -2<sup>28</sup> to 2<sup>28</sup> - 1 and the result is guaranteed to be at most 2<sup>31</sup> - 1.</p>

<p><b>Example:</b></p>

<pre><b>Input:</b>
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

<b>Output:</b>
2

<b>Explanation:</b>
The two tuples are:
1. (0, 0, 0, 1) -&gt; A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -&gt; A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
</pre>

<p>&nbsp;</p>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Binary Search](https://leetcode.com/tag/binary-search/)

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
        if (A.empty()) return 0;
        int N = A.size(), cnt = 0;
        unordered_map<int, int> AB, CD;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                AB[A[i] + B[j]]++;
                CD[C[i] + D[j]]++; 
            }
        }
        for (auto it = AB.begin(); it != AB.end(); ++it) {
            cnt += it->second * CD[-it->first];
        }
        return cnt;
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