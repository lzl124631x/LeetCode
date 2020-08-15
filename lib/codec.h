
#ifndef codec_h
#define codec_h
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

template<typename T> void _R(T &x) { cin >> x; }

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

vector<int> stringToIntVector(string str) {
	str = str.substr(1, str.size() - 2);
	istringstream ss(str);
	string token;
	vector<int> ans;
	while (getline(ss, token, ',')) ans.push_back(stoi(token));
	return ans;
}

vector<int> toIntVector(vector<string> v) {
	vector<int> ans(v.size(), 0);
	for (int i = 0; i < v.size(); ++i) ans[i] = stoi(v[i]);
	return ans;
}

template<typename T>
void printVector(vector<vector<T>> v){
    cout << "[" << endl;
    for (int i = 0; i < v.size(); ++i) {
        auto &row = v[i];
        cout << "[";
        for (int j = 0; j < row.size(); ++j) {
            auto &val = row[j];
            cout << val;
            if (j < row.size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < v.size() - 1) cout << ", ";
        cout << endl;
    }
    cout << "]" << endl;
}

vector<vector<int>> readVector() {
    vector<vector<int>> ans;
	int i = 0;
    cin.get(); // outer [
    while (cin.peek() != ']') {
        cin.get(); // inner [
        if (ans.size() <= i) ans.emplace_back();
        int k = 0;
        while (cin.peek() != ']') {
            int n;
            cin >> n;
            ans[i].push_back(n);
            if (cin.peek() == ',') cin.get();
        }
        cin.get(); // inner ]
        if (cin.peek() == ',') cin.get();
        ++i;
    }
    cin.get(); // outer ]
    return ans;
}

#endif