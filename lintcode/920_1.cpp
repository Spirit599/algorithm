/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
struct cmp_interval
{
    
    bool operator() (const Interval& p1, const Interval& p2)
    {
        if(p1.start != p2.start)
        {
            return p1.start < p2.start;
        }
        else
        {
            return p1.end > p2.end;
        }
    }
};

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp_interval());

        int n = intervals.size();
        for(int i = 0; i + 1 < n; ++i)
        {
            if(intervals[i].end > intervals[i + 1].start)
            {
                return false;
            }
        }

        return true;
    }
};