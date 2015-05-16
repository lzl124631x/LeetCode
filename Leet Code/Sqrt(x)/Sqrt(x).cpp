#include <iostream>
#include <iomanip> 
using namespace std;

// sqrt(int x): http://www.2cto.com/kf/201304/202852.html
// C 语言Printf cout 输出格式【转】: http://anwj336.blog.163.com/blog/static/8941520920109141031882/
class Solution {
public:
    int sqrt(int x) {
    	long long int low = 0, high = x - 1, mid;
    	while(low < high){
    		mid = (low + high) >> 1;
    		if(mid * mid < x){
    			low = mid + 1;
    		}else{
    			high = mid - 1;
    		}
    	}
    	if(low * low > x){
    		do{ low--; }while(low * low > x);
    	}else if(low * low < x){
    		low++;
    		if(low * low > x) low--;
    	}
    	return low;
    }
};

int main(){
	for(int i = 0; i < 20; ++i)
		cout << setw(3) << i;
	cout << endl;
	Solution s;
	for(int i = 0; i < 20; ++i)
		cout << setw(3) << s.sqrt(i);
	cout << endl;
	cout << s.sqrt(2147395599) << endl;
	return 0;
}