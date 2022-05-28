/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    struct cmp_interval
    {
        bool operator() (const Interval& p1, const Interval& p2)
        {
            return p1.start < p2.start;
        }
    };
    vector<Interval> merge(vector<Interval> &intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp_interval());

        vector<Interval> ans;

        Interval tmp{-1, -1};

        for(const auto& interval : intervals)
        {
            if(tmp.start == -1)
            {
                tmp.start = interval.start;
                tmp.end = interval.end;
            }
            else if(tmp.end >= interval.start)
            {
                tmp.end = max(tmp.end, interval.end);
            }
            else
            {
                ans.emplace_back(tmp);
                tmp.start = interval.start;
                tmp.end = interval.end;
            }
        }

        if(tmp.start != -1)
            ans.emplace_back(tmp);

        return ans;
    }
};