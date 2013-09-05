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
    vector<Interval> merge(vector<Interval> &intervals) {        
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > cur.end) {
                ans.push_back(cur);
                cur = intervals[i];                
            } else cur.end = max(cur.end, intervals[i].end);
        }
        ans.push_back(cur);
        return ans;
    }
private:
 static bool cmp(const Interval &lhs, const Interval &rhs) {
        return lhs.start < rhs.start;
    }
};
