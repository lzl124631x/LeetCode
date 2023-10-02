# [954. Array of Doubled Pairs (Medium)](https://leetcode.com/problems/array-of-doubled-pairs/)

<p>Given an integer array of even length <code>arr</code>, return <code>true</code><em> if it is possible to reorder </em><code>arr</code><em> such that </em><code>arr[2 * i + 1] = 2 * arr[2 * i]</code><em> for every </em><code>0 &lt;= i &lt; len(arr) / 2</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [3,1,3,6]
<strong>Output:</strong> false
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [2,1,2,6]
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [4,-2,2,-4]
<strong>Output:</strong> true
<strong>Explanation:</strong> We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,4,16,8,4]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>arr.length</code> is even.</li>
	<li><code>-10<sup>5</sup> &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Find Original Array From Doubled Array (Medium)](https://leetcode.com/problems/find-original-array-from-doubled-array/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/array-of-doubled-pairs/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        multiset<int> s(A.begin(), A.end());
        while (s.size()) {
            int val = *s.begin();
            if (val < 0 && val % 2) return false;
            int next = val >= 0 ? val * 2 : val / 2;
            s.erase(s.begin());
            auto it = s.find(next);
            if (it == s.end()) return false;
            s.erase(it);
        }
        return true;
    }
};
```

## Solution 2. Frequency Map

```cpp
// OJ: https://leetcode.com/problems/array-of-doubled-pairs/
// Author: github.com/lzl124631x
// Time: O(N + KlogK) where `K` is the number of unique elements in `A`.
// Space: O(K)
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        vector<int> nums;
        for (auto [n, cnt] : m) nums.push_back(n);
        sort(begin(nums), end(nums), [&](int a, int b) { return abs(a) < abs(b); });
        for (int n : nums) {
            if (m[2 * n] < m[n]) return false;
            m[2 * n] -= m[n];
        }
        return true;
    }
};
```