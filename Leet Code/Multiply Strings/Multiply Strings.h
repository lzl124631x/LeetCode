#include <string>
#include <algorithm>	// reverse
using namespace std;
class Solution {
public:
	string multiply(string num, int digit){
		if(!digit || num == "0") return "0";
		string::reverse_iterator i = num.rbegin();
		string ret;
		int carry = 0;
		for(; i != num.rend(); ++i){
			carry += (*i - '0') * digit;
			ret += carry % 10 + '0';
			carry /= 10;
		}
		if(carry){
			ret += carry + '0';
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}

	string plus(string num1, string num2, int offset_of_num2){
		if(num2 == "0") return num1;
		string ret;
		string::reverse_iterator i = num1.rbegin(), j = num2.rbegin();
		while(offset_of_num2-- > 0){
			if(i != num1.rend()){
				ret += *i;
				i++;				
			}else{
				ret += '0';
			}
		}
		int carry = 0;
		while(i != num1.rend() || j != num2.rend()){
			if(i != num1.rend()){
				carry += (*i - '0');
				i++;
			}
			if(j != num2.rend()){
				carry += (*j - '0');
				j++;
			}
			ret += carry % 10 + '0';
			carry /= 10;
		}
		if(carry){
			ret += carry + '0';
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
    
    string multiply(string num1, string num2) {
     	string ret = "0";
     	int len2 = num2.size();
     	for(int i = 0; i < len2; ++i){
     		ret = plus(ret, multiply(num1, num2[len2 - i - 1] - '0'), i);
     	}
     	return ret;
    }
};