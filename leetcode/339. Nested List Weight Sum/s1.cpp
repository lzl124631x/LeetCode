// OJ: https://leetcode.com/problems/nested-list-weight-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(D) where D is the max depth of the list.
class Solution {
private:
    int depthSum(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (auto &i : nestedList) {
            if (i.isInteger()) sum += i.getInteger() * depth;
            else sum += depthSum(i.getList(), depth + 1);
        }
        return sum;
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSum(nestedList, 1);
    }
};