// OJ: https://leetcode.com/problems/design-hashset/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class MyHashSet {
private:
    bitset<1000001> bs; 
public:
    MyHashSet() {}
    void add(int key) { bs.set(key); }
    void remove(int key) { bs.reset(key); }
    bool contains(int key) { return bs.test(key); }
};