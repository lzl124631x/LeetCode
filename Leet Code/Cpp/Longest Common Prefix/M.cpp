#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s = "123456";
	cout << string("123456", 3) << endl;
	cout << string(s, 3) << endl;
	cout << string(s.c_str(), 3) << endl;
	return 0;
}