#include <string>
using namespace std;
#include <stdio.h>

class Solution {
public:
    string countAndSay(int n) {
        string in = "1";
        char buf[100000] = {0}, *p = NULL;
        while(--n > 0){
            p = buf;
            string::iterator i = in.begin();
            while(i != in.end()){
                int cnt = 1;
                char c = *i++;
                while(i != in.end() && *i == c){
                    i++;
                    cnt++;
                }
                p += sprintf(p, "%d%c", cnt, c);
            }
            in = string(buf);
        }
        return in;
    }
};