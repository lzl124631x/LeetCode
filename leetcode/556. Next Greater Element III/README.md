# [556. Next Greater Element III (Medium)](https://leetcode.com/problems/next-greater-element-iii/)

<p>Given a positive <strong>32-bit</strong> integer <strong>n</strong>, you need to find the smallest <strong>32-bit</strong> integer which has exactly the same digits existing in the integer <strong>n</strong> and is greater in value than n. If no such positive <strong>32-bit</strong> integer exists, you need to return -1.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 12
<strong>Output:</strong> 21
</pre>

<p>&nbsp;</p>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 21
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/)
* [Next Greater Element II (Medium)](https://leetcode.com/problems/next-greater-element-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/next-greater-element-iii/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int nextGreaterElement(int n) {
        auto s = to_string(n);
        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] >= s[i + 1]) continue;
            int j = lower_bound(s.begin() + i + 1, s.end(), s[i], greater<int>()) - s.begin() - 1;
            swap(s[i], s[j]);
            sort(s.begin() + i + 1, s.end());
            long n = stol(s);
            return n > INT_MAX ? -1 : n;
        }
        return -1;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/next-greater-element-iii
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/85740/c-4-lines-next_permutation
class Solution {
public:
    int nextGreaterElement(int n) {
      auto digits = to_string(n);
      next_permutation(begin(digits), end(digits));
      auto ans = stol(digits);
      return (ans > INT_MAX || ans <= n) ? -1 : ans;
    }
};
```