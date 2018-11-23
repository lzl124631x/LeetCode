# [659. Split Array into Consecutive Subsequences (Medium)](https://leetcode.com/problems/split-array-into-consecutive-subsequences/)

<p>You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1,2,3,3,4,5]
<b>Output:</b> True
<b>Explanation:</b>
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [1,2,3,3,4,4,5,5]
<b>Output:</b> True
<b>Explanation:</b>
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
</pre>
<p></p>

<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> [1,2,3,4,4,5]
<b>Output:</b> False
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The length of the input is in range of [1, 10000]</li>
</ol>
<p></p>

## Solution 1. Greedy

Keep the count of numbers in `map` `m`.

Scan from the smallest number in `m`, and decrement the count of the current number. We stop the scanning when we meet:
1. The end of `m`
2. Or, the number doesn't equal the previous number + 1.
3. Or, the count of the number is less than the count of previous one.
If the length of this scan is smaller than 3, return `false`. Otherwise continue scanning until we deplete `m`.

```cpp
// OJ: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums) m[n]++;
        while (m.size()) {
            auto i = m.begin();
            int cnt = 0, len = 0, prev = i->first - 1;
            while (i != m.end() && i->first == prev + 1 && i->second >= cnt) {
                cnt = i->second;
                prev = i->first;
                if (!--i->second) i = m.erase(i);
                else ++i;
                ++len;
            }
            if (len < 3) return false;
        }
        return true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        queue<int> starts;
        int prevCnt = 0, prev, N = nums.size();
        for (int i = 0; i < N; ++i) {
            if (i > 0 && nums[i] != nums[i - 1] + 1) {
                while (prevCnt--) {
                    if (prev - starts.front() < 2) return false;
                    starts.pop();
                }
            }
            int cnt = 1;
            for (; i + 1 < N && nums[i + 1] == nums[i]; ++cnt, ++i);
            if (cnt > prevCnt) {
                for (int j = prevCnt; j < cnt; ++j) starts.push(nums[i]);
            } else if (cnt < prevCnt){
                int c = prevCnt - cnt;
                while (c--) {
                    if (prev - starts.front() < 2) return false;
                    starts.pop();
                }
            }
            prevCnt = cnt;
            prev = nums[i];
        }
        while (prevCnt--) {
            if (prev - starts.front() < 2) return false;
            starts.pop();
        }
        return true;
    }
};
```