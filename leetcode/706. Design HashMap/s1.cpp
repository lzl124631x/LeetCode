// OJ: https://leetcode.com/problems/design-hashmap/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class MyHashMap {
private:
    const static int N = 1000001;
    int m[N];
public:
    MyHashMap() {
        for (int i = 0; i < N; ++i) m[i] = -1;
    }
    void put(int key, int value) {
        m[key] = value;
    }
    int get(int key) {
        return m[key];
    }
    void remove(int key) {
        m[key] = -1;
    }
};