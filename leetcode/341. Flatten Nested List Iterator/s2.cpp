// OJ: https://leetcode.com/problems/flatten-nested-list-iterator/
// Author: github.com/lzl124631x
// Time: O(1) amortized
// Space: O(N)
class NestedIterator {
    stack<NestedInteger> s;
    void goToInteger() {
        while (s.size() && !s.top().isInteger()) {
            auto list = s.top().getList();
            s.pop();
            for (int i = list.size() - 1; i >= 0; --i) s.push(list[i]);
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) s.push(nestedList[i]);
        goToInteger();
    }
    int next() {
        int val = s.top().getInteger();
        s.pop();
        goToInteger();
        return val;
    }
    bool hasNext() {
        return s.size();
    }
};