// OJ: https://leetcode.com/problems/encode-and-decode-tinyurl
// Author: github.com/lzl124631x
// Time:
//    encode: O(log_36_N)
//    decode: O(1)
// Space: O(N)
class Solution {
private:
  unordered_map<string, string> m;
  string current = "0";
public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    m[current] = longUrl;
    string ret = current;
    int carry = 1, i = 0;
    for (; carry && i < current.size(); ++i) {
      carry = 0;
      if (current[i] == '9') current[i] = 'a';
      else if (current[i] == 'z') current[i] = 'A';
      else if (current[i] == 'Z') {
        current[i] = '0';
        carry = 1;
      } else current[i]++;
    }
    if (carry) current.push_back('0');
    return ret;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    return m[shortUrl];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));