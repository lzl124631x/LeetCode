# [670. Maximum Swap (Medium)](https://leetcode.com/problems/maximum-swap/)

<p>
Given a non-negative integer, you could swap two digits <b>at most</b> once to get the maximum valued number. Return the maximum valued number you could get.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 2736
<b>Output:</b> 7236
<b>Explanation:</b> Swap the number 2 and the number 7.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 9973
<b>Output:</b> 9973
<b>Explanation:</b> No swap.
</pre>
<p></p>


<p><b>Note:</b><br>
</p><ol>
<li>The given number is in the range [0, 10<sup>8</sup>]</li>
</ol>
<p></p>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-swap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num), memo(digits.size(), '\0');
        int maxIndex = digits.size() - 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] > digits[maxIndex]) maxIndex = i;
            memo[i] = maxIndex;
        }
        for (int i = 0; i < digits.size(); ++i) {
            if (memo[i] > i && digits[i] != digits[memo[i]]) {
                swap(digits[i], digits[memo[i]]);
                return stoi(digits);
            }
        }
        return num;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-swap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num);
        int last[10] = {};
        for (int i = 0; i < digits.size(); ++i) last[digits[i] - '0'] = i;
        for (int i = 0; i < digits.size(); ++i) {
            for (int j = 9; j > digits[i] - '0'; --j) {
                if (last[j] > i) {
                    swap(digits[i], digits[last[j]]);
                    return stoi(digits);
                }
            }
        }
        return num;
    }
};
```