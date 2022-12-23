class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {

        int n = req_skills.size();
        int S = 1 << n;

        
        int m = people.size();
        vector<int> peopleSkills(m);

        for(int j = 0; j < m; ++j)
        {
            int mask = 0;
            for(string& skill : people[j])
            {
                for(int i = 0; i < n; ++i)
                {
                    if(skill == req_skills[i])
                    {
                        mask |= 1 << i;
                        break;
                    }
                }
            }
            peopleSkills[j] = mask;
        }



        int dp[S];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        vector<int> dpv[S];

        for(int s = 1; s < S; ++s)
        {

            for(int j = 0; j < m; ++j)
            {
                int pmask = peopleSkills[j];
                int bothMask = pmask & s;
                if(dp[s ^ bothMask] + 1 < dp[s])
                {
                    dp[s] = dp[s ^ bothMask] + 1;
                    dpv[s] = dpv[s ^ bothMask];
                    dpv[s].emplace_back(j);
                }
            }
        }

        return dpv[S - 1];
    }
};