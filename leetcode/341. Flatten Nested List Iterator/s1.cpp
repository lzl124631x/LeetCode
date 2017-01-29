/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> s; // current, end
    
    void validate () {
        while (!s.empty()) {
            auto &p = s.top();
            auto &it = p.first, &end = p.second;
            if (it == end) {
                s.pop();
            } else if (it->isInteger()) break;
            else {
                auto &list = it->getList();
                s.top().first++;
                s.push(make_pair(list.begin(), list.end()));
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push(make_pair(nestedList.begin(), nestedList.end()));
        validate();
    }

    int next() {
        if (!hasNext()) return 0;
        auto &p = s.top();
        auto &cur = p.first, &end = p.second;
        int ans = cur->getInteger();
        ++cur;
        validate();
        return ans;
    }

    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */