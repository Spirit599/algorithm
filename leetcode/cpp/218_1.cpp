// 扫描线

class Solution {
public:

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<int> scanLine;
        for(auto& building : buildings)
        {
            scanLine.push_back(building[0]);
            scanLine.push_back(building[1]);
        }
        sort(scanLine.begin(), scanLine.end());

        vector<vector<int>> ans;
        int index = 0;
        int n = buildings.size();
        priority_queue<pair<int, int>> pq;
        for(int x : scanLine)
        {
            while(index < n && buildings[index][0] <= x)
            {
                pq.push(make_pair(buildings[index][2], buildings[index][1]));
                ++index;
            }
            while(!pq.empty() && pq.top().second <= x)
                pq.pop();

            int y = !pq.empty() ? pq.top().first : 0;
            if(!ans.size() || ans.back()[1] != y)
                ans.push_back({x, y});

        }

        return ans;
    }
};