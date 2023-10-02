# [1982. Find Array Given Subset Sums (Hard)](https://leetcode.com/problems/find-array-given-subset-sums/)

<p>You are given an integer <code>n</code> representing the length of an unknown array that you are trying to recover. You are also given an array <code>sums</code> containing the values of all <code>2<sup>n</sup></code> <strong>subset sums</strong> of the unknown array (in no particular order).</p>

<p>Return <em>the array </em><code>ans</code><em> of length </em><code>n</code><em> representing the unknown array. If <strong>multiple</strong> answers exist, return <strong>any</strong> of them</em>.</p>

<p>An array <code>sub</code> is a <strong>subset</strong> of an array <code>arr</code> if <code>sub</code> can be obtained from <code>arr</code> by deleting some (possibly zero or all) elements of <code>arr</code>. The sum of the elements in <code>sub</code> is one possible <strong>subset sum</strong> of <code>arr</code>. The sum of an empty array is considered to be <code>0</code>.</p>

<p><strong>Note:</strong> Test cases are generated such that there will <strong>always</strong> be at least one correct answer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 3, sums = [-3,-2,-1,0,0,1,2,3]
<strong>Output:</strong> [1,2,-3]
<strong>Explanation: </strong>[1,2,-3] is able to achieve the given subset sums:
- []: sum is 0
- [1]: sum is 1
- [2]: sum is 2
- [1,2]: sum is 3
- [-3]: sum is -3
- [1,-3]: sum is -2
- [2,-3]: sum is -1
- [1,2,-3]: sum is 0
Note that any permutation of [1,2,-3] and also any permutation of [-1,-2,3] will also be accepted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, sums = [0,0,0,0]
<strong>Output:</strong> [0,0]
<strong>Explanation:</strong> The only correct answer is [0,0].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
<strong>Output:</strong> [0,-1,4,5]
<strong>Explanation:</strong> [0,-1,4,5] is able to achieve the given subset sums.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
	<li><code>sums.length == 2<sup>n</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= sums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Similar Questions**:
