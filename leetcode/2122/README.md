# [2122. Recover the Original Array (Hard)](https://leetcode.com/problems/recover-the-original-array/)

<p>Alice had a <strong>0-indexed</strong> array <code>arr</code> consisting of <code>n</code> <strong>positive</strong> integers. She chose an arbitrary <strong>positive integer</strong> <code>k</code> and created two new <strong>0-indexed</strong> integer arrays <code>lower</code> and <code>higher</code> in the following manner:</p>

<ol>
	<li><code>lower[i] = arr[i] - k</code>, for every index <code>i</code> where <code>0 &lt;= i &lt; n</code></li>
	<li><code>higher[i] = arr[i] + k</code>, for every index <code>i</code> where <code>0 &lt;= i &lt; n</code></li>
</ol>

<p>Unfortunately, Alice lost all three arrays. However, she remembers the integers that were present in the arrays <code>lower</code> and <code>higher</code>, but not the array each integer belonged to. Help Alice and recover the original array.</p>

<p>Given an array <code>nums</code> consisting of <code>2n</code> integers, where <strong>exactly</strong> <code>n</code> of the integers were present in <code>lower</code> and the remaining in <code>higher</code>, return <em>the <strong>original</strong> array</em> <code>arr</code>. In case the answer is not unique, return <em><strong>any</strong> valid array</em>.</p>

<p><strong>Note:</strong> The test cases are generated such that there exists <strong>at least one</strong> valid array <code>arr</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,10,6,4,8,12]
<strong>Output:</strong> [3,7,11]
<strong>Explanation:</strong>
If arr = [3,7,11] and k = 1, we get lower = [2,6,10] and higher = [4,8,12].
Combining lower and higher gives us [2,6,10,4,8,12], which is a permutation of nums.
Another valid possibility is that arr = [5,7,9] and k = 3. In that case, lower = [2,4,6] and higher = [8,10,12]. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,3,3]
<strong>Output:</strong> [2,2]
<strong>Explanation:</strong>
If arr = [2,2] and k = 1, we get lower = [1,1] and higher = [3,3].
Combining lower and higher gives us [1,1,3,3], which is equal to nums.
Note that arr cannot be [1,3] because in that case, the only possible way to obtain [1,1,3,3] is with k = 0.
This is invalid since k must be positive.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [5,435]
<strong>Output:</strong> [220]
<strong>Explanation:</strong>
The only possible combination is arr = [220] and k = 215. Using them, we get lower = [5] and higher = [435].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 * n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>The test cases are generated such that there exists <strong>at least one</strong> valid array <code>arr</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/), [Enumeration](https://leetcode.com/tag/enumeration/)

**Similar Questions**:
* [Find Array Given Subset Sums (Hard)](https://leetcode.com/problems/find-array-given-subset-sums/)
* [Find Original Array From Doubled Array (Medium)](https://leetcode.com/problems/find-original-array-from-doubled-array/)

## Solution 1.

First sort the array.

The idea is to simply use `A[0]` as the smallest element in `lower` and try each `A[i] (1 <= i <= N)` as the corresponding element in `higher`.

But the implementation can easily get TLE. We need to use tricks to speed it up.

1. We might many duplicate `k`s. Use set to dedup them.
2. To further narrow down, we use `A.back()` as the largest element in `higher` and try each `A[i] (N-1 <= i < A.size()-1)` as the corresponding element in `lower`.

```cpp
// OJ: https://leetcode.com/problems/recover-the-original-array/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
class Solution {
public:
    vector<int> recoverArray(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size() / 2;
        unordered_set<int> ks, ks2; // Dedup `k`s using set.
        for (int i = 1; i <= N; ++i) { // Generate possible `k`s: Use A[0] as the smallest element in lower. Try each A[i] (1 <= i <= N) as the corresponding element in higher.
            int d = A[i] - A[0];
            if (d && d % 2 == 0) ks.insert(d / 2);
        }
        for (int i = N - 1; i < A.size() - 1; ++i) { // Narrow down: Use A.back() as the largest element in higher. Try each A[i] (N-1 <= i < A.size()-1) as the corresponding element in lower.
            int d = A.back() - A[i];
            if (d % 2 == 0 && ks.count(d / 2)) ks2.insert(d / 2);
        }
        vector<int> ans;
        ans.reserve(N);
        for (int k : ks2) {
            multiset<int> s(begin(A), end(A));
            ans.clear();
            while (s.size()) {
                int a = *s.begin();
                s.erase(s.begin());
                auto it = s.find(a + 2 * k);
                if (it == s.end()) break;
                s.erase(it);
                ans.push_back(a + k);
            }
            if (s.empty()) return ans;
        }
        return {};
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/recover-the-original-array/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<int> recoverArray(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size() / 2;
        vector<int> ans;
        ans.reserve(N);
        for (int i = 1; i <= N + 1; ++i) {
            int k = A[i] - A[0];
            if (k == 0 || k % 2) continue;
            k /= 2;
            ans.clear();
            int pos = 0;
            for (int j = 0; j < A.size(); ++j) {
                if (pos == ans.size()) ans.push_back(A[j] + k);
                else {
                    int d = A[j] - ans[pos];
                    if (d == k) ++pos;
                    else if (d < k) ans.push_back(A[j] + k);
                    else break;
                }
            }
            if (pos == N) return ans;
        }
        return {};
    }
};
```