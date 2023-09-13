# [39. Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)

<p>Given an array of <strong>distinct</strong> integers <code>candidates</code> and a target integer <code>target</code>, return <em>a list of all <strong>unique combinations</strong> of </em><code>candidates</code><em> where the chosen numbers sum to </em><code>target</code><em>.</em> You may return the combinations in <strong>any order</strong>.</p>

<p>The <strong>same</strong> number may be chosen from <code>candidates</code> an <strong>unlimited number of times</strong>. Two combinations are unique if the frequency of at least one of the chosen numbers is different.</p>

<p>It is <strong>guaranteed</strong> that the number of unique combinations that sum up to <code>target</code> is less than <code>150</code> combinations for the given input.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> candidates = [2,3,6,7], target = 7
<strong>Output:</strong> [[2,2,3],[7]]
<strong>Explanation:</strong>
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> candidates = [2,3,5], target = 8
<strong>Output:</strong> [[2,2,2,2],[2,3,3],[3,5]]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> candidates = [2], target = 1
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= candidates.length &lt;= 30</code></li>
	<li><code>1 &lt;= candidates[i] &lt;= 200</code></li>
	<li>All elements of <code>candidates</code> are <strong>distinct</strong>.</li>
	<li><code>1 &lt;= target &lt;= 500</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Airbnb](https://leetcode.com/company/airbnb), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Snapchat](https://leetcode.com/company/snapchat), [Adobe](https://leetcode.com/company/adobe), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Salesforce](https://leetcode.com/company/salesforce)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Letter Combinations of a Phone Number (Medium)](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
* [Combination Sum II (Medium)](https://leetcode.com/problems/combination-sum-ii/)
* [Combinations (Medium)](https://leetcode.com/problems/combinations/)
* [Combination Sum III (Medium)](https://leetcode.com/problems/combination-sum-iii/)
* [Factor Combinations (Medium)](https://leetcode.com/problems/factor-combinations/)
* [Combination Sum IV (Medium)](https://leetcode.com/problems/combination-sum-iv/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/combination-sum
// Author: github.com/lzl124631x
// Time: O(N^(T/M+1)) where N is the length of A, T is target and M is the minimum value of A[i]
// Space: O(T/M)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        function<void(int, int)> dfs = [&](int i, int target) {
            if (target == 0) {
                ans.push_back(tmp);
                return;
            }
            if (i == A.size()) return;
            int cnt = 0;
            do {
                dfs(i + 1, target);
                tmp.push_back(A[i]);
                target -= A[i];
                ++cnt;
            } while (target >= 0);
            while (cnt-- > 0) tmp.pop_back();
        };
        dfs(0, target);
        return ans;
    }
};
```

## Solution 2. Backtracking

```cpp
// OJ: https://leetcode.com/problems/combination-sum
// Author: github.com/lzl124631x
// Time: O(N^(T/M+1)) where N is the length of A, T is target and M is the minimum value of A[i]
// Space: O(T/M)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        function<void(int, int)> dfs = [&](int start, int target) {
            if (target == 0) {
                ans.push_back(tmp);
            } else if (target < 0) return;
            for (int i = start; i < A.size(); ++i) {
                tmp.push_back(A[i]);
                dfs(i, target - A[i]);
                tmp.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/combination-sum/
// Author: github.com/lzl124631x
// Time: O(N^(T/M+1)) where N is the length of A, T is target and M is the minimum value of A[i]
// Space: O(T/M)
// Ref: https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(begin(A), end(A)); // sorting is a must for this algorithm
        function<void(int, int)> dfs = [&](int start, int target) {
            if (target == 0) {
                ans.push_back(tmp);
            }
            for (int i = start; i < A.size() && target - A[i] >= 0; ++i) {
                tmp.push_back(A[i]);
                dfs(i, target - A[i]);
                tmp.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
```