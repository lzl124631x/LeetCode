// OJ: https://leetcode.com/problems/product-of-the-last-k-numbers/
// Author: github.com/lzl124631x
// Time:
//      ProductOfNumbers, add: O(1)
//      getProduct: O(k)
// Space: O(N)
class ProductOfNumbers {
    vector<int> v;
public:
    ProductOfNumbers() {}
    void add(int num) {
        v.push_back(num);
    }
    int getProduct(int k) {
        int ans = 1;
        for (int i = v.size() - 1; k-- && ans; --i) {
            ans *= v[i];
        }
        return ans;
    }
};