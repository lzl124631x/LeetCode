// OJ: https://leetcode.com/problems/flatten-nested-list-iterator/
// Author: github.com/lzl124631x
// Time: O(1) amortized
// Space: O(D) where D is the max depth of the list
class NestedIterator {
    typedef vector<NestedInteger>::iterator iter;
    stack<pair<iter, iter>> s;
    void goToInteger() {
        while (s.size()) {
            if (s.top().first == s.top().second) {
                s.pop();
                if (s.size()) s.top().first++;
            } else if (s.top().first->isInteger()) break;
            else {
                auto &list = s.top().first->getList();
                s.emplace(list.begin(), list.end());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &list) {
        s.emplace(list.begin(), list.end());
        goToInteger();
    }
    
    int next() {
        int val = s.top().first->getInteger();
        s.top().first++;
        goToInteger();
        return val;
    }
    
    bool hasNext() {
        return s.size();
    }
};