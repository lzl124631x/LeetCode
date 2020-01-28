
#ifndef codec_h
#define codec_h
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

template<typename T>
string vectorToString(vector<T> v){
	auto i = v.begin();
	ostringstream ans;
    ans << "[";
	for(; i != v.end(); ++i) {
		ans << *i;
		if (i + 1 != v.end()) ans << ",";
	}
	ans << "]";
	return ans.str();
}

vector<string> stringToVector(string str) {
	str = str.substr(1, str.size() - 2);
	istringstream ss(str);
	string token;
	vector<string> ans;
	while (getline(ss, token, ',')) ans.push_back(token);
	return ans;
}

template<typename T>
void printVector(vector<vector<T> > v){
	for(int i = 0; i < v.size(); ++i){
		for(int j = 0; j < v[i].size(); ++j){
			cout << "[" << v[i][j] << "] ";
		}
		cout << endl;
	}
}

vector<vector<int> > scanVector(int m, int n){
	vector<vector<int> > v;
	for(int i = 0; i < m; ++i){
		vector<int> v1;
		for(int j = 0; j < n; ++j){
			int d;
			cin >> d;
			v1.push_back(d);
		}
		v.push_back(v1);
	}
	return v;
}

#endif