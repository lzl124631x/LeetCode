// https://discuss.leetcode.com/topic/63827/c-solution-with-comments
class AllOne {
private:
    list<pair<int, unordered_set<string>>> v;
    unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> m;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!m.count(key)) m[key] = v.insert(v.begin(), { 0, { key }});
        auto it = m[key], n = next(it);
        if (n == v.end() || n->first > it->first + 1)
            n = v.insert(n, { it->first + 1, { }});
        n->second.insert(key);
        m[key] = n;
        
        it->second.erase(key);
        if (it->second.empty()) v.erase(it);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!m.count(key)) return;
        auto it = m[key], p = prev(it);
        m.erase(key);
        if (it->first > 1) {
            if (it == v.begin() || p->first < it->first - 1)
                p = v.insert(it, { it->first - 1, {} });
            p->second.insert(key);
            m[key] = p;
        }
        it->second.erase(key);
        if (it->second.empty()) v.erase(it);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return v.empty() ? "" : *v.back().second.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return v.empty() ? "" : *v.front().second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */