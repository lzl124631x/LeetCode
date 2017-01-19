#include "../+Helper/Helper.h"
#include "s2.cpp"

#include <cstdio>
int main() {
	Solution s;
	unordered_set<string> d{"hot","cog","dot","dog","hit","lot","log"};
	string a = "hit";
	string b = "cog";
	auto v = s.findLadders(a, b, d);
	for (auto vv : v) {
		for (auto s : vv) {
			cout << s << ",";
		}
		cout << endl;
	}
	return 0;
}