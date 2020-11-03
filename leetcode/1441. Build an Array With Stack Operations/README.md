Build an Array With Stack Operations


## Solution 1.

We use `i` to scan from `1` to `n`, and `j` to scan each element in `A`.

For each `i`:
* if `i` doesn't exist in `A`, we push `"Push"` and `"Pop"` into the answer.
* if `i` exist in `A`, we push `"Push"` into the answer, and increment `j`.

We should break the loop once `j` reaches the end of `A`.

```cpp
// OJ: https://leetcode.com/problems/build-an-array-with-stack-operations/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> buildArray(vector<int>& A, int n) {
        vector<string> ans;
        int i = 1, j = 0;
        while (j < A.size()) {
            while (i != A[j]) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++i;
            } 
            ans.push_back("Push");
            ++i;
            ++j;
        }
        return ans;
    }
};
```