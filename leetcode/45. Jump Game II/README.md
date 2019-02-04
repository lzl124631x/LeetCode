# [45. Jump Game II (Hard)](https://leetcode.com/problems/jump-game-ii/)

<p>Given an array of non-negative integers, you are initially positioned at the first index of the array.</p>

<p>Each element in the array represents your maximum jump length at that position.</p>

<p>Your goal is to reach the last index in the minimum number of jumps.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [2,3,1,1,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.</pre>

<p><strong>Note:</strong></p>

<p>You can assume that you can always reach the last index.</p>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Jump Game (Medium)](https://leetcode.com/problems/jump-game/)

## Idea

This problem is asking for **the shortest distance**, so **BFS** should be the first solution we come up with.

The following solutions are variants of BFS.

Normally we use `queue` to keep track of the active indexes. But for this problem, we just need to track the **furthest index we can reach**.

## Solution 1.

Use `vector<int> endsAt` to store the furthest index we can go. `endsAt[i]` means we can reach `endsAt[i]` given `i` steps. It starts with a single 0 at position 0, and will be strictly ascending.

For index `i` &isin; `[0, N - 2]`, use binary search to find the minimum step needed to get to index `i`. Try to use `i + nums[i]` to update `endsAt`.

Eventually, use binary search again to find the minimum step needed to get to `N - 1`.

```cpp
// OJ: https://leetcode.com/problems/jump-game-ii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> endsAt(1, 0);
        for (int i = 0; i < nums.size() - 1; ++i) {
            int step = lower_bound(endsAt.begin(), endsAt.end(), i) - endsAt.begin();
            int next = i + nums[i];
            if (step == endsAt.size() - 1) {
                if (next > endsAt[step]) endsAt.push_back(next);
            } else {
                 if (next > endsAt[step + 1]) endsAt[step + 1] = next;
            }
        }
        return lower_bound(endsAt.begin(), endsAt.end(), nums.size() - 1) - endsAt.begin();
    }
};
```

## Solution 2. BFS + Greedy

In essense, this solution is BFS. It's separating the points into groups that can be reached given different steps.

Let's say given `jumps` jumps, we can reach at most index `jumpsEnd`.

Once the current point reaches `jumpsEnd`, we have to trigger another jump to extend `jumpsEnd`. And `jumpsEnd` should extend to `furthest` which is the fursthest index we can jump to given the points between index `0` and `jumpsEnd`.

Keep the above steps for points `[0..(N - 1)]`:

```cpp
// OJ: https://leetcode.com/problems/jump-game-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, jumpsEnd = 0, furthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            furthest = max(furthest, i + nums[i]);
            if (i == jumpsEnd) {
                ++jumps;
                jumpsEnd = furthest;
            }
        }
        return jumps;
    }
};
```