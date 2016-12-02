class Solution {
public:
    string reverseString(string s) {
    	string r;
    	r.assign(s.rbegin(), s.rend());
    	return r;
    }
};