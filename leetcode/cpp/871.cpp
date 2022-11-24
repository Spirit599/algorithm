class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        int ans = 0;
        int curX = startFuel;
        int curIndex = 0;
        int n = stations.size();
        priority_queue<int> pq;

        while(curX < target)
        {
            while(curIndex < n && curX >= stations[curIndex][0])
            {
                pq.emplace(stations[curIndex][1]);
                ++curIndex;
            }
            if(pq.empty())
                return -1;
            ++ans;
            curX += pq.top();
            pq.pop();
        }

        return ans;
    }
};