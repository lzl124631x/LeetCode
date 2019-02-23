// OJ: https://leetcode.com/problems/design-phone-directory/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(N)
class PhoneDirectory {
private:
    unordered_set<int> pool;
public:
    PhoneDirectory(int maxNumbers) {
        while (maxNumbers--) pool.insert(maxNumbers);
    }
    int get() {
        if (pool.empty()) return -1;
        int ans = *pool.begin();
        pool.erase(pool.begin());
        return ans;
    }
    bool check(int number) {
        return pool.find(number) != pool.end();
    }
    void release(int number) {
        if (check(number)) return;
        pool.insert(number);
    }
};