class RandomizedCollection {
private:
    vector<int> v;
    unordered_multimap<int, int> m;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = false;
        if (m.find(val) == m.end()) ret = true;
        v.push_back(val);
        m.insert(make_pair(val, v.size() - 1));
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        auto it = m.find(val);
        auto range = m.equal_range(v.back());
        for_each(
            range.first,
            range.second,
            [&] (unordered_multimap<int, int>::value_type &x) {
                if (x.second == v.size() - 1) x.second = it->second;
            });
        v[it->second] = v.back();
        v.pop_back();
        m.erase(it);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */