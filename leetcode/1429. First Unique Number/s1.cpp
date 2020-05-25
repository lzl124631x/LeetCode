// OJ: https://leetcode.com/problems/first-unique-number/
// Author: github.com/lzl124631x
// Time:
//    FirstUnique: O(N)
//    showFirstUnique: O(1)
//    add: O(1)
// Space: O(N)
class FirstUnique {
    list<int> data;
    typedef list<int>::iterator iter;
    unordered_map<int, iter> m;
    unordered_set<int> s;
public:
    FirstUnique(vector<int>& nums) {
        for (int n : nums) add(n);
    }
    
    int showFirstUnique() {
        return data.size() ? data.front() : -1;
    }
    
    void add(int value) {
        if (s.count(value)) return;
        if (m.count(value)) {
            data.erase(m[value]);
            s.insert(value);
        } else {
            data.push_back(value);
            m[value] = prev(data.end());
        }
    }
};
