//hash
//前缀和
//TLE

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        int n = s.size();
        vector<unordered_map<char, int>> vu(n);
        unordered_map<char, int> um;
        um[s[0]] = 1;
        vu[0] = um;
        for (int i = 1; i < n; ++i)
        {
            unordered_map<char, int> um = vu[i - 1];
            if(um.count(s[i]) == 1)
            {
                ++um[s[i]];
            }
            else
            {
                um[s[i]] = 1;
            }
            //vu.push_back(um);
            vu[i] = um;
            // cout<<"-----------"<<endl;
            // for(auto kav : um)
            // {
            //     cout<<kav.first<<" "<<kav.second<<endl;
            // }
        }

        vector<bool> ans;
        int m = queries.size();
        for (int i = 0; i < m; ++i)
        {

            unordered_map<char, int> start;
            if(queries[i][0] != 0)
                start = vu[queries[i][0] - 1];
            unordered_map<char, int> end = vu[queries[i][1]];
            int detal = 0;
            // cout<<"-----------"<<endl;
            // for(auto kav : start)
            // {
            //     cout<<kav.first<<" "<<kav.second<<endl;
            // }
            // cout<<"-----------"<<endl;
            // for(auto kav : end)
            // {
            //     cout<<kav.first<<" "<<kav.second<<endl;
            // }
            for(auto kav : end)
            {
                char key = kav.first;
                int value = kav.second;
                if(start.count(key) == 1)
                {
                    detal += (value - start[key]) % 2;
                }
                else
                {
                    detal += value % 2;
                }
            }
            detal = detal / 2;

            if(detal > queries[i][2])
                ans.push_back(false);
            else
                ans.push_back(true);

        }

        return ans;
    }
};