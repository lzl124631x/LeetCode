// OJ: https://leetcode.com/problems/zigzag-iterator/
// Author: github.com/lzl124631x
// Time:
//   ZigzagIterator: O(K)
//   next: O(1)
//   hasNext: O(1)
// Space: O(K) where K is the number of input vectors
class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end()) q.push(make_pair(v1.begin(), v1.end()));
        if (v2.begin() != v2.end()) q.push(make_pair(v2.begin(), v2.end()));
    }
    int next() {
        auto p = q.front();
        q.pop();
        int val = *p.first;
        p.first++;
        if (p.first != p.second) q.push(p);
        return val;
    }
    bool hasNext() {
        return q.size();
    }
};