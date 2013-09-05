/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        bool flag = false;
        for (Interval &interval : intervals) {
            if (Overlap(interval, newInterval)) {
                Merge(newInterval, interval);
            } else {
                if (!flag && newInterval.end < interval.start) {
                    ans.push_back(newInterval);
                    flag = true;
                }                 
                ans.push_back(interval);                    
            }
        }
        if (!flag) ans.push_back(newInterval);
        return ans;
    }
private:
    bool Overlap(Interval &lhs, Interval &rhs) const {
        return lhs.start <= rhs.end && rhs.start <= lhs.end;
    }
    void Merge(Interval &lhs, const Interval &rhs) {
        lhs.start = min(lhs.start, rhs.start);
        lhs.end = max(lhs.end, rhs.end);
    }
};
