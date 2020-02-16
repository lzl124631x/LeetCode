// OJ: https://leetcode.com/problems/product-of-the-last-k-numbers/
// Author: github.com/lzl124631x
// Time: O(1) for all functions
// Space: O(N)
class ProductOfNumbers {
    vector<int> v{1};
public:
    ProductOfNumbers() {}
    
    void add(int num) {
        if (num) v.push_back(v.back() * num);
        else v = {1};
    }
    
    int getProduct(int k) {
        return k < v.size() ? v.back() / v[v.size() - k - 1] : 0;
    }
};