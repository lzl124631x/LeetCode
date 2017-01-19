#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v){
	vector<int>::iterator i = v.begin();
	for(; i != v.end(); ++i){
		cout << *i << " ";
	}
	cout<<endl;
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	vector<int> v;
    	string::iterator i1, i2, i3;
    	i1 = s1.begin();
    	i2 = s2.begin();
    	i3 = s3.begin();
    	v.push_back(1);
    	while(!v.empty() && i3 != s3.end()){
    		if(v.back() == 1){
    			if(i1 != s1.end() && *i1 == *i3){
    				i1++; i3++;
    				v.push_back(1);
    			}else{
    				v.back() = 2;
    			}
    		}else{
    			if(i2 != s2.end() && *i2 == *i3){
    				i2++; i3++;
    				v.push_back(1);
    			}else{
    				v.pop_back();
    				while(!v.empty() && v.back() == 2){
    						i2--; i3--;
    						v.pop_back();
    				}
    				if(!v.empty()){
    					i1--; i3--;
    					v.back() = 2;
    				}
    			}
    		}
    	}
    	return i1 == s1.end() && i2 == s2.end() && i3 == s3.end();
    }
};

int main(){
	string s1, s2, s3;
	s1 = "aabcc";
	s2 = "dbbca";
	// s3 = "aadbbcbcac"; // true
	// s3 = "aadbbbaccc"; // false
	
	s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
	s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
	s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
	Solution s;
	cout << boolalpha << s.isInterleave(s1, s2, s3) << endl;
	return 0;
}


/*

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	int a, b, c, i, j;
    	a = b = c = 0;
    	while(s1[a] && s2[b] && s3[c]){
    		i = a; j = b;
    		if(s1[i] != s3[c] && s2[j] != s3[c]){
    			return false;
    		}else{
    			while(s1[i] && s2[j] && s3[c] &&
    				s1[i] == s3[c] && s2[j] == s3[c]){
    				i++; j++; c++;
    			}
    			if(s1[i] && s3[c] && s1[i] == s3[c]){
    				a = i + 1; c++;
    			}else if(s2[j] && s3[c] && s2[j] == s3[c]){
    				b = j + 1; c++;
    			}
    		}
    	}
    	if(s1[a] == s3[c]){
    		while(s1[a] && s3[c] && s1[a] == s3[c]){
    			a++; c++;
    		}
    	}else{
    		while(s2[b] && s3[c] && s2[b] == s3[c]){
    			b++; c++;
    		}
    	}
        return !s1[a] && !s2[b] && !s3[c];
    }
};

*/

/*

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	stack<int> s;
    	string::iterator i1, i2, i3;
    	i1 = s1.begin();
    	i2 = s2.begin();
    	i3 = s3.begin();
    	while(i1 != s1.end() && i2 != s2.end() && i3 != s3.end()){
    		if(*i1 != *i3 && *i2 != *i3){
    			return false;
    		}else if(*i1 == *i3 && *i2 == *i3){

    		}else if(*i1 == *i3){
    			i1++; i3++;
    		}else{
    			i2++; i3++;
    		}
    	}
    	return true;
    }
};

*/