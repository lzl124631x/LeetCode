#include <iostream>
#include <string>
using namespace std;

void printString(const char *s){
	cout << "const char *s" << endl;
}

// String.cpp:22:17: warning: deprecated conversion from string constant to ‘char*’
// void printString(char *s){
// 	cout << "char *s" << endl;
// }

void printString(const string s){
	cout << "const string s" << endl;
}

// String.cpp:18:6: error: redefinition of ‘void printString(std::string)’
// void printString(string s){
// 	cout << "string s" << endl;
// }

int main(){
	printString("Hello");
	return 0;
}