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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> times;
        int res = 0;
        for (auto val:intervals) {
            times.push_back(make_pair(val.start,1));
            times.push_back(make_pair(val.end,-1));
        }
        sort(times.begin(), times.end());
        int tmp = 0;
        for (int i=0;i<times.size();i++) {
            tmp += times[i].second;
            res = max(res, tmp);
        }
        return res;
    }
};