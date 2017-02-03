// https://discuss.leetcode.com/topic/46904/very-concise-c-solution
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
private:
    struct cmp {
        bool operator() (Interval a, Interval b) { return a.start < b.start; }
    };
    set<Interval, cmp> s;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = s.lower_bound(Interval(val, val));
        if (it != s.begin() && prev(it)->end + 1 >= val) --it;
        int start = val, end = val;
        while (it != s.end() && it->start - 1 <= val && it->end + 1 >= val) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = s.erase(it);
        }
        s.insert(Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(s.begin(), s.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */