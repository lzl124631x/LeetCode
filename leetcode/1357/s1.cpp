// OJ: https://leetcode.com/problems/apply-discount-every-n-orders/
// Author: github.com/lzl124631x
// Time:
//      Cashier: O(P) where P is the count of all products
//      getBill: O(N) where N is the count of product the customer bought
// Space: O(P)
class Cashier {
    int num = 0, n, discount;
    unordered_map<int, int> m;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : n(n), discount(discount) {
        for (int i = 0; i < products.size(); ++i) m[products[i]] = prices[i];
    }
    double getBill(vector<int> product, vector<int> amount) {
        double p = 0;
        for (int i = 0; i < product.size(); ++i) p += m[product[i]] * amount[i];
        if (++num % n == 0) p -= (discount * p) / 100;
        return p;
    }
};