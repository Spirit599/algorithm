class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<int> arr1;
        vector<int> arr2;
        int n = 100005;
        int win[n];
        memset(win, 0, sizeof(win));
        int lose[n];
        memset(lose, 0, sizeof(lose));

        for(auto& match : matches)
        {
            ++win[match[0]];
            ++lose[match[1]];
        }

        for(int i = 0; i < n; ++i)
        {
            if(lose[i] == 0 && win[i])
                arr1.push_back(i);
            else if(lose[i] == 1)
                arr2.push_back(i)
        }

        return {arr1, arr2};
    }
};