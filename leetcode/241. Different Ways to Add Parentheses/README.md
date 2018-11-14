# [241. Different Ways to Add Parentheses (Medium)](https://leetcode.com/problems/different-ways-to-add-parentheses/)

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are `+`, `-` and `*`.

**Example 1:**

**Input:** `"2-1-1"`  
**Output:** `[0, 2]`  
**Explanation:**
```
((2-1)-1) = 0 
(2-(1-1)) = 2
```

**Example 2:**

**Input:** `"2*3-4*5"`  
**Output:** `[-34, -14, -10, -10, 10]`  
**Explanation:**
```
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
```

## Solution 1. Divide And Conquer

For each operator, use it to separate the expression into two parts. Compute the `diffWaysToCompute` for both the left and right parts, and merge the results.

```cpp
// OJ: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author: github.com/lzl124631x
// Time: O(C(N)) where C(N) is the count of the result given `input` of length N
// Space: O(C(N))
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for (int i = 0; i < input.size(); ++i) {
            if (isdigit(input[i])) continue;
            auto lefts = diffWaysToCompute(input.substr(0, i));
            auto rights = diffWaysToCompute(input.substr(i + 1));
            for (int left : lefts) {
                for (int right : rights) {
                    switch(input[i]) {
                        case '+': ans.push_back(left + right); break;
                        case '-': ans.push_back(left - right); break;
                        case '*': ans.push_back(left * right); break;
                    }
                }
            }
        }
        return ans.size() ? ans : vector<int>{ stoi(input) };
    }
};
```