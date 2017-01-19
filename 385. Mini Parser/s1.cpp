/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger(); // empty list
        if (s[0] == '[') { // nested list
            NestedInteger n;
            int i = 1, end = s.size() - 1;
            while (i < end) {
                int begin = i;
                if (s[i] == '[') { // element being nested list
                    int cnt = 0;
                    do {
                        if (s[i] == '[') ++cnt;
                        else if (s[i] == ']') --cnt;
                        ++i;
                    } while (cnt > 0);
                } else {
                    while (isdigit(s[i]) || s[i] == '-') ++i;
                }
                n.add(deserialize(s.substr(begin, i - begin)));
                ++i;
            }
            return n;
        }
        // plain number
        return NestedInteger(stoi(s));
    }
};