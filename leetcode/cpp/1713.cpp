class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {

        unordered_map<int, int> memo;
        
        int n = target.size();
        for(int i = 0; i < n; ++i)
            memo[target[i]] = i;

        vector<int> upArr;
        for(int num : arr)
        {
            auto it = memo.find(num);
            if(it == memo.end())
                continue;
            int idx = it->second;
            auto itArr = lower_bound(upArr.begin(), upArr.end(), idx);
            if(itArr != upArr.end())
                *itArr = idx;
            else
                upArr.emplace_back(idx);
        }

        return n - upArr.size();
    }
};