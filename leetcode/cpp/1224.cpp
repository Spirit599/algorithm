class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {

        unordered_map<int, int> memo1;
        map<int, int> memo2;

        int n = nums.size();
        for(int i = 0; i < n; ++i)
            ++memo1[nums[i]];
        for(auto& kv : memo1)
            ++memo2[kv.second];


        auto check = [&]() -> bool {

            if(memo1.size() == 1)
                return true;
            if(memo2.size() == 1)
                return memo2.begin()->first == 1;
            if(memo2.size() != 2)
                return false;
            auto it = memo2.begin();
            int k1 = it->first;
            int v1 = it->second;
            if(k1 == 1 && v1 == 1)
                return true;
            ++it;
            int k2 = it->first;
            int v2 = it->second;
            if(k2 - k1 == 1 && v2 == 1)
                return true;
            return false;
            
        };



        int right = n - 1;
        while(!check())
        {
            auto it = memo1.find(nums[right]);
            int key = it->second;
            auto it1 = memo2.find(key);
            --(it1->second);
            if(it1->second == 0)
                memo2.erase(it1);
            if(key != 1)
                ++memo2[key - 1];
            --(it->second);
            if(it->second == 0)
                memo1.erase(it);
            --right;
        }

        return right + 1;

    }
};