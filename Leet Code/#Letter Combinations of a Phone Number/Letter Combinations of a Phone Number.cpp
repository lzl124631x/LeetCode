#include <string>
using namespace std;

class Solution {
public:
	static const char map[][5]; 
	char buf[10000];
	void DFS(const char *digits, char *output, vector<string> &v){
		if(!*digits){
			*output = '\0';
			v.push_back(string(buf));
			return;
		}
		int n = *digits - '0';
		for(int i = 0; map[n][i]; ++i){
			*output++ = map[n][i];
			DFS(digits + 1, output, v);
			output--;
		}
	}

    vector<string> letterCombinations(string digits) {
    	vector<string> v;
    	DFS(digits.c_str(), buf, v);
    	return v;
    }
};

const char Solution::map[][5] = {
		" ",
		"", "abc", "def",
		"ghi", "jkl", "mno",
		"pqrs", "tuv", "wxyz",
	};