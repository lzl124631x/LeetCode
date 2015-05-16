class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        string::reverse_iterator i = a.rbegin(), j = b.rbegin();
        int carry = 0;
        while(i != a.rend() || j != b.rend()){
            if(i != a.rend()){
                carry += *i++ - '0';
            }
            if(j != b.rend()){
                carry += *j++ - '0';
            }
            ret += carry % 2 + '0';
            carry /= 2;
        }
        if(carry){
            ret += '1';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};