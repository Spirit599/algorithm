// 919 会议室2

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
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b)
                                                    {
                                                        if(a.start != b.start)
                                                            return a.start < b.start;
                                                        else
                                                            return a.end < b.end;
                                                    });


        priority_queue<int, vector<int>, greater<int>> pq;

        for(Interval meeting : intervals)
        {
            if(!pq.empty())
            {
                if(pq.top() <= meeting.start)
                {
                    pq.pop();
                    pq.push(meeting.end);
                }
                else
                {
                    pq.push(meeting.end);
                }
            }
            else
            {
                pq.push(meeting.end);
            }
        }

        return pq.size();
    }
};