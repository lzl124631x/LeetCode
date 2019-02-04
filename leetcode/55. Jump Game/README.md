# [55. Jump Game (Medium)](https://leetcode.com/problems/jump-game/)

<p>Given an array of non-negative integers, you are initially positioned at the first index of the array.</p>

<p>Each element in the array represents your maximum jump length at that position.</p>

<p>Determine if you are able to reach the last index.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [2,3,1,1,4]
<strong>Output:</strong> true
<strong>Explanation:</strong> Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [3,2,1,0,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> You will always arrive at index 3 no matter what. Its maximum
&nbsp;            jump length is 0, which makes it impossible to reach the last index.
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Jump Game II (Hard)](https://leetcode.com/problems/jump-game-ii/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/jump-game/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    vector<bool> visited;
    bool dfs(vector<int> &nums, int start) {
        if (visited[start]) return false;
        visited[start] = true;
        if (start + nums[start] >= nums.size() - 1) return true;
        for (int i = nums[start]; i >= 0; --i) {
            if (dfs(nums, start + i)) return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        visited = vector<bool>(nums.size());
        return dfs(nums, 0);
    }
};
```

## Solution 2. Greedy

```cpp
// OJ: https://leetcode.com/problems/jump-game/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > last) return false;
            last = max(last, i + nums[i]);
        }
        return true;
    }
};
```