* [Subsets (Medium)](https://leetcode.com/problems/subsets/)
* [Subsets II (Medium)](https://leetcode.com/problems/subsets-ii/)

## Solution 1.

**Intuition**: If all the numbers in the unknown array are non-negative, it's easy to solve because `A[0]` must be `0` (empty set) and `A[1]` must be a number in the unknown array.

**Hint**: 
* **Step 1**: Solve the problem knowning that the unknown array only has non-negative numbers.
* **Step 2**: Find a subset in the answer array whose sum is the minimal value in `A`, and turn all the numbers in this subset negative

**Algorithm**:

Let `mn` be the minimal number in `A`. We offset all the numbers in `A` by `-mn`, making all the numbers in `A` non-negative.

**Step 1**:

We store all the numbers in a `multiset<int> s`.

Now we can repeat the following process to get the unknown array:
1. Take the 2nd smallest element (say `num`) as a number in the answer `ans`.
2. Keep moving the first element (say `first`) from `s` to a new `multiset<int> tmp`, and removing `first + num` from `s`, until `s` becomes empty.
3. Now `tmp` contains all the subset sums that are formed with the rest of the unknown numbers. This `tmp` becomes the new `s`.
4. We repeat this process `n` times to fill `n` numbers into `ans`.

Now we get an array `ans` corresponding to the unknown array of the original `A` with offset `-mn`.

**Step 2**:

We know that `mn` is the sum of all the negative numbers, so now our goal is to find a subset in `ans` whose sum is `-mn`. And then we just need to make all the numbers in the subset negative. We can solve this using a backtracking DFS.

### Complexity Analysis

`O(2^N)` time for getting the minimal numbers in `A` and offsetting every number in `A` by `-mn`.

Initiallizing `multiset<int> s` takes `O(2^N * log(2^N)) = O(2^N * N)` time, and `O(2^N)` space.

Within the `for` loop, we at most go through `2^N` elements in `s` and take `O(log(2^N)) = O(N)` time to move/remove an element from the multiset. So each round takes `O(2^N * N)` times. Since we need to repeat `N` times, the overall time complexity is `O(2^N * N^2)`.

The step 2 takes `O(2^N)` time and `O(N)` space, because we have `N` numbers and each of which has two options, inverting or not.

So, overall this algorithm has time complexity `O(2^N * N^2)` and space complexity `O(2^N)`.

```cpp
// OJ: https://leetcode.com/problems/find-array-given-subset-sums/
// Author: github.com/lzl124631x
// Time: O(2^N * N^2)
// Space: O(2^N)
class Solution {
    bool dfs(vector<int> &ans, int target, int i) {
        if (i == ans.size()) return target == 0;
        int n = ans[i];
        if (dfs(ans, target, i + 1)) return true; // if we don't invert this number
        ans[i] = -n;
        if (dfs(ans, target - n, i + 1)) return true; // if we invert this number
        ans[i] = n;
        return false;
    }
public:
    vector<int> recoverArray(int n, vector<int>& A) {
        int mn = *min_element(begin(A), end(A)); // `mn` must be the sum of all the negative numbers in `A`.
        for (int &n : A) n += -mn; // offset all the numbers by -mn, so that all the numbers in `A` are non-negative.
        multiset<int> s(begin(A), end(A)), tmp;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            tmp.clear();
            int num = *next(s.begin()); // the 2nd number in the sorted subset sums must be a number in the answer
            ans.push_back(num);
            while (s.size()) {
                int first = *s.begin(); // `first` is a subset sum without `num`. We leave it for the next round.
                tmp.insert(first);
                s.erase(s.begin());
                s.erase(s.find(first + num)); // `first + num` is a subset sum with `num` which should be ignored going forward.
            }
            swap(s, tmp);
        }
        dfs(ans, -mn, 0); // Find a subset in `ans` whose sum is `-mn`. Invert all the numbers in this subset.
        return ans;
    }
};
```

Anthor way to recover the original array without using `multiset`.

```cpp
// OJ: https://leetcode.com/problems/find-array-given-subset-sums/
// Author: github.com/lzl124631x
// Time: O(2^N * N)
// Space: O(2^N)
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& A) {
        sort(begin(A), end(A));
        int mn = A[0];
        for (int &n : A) n -= mn;
        vector<int> ans, next;
        while (n--) {
            int num = A[1], j = 0;
            next.clear();
            for (int i = 0; i < A.size(); ++i) {
                if (j < next.size() && A[i] == next[j] + num) ++j;
                else next.push_back(A[i]);
            }
            ans.push_back(num);
            swap(next, A);
        }
        function<bool(int, int)> dfs = [&](int sum, int i) {
            if (sum == 0) return true;
            if (i == ans.size()) return false;
            int num = ans[i];
            ans[i] = -num;
            if (dfs(sum - num, i + 1)) return true;
            ans[i] = num;
            return dfs(sum, i + 1);
        };
        dfs(-mn, 0);
        return ans;
    }
};
```

## Solution 2.


```cpp
// OJ: https://leetcode.com/problems/find-array-given-subset-sums/
// Author: github.com/lzl124631x
// Time: O(2^N * N)
// Space: O(2^N)
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& A) {
        sort(begin(A), end(A));
        int len = A.size();
        vector<int> left(len / 2), right(len / 2), ans(n);
        for (int i = 0; i < n; ++i) {
            int diff = A[1] - A[0], p = 0, q = 0, k = 0;
            bool zero = false;
            for (int j = 0; j < len; ++j) {
                if (k < q && right[k] == A[j]) ++k;
                else {
                    if (A[j] == 0) zero = true;
                    left[p++] = A[j];
                    right[q++] = A[j] + diff;
                }
            }
            if (zero) {
                swap(left, A);
                ans[i] = diff;
            } else {
                swap(right, A);
                ans[i] = -diff;
            }
            len /= 2;
        }
        return ans;
    }
};
```