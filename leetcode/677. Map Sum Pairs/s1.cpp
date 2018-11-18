// OJ: https://leetcode.com/problems/map-sum-pairs/
// Author: github.com/lzl124631x
// Time:
//     * insert: O(logN)
//     * sum: O(NW) where W is word length
// Space: O(N)
class MapSum {
private:
    map<string, int> m;
public:
    MapSum() { }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        for (auto start = m.lower_bound(prefix); start != m.end(); ++start) {
            if (start->first.compare(0, prefix.size(), prefix) != 0) break;
            sum += start->second;
        }
        return sum;
    }
};