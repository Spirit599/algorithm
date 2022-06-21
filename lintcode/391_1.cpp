// 391 · 数飞机

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
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        
        vector<pair<int, int>> vec;
        for(Interval interval : airplanes)
        {
            vec.push_back(make_pair(interval.start, 1));
            vec.push_back(make_pair(interval.end, -1));
        }

        sort(vec.begin(), vec.end(), [](const pair<int, int>& p1, const pair<int, int>& p2)
                                        {
                                            if(p1.first != p2.first)
                                                return p1.first < p2.first;
                                            else
                                                return p1.second < p2.second;
                                        });

        int cur = 0;
        int ans = 0;
        for(auto& p : vec)
        {
            cur += p.second;
            ans = max(ans, cur);
        }

        return ans;
    }
};