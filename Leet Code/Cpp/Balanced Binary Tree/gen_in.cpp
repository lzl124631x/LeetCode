#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	while(true){
		int limit = 0;
		cin >> limit;
		limit = (1 << limit) - 1;
		char fname[20] = {0};
		sprintf(fname, "%d.txt", limit);
		freopen(fname, "w", stdout);
		cout << limit << ",";
		for(int i = 2; i < limit; ++i){
			cout << 1 << ",";
		}
		cout << "1" << endl;
	}
	return 0;
}