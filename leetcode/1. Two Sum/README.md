# [1. Two Sum (Easy)](https://leetcode.com/problems/two-sum/)

<p>Given an array of integers <code>nums</code>&nbsp;and an integer <code>target</code>, return <em>indices of the two numbers such that they add up to <code>target</code></em>.</p>

<p>You may assume that each input would have <strong><em>exactly</em> one solution</strong>, and you may not use the <em>same</em> element twice.</p>

<p>You can return the answer in any order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,7,11,15], target = 9
<strong>Output:</strong> [0,1]
<strong>Output:</strong> Because nums[0] + nums[1] == 9, we return [0, 1].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,4], target = 6
<strong>Output:</strong> [1,2]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,3], target = 6
<strong>Output:</strong> [0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><strong>Only one valid answer exists.</strong></li>
</ul>

<p>&nbsp;</p>
<strong>Follow-up:&nbsp;</strong>Can you come up with an algorithm that is less than&nbsp;<code>O(n<sup>2</sup>)&nbsp;</code>time complexity?

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Uber](https://leetcode.com/company/uber), [SAP](https://leetcode.com/company/sap), [Cisco](https://leetcode.com/company/cisco), [Paypal](https://leetcode.com/company/paypal), [tcs](https://leetcode.com/company/tcs), [Yahoo](https://leetcode.com/company/yahoo), [Oracle](https://leetcode.com/company/oracle), [Expedia](https://leetcode.com/company/expedia), [Walmart Labs](https://leetcode.com/company/walmart-labs), [VMware](https://leetcode.com/company/vmware), [Intel](https://leetcode.com/company/intel), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Morgan Stanley](https://leetcode.com/company/morgan-stanley)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [3Sum (Medium)](https://leetcode.com/problems/3sum/)
* [4Sum (Medium)](https://leetcode.com/problems/4sum/)
* [Two Sum II - Input array is sorted (Easy)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
* [Two Sum III - Data structure design (Easy)](https://leetcode.com/problems/two-sum-iii-data-structure-design/)
* [Subarray Sum Equals K (Medium)](https://leetcode.com/problems/subarray-sum-equals-k/)
* [Two Sum IV - Input is a BST (Easy)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
* [Two Sum Less Than K (Easy)](https://leetcode.com/problems/two-sum-less-than-k/)
* [Max Number of K-Sum Pairs (Medium)](https://leetcode.com/problems/max-number-of-k-sum-pairs/)
* [Count Good Meals (Medium)](https://leetcode.com/problems/count-good-meals/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        vector<vector<int>> v; 
        int N = A.size(), L = 0, R = N - 1;
        for (int i = 0; i < N; ++i) v.push_back({ A[i], i });
        sort(begin(v), end(v));
        while (L < R) {
            int sum = v[L][0] + v[R][0];
            if (sum == target) return { v[L][1], v[R][1] };
            if (sum < target) ++L;
            else --R;
        }
        return {};
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
            int t = target - A[i];
            if (m.count(t)) return { m[t], i };
            m[A[i]] = i;
        }
        return {};
    }
};
```