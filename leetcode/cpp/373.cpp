typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> ans;
        bool vis[1005][1005];
        memset(vis, 0, sizeof(vis));
        vis[0][0] = true;
        auto cmp = [&](const pii& p1, const pii& p2)
        {

            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        pq.emplace(0, 0);
        int n1 = nums1.size();
        int n2 = nums2.size();
        while(k-- && !pq.empty())
        {
            int i = pq.top().first;
            int j = pq.top().second;
            ans.push_back({nums1[i], nums2[j]});
            pq.pop();
            if(j + 1 < n2 && !vis[i][j + 1])
            {
                pq.emplace(i, j + 1);
                vis[i][j + 1] = true;
            }
            if(i + 1 < n1 && !vis[i + 1][j])
            {
                pq.emplace(i + 1, j);
                vis[i + 1][j] = true;
            }
        }

        return ans;
    }
};