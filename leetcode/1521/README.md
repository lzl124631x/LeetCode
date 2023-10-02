# [1521. Find a Value of a Mysterious Function Closest to Target (Hard)](https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/)

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/07/09/change.png" style="width: 635px; height: 312px;"></p>

<p>Winston was given the above mysterious function <code>func</code>. He has an integer array <code>arr</code> and an integer <code>target</code> and he wants to find the values&nbsp;<code>l</code> and <code>r</code>&nbsp;that make&nbsp;the value <code>|func(arr, l, r) - target|</code> minimum possible.</p>

<p>Return <em>the minimum possible value</em> of <code>|func(arr, l, r) - target|</code>.</p>

<p>Notice that <code>func</code> should be called with the values&nbsp;<code>l</code> and <code>r</code> where <code>0 &lt;= l, r &lt; arr.length</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [9,12,3,7,15], target = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> Calling func with all the pairs of [l,r] = [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]], Winston got the following results [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0]. The value closest to 5 is 7 and 3, thus the minimum difference is 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1000000,1000000,1000000], target = 1
<strong>Output:</strong> 999999
<strong>Explanation:</strong> Winston called the func with all possible values of [l,r] and he always got 1000000, thus the min difference is 999999.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,4,8,16], target = 0
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^6</code></li>
	<li><code>0 &lt;= target &lt;= 10^7</code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Segment Tree](https://leetcode.com/tag/segment-tree/)

## Solution 1. Brute force

The `func`  funciton is calculating the result of applying bitwise `and` operation on all the elements between `arr[l]` and `arr[r]` inclusive.

Note that when we apply bitwise `and` operation from left to right, the result value is monotonically decreasing since whenever a bit `0` is met, that bit will no longer be set back to `1`. 

So we can have two insights:

* Once the result is `0`, we don't need to continue calculating more elements.
* We only need to keep calculating if the `and` result is greater than or equal to `target` because:
  * If the result is greater than or equal to `target`, we can keep calculating the result since decreased result will get closer to `target`.
  * If the result is less than `target`, we don't need to continue calculating because the difference between it and the `target` will only increase.

```cpp
// OJ: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int closestToTarget(vector<int>& A, int target) {
        int N = A.size(), ans = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && A[i] == A[i - 1]) continue;
            int func = A[i];
            ans = min(ans, abs(func - target));
            for (int j = i + 1; j < N && func && func >= target; ++j) {
                func &= A[j];
                ans = min(ans, abs(func - target));
            }
            if (ans == 0) return 0;
        }
        return ans;
    }
};
```

Or 

```cpp
// OJ: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int closestToTarget(vector<int>& A, int target) {
        int N = A.size(), ans = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && A[i] == A[i - 1]) continue;
            int func = A[i];
            for (int j = i; j < N; ++j) {
                func &= A[j];
                ans = min(ans, abs(func - target));
                if (func <= target) break;
            }
            if (func >= target) break; // if the result is greater than or equal to `target`, the best result we can get in the next loop must be greater than the current result, so the difference can only increase, we can break here.
        }
        return ans;
    }
};
```

## Solution 2.

Note that using `set` is more performant than `unordered_set` here. It's because `unordered_set` initialization has greater overhead.

```cpp
// OJ: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
// Author: github.com/lzl124631x
// Time: O(N(logM)^2) where M is the maximum element in A
// Space: O(logM)
// Ref: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/discuss/743381/Python-6-lines-O(nlogm)-solution
class Solution {
public:
    int closestToTarget(vector<int>& A, int target) {
        set<int> s;
        int ans = INT_MAX;
        for (int n : A) {
            set<int> next{n};
            for (int m : s) {
                if ((m & n) < target) continue;
                next.insert(m & n);
            }
            for (int val : next) ans = min(ans, abs(val - target));
            if (ans == 0) return 0;
            swap(s, next);
        }
        return ans;
    }
};
```

Since there are only `log(M)` elements in the set, we can even use `vector<int>` to store the values.

```cpp
// OJ: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
// Author: github.com/lzl124631x
// Time: O(N * logM * loglogM)
// Space: O(logM)
class Solution {
public:
    int closestToTarget(vector<int>& A, int target) {
        vector<int> s;
        int ans = INT_MAX;
        for (int n : A) {
            vector<int> next{ n };
            for (int m : s) {
                if ((m & n) < target) continue;
                next.push_back(m & n);
            }
            sort(begin(next), end(next));
            next.resize(unique(begin(next), end(next)) - begin(next));
            swap(s, next);
            ans = min(ans, abs(s.front() - target));
        }
        return ans;
    }
};
```