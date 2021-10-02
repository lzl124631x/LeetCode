# [992. Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers/)

<p>Given an array <code>A</code> of positive integers, call a (contiguous, not necessarily distinct) subarray of <code>A</code> <em>good</em> if the number of different integers in that subarray is exactly <code>K</code>.</p>

<p>(For example, <code>[1,2,3,1,2]</code> has <code>3</code> different integers: <code>1</code>, <code>2</code>, and <code>3</code>.)</p>

<p>Return the number of good subarrays of <code>A</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">[1,2,1,2,3]</span>, K = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">7</span>
<strong>Explanation: </strong>Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">[1,2,1,3,4]</span>, K = <span id="example-input-2-2">3</span>
<strong>Output: </strong><span id="example-output-2">3</span>
<strong>Explanation: </strong>Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 20000</code></li>
	<li><code>1 &lt;= A[i] &lt;= A.length</code></li>
	<li><code>1 &lt;= K &lt;= A.length</code></li>
</ol>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [Longest Substring with At Most Two Distinct Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
* [Longest Substring with At Most K Distinct Characters (Hard)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)

## Solution 1. Sliding Window

Use `[i, j)` as a sliding window to find the maximum window which contains no more than `K` unique elements.

To achieve this, we use a map `m` to store the last position of each number in the current window.

When `m.size() > K`, we should move forward `i` to shrink the window until it become valid again.

When `m.size() == K`, `[i, j)` is the maximum window we are looking for. 

Within this maximum window `[i, j)`, there is a minimum window `[k, j)` containing no more than `K` unique elements. `k` is the minimal index in `m`.

Now, the number of valid subarrays in this window is `k - i + 1`.

Since `k` is monotonically increasing and must be no less than `i`, we can use `k` as a global pointer just like `i` and `j` so that the overall time complexity of moving `k` is `O(N)`.

Whenever `m.size() == K`, we can move `k` forward until `m[A[k] - '0'] == k`, and add `k - i + 1` to the answer.

```cpp
// OJ: https://leetcode.com/problems/subarrays-with-k-different-integers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int ans = 0, i = 0, j = 0, k = 0, N = A.size();
        unordered_map<int, int> m;
        while (j < N) {
            m[A[j] - '0'] = j;
            ++j;
            while (m.size() > K) {
                int d = A[i++] - '0';
                if (m[d] < i) m.erase(d);
            }
            if (m.size() == K) {
                k = max(i, k);
                while (m[A[k] - '0'] != k) ++k;
                ans += k - i + 1;
            }
        }
        return ans;
    }
};
```

## Solution 2. Shrinkable Sliding Window

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)" which can help you solve all sliding window problems.

We can turn this problem into two find maximum sliding window problem: one is to find a window with at most `k` different integers, another is to find a window with at most `k - 1` different integers.

```cpp
// OJ: https://leetcode.com/problems/subarrays-with-k-different-integers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(U) where U is the number of unique numbers in `A`
class Solution {
    int atMost(vector<int> &A, int k) {
        int distinct = 0, i = 0, j = 0, N = A.size(), ans = 0;
        unordered_map<int, int> cnt;
        for (; j < N; ++j) {
            distinct += ++cnt[A[j]] == 1;
            while (distinct > k) distinct -= --cnt[A[i++]] == 0;
            ans += j - i;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
    }
};
```