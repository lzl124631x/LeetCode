#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int>::reverse_iterator i;
        i = digits.rbegin();
        int carry = 1;
        for(; i != digits.rend(); ++i){
        	carry += *i;
        	*i = carry % 10;
        	carry /= 10;
        }
        if(carry){
        	digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};