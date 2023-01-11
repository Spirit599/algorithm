class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        
        unordered_map <int, pair<unordered_set<int>, vector<int>>> memo;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        int key;

        bool ok = false;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                int dif = nums[j] - nums[i];
                if(dif == 0 || dif & 1)
                    continue;
                auto& ss = memo[dif].first;
                auto& vv = memo[dif].second;
                if(!ss.count(i) && !ss.count(j))
                {
                    ss.emplace(i);
                    ss.emplace(j);
                    vv.emplace_back(i);
                }
                if(ss.size() == n)
                {
                    key = dif >> 1;
                    ans = vv;
                    ok = true;
                    break;
                }
            }
            if(ok)
                break;
        }

        printf("n = %d\n", n);

        int k = n >> 1;
        for(int i = 0; i < k; ++i)
            ans[i] = nums[ans[i]] + key;



        return ans;
    }
};