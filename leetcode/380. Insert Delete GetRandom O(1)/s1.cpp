// OJ: https://leetcode.com/problems/insert-delete-getrandom-o1/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.count(val)) return false;
        m[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!m.count(val)) return false;
        int i = m[val];
        m[v.back()] = i;
        swap(v[i], v.back());
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};