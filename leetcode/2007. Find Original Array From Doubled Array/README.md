# [2007. Find Original Array From Doubled Array (Medium)](https://leetcode.com/problems/find-original-array-from-doubled-array/)

<p>An integer array <code>original</code> is transformed into a <strong>doubled</strong> array <code>changed</code> by appending <strong>twice the value</strong> of every element in <code>original</code>, and then randomly <strong>shuffling</strong> the resulting array.</p>

<p>Given an array <code>changed</code>, return <code>original</code><em> if </em><code>changed</code><em> is a <strong>doubled</strong> array. If </em><code>changed</code><em> is not a <strong>doubled</strong> array, return an empty array. The elements in</em> <code>original</code> <em>may be returned in <strong>any</strong> order</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> changed = [1,3,4,2,6,8]
<strong>Output:</strong> [1,3,4]
<strong>Explanation:</strong> One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> changed = [6,3,0,1]
<strong>Output:</strong> []
<strong>Explanation:</strong> changed is not a doubled array.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> changed = [1]
<strong>Output:</strong> []
<strong>Explanation:</strong> changed is not a doubled array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= changed.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= changed[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Array of Doubled Pairs (Medium)](https://leetcode.com/problems/array-of-doubled-pairs/)

## Solution 1. Frequency Map

Sort the array `A`. Keep removing the smallest element `n` and `2 * n` from the array, and put `n` into the answer until `A` becomes empty. Anytime we can't do the removal, we return empty array.

We can keep a frequency map in `map<int, int> m`, and remove elements of the same value in batch.

```cpp
// OJ: https://leetcode.com/problems/find-original-array-from-doubled-array/
// Author: github.com/lzl124631x
// Time: O(NlogK) where `N` is the length of `A`, and `K` is the number of unique elements in `A`
// Space: O(N)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& A) {
        if (A.size() % 2) return {};
        map<int, int> m; // a frequency map
        for (int n : A) m[n]++;
        vector<int> ans;
        while (m.size()) {
            auto [n, cnt] = *m.begin();
            if (n == 0) {
                if (cnt % 2) return {}; // count of `0` is odd.
                for (int j = 0; j < cnt / 2; ++j) ans.push_back(0);
                m.erase(0);
            } else {
                if (m[2 * n] < cnt) return {}; // not enough `2n` available.
                m.erase(n);
                for (int j = 0; j < cnt; ++j) ans.push_back(n);
                m[2 * n] -= cnt;
                if (m[2 * n] == 0) m.erase(2 * n);
            }
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/find-original-array-from-doubled-array/
// Author: github.com/lzl124631x
// Time: O(NlogK) where `N` is the length of `A`, and `K` is the number of unique elements in `A`
// Space: O(N)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& A) {
        if (A.size() % 2) return {};
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        vector<int> nums;
        for (auto [n, cnt] : m) nums.push_back(n);
        sort(begin(nums), end(nums));
        vector<int> ans;
        for (int n : nums) {
            if (m[2 * n] < m[n]) return {};
            for (int i = 0; i < m[n]; ++i, --m[2 * n]) ans.push_back(n);
        }
        return ans;
    }
};
```