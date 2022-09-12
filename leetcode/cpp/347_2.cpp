class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {


        unordered_map<int, int> memo;
        for(int num : nums)
            memo[num]++;
        vector<pair<int, int>> fk;
        for(auto& kav : memo)
            fk.push_back({kav.second, kav.first});

        priority_queue<pair<int, int>> pq(fk.begin(), fk.end());
        vector<int> ans(k);

        for(int i = 0; i < k; ++i)
        {
            ans[i] = pq.top().second;
            pq.pop();
        }


        return ans;


    }


};