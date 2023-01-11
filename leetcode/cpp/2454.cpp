// 双单调栈

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, -1), sta1, sta2;

        for(int i = 0; i < n; ++i)
        {
            while(!sta2.empty() && nums[sta2.back()] < nums[i])
            {
                ans[sta2.back()] = nums[i];
                sta2.pop_back();
            }

            int j = sta1.size() - 1;
            while(j >= 0 && nums[sta1[j]] < nums[i])
                --j;
            sta2.insert(sta2.end(), sta1.begin() + (j + 1), sta1.end());
            sta1.resize(j + 1);
            sta1.push_back(i);
        }

        return ans;
    }
};