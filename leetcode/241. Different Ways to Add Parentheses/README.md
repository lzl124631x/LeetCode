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

> Tip: find the pattern of the length of output given `N` operators in `input`.
> |0|1|2|3|4|...|
> |---|---|---|---|---|---|
> |1|1|2|5|14|...|
> This is a Catalan Number Sequence. For this sequence, it's very likely that you can use "Divide and Conquer" -- separating the input as two parts, solve the subproblem of the smaller parts and merge them.

For each operator, use it to separate the expression into two parts. Compute the `diffWaysToCompute` for both the left and right parts, and merge the results.

```cpp
// OJ: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author: github.com/lzl124631x
// Time: S * O(C(N))
//          where S is the length of `input`,
//          N is the count of operators in `input` and C(N) is the Nth Catalan Number
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

## Solution 2.

Same idea as Solution 1, but with optimizations:

1. preprocess the input to avoid `substr` etc. operations that can be avoided
1. use `unordered_map` to memoize the results computed.

```cpp
// OJ: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author: github.com/lzl124631x
// Time: O(C(N)) where N is the count of operators in `input` and C(N) is the Nth Catalan Number
// Space: O(C(N))
class Solution {
private:
    unordered_map<int, unordered_map<int, vector<int>>> m;
    vector<int> nums;
    vector<char> ops;
    vector<int> compute(int begin, int end) {
        if (!m[begin][end].empty()) return m[begin][end];
        if (begin + 1 == end) return m[begin][end] = { nums[begin] };
        vector<int> ans;
        for (int i = begin; i < end - 1; ++i) {
            auto as = compute(begin, i + 1), bs = compute(i + 1, end);
            for (auto a : as) {
                for (auto b : bs) {
                    switch (ops[i]) {
                        case '+': ans.push_back(a + b); break;
                        case '-': ans.push_back(a - b); break;
                        case '*': ans.push_back(a * b); break;
                    }
                }
            }
        }
        return m[begin][end] = ans;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        istringstream ss(input);
        while (true) {
            int num;
            ss >> num;
            nums.push_back(num);
            char c;
            if (ss >> c) ops.push_back(c);
            else break;
        }
        compute(0, nums.size());
        return m[0][nums.size()];
    }
};
```