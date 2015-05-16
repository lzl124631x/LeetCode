#include <iostream>
using namespace std;
#include <time.h>
#include "../+Helper/Helper.h"

int fibonacci_recursive(int n){
	if(n <= 0) return 0;
	if(n == 1 || n == 2) return 1;
	return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_iterative(int n){
	if(n <= 0) return 0;
	if(n == 1 || n == 2) return 1;
	int a = 1, b = 1, ret; n -= 2;
	while(n--){
		ret = a + b;
		a = b;
		b = ret;
	}
	return ret;
}

int main(){
	CLK_INIT;
	cout << "RECURSIVE" << endl;
	for(int i = 1; i <= 20; ++i){
		CLK_START;
		cout << i << ": " << fibonacci_recursive(i) << endl;
		CLK_END;
	}
	CLK_START;
	cout << "40: " << fibonacci_recursive(40) << endl;
	CLK_END;
	for(int i = 1; i <= 20; ++i){
		CLK_START;
		cout << i << ": " << fibonacci_iterative(i) << endl;
		CLK_END;
	}
	CLK_START;
	cout << "40: " << fibonacci_iterative(40) << endl;
	CLK_END;
	return 0;
}