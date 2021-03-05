/*
题目：https://www.nowcoder.com/practice/69f4e5b7ad284a478777cb2a17fb5e6a
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
*/

bool cmp(Interval a, Interval b) {
    if (a.start == b.start) {
        return a.end < b.end;
    }
    
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> tmp;
        if (intervals.empty()) {
            return tmp;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        tmp.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (tmp.back().end < intervals[i].start) {
                tmp.push_back(intervals[i]);
            } else if (intervals[i].end > tmp.back().end) {
                tmp.back().end = intervals[i].end;
            }
        }
        
        return tmp;
    }
};