// 2406. 将区间分为最少组数

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2)
                                                    {
                                                        return v1[0] < v2[0];
                                                    });

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& vec : intervals)
        {
            if(pq.empty() || pq.top() >= vec[0])
            {
                pq.push(vec[1]);
            }
            else
            {
                pq.pop();
                pq.push(vec[1]);
            }
        }


        return pq.size();

    }
};