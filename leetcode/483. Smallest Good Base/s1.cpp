// https://discuss.leetcode.com/topic/76347/3ms-ac-c-long-long-int-binary-search
class Solution {
    typedef unsigned long long ull;
public:
    string smallestGoodBase(string n) {
        ull num = (ull)stoll(n);
        int maxlen = log(num) / log(2) + 1;
        for(int k = maxlen; k >= 3; --k){
            ull b = pow(num, 1.0 / (k - 1)), sum = 1, cur = 1;
            for (int i = 1; i < k; ++i) sum += (cur *= b);
            if (sum == num) return to_string(b);
        }  
        return to_string(num - 1);
    }
};