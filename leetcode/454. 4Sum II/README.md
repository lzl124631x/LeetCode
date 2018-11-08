# [454. 4Sum II (Medium)](https://leetcode.com/problems/4sum-ii)

Given four lists A, B, C, D of integer values, compute how many tuples `(i, j, k, l)` there are such that `A[i] + B[j] + C[k] + D[l]` is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

**Example:**

**Input:**  
A = \[ 1, 2\]  
B = \[-2,-1\]  
C = \[-1, 2\]  
D = \[ 0, 2\]  

**Output:**  
2

**Explanation:**  
The two tuples are:  
1. (0, 0, 0, 1) -> A\[0\] + B\[0\] + C\[0\] + D\[1\] = 1 + (-2) + (-1) + 2 = 0  
2. (1, 1, 0, 0) -> A\[1\] + B\[1\] + C\[0\] + D\[0\] = 2 + (-1) + (-1) + 0 = 0  

## Solution 1. Map + Bi-directional Search

Use map to store the counts of different sums in `AB` and `CD`. Use two pointers one from smallest in `AB` going to greater values, and the other one from greatest in `CD` to smaller values. Whenever found a pair summing to 0, add `count1 * count2` to the result.

```cpp
// OJ: https://leetcode.com/problems/4sum-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
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
// Space: O(N)
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