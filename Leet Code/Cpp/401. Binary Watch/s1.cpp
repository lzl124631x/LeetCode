class Solution {
private:
    vector<string> v;
    int A = 0;
    void recursiveRead(int start, int num) {
        if (num == 0) {
            readOut();
            return;
        }
        for (int i = start; i <= 10 - num; ++i) {
            A |= (1 << i);
            recursiveRead(i + 1, num - 1);
            A &= (~0 ^ (1 << i));
        }
    }
    
    void readOut() {
        string s;
        int hour = (A >> 6), minute = A & ((1 << 6) - 1);
        if (hour > 11) return;
        if (minute > 59) return;
        s += to_string(hour);
        s += ":";
        if (minute < 10) s += "0";
        s += to_string(minute);
        v.push_back(s);
    }
public:
    vector<string> readBinaryWatch(int num) {
        recursiveRead(0, num);
        return v;
    }
};