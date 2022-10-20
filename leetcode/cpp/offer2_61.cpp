typedef pair<int, int> pii;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> ans;
        auto cmp = [&](const pii& x, const pii& y) {
            return nums1[x.first] + nums2[x.second] > nums1[y.first] + nums2[y.second];
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        set<pii> vis;
        vis.insert(make_pair(0, 0));
        pq.push(make_pair(0, 0));
        //ans.push_back({nums1[0], nums2[0]});
        while(k-- && !pq.empty())
        {
            pii cur = pq.top();
            pq.pop();
            ans.push_back({nums1[cur.first], nums2[cur.second]});
            int x1 = cur.first + 1;
            int y1 = cur.second;
            if(x1 < n1 && !vis.count(make_pair(x1, y1)))
            {
                vis.insert(make_pair(x1, y1));
                pq.push(make_pair(x1, y1));
                //ans.push_back({nums1[x1], nums2[y1]});
            }
            int x2 = cur.first;
            int y2 = cur.second + 1;
            if(y2 < n2 && !vis.count(make_pair(x2, y2)))
            {
                vis.insert(make_pair(x2, y2));
                pq.push(make_pair(x2, y2));
                //ans.push_back({nums1[x2], nums2[y2]});
            }
        }
        return ans;
    }
};