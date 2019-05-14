// OJ: https://leetcode.com/problems/nested-list-weight-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int getDepth(vector<NestedInteger>& nestedList) {
        int ans = 0;
        for (auto &item : nestedList) ans = max(ans, item.isInteger() ? 1 : 1 + getDepth(item.getList()));
        return ans;
    }
    int getSum(vector<NestedInteger>& nestedList, int weight) {
        int sum = 0;
        for (auto &item : nestedList) sum += item.isInteger() ? (item.getInteger() * weight) : getSum(item.getList(), weight - 1);
        return sum;
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = getDepth(nestedList);
        return getSum(nestedList, depth);
    }
};