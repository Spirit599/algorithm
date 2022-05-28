//hash
//哈希表

bool cmp(pair<char, vector<int>>& p1, pair<char, vector<int>>& p2)
{
    // int n = p1.second.size();
    // for (int i = 0; i < n; ++i)
    // {
    //     if(p1.second[i] != p2.second[i])
    //     {
    //         return p1.second[i] > p2.second[i];
    //     }
    // }
    if(p1.second != p2.second)
        return p1.second > p2.second;
    else
        return p1.first < p2.first;
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {

        int m = votes.size();
        int n = votes[0].size();

        unordered_map<char, vector<int>> um;
        for (int j = 0; j < n; ++j)
        {
            um[votes[0][j]].resize(n);
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ++um[votes[i][j]][j];
            }
        }


        vector<pair<char, vector<int>>> vp(um.begin(), um.end());
        // for(auto kav : um)
        // {
        //     vp.push_back({kav.first, kav.second});
        // }

        sort(vp.begin(), vp.end(), cmp);

        string ans;
        for (int i = 0; i < n; ++i)
        {
            ans.push_back(vp[i].first);
        }

        return ans;
    }
};