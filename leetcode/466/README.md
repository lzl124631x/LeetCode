# [466. Count The Repetitions (Hard)](https://leetcode.com/problems/count-the-repetitions/)

<p>Define <code>S = [s,n]</code> as the string S which consists of n connected strings s. For example, <code>["abc", 3]</code> ="abcabcabc". </p>
<p>On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc”  can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.</p>
<p>You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 10<sup>6</sup> and 1 ≤ n2 ≤ 10<sup>6</sup>. Now consider the strings S1 and S2, where <code>S1=[s1,n1]</code> and <code>S2=[s2,n2]</code>. Find the maximum integer M such that <code>[S2,M]</code> can be obtained from <code>S1</code>.</p>

<p><b>Example:</b>
</p><pre>Input:
s1="acb", n1=4
s2="ab", n2=2

Return:
2
</pre>
<p></p>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

See explanation [here](https://leetcode.com/problems/count-the-repetitions/discuss/95398/C%2B%2B-solution-inspired-by-%4070664914-with-organized-explanation)

```cpp
// OJ: https://leetcode.com/problems/count-the-repetitions/
// Author: github.com/lzl124631x
// Time: O(|s1| * n1) where |s1| is the length of s1
// Space: O(n1)
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCount(n1 + 1, 0);
        vector<int> nextIndex(n1 + 1, 0);
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    ++j;
                    if (j == s2.size()) {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            repeatCount[k] = cnt;
            nextIndex[k] = j;
            for (int start = 0; start < k; ++start) {
                if (nextIndex[start] == j) {
                    int prefixCount = repeatCount[start];
                    int patternCount = (n1 - start) / (k - start) * (repeatCount[k] - prefixCount);
                    int suffixCount = repeatCount[start + (n1 - start) % (k - start)] - prefixCount;
                    return (prefixCount + patternCount + suffixCount) / n2;
                }
            }
        }
        return repeatCount[n1] / n2;
    }
};
```

## Solution 2.

Same idea as Solution 1, but use `unordered_map` to save computation. Reduce runtime from ~80ms to ~4ms.

```cpp
// OJ: https://leetcode.com/problems/count-the-repetitions/
// Author: github.com/lzl124631x
// Time: O(|s1| * n1) where |s1| is the length of s1
// Space: O(n1)
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_map<int, int> kToRepeatCount;
        unordered_map<int, int> nextIndexToK;
        kToRepeatCount[0] = 0;
        nextIndexToK[0] = 0;
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    ++j;
                    if (j == s2.size()) {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            if (nextIndexToK.find(j) != nextIndexToK.end()) {
                int start = nextIndexToK[j];
                int prefixCount = kToRepeatCount[start];
                int patternCount = (n1 - start) / (k - start) * (cnt - prefixCount);
                int suffixCount = kToRepeatCount[start + (n1 - start) % (k - start)] - prefixCount;
                return (prefixCount + patternCount + suffixCount) / n2;
            }
            kToRepeatCount[k] = cnt;
            nextIndexToK[j] = k;
        }
        return kToRepeatCount[n1] / n2;
    }
};
```