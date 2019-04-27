# [89. Gray Code (Medium)](https://leetcode.com/problems/gray-code/)

<p>The gray code is a binary numeral system where two successive values differ in only one bit.</p>

<p>Given a non-negative integer <em>n</em> representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong>&nbsp;2
<strong>Output:</strong>&nbsp;<code>[0,1,3,2]</code>
<strong>Explanation:</strong>
00 - 0
01 - 1
11 - 3
10 - 2

For a given&nbsp;<em>n</em>, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>&nbsp;0
<strong>Output:</strong>&nbsp;<code>[0]
<strong>Explanation:</strong> We define the gray code sequence to begin with 0.
&nbsp;            A gray code sequence of <em>n</em> has size = 2<sup>n</sup>, which for <em>n</em> = 0 the size is 2<sup>0</sup> = 1.
&nbsp;            Therefore, for <em>n</em> = 0 the gray code sequence is [0].</code>
</pre>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/gray-code/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
private:
    inline int toggle(int n, int i) {
        return n ^ (1 << i);
    }
    int next(int n, unordered_set<int> s) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans = toggle(n, i);
            if (s.find(ans) == s.end()) break;
        }
        return ans;
    }
public:
    vector<int> grayCode(int n) {
        unordered_set<int> s{0};
        vector<int> ans(pow(2, n), 0);
        for (int i = 1; i < ans.size(); ++i) {
            s.insert(ans[i] = next(ans[i - 1], s));
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/gray-code/
// Author: github.com/lzl124631x
// Time: O(2^(N-1))
// Space: O(1)
class Solution {
public:
    vector<int> grayCode(int n) {
        int N = (1 << n);
        vector<int> ans(N, 0);
        for (int i = 0; true; ++i) {
            int j = (1 << i), d = (1 << (i + 1));
            if (j >= N) break;
            for (; j < N; j += 2 * d) {
                for (int k = j; k < N && k < j + d; ++k) ans[k] |= (1 << i);
            }
        }
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/gray-code/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(1)
class Solution {
private:
    inline int toggle(int val, int i) {
        return val ^ (1 << i);
    }
    void grayCode(int n, int &val, vector<int> &v){
        if (n < 0) return;
        grayCode(n - 1, val, v);
        val = toggle(val, n);
        v.push_back(val);
        grayCode(n - 1, val, v);
    }
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        int val = 0;
        v.push_back(val);
        grayCode(n - 1, val, v);
        return v;
    }
};
```