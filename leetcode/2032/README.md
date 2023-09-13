# [2032. Two Out of Three (Easy)](https://leetcode.com/problems/two-out-of-three/)

Given three integer arrays <code>nums1</code>, <code>nums2</code>, and <code>nums3</code>, return <em>a <strong>distinct</strong> array containing all the values that are present in <strong>at least two</strong> out of the three arrays. You may return the values in <strong>any</strong> order</em>.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
<strong>Output:</strong> [3,2]
<strong>Explanation:</strong> The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
<strong>Output:</strong> [2,3,1]
<strong>Explanation:</strong> The values that are present in at least two arrays are:
- 2, in nums2 and nums3.
- 3, in nums1 and nums2.
- 1, in nums1 and nums3.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
<strong>Output:</strong> []
<strong>Explanation:</strong> No value is present in at least two arrays.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length, nums3.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums1[i], nums2[j], nums3[k] &lt;= 100</code></li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/two-out-of-three/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(R) where `R` is the range of the numbers in arrays.
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& A, vector<int>& B, vector<int>& C) {
        unordered_set<int> a(begin(A), end(A)), b(begin(B), end(B)), c(begin(C), end(C));
        unordered_map<int, int> cnt;
        for (int n : a) cnt[n]++;
        for (int n : b) cnt[n]++;
        for (int n : c) cnt[n]++;
        vector<int> ans;
        for (auto [n, c] : cnt) {
            if (c >= 2) ans.push_back(n);
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/two-out-of-three/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(R) where `R` is the range of the numbers in arrays.
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& A, vector<int>& B, vector<int>& C) {
        bool seen[3][101] = {};
        for (int n : A) seen[0][n] = true;
        for (int n : B) seen[1][n] = true;
        for (int n : C) seen[2][n] = true;
        vector<int> ans;
        for (int i = 1; i <= 100; ++i) {
            if (seen[0][i] + seen[1][i] + seen[2][i] >= 2) ans.push_back(i);
        }
        return ans;
    }
};
```