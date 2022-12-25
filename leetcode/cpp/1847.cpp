class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {

        int querieSize = queries.size();
        for(int i = 0; i < querieSize; ++i)
        {
            swap(queries[i][0], queries[i][1]);
            queries[i].emplace_back(i);
        }

        sort(queries.begin(), queries.end(), greater<>());
        int n = rooms.size();
        for(int i = 0; i < n; ++i)
            swap(rooms[i][0], rooms[i][1]);
        sort(rooms.begin(), rooms.end(), greater<>());

        vector<int> ans(querieSize);
        int idx = 0;
        
        set<int> roomsId;
        for(int i = 0; i < querieSize; ++i)
        {
            int minq = queries[i][0];
            while(idx < n && rooms[idx][0] >= minq)
            {
                roomsId.insert(rooms[idx][1]);
                ++idx;
            }

            int perfId = queries[i][1];
            int qIdx = queries[i][2]; 
            if(roomsId.empty())
            {
                ans[qIdx] = -1;
                continue;
            }

            int ret = -1;
            auto it = roomsId.lower_bound(perfId);
            if(it != roomsId.end())
                ret = *it;

            if(it != roomsId.begin())
            {
                --it;
                if(ret == -1)
                    ret = *it;
                else
                {
                    if(perfId - *it <= ret - perfId)
                        ret = *it;
                }
            }
            ans[qIdx] = ret;
        }

        return ans;
    }
};